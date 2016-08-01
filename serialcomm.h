#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QThread>
#include <QtCore>
#include <string>
#include <iostream>
#include <cstdio>
#include <time.h>
#include <sys/time.h>
#include <vector>
#include <utility>
// OS Specific sleep
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "serial/serial.h"

using std::string;
using std::exception;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using namespace std;

class serialcomm:public QObject
{
    Q_OBJECT
public:
    serialcomm();
    void process();
    void quit();
    const string currentDateTime();
    vector<pair< string, string> > stateinfo;
private:
    bool stop;
    serial::Serial my_serial;
};

#endif // SEIALCOMM_H
