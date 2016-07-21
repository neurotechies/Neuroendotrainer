#ifndef CAM_IDS_PRODUCER_CONSUMER_H
#define CAM_IDS_PRODUCER_CONSUMER_H

/*
 * Producer consumer class for the IDS Camera
 *
*/
#include <QThread>
#include <QImage>
#include "buf_aux.h"
#include <QTime>
#include <stdio.h>
#include <QtCore>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <stdexcept>
#include <sys/time.h>
#include <sstream>
#include "/usr/include/ueye.h"

using namespace std;
using namespace cv;
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
    ( std::ostringstream() << std::dec << x ) ).str()
/*
 * Producer class for the IDS Camera
 *
*/
class cam_ids_producer : public QObject
{
    Q_OBJECT
public:
    //ctor
    cam_ids_producer();

    // bool to break the event loop
    bool m_abort;

    // Initialize the private members after set button press
    bool initialize(const string &settingFile, string &errmsg);

    // dtor
    ~cam_ids_producer();
    //virtual ~cam_ids_producer() {}
signals:
    void finished();

public slots:
     // Event loop function
     void process();
private:
     char *m_pMemBuffer;
     int   m_nMemID;
     HIDS  m_hCam;
     SENSORINFO m_SensorInfo;
     int camid;

     // member vars for capturing
     uint rows;                      // No of rows
     uint cols;                      // No of cols
     uint size_bin_aux;              // bin size
     uint size_1_rgb;                // size of rgb frame (rows*cols*3)
     uint size_1_yuv;                // size of yuv frame (rows*cols*2)
     uint n_channels;                // 3
     string settingFile_yml;         // settings file to set the parameters
};

/*
 * Consumer thread for the Auxillary Camera
 *
*/
class cam_ids_consumer : public QObject
{
    Q_OBJECT
public:
    // Ctor
    cam_ids_consumer();

    // bool to break the event loop
    bool m_abort;

    //bool to start the capturing
    bool m_grab;

     // Initialize the private members after set button press
    void initialize(string settingFile, string videoPath, string videofilename);

    //dtor
    ~cam_ids_consumer(){}
    //virtual ~cam_ids_consumer() {}
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
#endif // CAM_IDS_PRODUCER_H
