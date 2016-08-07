#include "qmainwindow.h"
#include "ui_qmainwindow.h"
#include <QCameraInfo>

qMainWindow::qMainWindow(/*settings_main &obj, */const params &par, string type, int level, string drName, string camAux,
                         bool RecordOnlineEndo, bool RecordOnlineAux, bool FlipVert, bool FlipHorz,
                         QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qMainWindow),
    /*mSettingMain(&obj),*/
    param(par),
    type(type),
    level(level),
    drName(drName),
    camAux(camAux),
    RecordOnlineEndo(RecordOnlineEndo),
    RecordOnlineAux(RecordOnlineAux),
    mFlipVert(FlipVert),
    mFlipHoriz(FlipHorz)
    {
    ui->setupUi(this);
    // set up the camera and start streaming on the central widget
    mFlipVert=true;
    mFlipHoriz=false;
    switchCam = true;

    if(type == "practice")
    {
        // create auxiliary and endoscopy camera object and stream the endoscopy video
        mProducer_endo = new usbCamRecordDisp_producer();
        mThread_endo_producer = new QThread;
        mProducer_endo->moveToThread(mThread_endo_producer);

        connect(mThread_endo_producer, SIGNAL(started()), mProducer_endo, SLOT(process()));
        connect(mProducer_endo, SIGNAL(finished()), mThread_endo_producer, SLOT(quit()));


        qRegisterMetaType< myMat>("const myMat &");
        connect(mProducer_endo, SIGNAL(sendtoUI(const myMat &)), this, SLOT(updateScreen(const myMat &)), Qt::QueuedConnection);

        bool success = mProducer_endo->initialize(param);
        if(!success)
        {
            ui->statusBar->showMessage("Error initializing endoscopic camera.");
            return;
        }        
        mThread_endo_producer->start();
        ui->statusBar->showMessage("Practice session has started. Follow the Red LED to put the ring. Press exit to return to main menu");
        ui->actionSwitch_Camera->setEnabled(false);
    }
    if(type == "record" || type == "online" )
    {
        // create auxiliary and endoscopy camera object and stream the endoscopy video
        mProducer_endo = new usbCamRecordDisp_producer();
        mConsumer_endo = new usbCamRecordDisp_consumer();
        mProducer_aux  = new auxCamRecord_producer();
        mConsumer_aux  = new auxCamRecord_consumer();


        mThread_endo_producer = new QThread;
        mThread_endo_consumer = new QThread;
        mThread_aux_producer = new QThread;
        mThread_aux_consumer = new QThread;


        mProducer_endo->moveToThread(mThread_endo_producer);
        mConsumer_endo->moveToThread(mThread_endo_consumer);

        mProducer_aux->moveToThread(mThread_aux_producer);
        mConsumer_aux->moveToThread(mThread_aux_consumer);


        connect(mThread_endo_producer, SIGNAL(started()), mProducer_endo, SLOT(process()));
        connect(mProducer_endo, SIGNAL(finished()), mThread_endo_producer, SLOT(quit()));

        connect(mThread_endo_consumer, SIGNAL(started()), mConsumer_endo, SLOT(process()));
        connect(mConsumer_endo, SIGNAL(finished()), mThread_endo_consumer, SLOT(quit()));

        connect(mThread_aux_producer, SIGNAL(started()), mProducer_aux, SLOT(process()));
        connect(mProducer_aux, SIGNAL(finished()), mThread_aux_producer, SLOT(quit()));

        connect(mThread_aux_consumer, SIGNAL(started()), mConsumer_aux, SLOT(process()));
        connect(mConsumer_aux, SIGNAL(finished()), mThread_aux_consumer, SLOT(quit()));


        qRegisterMetaType< myMat>("const myMat &");
        connect(mProducer_endo, SIGNAL(sendtoUI(const myMat &)), this, SLOT(updateScreen_endo(const myMat &)), Qt::QueuedConnection);
        connect(mProducer_aux, SIGNAL(sendtoUI(const myMat &)), this, SLOT(updateScreen_aux(const myMat &)), Qt::QueuedConnection);


        bool success = mProducer_endo->initialize(param);
        if(!success)
        {
            ui->statusBar->showMessage("Error initializing endoscopic camera.");
            return;
        }
        mConsumer_endo->initialize(param, drName);

        string errmsg;
        success = mProducer_aux->initialize(param, errmsg);
        if(!success)
        {
            ui->statusBar->showMessage(QString::fromStdString("Error initializing auxiliary camera ") + QString::fromStdString(errmsg));
            return;
        }
        mConsumer_aux->initialize(param, drName);

        mThread_endo_producer->start();

        if(type == "record" )
        {
            ui->statusBar->showMessage("Press Start to Start the recording; Follow the Red LED to put the ring");
        }
        else if (type == "online" )
        {
            ui->statusBar->showMessage("Press Start to Start your online evaluation. Follow the Red LED to put the ring");
        }

        ui->actionStart_Activity->setEnabled(true);
    }

}

void qMainWindow::updateScreen_endo(const myMat &image)
{
    if(!switchCam)
    {
        if( mFlipVert && mFlipHoriz )
            cv::flip( image,image, -1);
        else if( mFlipVert )
            cv::flip( image,image, 0);
        else if( mFlipHoriz )
            cv::flip( image,image, 1);

        ui->openCVviewer->showImage( image );
    }

}
void qMainWindow::updateScreen_aux(const myMat &image)
{
    if(switchCam)
    {
        if( mFlipVert && mFlipHoriz )
            cv::flip( image,image, -1);
        else if( mFlipVert )
            cv::flip( image,image, 0);
        else if( mFlipHoriz )
            cv::flip( image,image, 1);

        ui->openCVviewer->showImage( image );

    }
}

void qMainWindow::cleanup()
{
    cout << "cleanup mainwindow \n";

    if(type == "practice")
    {
        cout << "cleanup mainwindow(practice) \n";
        if(mThread_endo_producer->isRunning())
            mThread_endo_producer->quit();
        delete mProducer_endo; mProducer_endo = NULL;
    }
    if(type == "record" || type == "online")
    {
        cout << "cleanup mainwindow(record) \n";
        if(mThread_endo_producer->isRunning() )
            mThread_endo_producer->quit();
        if(mProducer_endo != NULL)
        {
            delete mProducer_endo; mProducer_endo = NULL;
        }
        if(mThread_endo_consumer->isRunning())
            mThread_endo_consumer->quit();
        if(mConsumer_endo)
        {
            delete mConsumer_endo; mConsumer_endo = NULL;
        }


        if(mThread_aux_producer->isRunning())
            mThread_aux_producer->quit();
        if(mProducer_aux)
        {
            delete mProducer_aux; mProducer_aux = NULL;
        }


        if(mThread_aux_consumer->isRunning())
            mThread_aux_consumer->quit();
        if(mConsumer_aux != NULL)
        {
            delete mConsumer_aux; mConsumer_aux = NULL;
        }
    }
//   emit ReinitializeSettings_Main();
}

qMainWindow::~qMainWindow()
{
    cleanup();
    delete ui;
}
void qMainWindow::on_actionStart_Activity_triggered()
{



    if(type == "practice")
    {
         ui->statusBar->showMessage("Practice session has started. Follow the Red LED to put the ring. Press exit to return to main menu");
    }
    else if(type == "record" ||  type == "online")
    {
         mThread_endo_consumer->start();
         mThread_aux_producer->start();
         mThread_aux_consumer->start();
         usleep(1000);
         if(type == "record")
         {
             mConsumer_aux->startGrabbing();
             mConsumer_endo->startGrabbing();
             ui->statusBar->showMessage("Press Stop to Stop the recording; Follow the Red LED to put the ring");
         }
         else if(type == "online")
         {
             if(RecordOnlineEndo)
             {
                 mConsumer_endo->startGrabbing();
             }
             if(RecordOnlineAux)
             {
                 mConsumer_aux->startGrabbing();
             }
              ui->statusBar->showMessage("Press Stop to stop your online evaluation. Follow the Red LED to put the ring");
              mProducer_aux->evaluate();
         }
         ui->actionStop_2->setEnabled(true);
         ui->actionStart_Activity->setEnabled(false);
         ui->actionQuit->setEnabled(false);
    }
}


void qMainWindow::on_action_Vertical_Flip_toggled(bool checked)
{
    mFlipVert = checked;
}

void qMainWindow::on_action_Horizontal_Flip_triggered(bool checked)
{
    mFlipHoriz = checked;
}

void qMainWindow::on_actionQuit_triggered()
{
    if(type == "practice")
    {
         ui->statusBar->showMessage("Practice session finished. Exiting to main menu");
    }
    else if(type == "record")
    {
         ui->statusBar->showMessage("Recording done. Exiting to main menu");
    }
    else if(type == "online")
    {
         ui->statusBar->showMessage("Online evaluation done. Exiting to main menu");
    }
    cleanup();
    this->close();
    /*mSettingMain->show();*/
}
void qMainWindow::on_actionStop_2_triggered()
{
    if(type == "practice")
    {
        cout << "action exit in pracrice \n";
        mProducer_endo->abort();
    }
    else if(type == "record")
    {
        cout << "action exit in record \n";
        mProducer_endo->abort();
        mConsumer_endo->abort();
        mProducer_aux->abort();
        mConsumer_aux->abort();
        ui->statusBar->showMessage("Recording finished. Press exit for the main menu");
    }
    else if(type == "online")
    {
        mProducer_endo->abort();
        mConsumer_endo->abort();
        mProducer_aux->abort();
        mConsumer_aux->abort();

        ui->statusBar->showMessage("Online evaluation done. Press exit for the main menu");
    }
    usleep(1000000);
    ui->actionStart_Activity->setEnabled(false);
    ui->actionQuit->setEnabled(true);
}

void qMainWindow::on_actionSwitch_Camera_toggled(bool arg1)
{
    switchCam = arg1;
}
