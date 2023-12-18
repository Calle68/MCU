#ifndef IBN_h
#define IBN_h

#include <Arduino.h>

class IBN
{
private:
    unsigned long previousMillis = 0;
    unsigned long currentMillis = 0;
public:
    void laufZeit();
};

#endif