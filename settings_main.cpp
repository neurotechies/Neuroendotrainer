#include "settings_main.h"
#include "ui_settings_main.h"
#include "Gui.h"

Q_DECLARE_METATYPE(QCameraInfo)

settings_main::settings_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings_main)
{
    ui->setupUi(this);
    clearUI();
    mSettings = new settings();

    connect(ui->pbSettings, SIGNAL(clicked()), this, SLOT(openSettingsDialog()));
    //qRegisterMetaType< myMat>("const myMat &");
    connect(mSettings, SIGNAL(makeUpdateParams(params)), this, SLOT(updateParameters(params)));
    //connect(mainWindow, SIGNAL(ReinitializeSettings_Main()), this, SLOT(initialSetup()));
    initialSetup();

    img3u_disp = Mat::zeros(280, 350, CV_8UC3);
    img3u_disp1 = Mat::zeros(280, 350, CV_8UC3);

    pegGroupROI = Rect(100, 100, 500, 400);

    gui = new Gui;
}

void settings_main::clearUI()
{
    endoInitialized = false;
    auxInitialized = false;
    cameraCountEndo = 0;
    cameraCountAux = 0;
    camBaslerFound = false;
    camIDSFound = false;
    camEndoFound = false;
    camAuxFound = false;
    ui->listWidgetEndoOnline->clear();
    ui->listWidgetAuxOnline->clear();
    ui->listWidgetEndoOffline->clear();
    ui->listWidgetEndoOnline->clear();
    ui->listWidgetPractice->clear();
}

bool settings_main::initialSetup()
{
    // setup for the endoscopy camera
    if(!endoInitialized)
    {
        //cout << "a\n";
        mTest_USB    = new testUSB;
        thread_endo = new QThread;
        cameraCountEndo =mTest_USB->initialize(parameters, devs_endo);
        camEndoFound = cameraCountEndo>0 ? true:false;
    }


    if(camEndoFound && !endoInitialized)
    {
        //cout << "b\n";
        for(int i = 0; i < devs_endo.size(); ++i)
        {
            ui->listWidgetEndoOnline->addItem(QString::fromStdString(devs_endo[i]));
            ui->listWidgetEndoOffline->addItem(QString::fromStdString(devs_endo[i]));
            ui->listWidgetPractice->addItem(QString::fromStdString(devs_endo[i]));
        }

        mTest_USB->moveToThread(thread_endo);
        connect(thread_endo, SIGNAL(started()), mTest_USB, SLOT(process()));
        connect(mTest_USB, SIGNAL(finished()), thread_endo, SLOT(quit()));

        qRegisterMetaType< myMat>("const myMat &");
        connect(mTest_USB, SIGNAL(sendtoUI(const myMat &)), this, SLOT(updatelblEndo(const myMat &)), Qt::QueuedConnection);
        thread_endo->start();
        usleep(10000);
        mTest_USB->m_start = true;
        ui->pbPractice->setEnabled(true);
        endoInitialized = true;
    }
    else
    {
        //cout << "c\n";
        if(!endoInitialized)
        {
            const QString msg = "Endoscopy camera not found. Can't run online evaluation";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            delete mTest_USB; mTest_USB = NULL;
            delete thread_endo; thread_endo = NULL;
            return false;
        }
   }

    // setup for the endoscopy camera

    if(!auxInitialized)
    {
        //cout << "d\n";
        mTest_Basler = new testBasler;
        mTest_IDS    = new testIDS;
        thread_aux  = new QThread;

        // check if any GIGE camera is connected
        camBaslerFound = mTest_Basler->initialize(parameters, errmsg);
        camIDSFound =mTest_IDS->initialize(parameters, errmsg);
        camAuxFound = (camBaslerFound || camIDSFound) ?true:false;
        devAux      = camBaslerFound?"basler":camIDSFound?"ids":"";
        parameters.cap_auxCam = devAux;
    }

    if(camAuxFound && !auxInitialized)
    {
        //cout << "e\n";
        if(camIDSFound)
        {
            cout << "f\n";
            ui->listWidgetAuxOnline->addItem("IDS UI-5240CP-C-HQ");
            ui->listWidgetAuxOffline->addItem("IDS UI-5240CP-C-HQ");
            mTest_IDS->moveToThread(thread_aux);
            connect(thread_aux, SIGNAL(started()), mTest_IDS, SLOT(process()));
            connect(mTest_IDS, SIGNAL(finished()), thread_aux, SLOT(quit()));

            qRegisterMetaType< myMat>("const myMat &");
            connect(mTest_IDS, SIGNAL(sendtoUI(const myMat &)), this, SLOT(updatelblAux(const myMat &)), Qt::QueuedConnection);

            mTest_IDS->m_start = true;
            usleep(10000);
            delete mTest_Basler; mTest_Basler = NULL;
        }
        if(camBaslerFound)
        {
            //cout << "g\n";
            ui->listWidgetAuxOnline->addItem("Basler acA1300-60gc");
            ui->listWidgetAuxOffline->addItem("Basler acA1300-60gc");
            mTest_Basler->moveToThread(thread_aux);
            connect(thread_aux, SIGNAL(started()), mTest_Basler, SLOT(process()));
            connect(mTest_Basler, SIGNAL(finished()), thread_aux, SLOT(quit()));

            qRegisterMetaType< myMat>("const myMat &");
            connect(mTest_Basler, SIGNAL(sendtoUI(const myMat &)), this, SLOT(updatelblAux(const myMat &)), Qt::QueuedConnection);
            mTest_Basler->m_start = true;
            usleep(10000);
            delete mTest_IDS; mTest_IDS = NULL;
        }
        //cout << "h\n";
        thread_aux->start();
        ui->pbOnline->setEnabled(true);
        ui->pbOffline->setEnabled(true);

        auxInitialized = true;
        const QString msg1 = "Ready to go for online evaluation";
        ui->label_status->clear();
        ui->label_status->setText(msg1);
    }
    else
    {
        //cout << "i\n";
        if(!auxInitialized)
        {
            const string msg = "Auxiliary camera not found. Can't run online evaluation";
            ui->label_status->clear();
            ui->label_status->setText(QString::fromStdString(msg));
            delete mTest_IDS; mTest_IDS = NULL;
            delete mTest_Basler; mTest_Basler = NULL;
            delete thread_aux; thread_aux = NULL;
            return false;
        }
    }
    //cout << "j\n";
    return true;
}


void settings_main::updatelblAux(const myMat &lblImg)
{
    cvtColor(lblImg, AuxImg, CV_BGR2RGB);
    cv::resize(lblImg, img3u_disp, img3u_disp.size());
    QImage qimg((uchar*)img3u_disp.data, 350, 280, img3u_disp.step, QImage::Format_RGB888);
    if(thread_aux->isRunning())
    {
        if(ui->tabWidget->currentIndex() == 0)
            ui->label_aux->setPixmap(QPixmap::fromImage(qimg));
        if(ui->tabWidget->currentIndex() == 1)
            ui->label_aux_2->setPixmap(QPixmap::fromImage(qimg));
    }
}

void settings_main::updatelblEndo(const myMat &lblImg)
{
    cvtColor(lblImg, EndoImg, CV_BGR2RGB);
    cv::resize(EndoImg, img3u_disp, img3u_disp.size());
    QImage qimg((uchar*)img3u_disp.data, 350, 280, img3u_disp.step, QImage::Format_RGB888);
    if(thread_endo->isRunning())
    {
        if(ui->tabWidget->currentIndex() == 0)
            ui->label_endo->setPixmap(QPixmap::fromImage(qimg));
        if(ui->tabWidget->currentIndex() == 1)
            ui->label_endo_2->setPixmap(QPixmap::fromImage(qimg));
        if(ui->tabWidget->currentIndex() == 2)
            ui->label_endo_3->setPixmap(QPixmap::fromImage(qimg));
    }
}


void settings_main::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0)
    {
        if(!camEndoFound)
        {
            const QString msg = "Endoscopy camera not found.Can't run online evaluation";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            ui->pbOnline->setEnabled(false);
        }
        else if(!(camAuxFound))
        {
            const QString msg = "Auxiliary camera not found.Can't run offline evaluation";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            ui->pbOnline->setEnabled(false);
        }
        else
        {
            const QString msg = "Ready to go for online evaluation";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            ui->pbOnline->setEnabled(true);
        }
    }
    else if (index == 1)
    {
        if(!camEndoFound)
        {
            const QString msg = "Endoscopy camera not found.Can't record activity";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            ui->pbOffline->setEnabled(false);
        }
        else if(!(camAuxFound))
        {
            const QString msg = "Auxiliary camera not found.Can't record activity";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            ui->pbOffline->setEnabled(false);
        }
        else
        {
            const QString msg = "Press Record for the recording";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            ui->pbOffline->setEnabled(true);
        }
    }
    else if(index == 2)
    {
        if(camEndoFound)
        {
            const QString msg = "Found " + QString::number(cameraCountEndo) + " endoscopic cameras. Ready to go for Practice session";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            ui->pbPractice->setEnabled(true);
        }
        else
        {
            const QString msg = "Endoscopy camera not found. Can't run Practice session";
            ui->label_status->clear();
            ui->label_status->setText(msg);
            ui->pbPractice->setEnabled(false);
        }
    }
}

void settings_main::on_listWidgetEndoOnline_clicked(const QModelIndex &index)
{
    if(camEndoFound)
    {
        mTest_USB->m_start = true;
    }
}

void settings_main::on_listWidgetAuxOnline_clicked(const QModelIndex &index)
{

    if(camAuxFound)
    {
        if(devAux == "basler")
        {
            mTest_Basler->m_start = true;
        }
        else if (devAux == "ids")
        {
            mTest_IDS->m_start = true;
        }
    }
}

void settings_main::on_listWidgetAuxOffline_clicked(const QModelIndex &index)
{
    if(camAuxFound)
    {
        if(devAux == "basler")
        {
            mTest_Basler->m_start = true;
        }
        else if (devAux == "ids")
        {
            mTest_IDS->m_start = true;
        }
    }
}

void settings_main::on_listWidgetEndoOffline_clicked(const QModelIndex &index)
{
    if(camEndoFound)
    {
        mTest_USB->m_start = true;
    }
}

void settings_main::on_listWidgetPractice_clicked(const QModelIndex &index)
{
    if(camEndoFound)
    {
        mTest_USB->m_start = true;
    }
}


void settings_main::on_pbPractice_clicked()
{
    cleanup();
    string DrName = ui->lineEditDrName->text().toUtf8().constData();
    int level = ui->selectLevel->currentIndex();
    //this->setVisible(false);
    clearUI();
    mainWindow = new qMainWindow(parameters, "practice", level, DrName, devAux);
    mainWindow->setWindowTitle("Neuro-Endo-Trainer");
    mainWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    mainWindow->showMaximized();
    mainWindow->show();

}

void settings_main::on_pbOnline_clicked()
{
    cleanup();
    string DrName = ui->lineEditDrName->text().toUtf8().constData();
    int level = ui->selectLevel->currentIndex();
    bool recordEndo = ui->checkBoxRecordEndo->isChecked();
    bool recordAux  = ui->checkBoxRecordAux->isChecked();

    //this->setVisible(false);
    clearUI();
    mainWindow = new qMainWindow(parameters, "online", level, DrName, devAux, recordEndo, recordAux);
    mainWindow->setWindowTitle("Neuro-Endo-Trainer");
    mainWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    mainWindow->showMaximized();
    mainWindow->show();

}

void settings_main::on_pbOffline_clicked()
{
    cleanup();
    string DrName = ui->lineEditDrName->text().toUtf8().constData();
    int level = ui->selectLevel->currentIndex();
    bool recordEndo = ui->checkBoxRecordEndo->isChecked();
    bool recordAux  = ui->checkBoxRecordAux->isChecked();


    //this->setVisible(false);
    clearUI();
    mainWindow = new qMainWindow(parameters, "record", level, DrName, devAux, recordEndo, recordAux);
    mainWindow->setWindowTitle("Neuro-Endo-Trainer");
    mainWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    mainWindow->showMaximized();
    mainWindow->show();

}


void settings_main::cleanup()
{
    cout << "cleanup triggered \n";
    if(camAuxFound)
    {
        if(devAux == "basler")
        {
            cout << "cleaning basler camera \n";
            if(mTest_Basler != NULL)
            {
                mTest_Basler->m_abort = true;
            }
            usleep(100000);
            if(thread_aux->isRunning())
                thread_aux->quit();
            usleep(500000);
            //delete thread_aux;
            if(mTest_Basler != NULL)
            {
                delete mTest_Basler;
                mTest_Basler = NULL;
            }

        }
        else if (devAux == "ids")
        {
            cout << "cleaning ids camera\n";
            if(mTest_IDS != NULL)
            {
                mTest_IDS->m_abort = true;
            }
            usleep(100000);
            if(thread_aux->isRunning())
                thread_aux->quit();
            usleep(500000);
            //delete thread_aux;
            if(mTest_IDS != NULL)
            {
                delete mTest_IDS;
                mTest_IDS = NULL;
            }
        }
    }
    if(camEndoFound)
    {
        cout << "cleaning endo camera\n";
        if(mTest_USB != NULL)
        {
            mTest_USB->m_abort = true;
        }
        usleep(100000);
        if(thread_endo->isRunning())
            thread_endo->quit();
        usleep(500000);
        //delete thread_endo;
        if(mTest_USB != NULL)
        {
            delete mTest_USB;
            mTest_USB = NULL;
        }
    }
}

void settings_main::on_pbQuit_clicked()
{
    QApplication::instance()->exit();
}

settings_main::~settings_main()
{
    // ""
    cout << "Destructor Triggered \n";
    cleanup();
    delete gui;
    delete ui;
}

//void settings_main::closeEvent(QCloseEvent *event)
//{
//    event->ignore();
//}

void settings_main::on_pbRefresh_clicked()
{
    initialSetup();
}


void settings_main::openSettingsDialog()
{
    mSettings->exec();
}

void settings_main::updateParameters(const params &params)
{
    this->parameters = params;
}


void settings_main::on_checkCalib_clicked(bool checked)
{
//    QPalette* palette1 = new QPalette();
//    QPalette* palette2 = new QPalette();
//    palette1->setColor(QPalette::Foreground,Qt::white);
//    palette2->setColor(QPalette::Foreground,Qt::red);
    if(checked)
    {
        mTest_Basler->m_pause = true;
        ui->radioPegSegment->setEnabled(true);
        ui->radioBoundingBox->setEnabled(true);
        //ui->radioPegSegment->setPalette(*palette1);
        //ui->radioPegSegment->setText("Peg Segment?");
        //ui->radioPegSegment->setPalette(*palette1);

        ui->radioRingSegment->setEnabled(true);
        //ui->radioRingSegment->setPalette(*palette1);

        ui->radioToolTipSegment->setEnabled(true);
        //ui->radioToolTipSegment->setPalette(*palette1);

        ui->sliderPegSegment->setEnabled(true);
        ui->sliderRingSegment->setEnabled(true);
    }
    else
    {
        mTest_Basler->m_pause = false;
        ui->radioPegSegment->setEnabled(false);
        //ui->radioPegSegment->setPalette(*palette2);

        ui->radioRingSegment->setEnabled(false);
        //ui->radioRingSegment->setPalette(*palette2);

        ui->radioToolTipSegment->setEnabled(false);
        //ui->radioToolTipSegment->setPalette(*palette2);
        ui->radioBoundingBox->setEnabled(false);

        ui->sliderPegSegment->setEnabled(false);
        ui->sliderRingSegment->setEnabled(false);
    }
}


void settings_main::on_radioPegSegment_clicked(bool checked)
{


}

void settings_main::on_radioRingSegment_clicked(bool checked)
{

}

void settings_main::on_radioToolTipSegment_clicked(bool checked)
{

}


void settings_main::on_checkBox_3_clicked(bool checked)
{
    if(checked)
    {
        ui->pbOnline->setEnabled(true);
    }
    else
    {
        ui->pbOnline->setEnabled(false);
    }
}


void settings_main::on_radioBoundingBox_clicked(bool checked)
{
    // code to get the bounding box of the working area
    qDebug() << "done 1";
    cv::Mat img1;

    cv::resize(AuxImg, img1, Size(750, 600));
    qDebug() << "done 2";
    IplImage* img = cvCreateImage(cvSize(img1.cols,img1.rows),8,3);
    IplImage ipltemp = img1;
    cvCopy(&ipltemp,img);
    qDebug() << "done 3";
    IplImage* im1 = cvCloneImage(img);
    string message = "Press Enter to confirm the bounding box or any other key to redraw the bounding box";
    cvRectangle(im1, pegGroupROI.tl(), pegGroupROI.br(), CV_RGB(255, 0, 0), 3);
    CvFont font1;
    cvInitFont(&font1, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1, 8);
    cvPutText(im1, message.c_str(), cvPoint(0, 60), &font1, cvScalar(255, 255, 0));
    qDebug() << "done 4";
    gui->showImage(im1);
    waitKey(0);
    qDebug() << "done 5";
    char key1 = cin.get();
    qDebug() << static_cast<int>(key1);
    if ((key1 != '\r' || key1 != '\n'))
    {
        CvRect box;
        IplImage* im2 = cvCloneImage(img);
        string message = "Draw a bounding box around the pegs and press enter";
        if (getBBFromUser(im2, box, gui, message) == PROGRAM_EXIT)
        {
            return;
        }
        qDebug() << "done 4";
        pegGroupROI = Rect(box);
        cvReleaseImage(&im2);
    }
    cvReleaseImage(&im1);
}
