#include <Arduino.h>
#include "IBN.h"

void IBN::laufZeit()
{
    currentMillis = millis();
    if (currentMillis - previousMillis >= 1000)
    {
        Serial.print("Aktuelle Laufzeit in Sec.: ");
        Serial.println(currentMillis / 1000);
        previousMillis = currentMillis;
    }
};