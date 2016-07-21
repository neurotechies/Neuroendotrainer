#ifndef SETTINGS_MAIN_H
#define SETTINGS_MAIN_H

#include <QDialog>
#include <string>
#include <QImage>
#include <QFileInfo>
#include <fstream>
#include <iterator>
#include <vector>
#include <QtCore>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QTimer>
#include <QCameraInfo>
#include <sys/time.h>
#include <QDebug>
#include <QThread>
#include <QCloseEvent>
#include "testBasler.h"
#include "testIDS.h"
#include "testUSB.h"
#include "qmainwindow.h"
#include "settings.h"
#include "params.h";


using namespace std;
using namespace cv;

namespace Ui {
class settings_main;
}

class settings_main : public QDialog
{
    Q_OBJECT

public:
    explicit settings_main(QWidget *parent = 0);
    ~settings_main();

    void clearUI();
    //virtual void closeEvent(QCloseEvent *event);
private slots:
    void on_tabWidget_tabBarClicked(int index);
    void on_pbPractice_clicked();
    void on_pbOnline_clicked();
    void on_pbOffline_clicked();
    void on_listWidgetEndoOnline_clicked(const QModelIndex &index);
    void on_listWidgetAuxOnline_clicked(const QModelIndex &index);
    void updatelblAux(const QImage &);
    void updatelblEndo(const QImage &);
    void on_pbQuit_clicked();
    void on_listWidgetAuxOffline_clicked(const QModelIndex &index);
    void on_listWidgetEndoOffline_clicked(const QModelIndex &index);
    void on_listWidgetPractice_clicked(const QModelIndex &index);
    void on_pbRefresh_clicked();
    void openSettingsDialog();
    void updateParameters(const params &params);

    bool initialSetup();

private:
    void cleanup();
    Ui::settings_main *ui;
    //QMap<QString, QAction *> cameraStr;
    QMainWindow *mainWindow;
    settings  *mSettings;

    testBasler *mTest_Basler;
    testIDS    *mTest_IDS;
    testUSB    *mTest_USB;
    QThread* thread_endo;
    QThread* thread_aux;

    params parameters;

    int cameraCountEndo;
    int cameraCountAux;
    bool camBaslerFound, camIDSFound, camEndoFound, camAuxFound, endoInitialized, auxInitialized;
    string devAux;
    string errmsg;
    vector<string> devs_endo;

};
#endif
