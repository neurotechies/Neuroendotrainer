#include "qmainwindow.h"
#include "ui_qmainwindow.h"
#include <QCameraInfo>
#include <QtSerialPort/QSerialPortInfo>

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
    switchCam = false;
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
        connect(mProducer_aux, SIGNAL(sendEvalData(vector<pair<string,QRect> >)), this, SLOT(processEvaluationData(vector<pair<string, pair<double, double> > >)));

        connect(mThread_aux_consumer, SIGNAL(started()), mConsumer_aux, SLOT(process()));
        connect(mConsumer_aux, SIGNAL(finished()), mThread_aux_consumer, SLOT(quit()));


        qRegisterMetaType< myMat>("const myMat &");
        connect(mProducer_endo, SIGNAL(sendtoUI(const myMat &)), this, SLOT(updateScreen(const myMat &)), Qt::QueuedConnection);
        connect(mProducer_aux, SIGNAL(sendtoUI(const myMat &)), this, SLOT(updateScreen(const myMat &)), Qt::QueuedConnection);


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
    // serial port settings and stuff
    serial = new QSerialPort(this);
    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(serial, SIGNAL(readChannelFinished()), this, SLOT(readData()));
    openSerialPort();
    start_serial_logging = false;
}

void qMainWindow::stringToValues(const string &str, pair<int, int> &values, char separator)
{
    string s = str.substr(5, str.size()-5);
    cout << s << endl;
    std::string::size_type index = s.find(separator);
    if(index != string::npos)
    {
        values.first = std::atoi(s.substr(0, index).c_str());
        values.second = std::atoi(s.substr(index+1).c_str());
    }
    else
    {
        values.first = atoi(s.c_str());
    }
}

void qMainWindow::processEvaluationData(const vector<pair<string, pair<double, double> > > &trackingDataWithTime)
{
    if(trackingDataWithTime.size() > 0 && stateAndHittingInfo.size() > 0)
    {
        // Separate the Hitting data from the State Machine Data
        vector<pair<string, string> > Hitting;
        vector<pair<pair<string, int>, string> > State;
        int count = 0;
        for(uint i = 0; i < stateAndHittingInfo.size(); ++i)
        {
            string data = stateAndHittingInfo[i].second;
            string data1 = data.substr(0,3);
            if(data1 == "Ht:")
            {
                Hitting.push_back(stateAndHittingInfo[i]);
            }
            else if(data1 == "St:")
            {
               State.push_back(make_pair(make_pair(stateAndHittingInfo[i].first, ++count), stateAndHittingInfo[i].second));
            }
        }

        string status;
        uint size = State.size();
        bool No_activity_start = false;
        bool picking_activity_start = false;
        bool moving_activity_start = false;
        bool update_startFrameAndType = true;
        Activity objActivity;


        for(uint i = 0; i < size; ++i)
        {
            string p = State[i].second;
            if(p.substr(3,1) == "S")
            {
                status = "stationary";
            }
            else if(p.substr(3,1) == "P")
            {
                status = "picking";
            }
            else if(p.substr(3,1) == "M")
            {
                status = "moving";
            }
            if(status == "stationary")
            {
                if(moving_activity_start)
                {
                    objActivity.m.endTime = State[i-1].first.first;
                    objActivity.m.endIndex = State[i-1].first.second;
                    pair<int, int> values;
                    stringToValues(State[i-1].second, values, ',');
                    objActivity.m.to_peg = values.second;
                    activities.push_back(objActivity);
                    objActivity.clear();
                    moving_activity_start = false;
                    update_startFrameAndType = true;
                }
                if(update_startFrameAndType)
                {
                    objActivity.type = "stationary";
                    objActivity.s.startTime = State[i].first.first;
                    objActivity.s.startIndex = State[i].first.second;
                    update_startFrameAndType = false;
                }
                No_activity_start = true;
            }
            else if(status == "picking")
            {
                if(No_activity_start)
                {
                    objActivity.s.endTime = State[i-1].first.first;
                    objActivity.s.endIndex = State[i-1].first.second;
                    activities.push_back(objActivity);
                    objActivity.clear();
                    No_activity_start = false;
                    update_startFrameAndType = true;
                }
                if(update_startFrameAndType)
                {
                    objActivity.type = "picking";
                    objActivity.p.startTime = State[i].first.first;
                    objActivity.p.startIndex = State[i].first.second;
                    pair<int, int> values;
                    stringToValues(State[i].second, values, ',');
                    objActivity.p.from_peg = values.first;
                    update_startFrameAndType = false;
                }
                picking_activity_start = true;
            }
            else if(status == "moving")
            {
                if(picking_activity_start)
                {
                    objActivity.p.endTime = State[i-1].first.first;
                    objActivity.p.endIndex  = State[i-1].first.second;
                    activities.push_back(objActivity);
                    objActivity.clear();
                    picking_activity_start = false;
                    update_startFrameAndType = true;
                }
                if(No_activity_start)
                {
                    objActivity.s.endTime = State[i-1].first.first;
                    objActivity.s.endIndex = State[i-1].first.second;
                    activities.push_back(objActivity);
                    objActivity.clear();
                    No_activity_start = false;
                    update_startFrameAndType = true;
                }
                if(update_startFrameAndType)
                {
                    objActivity.type = "moving";
                    objActivity.m.startTime = State[i].first.first;
                    objActivity.m.startIndex = State[i].first.second;
                    pair<int, int> values;
                    stringToValues(State[i].second, values, ',');
                    objActivity.m.from_peg = values.first;
                    update_startFrameAndType = false;
                }
                moving_activity_start = true;
            }
        }

        if((int)State.size() > objActivity.s.startIndex)
        {
            objActivity.s.endIndex = State.size();
            objActivity.s.endTime = State[State.size()-1].first.first;
            activities.push_back(objActivity);
            objActivity.clear();
        }

        // Process the tracking and Hitting data and put in the activity
        for(uint p = 0; p < activities.size(); ++p)
        {
            string starttime, endtime;
            timeClass temp;
            if(activities[p].type == "stationary")
            {
                starttime = activities[p].s.startTime;
                endtime  = activities[p].s.endTime;
                pair<int, int> rangeHitting;
                bool resHitting = temp.getRange(Hitting, starttime, endtime, rangeHitting);
                pair<int, int> rangeTracking;
                bool resTracking = temp.getRange(trackingDataWithTime, starttime, endtime, rangeTracking);
                if(resHitting)
                {
                    for(int i =  rangeHitting.first; i <= rangeHitting.second; i++)
                    {
                        string date = Hitting[i].first;
                        string str1= Hitting[i].second;
                        string str = str1.substr(3, str1.size()-3);
                        std::string::size_type index = str.find(',', 0);
                        int n1 = std::atoi(str.substr(0, index).c_str());
                        int n2 = std::atoi(str.substr(index+1).c_str());
                        activities[p].s.hitting.push_back(make_pair(date, make_pair(n1, n2)));
                    }
                }
                if(resTracking)
                {
                    for(int i =  rangeTracking.first; i < rangeTracking.second; i++)
                    {
                        string date = trackingDataWithTime[i].first;
                        pair<double, double> vals = trackingDataWithTime[i].second;
                        activities[p].s.trackingData.push_back(make_pair(date, vals));
                    }
                }
            }
            else if (activities[p].type == "picking")
            {
                starttime = activities[p].p.startTime;
                endtime  = activities[p].p.endTime;
                pair<int, int> rangeHitting;
                bool resHitting = temp.getRange(Hitting, starttime, endtime, rangeHitting);
                pair<int, int> rangeTracking;
                bool resTracking = temp.getRange(trackingDataWithTime, starttime, endtime, rangeTracking);
                if(resHitting)
                {
                    for(int i =  rangeHitting.first; i <= rangeHitting.second; i++)
                    {
                        string date = Hitting[i].first;
                        string str1 = Hitting[i].second;
                        string str = str1.substr(3, str1.size()-3);
                        std::string::size_type index = str.find(',', 0);
                        int n1 = std::atoi(str.substr(0, index).c_str());
                        int n2 = std::atoi(str.substr(index+1).c_str());
                        activities[p].p.hitting.push_back(make_pair(date, make_pair(n1, n2)));
                    }
                }
                if(resTracking)
                {
                    for(int i =  rangeTracking.first; i < rangeTracking.second; i++)
                    {
                        string date = trackingDataWithTime[i].first;
                        pair<double, double> vals = trackingDataWithTime[i].second;
                        activities[p].p.trackingData.push_back(make_pair(date, vals));
                    }
                }
            }
            else if (activities[p].type == "moving")
            {
                starttime = activities[p].m.startTime;
                endtime  = activities[p].m.endTime;
                pair<int, int> rangeHitting;
                bool resHitting = temp.getRange(Hitting, starttime, endtime, rangeHitting);
                pair<int, int> rangeTracking;
                bool resTracking = temp.getRange(trackingDataWithTime, starttime, endtime, rangeTracking);
                if(resHitting)
                {
                    for(int i =  rangeHitting.first; i <= rangeHitting.second; i++)
                    {
                        string date = Hitting[i].first;
                        string str1 = Hitting[i].second;
                        string str = str1.substr(3, str1.size()-3);
                        std::string::size_type index = str.find(',', 0);
                        int n1 = std::atoi(str.substr(0, index).c_str());
                        int n2 = std::atoi(str.substr(index+1).c_str());
                        activities[p].m.hitting.push_back(make_pair(date, make_pair(n1, n2)));
                    }
                }
                if(resTracking)
                {
                    for(int i =  rangeTracking.first; i < rangeTracking.second; i++)
                    {
                        string date = trackingDataWithTime[i].first;
                        pair<double, double> vals = trackingDataWithTime[i].second;
                        activities[p].m.trackingData.push_back(make_pair(date, vals));
                    }
                }
            }
        }
        for(uint i = 0 ; i < activities.size(); ++i)
        {
            activities[i].print();
        }
    }
    else
    {
        qDebug() << "Nothing to process";
    }
}

void qMainWindow::readData()
{
    QByteArray data;
    while (serial->canReadLine())
    {
       data = serial->readLine();   //reads in data line by line, separated by \n or \r characters
       if(start_serial_logging)
       {
           // start logging the hitting data and state info
           qDebug() << "Serial Data -> " << data << endl;
           stateAndHittingInfo.push_back(make_pair(currentDateTime(), data));
       }
    }
}


void qMainWindow::updateScreen(const myMat &image)
{
    if( mFlipVert && mFlipHoriz )
        cv::flip( image,image, -1);
    else if( mFlipVert )
        cv::flip( image,image, 0);
    else if( mFlipHoriz )
        cv::flip( image,image, 1);
    ui->openCVviewer->showImage( image );
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
    closeSerialPort();
    delete serial;
    delete ui;
}
void qMainWindow::on_actionStart_Activity_triggered()
{
    // reset the serial port device
    writeData("z\n");
    usleep(100000);

    // start the training process
    writeData("s\n");
    usleep(100000);
    if(type == "practice")
    {
         ui->statusBar->showMessage("Practice session has started. Follow the Red LED to put the ring. Press exit to return to main menu");
    }
    else if(type == "record" ||  type == "online")
    {
         start_serial_logging = true;
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
    closeSerialPort();
    this->close();
    /*mSettingMain->show();*/
}
void qMainWindow::on_actionStop_2_triggered()
{
    writeData("z\n");
    usleep(100000);
    start_serial_logging = false;
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
        ui->statusBar->showMessage("Activity done. Processing data for the scoring ...");
    }
    usleep(1000000);
    ui->actionStart_Activity->setEnabled(false);
    ui->actionSwitch_Camera->setEnabled(false);
    ui->actionQuit->setEnabled(true);
}

void qMainWindow::on_actionSwitch_Camera_toggled(bool arg1)
{
    //qDebug() << "arg1-> " << arg1;
    mProducer_aux->sendFrame = arg1;
    mProducer_endo->sendFrame = !arg1;
}
void qMainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void qMainWindow::openSerialPort()
{
    serial->setPortName(param.serial_name);
    serial->setBaudRate(param.serial_baudRate);
    serial->setDataBits(param.serial_dataBits);
    serial->setParity(param.serial_parity);
    serial->setStopBits(param.serial_stopBits);
    serial->setFlowControl(param.serial_flowControl);
    if (!serial->open(QIODevice::ReadWrite))
    {
       QMessageBox::critical(this, tr("Error"), serial->errorString());
    }

}

void qMainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
}

void qMainWindow::writeData(const QString str)
{
    QByteArray commandSerial = str.toLocal8Bit();
    serial->write(commandSerial);
    usleep(100000);
}

const string qMainWindow::currentDateTime()
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
