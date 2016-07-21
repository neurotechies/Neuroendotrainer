#include "cam_idsProdCons.h"

cam_ids_producer::cam_ids_producer()
{
    m_hCam = 0;
    m_pMemBuffer = NULL;
    m_nMemID = 0;
}

bool cam_ids_producer::initialize(const string &settingFile, string &errmsg)
{
    buf_aux::instance();

    FileStorage fs;

    settingFile_yml = settingFile;
    fs.open(settingFile_yml, FileStorage::READ);
    if (!fs.isOpened())
    {
        errmsg =  "Could not open the configuration file: " + settingFile_yml;
        return false;
    }
    camid = (int) fs["camID_ids"];
    rows = (int) fs["rows_ids"]; // 1024 / divider;
    cols = (int) fs["cols_ids"]; // 1280 / divider;
    size_bin_aux = (int) fs["size_Bin"];
    n_channels = 3;
    size_1_rgb = rows * cols * n_channels;
    size_1_yuv = rows * cols * 2;

    // first exit the instance of the camera
    /*cout << "Initialize Producer - mHCam - " << m_hCam << endl;
    if(m_hCam != 0)
    {
        //Disable messages
        is_EnableMessage(m_hCam, IS_FRAME, NULL);

        // stop live video
        is_StopLiveVideo(m_hCam, IS_WAIT);

        if(m_pMemBuffer != NULL)
        {
            is_FreeImageMem(m_hCam, m_pMemBuffer, m_nMemID);
        }
        m_pMemBuffer = NULL;

        //close the camera
        int pp = is_ExitCamera(m_hCam);
        cout << "Error code of Exiting the camera Initialize Producer - " << pp << endl;
        m_hCam = 0;
    }*/


    HIDS cam = camid;
    int nRet = is_InitCamera(&cam, 0);
    if (nRet == IS_SUCCESS)
    {
        m_hCam = cam;
        nRet = is_GetSensorInfo(m_hCam, &m_SensorInfo);

        cout<< "using device IDS UI-5240CP-C-HQ" << endl;
        errmsg = "using device IDS UI-5240CP-C-HQ";

        // Allocate the memory to buffer;
        // first free the previous allocated memory
        if(m_pMemBuffer != NULL && m_nMemID != 0)
        {
            nRet = is_FreeImageMem(m_hCam, m_pMemBuffer, m_nMemID);
            m_pMemBuffer = 0;
            m_nMemID = 0;
        }
        nRet = is_AllocImageMem(m_hCam, m_SensorInfo.nMaxWidth, m_SensorInfo.nMaxHeight, 24, &m_pMemBuffer, &m_nMemID);
        nRet = is_SetImageMem(m_hCam, m_pMemBuffer, m_nMemID);

        // Set the BGR8 capturing mode
        nRet = is_SetColorMode(m_hCam, IS_CM_BGR8_PACKED);
	
	// to do the top-left and top-bottom mirror 
        //is_SetRopEffect (m_hCam, IS_SET_ROP_MIRROR_UPDOWN, true, 0);
        //is_SetRopEffect (m_hCam, IS_SET_ROP_MIRROR_LEFTRIGHT, true, 0);


        cout<< "Memory Allocation Done \n";
        is_CaptureVideo(m_hCam, IS_DONT_WAIT);
        fs.release();
        return true;
    }
    else if (nRet == IS_DEVICE_ALREADY_PAIRED)
    {
        // Do nothing
        return true;
    }
    else
    {
        //cout << "Error code - " << nRet << endl;
        cout<< "Fail to open camera IDS UI-5240CP-C-HQ - Check if it is connected" << endl;
        errmsg = "Fail to open camera IDS UI-5240CP-C-HQ - Check if it is connected";
        fs.release();
        return false;
    }
    return true;
}

void cam_ids_producer::process()
{
    //std::vector<unsigned char> temp_rgb(size_1_rgb);
    std::vector<unsigned char> vec_frame_ax_rgb(size_1_rgb*size_bin_aux);
    char *lastBuffer;
    INT nRet;
    while(!m_abort)
    {
        if(m_hCam == 0) break;
        for(uint i = 0; i < size_bin_aux; ++i)
        {
            nRet = is_GetActSeqBuf(m_hCam, 0, 0, &lastBuffer);
            if (nRet == IS_SUCCESS)
            {
                std::copy ( lastBuffer, lastBuffer + (size_1_rgb), vec_frame_ax_rgb.begin() + ((i) * (size_1_rgb)));
            }
            else
            {
                cout << "Getting the frame error ... exiting \n";
                exit(1);
            }
        }
        //cout << "Going to lock \n";
        buf_aux::instance()->mutex.lock();
        while(buf_aux::instance()->getFull())
        {
            buf_aux::instance()->notFull.wait(&buf_aux::instance()->mutex);
        }
        //printf("Aux->P%d\n", buf_aux::instance()->getTail());
        buf_aux::instance()->setBuffer(vec_frame_ax_rgb);
        buf_aux::instance()->mutex.unlock();
        buf_aux::instance()->notEmpty.wakeOne();
        usleep(10);
        //cout << "End statement; val of m_abort (prcocess producer IDS) - " << m_abort << endl;
    }

    cout << "Out of Auxillary Producer\n";
    // close the camera
    //cout << "process Producer - mHCam - " << m_hCam << endl;
    if(m_hCam != 0)
    {
        //Disable messages
        is_EnableMessage(m_hCam, IS_FRAME, NULL);

        // stop live video
        is_StopLiveVideo(m_hCam, IS_WAIT);

        if(m_pMemBuffer != NULL)
        {
            is_FreeImageMem(m_hCam, m_pMemBuffer, m_nMemID);
        }
        m_pMemBuffer = NULL;

        //close the camera
        is_ExitCamera(m_hCam);
        //cout << "Error code of Exiting the camera Process Producer - " << pp <<endl;
        m_hCam = 0;
    }
    //cout << "finish the thread -- \n";
    emit finished();
}
cam_ids_consumer::cam_ids_consumer()
{
    m_grab = false;
}

void cam_ids_consumer::initialize(string settingFile, string videoPath, string videofilename)
{
    m_grab = false;
    this->settingFile_yml = settingFile;
    this->videoPathName = videoPath;
    this->videoFilename = videofilename;
    FileStorage fs;
    fs.open(settingFile_yml, FileStorage::READ);
    if (!fs.isOpened())
    {
        cout << "Could not open the configuration file: \"" << settingFile_yml << endl;
        exit(1);
    }
    string vidpath = videoPathName + "/" + videoFilename + "_Aux.avi";
    rows = (int) fs["rows_ids"];
    cols = (int) fs["cols_ids"];
    size_bin_aux =(int) fs["size_Bin"];
    n_channels = 3;
    size_1_rgb = rows * cols * n_channels;
    no_of_frames = 0;
    timestamp_aux.clear();
    video.open(vidpath.c_str(), CV_FOURCC('F','M','P','4'), 25, Size(cols, rows), true);
    fs.release();
}

void cam_ids_consumer::process()
{
    //Mat img3u = Mat::zeros(rows, cols, CV_8UC3);
    //cout << "Process Consumer started\n";
    m_abort = false;
    std::vector<unsigned char> vec_frame_consume;
    Mat img3u = Mat::zeros(rows, cols, CV_8UC3);
    Mat img3u_disp = Mat::zeros(300, 300, CV_8UC3);
    unsigned char* color = img3u.ptr<unsigned char>(0);
    while(!m_abort)
    {
        //std::vector<unsigned char> vec_frame_consume;

        //cout << "Going to get frame Consumer \n";
        buf_aux::instance()->mutex.lock();
        while (buf_aux::instance()->getEmpty())
        {
            //cout << "Auxillary-> Consumer: queue EMPTY.\n";
            buf_aux::instance()->notEmpty.wait(&buf_aux::instance()->mutex);
        }
        //printf("Aux->C%d\n", buf_aux::instance()->getHead());
        buf_aux::instance()->getBuffer(vec_frame_consume);
        buf_aux::instance()->mutex.unlock();
        buf_aux::instance()->notFull.wakeOne();

        if(!vec_frame_consume.empty())
        {
            for(int i = 0; i < size_bin_aux; i++)
            {
                std::copy (vec_frame_consume.begin() + (i * size_1_rgb), vec_frame_consume.begin() + ((i+1) * size_1_rgb), color);
                //color = reinterpret_cast<unsigned char*>(&vec_frame_consume[i*endoVars.size_1_frame_endo]);
                if (m_grab)
                {
                    video.write(img3u);
                    timestamp_aux.push_back("Aux " + SSTR(++no_of_frames) + " " + currentDateTime() );
                }
            }
        }
        resize(img3u, img3u_disp, img3u_disp.size());
        QImage qimg((uchar*)img3u_disp.data, 300, 300, img3u_disp.step, QImage::Format_RGB888);
        emit sendtoUI_aux(qimg);
        //cout << no_of_frames << endl;
        usleep(10);
    }
    cout << "No of frames produced (Auxillary)-> " << no_of_frames<< endl;
    no_of_frames = 0;
    video.release();
    emit finished();
}
cam_ids_producer::~cam_ids_producer()
{
    if( m_hCam != 0 )
    {
        // Disable messages
        is_EnableMessage( m_hCam, IS_FRAME, NULL );

        // Stop live video
        is_StopLiveVideo( m_hCam, IS_WAIT );

        // Free the allocated buffer
        if( m_pMemBuffer != NULL )
            is_FreeImageMem( m_hCam, m_pMemBuffer, m_nMemID );

        m_pMemBuffer = NULL;

        // Close camera
        is_ExitCamera( m_hCam );
        m_hCam = NULL;
    }
}
const string cam_ids_consumer::currentDateTime()
{
    //time_t     now = time(0);
    //struct tm  tstruct;
    //char       buf[80];
    //tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    //strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    //return buf;

    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer [80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

    char currentTime[84] = "";
    sprintf(currentTime, "%s:%d", buffer, milli);
    return currentTime;
}
