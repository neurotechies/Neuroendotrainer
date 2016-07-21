#include "cam_auxProdCons.h"

cam_aux_producer::cam_aux_producer()
{
}

bool cam_aux_producer::initialize(const string &settingFile, string &errmsg)
{
    //cout << "Initialization Producer \n";
    buf_aux::instance();
    //cout << "Buffer Size => " << buf_aux::instance()->getBufSize() << endl;
    FileStorage fs;
    this->settingFile_yml = settingFile;
    fs.open(settingFile_yml, FileStorage::READ);
    if (!fs.isOpened())
    {
        cout << "Could not open the configuration file: \"" << settingFile_yml << endl;
        exit(1);
    }
    c_countOfImagesToGrab = (int) fs["countOfImagesToGrab"]; //180000;
    rows = (int) fs["rows_Basler"]; // 1024 / divider;
    cols = (int) fs["cols_Basler"]; // 1280 / divider;
    frame_rate = (int) fs["frame_rate_basler"]; //25;
    size_bin_aux =(int) fs["size_Bin"];
    n_channels = 3;
    size_1_rgb = rows * cols * n_channels;
    size_1_yuv = rows * cols * 2;

    //Pylon::PylonAutoInitTerm autoInitTerm;
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
            camera.MaxNumBuffer = (int) fs["max_num_buffer_basler"]; //25;
            camera.StartGrabbing(c_countOfImagesToGrab);
            fs.release();
        }
        errmsg = "Using device " + camera.GetDeviceInfo().GetModelName();
        return true;
    }
    catch (GenICam::GenericException &e)
    {
        // Error handling.
        errmsg = e.GetDescription();
        fs.release();
        return false;
    }
}

cam_aux_consumer::cam_aux_consumer()
{
    m_grab = false;
}

void cam_aux_consumer::initialize(string settingFile, string videoPath, string videofilename)
{
    //cout << "Initialization Consumer \n";
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
    rows = (int) fs["rows_Basler"];
    cols = (int) fs["cols_Basler"];
    size_bin_aux =(int) fs["size_Bin"];
    n_channels = 3;
    size_1_rgb = rows * cols * n_channels;
    no_of_frames = 0;
    video.open(vidpath.c_str(), CV_FOURCC('F','M','P','4'), 25, Size(cols, rows), true);
    timestamp_aux.clear();
    fs.release();
}

void cam_aux_producer::process()
{
    std::vector<unsigned char> temp_rgb(size_1_rgb);
    std::vector<unsigned char> vec_frame_ax_rgb(size_1_rgb*size_bin_aux);

    m_abort = false;
    while(!m_abort)
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
                    temp_rgb[p] = b1; temp_rgb[p + 1] = g1; temp_rgb[p + 2] = r1;
                    temp_rgb[p + 3] = b2; temp_rgb[p + 4] = g2; temp_rgb[p + 5] = r2;
                }
                //cout << "conversion complete\n";
                std::copy ( temp_rgb.begin(), temp_rgb.begin() + (size_1_rgb), vec_frame_ax_rgb.begin() + ((i) * (size_1_rgb)));
            }
            else
            {
                cout << "Auxillary Camera->Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
                exit(1);
            }
            //cout << "Putting data in temp rgb\n";
        }

        //cout << "Going to dump frame Producer \n";
        // Lock the Buffer, and put frame in buffer
        //cout << "Going to lock\n";
        buf_aux::instance()->mutex.lock();
        while(buf_aux::instance()->getFull())
        {
            //cout<<"Auxilary->Producer Full \n";
            buf_aux::instance()->notFull.wait(&buf_aux::instance()->mutex);
        }
        //printf("Aux->P%d\n", buf_aux::instance()->getTail());
        buf_aux::instance()->setBuffer(vec_frame_ax_rgb);
        buf_aux::instance()->mutex.unlock();
        buf_aux::instance()->notEmpty.wakeOne();
        usleep(10);
    }
    cout << "Out Auxillary Producer \n";
    if(camera.IsOpen())
        camera.Close();
    emit finished();
}

void cam_aux_consumer::process()
{
    //Mat img3u = Mat::zeros(rows, cols, CV_8UC3);
    //cout << "Process Consumer started\n";
    m_abort = false;
    std::vector<unsigned char> vec_frame_consume;
    Mat img3u = Mat::zeros(rows, cols, CV_8UC3);
    Mat img3u_disp = Mat::zeros(300, 300, CV_8UC3);
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
                unsigned char* color = img3u.ptr<unsigned char>(0);
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
const string cam_aux_consumer::currentDateTime()
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
