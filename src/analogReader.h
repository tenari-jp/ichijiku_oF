#include "ofMain.h"
#include <wiringPi.h>
#include <wiringPiSPI.h>

class analogReader{
public:
    void setup()
    {
        cout << "SPI setup...";
        if (wiringPiSPISetup(0, 10000) < 0)
        {
            cout << "ERROR!";
        }
        cout << "Done." << endl;

        wiringPiSetupGpio();
        pinMode(14, OUTPUT);
        
    }

    int update()
    {
        int ret = 0;
        unsigned char dat[2] = {0x68, 0x0};
        
        digitalWrite(14, LOW);
       	usleep(1000);
        
        ret = wiringPiSPIDataRW(0, dat, 2);
        
        usleep(1000);
        digitalWrite(14, HIGH);
        
        ret = dat[0] << 8 | dat[1];
        return ret;
    }    
};