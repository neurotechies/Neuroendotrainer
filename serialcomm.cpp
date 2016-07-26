#include "serialcomm.h"

serialcomm::serialcomm()
{
    my_serial.setTimeout(serial::Timeout::simpleTimeout(1000));
    my_serial.setPort("/dev/");
    my_serial.setBaudrate(115200);
}

void serialcomm::process()
{
    while(1)
    {
        string readByte = my_serial.read(1);
        cout << readByte << endl;
    }
}
