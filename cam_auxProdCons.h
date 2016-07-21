#ifndef CAM_AUXPRODCONS_H
#define CAM_AUXPRODCONS_H
/*
 * Producer consumer thread for the Auxillary Camera
 *
*/
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

using namespace std;
using namespace Pylon;
using namespace Basler_GigECameraParams;
using namespace cv;
typedef Pylon::CBaslerGigEInstantCamera Camera_t;

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
    ( std::ostringstream() << std::dec << x ) ).str()

/*
 * Producer thread for the Auxillary Camera
 *
*/
class cam_aux_producer: public QObject
{
    Q_OBJECT
public:
    // Ctor
    cam_aux_producer();

    // bool to break the event loop
    bool m_abort;


    // Initialize the private members after set button press
    bool initialize(const string &settingFile, string &errmsg);

    // dtor
    ~cam_aux_producer(){camera.Close();}
    //virtual ~cam_aux_producer() {camera.Close();}
signals:
     void finished();
     //void error(QString err);

public slots:
     // Event loop function
     void process();

private:
    CDeviceInfo info;               // Device info to create camera
    CGrabResultPtr ptrGrabResult;   // Grabber pointer from camera
    Camera_t camera;                // camera object
    uint c_countOfImagesToGrab;     // maximum number of frames to capture
    uint divider;
    uint rows;                      // No of rows
    uint cols;                      // No of cols
    uint size_bin_aux;              // bin size
    uint frame_rate;                // fps
    uint size_1_rgb;                // size of rgb frame (rows*cols*3)
    uint size_1_yuv;                // size of yuv frame (rows*cols*2)
    uint n_channels;                // 3
    string settingFile_yml;         // settings file to set the parameters
};


/*
 * Consumer thread for the Auxillary Camera
 *
*/
class cam_aux_consumer : public QObject
{
    Q_OBJECT
public:
    // Ctor
    cam_aux_consumer();

    // bool to break the event loop
    bool m_abort;

    //bool to start the duming the frame
    bool m_grab;

     // Initialize the private members after set button press
    void initialize(string settingFile, string videoPath, string videofilename);

    //dtor
    ~cam_aux_consumer(){}
    //virtual ~cam_aux_consumer() {}

    //timestamp
    vector<string> timestamp_aux;

signals:
    // send the 300x300 to UI -> in producer because producer is fast as compare to
    // consumer so extra computation can be done in producer
    void sendtoUI_aux(const QImage &);

    void finished();
    //void error(QString err);

public slots:
     // Event loop function
     void process();

private:
    const string currentDateTime();

    uint divider;
    uint rows;                 // No of rows
    uint cols;                 // No of cols
    uint n_channels;           // 3
    uint size_1_rgb;           // size of rgb frame (rows*cols*3)
    uint size_bin_aux;         // Bin Size
    int no_of_frames;          // count no of frames captured.
    cv::VideoWriter video;     // opencv videowriter object
    string videoPathName;      // capture scratch path
    string videoFilename;      // video file name
    string settingFile_yml;    // settings file to set the parameters

};
#endif // CAM_AUXPRODCONS_H
