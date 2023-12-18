#ifndef leds_h
#define leds_h

#include <Arduino.h>

class leds{
    //kein AnalogWrite und diditalWrite mischen
    private:
        int pinLED;
        int brightness=0;
        int fadeAmount=1;
        bool pusateMode=true;
        unsigned long previousMillis = 0;
        unsigned long previousMilliAusschalten = 0;
        unsigned long previousMillisPulsate = 0;
        unsigned long previousMillisFadeOn = 0;
        unsigned long previousMillisFadeOFF = 0;

    public:
        leds(int pin);
        void turnOn();
        void turnOff(bool analogOff);
        void fadeOn(int millisec);
        void toggle();
        void flash(int delay_ms);
        void turnOffAfterDelay(int millisec, bool analogOff);
        void pulsate(int delay_ms);
        void setPulsateMode(bool val);
};

#endif