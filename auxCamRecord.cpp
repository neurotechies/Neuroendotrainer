#include "auxCamRecord.h"

auxCamRecord_producer::auxCamRecord_producer()
{
}
auxCamRecord_producer::~auxCamRecord_producer()
{
    if(deviceName == "basler")
    {
        if(camera.IsOpen())
            camera.Close();
    }
}

const string auxCamRecord_producer::currentDateTime()
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

bool auxCamRecord_producer::initialize(const params &par, string &errmsg)
{
    // instantiate the buffer class;
    parameters = par;
    buf_aux::instance(par);
    rows = par.cap_rowsAux;
    cols = par.cap_colsAux;
    frame_rate = par.cap_fpsAux;
    size_bin_aux = par.cap_binSize;
    camid =par.cap_camID_IDS;
    deviceName = par.cap_auxCam;
    n_channels = 3;
    size_1_rgb = rows * cols * n_channels;
    size_1_yuv = rows * cols * 2;
    m_abort = false;
    c_countOfImagesToGrab = 1800000;
    if(deviceName == "basler")
    {
        try
        {
            if(!camera.IsOpen())
            {
                info.SetDeviceClass(Camera_t::DeviceClass());
                camera.Attach(CTlFactory::GetInstance().CreateFirstDevice(info));
                camera.Open();
                camera.PixelFormat.SetValue(PixelFormat_YUV422Packed);
                camera.Width.SetValue(cols);
                camera.Height.SetValue(rows);
                camera.AcquisitionFrameRateAbs.SetValue(frame_rate);
                //cout << "Using device " << camera.GetDeviceInfo().GetModelName() << endl;
                camera.MaxNumBuffer = 25;//(int) fs["max_num_buffer_basler"]; //25;
                camera.StartGrabbing(c_countOfImagesToGrab);
            }
            errmsg = "Using device " + camera.GetDeviceInfo().GetModelName();
            return true;
        }
        catch (GenICam::GenericException &e)
        {
            // Error handling.
            errmsg = e.GetDescription();
            return false;
        }
    }
    else if (deviceName == "ids")
    {
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
            nRet = is_AllocImageMem(m_hCam, m_SensorInfo.nMaxWidth, m_SensorInfo.nMaxHeight, 24,
                                    &m_pMemBuffer, &m_nMemID);
            nRet = is_SetImageMem(m_hCam, m_pMemBuffer, m_nMemID);

            // Set the BGR8 capturing mode
            nRet = is_SetColorMode(m_hCam, IS_CM_BGR8_PACKED);

             // to do the top-left and top-bottom mirror
            //is_SetRopEffect (m_hCam, IS_SET_ROP_MIRROR_UPDOWN, true, 0);
            //is_SetRopEffect (m_hCam, IS_SET_ROP_MIRROR_LEFTRIGHT, true, 0);

            cout<< "Memory Allocation Done \n";
            is_CaptureVideo(m_hCam, IS_DONT_WAIT);
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
            //fs.release();
            return false;
        }
    }
    return true;
}

void auxCamRecord_producer::evaluate()
{
    m_eval = true;
}

void auxCamRecord_producer::abort()
{
    m_abort = true;
}
void auxCamRecord_producer::processFrame(const cv::Mat &current_frame)
{
    // process the current frame; Entry point for the online evaluation for the auxiliary camera.
    if(m_eval)
    {

    }
}

void auxCamRecord_producer::process()
{
    //std::vector<unsigned char> temp_rgb(size_1_rgb);
    std::vector<Mat> vec_frame_ax_rgb(size_bin_aux);
    Mat img3u = Mat::zeros(rows, cols, CV_8UC3);
    unsigned char* color = img3u.ptr<unsigned char>(0);

    char *lastBuffer;
    INT nRet;
    while(!m_abort)
    {
        if(deviceName == "basler")
        {
            if(!camera.IsGrabbing()) break;
            //cout << "Grabbing Start Producer\n";
            for (uint i = 0 ; i < size_bin_aux; ++i)
            {
                //cout << "Going to trigger camera\n";
                camera.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);
                if(ptrGrabResult->GrabSucceeded())
                {
                    //cout << "Grab succeed\n";
                    const uchar *pImageBuffer = (uchar *)ptrGrabResult->GetBuffer();
                    // conversion from yuv to rgb;
                    for(unsigned int k = 0, p = 0; k < size_1_yuv; k = k + 4, p = p + 6)
                    {
                        int zero = 0; int max_1 = 255;
                        float Cr = static_cast<float>(static_cast<unsigned int>(pImageBuffer[k]));
                        float Y0 = static_cast<float>(static_cast<unsigned int>(pImageBuffer[k + 1]));
                        float Cb = static_cast<float>(static_cast<unsigned int>(pImageBuffer[k + 2]));
                        float Y1 = static_cast<float>(static_cast<unsigned int>(pImageBuffer[k + 3]));
                        uint8_t r1 = (uint8_t)max(zero, min(max_1, static_cast<int>((Y0)+1.403f*(Cb - 128))));
                        uint8_t g1 = (uint8_t)max(zero, min(max_1, static_cast<int>((Y0)-0.344f*(Cr - 128) - 0.714f*(Cb - 128))));
                        uint8_t b1 = (uint8_t)max(zero, min(max_1, static_cast<int>((Y0)+1.773f*(Cr - 128))));
                        uint8_t r2 = (uint8_t)max(zero, min(max_1, static_cast<int>((Y1)+1.403f*(Cb - 128))));
                        uint8_t g2 = (uint8_t)max(zero, min(max_1, static_cast<int>((Y1)-0.344f*(Cr - 128) - 0.714f*(Cb - 128))));
                        uint8_t b2 = (uint8_t)max(zero, min(max_1, static_cast<int>((Y1)+1.773f*(Cr - 128))));
                        //temp_rgb[p] = b1; temp_rgb[p + 1] = g1; temp_rgb[p + 2] = r1;
                        //temp_rgb[p + 3] = b2; temp_rgb[p + 4] = g2; temp_rgb[p + 5] = r2;
                        color[p] = b1; color[p + 1] = g1; color[p + 2] = r1;
                        color[p + 3] = b2; color[p + 4] = g2; color[p + 5] = r2;
                    }
                    //cout << "conversion complete\n";
                    //std::copy ( temp_rgb.begin(), temp_rgb.begin() + (size_1_rgb), vec_frame_ax_rgb.begin() + ((i) * (size_1_rgb)));
                    vec_frame_ax_rgb[i] = img3u;
                    processFrame(img3u);
                }
                else
                {
                    cout << "Auxillary Camera->Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
                    exit(1);
                }
                //cout << "Putting data in temp rgb\n";
            }
        }
        else if(deviceName == "ids")
        {
            if(m_hCam == 0) break;
            for(uint i = 0; i < size_bin_aux; ++i)
            {
                nRet = is_GetActSeqBuf(m_hCam, 0, 0, &lastBuffer);
                if (nRet == IS_SUCCESS)
                {
                    //std::copy ( lastBuffer, lastBuffer + (size_1_rgb), vec_frame_ax_rgb.begin() + ((i) * (size_1_rgb)));
                }
                else
                {
                    cout << "Getting the frame error ... exiting \n";
                    exit(1);
                }
            }
        }
        // Lock the Buffer, and put frame in buffer
        //cout << "Going to lock\n";
        buf_aux::instance(parameters)->mutex.lock();
        while(buf_aux::instance(parameters)->getFull())
        {
            //cout<<"Auxilary->Producer Full \n";
            buf_aux::instance(parameters)->notFull.wait(&buf_aux::instance(parameters)->mutex);
        }
        //printf("Aux->P%d\n", buf_aux::instance()->getTail());
        buf_aux::instance(parameters)->setBuffer(vec_frame_ax_rgb);
        buf_aux::instance(parameters)->mutex.unlock();
        buf_aux::instance(parameters)->notEmpty.wakeOne();
        usleep(10);
    }
    cout << "Out of Auxillary Producer\n";
    if(deviceName == "basler")
    {
        if(camera.IsOpen())
            camera.Close();
    }
    else if(deviceName == "ids")
    {
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
    }

    emit finished();
}


// consumer functuions
auxCamRecord_consumer::auxCamRecord_consumer()
{
}

auxCamRecord_consumer::~auxCamRecord_consumer()
{

}

void auxCamRecord_consumer::initialize(const params &par, const string &drName)
{
    parameters = par;
    if(par.cap_paths.size())
    {
        capturePath = par.cap_paths[0];
    }

    rows = par.cap_rowsAux;
    cols = par.cap_colsAux;
    size_bin_aux = par.cap_binSize;
    n_channels = 3;
    size_1_rgb = rows * cols * n_channels;
    no_of_frames = 0;
    timestamp_aux.clear();
    startdumping = false;
    m_grab = false;
    m_abort = false;

    videoFullpath = capturePath + "/" + drName + "_" + currentDateTime()+ "_aux.avi";
}

void auxCamRecord_consumer::abort()
{
    m_abort = true;
}

void auxCamRecord_consumer::startGrabbing()
{
    m_grab = true;
}

const string auxCamRecord_consumer::currentDateTime()
{
    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer [80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

    char currentTime[84] = "";
    sprintf(currentTime, "%s:%d", buffer, milli);
    return currentTime;
}

const string auxCamRecord_consumer::num2str(int num)
{
    string str;
    str = dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << num ) ).str();
    return str;
}

void auxCamRecord_consumer::process()
{
    while(!m_abort)
    {
        std::vector<Mat> vec_frame_consume;
        buf_aux::instance(parameters)->mutex.lock();
        while (buf_aux::instance(parameters)->getEmpty())
        {
            //cout << "Endoscopy-> Consumer: queue EMPTY.\n";
            buf_aux::instance(parameters)->notEmpty.wait(&buf_aux::instance(parameters)->mutex);
        }
        //printf("Endo->C%d\n", buf_endo::instance()->getHead());
        buf_aux::instance(parameters)->getBuffer(vec_frame_consume);
        buf_aux::instance(parameters)->mutex.unlock();
        buf_aux::instance(parameters)->notFull.wakeOne();
        if(!vec_frame_consume.empty())
        {
            for(int i = 0; i < size_bin_aux; i++)
            {
                if (m_grab)
                {
                    if(!startdumping)
                    {
                        cout << "started dumping aux\n";
                        cout << "capture path aux-> " << videoFullpath << endl;
                        videoWriter.open(videoFullpath.c_str(), CV_FOURCC('F','M','P','4'), 25, Size(cols, rows), true);
                        startdumping = true;
                    }
                    videoWriter.write(vec_frame_consume[i]);
                    timestamp_aux.push_back("Aux " + num2str(++no_of_frames) + " " + currentDateTime() );
                    usleep(10);
                }
            }
        }
        else
        {
            cout << "vector is empty \n";
        }
    }
    cout << "No of frames produced (Auxiliary)-> " << no_of_frames<< endl;
    no_of_frames = 0;
    videoWriter.release();
    emit finished();
}
