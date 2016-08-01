#include "serialcomm.h"

serialcomm::serialcomm()
{
    //my_serial.setTimeout(serial::Timeout::simpleTimeout(1000));
    my_serial.setPort("/dev/");
    my_serial.setBaudrate(115200);
    stop = false;
}

void serialcomm::process()
{
    while(!stop)
    {
        string readByte = my_serial.read(1);
        cout << readByte << endl;
        if(readByte == "S" || readByte == "M")
        {
            stateinfo.push_back(make_pair(currentDateTime(), readByte));
        }
    }
    // sent stateinfo datastructure for the processing
}
void serialcomm::quit()
{
    stop = true;
}
const string serialcomm::currentDateTime()
{
    //time_t     now = time(0);
    //struct tm  tstruct;
    //char       buf[80];
    //tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    //strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    //return buf;

    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer [80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

    char currentTime[84] = "";
    sprintf(currentTime, "%s:%d", buffer, milli);
    return currentTime;
}
