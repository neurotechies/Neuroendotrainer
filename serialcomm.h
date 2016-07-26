#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QThread>
#include <string>
#include <iostream>
#include <cstdio>

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

class serialcomm:public QObject
{
    Q_OBJECT
public:
    serialcomm();
    void process();

};

#endif // SEIALCOMM_H
