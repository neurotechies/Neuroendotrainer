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
#include "serialcomm.h"

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

signals:
//    void ReinitializeSettings_Main();

private:

    void cleanup();

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

    serialcomm *mSerial;

    string type;
    int level;
    string drName;
    string camAux;
    bool RecordOnlineEndo;
    bool RecordOnlineAux;


protected:
    //void timerEvent(QTimerEvent *event);
};

#endif // QMAINWINDOW_H
