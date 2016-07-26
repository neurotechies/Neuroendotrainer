#ifndef AUXCAMRECORD_H
#define AUXCAMRECORD_H

#include <QThread>
#include <QImage>
#include "buf_aux.h"
#include <QTime>
#include <stdio.h>
#include <QtCore>
#include <pylon/PylonIncludes.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <sys/time.h>
#include <stdexcept>
#include "/usr/include/ueye.h"
#include "params.h"

using namespace std;
using namespace Pylon;
using namespace Basler_GigECameraParams;
using namespace cv;
typedef Pylon::CBaslerGigEInstantCamera Camera_t;


class auxCamRecord_producer:public QObject
{
    Q_OBJECT
public:
    auxCamRecord_producer();

    // Initialize the private members after set button press
    bool initialize(const params &par, string &errmsg);
    void evaluate();
    void abort();
    void processFrame(const cv::Mat &current_frame);


    // dtor
    ~auxCamRecord_producer();


signals:
     void finished();

public slots:
     // Event loop function
     void process();

private:
    //pylon specific
    CDeviceInfo info;               // Device info to create camera
    CGrabResultPtr ptrGrabResult;   // Grabber pointer from camera
    Camera_t camera;                // camera object
    uint c_countOfImagesToGrab;     // maximum number of frames to capture

    // ids specific
    char *m_pMemBuffer;
    int   m_nMemID;
    HIDS  m_hCam;
    SENSORINFO m_SensorInfo;
    int camid;
    params parameters;

    // bools to control flow
    bool m_abort;
    bool m_eval;

    string deviceName;
    uint divider;
    uint rows;                      // No of rows
    uint cols;                      // No of cols
    uint size_bin_aux;              // bin size
    uint frame_rate;                // fps
    uint size_1_rgb;                // size of rgb frame (rows*cols*3)
    uint size_1_yuv;                // size of yuv frame (rows*cols*2)
    uint n_channels;                // 3

};


class auxCamRecord_consumer:public QObject
{
    Q_OBJECT
public:
    auxCamRecord_consumer();

    // Initialize the private members after set button press
    void initialize(const params &par, const string &drName);
    void abort();
    void startGrabbing();
    // dtor
    ~auxCamRecord_consumer();


    //timestamp
    vector<string> timestamp_aux;

signals:2
     void finished();

public slots:
     // Event loop function
     void process();

private:
     const string currentDateTime();
     const string num2str(int num);
     params parameters;

     bool m_abort;
     //bool to start the duming the frame
     bool m_grab;


     uint divider;
     uint rows;                 // No of rows
     uint cols;                 // No of cols
     uint n_channels;           // 3
     uint size_1_rgb;           // size of rgb frame (rows*cols*3)
     uint size_bin_aux;         // Bin Size
     int no_of_frames;          // count no of frames captured.
     cv::VideoWriter videoWriter;     // opencv videowriter object
     string capturePath;
     string videoFullpath;      // capture scratch path
     bool startdumping;
};

#endif // AUXCAMRECORD_H
