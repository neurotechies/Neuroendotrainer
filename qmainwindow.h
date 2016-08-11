#ifndef QMAINWINDOW_H
#define QMAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QThread>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include "usbcamrecorddisp.h"
#include "auxCamRecord.h"
#include <string>
#include <QImage>
#include <QFileInfo>
#include <fstream>
#include <iterator>
#include <vector>
#include "params.h"
#include "settings_main.h"
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include "Scorer.h"

using namespace std;

namespace Ui {
class qMainWindow;
}

typedef cv::Mat myMat;

class qMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit qMainWindow(/*settings_main &p, */const params &par, string type, int level, string drName, string camAux,
                         bool RecordOnlineEndo = false, bool RecordOnlineAux = false,
                         bool FlipVert = false, bool FlipHorz = false,
                         QWidget *parent = 0);
    ~qMainWindow();

private slots:
    void on_actionStart_Activity_triggered();

    void on_action_Vertical_Flip_toggled(bool arg1);

    void on_action_Horizontal_Flip_triggered(bool checked);

    void updateScreen(const myMat &);

    void on_actionQuit_triggered();

    void on_actionStop_2_triggered();

    void on_actionSwitch_Camera_toggled(bool arg1);

    void readData();

    void handleError(QSerialPort::SerialPortError error);

    void processEvaluationData(const vector<pair<string, pair<double, double> > > &);


signals:
//    void ReinitializeSettings_Main();

private:

    void cleanup();
    void openSerialPort();
    void closeSerialPort();
    void writeData(const QString str);
    const string currentDateTime();

    Ui::qMainWindow *ui;
    bool mFlipVert;
    bool mFlipHoriz;
    params param;

    /*settings_main *mSettingMain;*/

    QThread* mThread_endo_producer;
    QThread* mThread_endo_consumer;

    QThread* mThread_aux_producer;
    QThread* mThread_aux_consumer;

    QThread* mThread_serialComm;

    usbCamRecordDisp_producer* mProducer_endo;
    usbCamRecordDisp_consumer* mConsumer_endo;

    auxCamRecord_producer* mProducer_aux;
    auxCamRecord_consumer* mConsumer_aux;
    string type;
    int level;
    string drName;
    string camAux;
    bool RecordOnlineEndo;
    bool RecordOnlineAux;
    bool switchCam;
    bool start_serial_logging;
    QSerialPort *serial;

    vector<pair<string, string> > stateAndHittingInfo;
    vector<Activity> activities;

protected:
    //void timerEvent(QTimerEvent *event);
};

#endif // QMAINWINDOW_H
