#include <Arduino.h>
#include <analogWrite.h>
#include "leds.h"

leds::leds(int pin)
{
    pinLED = pin;
    pinMode(pinLED, OUTPUT);
}

void leds::turnOn()
{
    digitalWrite(pinLED, HIGH);
}

void leds::turnOff(bool analogOff)
{
    if (analogOff)
    {
        analogWrite(pinLED, 0);
    }
    else
    {
        digitalWrite(pinLED, LOW);
    }
}

void leds::toggle()
{
    digitalWrite(pinLED, !digitalRead(pinLED));
}

void leds::turnOffAfterDelay(int millisec, bool analogOff)
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMilliAusschalten <= (millisec))
    {
        // kein zurücksetzen von previosmillis
        // Dieser Abschnitt soll nur 1x pro Aufruf ausgeführt werden

        // man könnte mit dieser Funktion auch die LED einschalten
        // digitalWrite(pinLED, HIGH);
    }
    else
    {
        turnOff(analogOff);
    }
}

void leds::fadeOn(int millisec)
{
        unsigned long currentMillis = millis();

        if (currentMillis - previousMillisFadeOn <= (millisec))
        {
            Serial.print("Laufzeit 1 in ms: "); Serial.println(currentMillis);
            previousMillisFadeOn = currentMillis;
            if (brightness <= 255)
            {
                Serial.print("Laufzeit in ms: "); Serial.println(currentMillis);
                Serial.print("Fade On: "); Serial.println(previousMillisFadeOn);
                Serial.print("Subtraktion: "); Serial.println(currentMillis - previousMillisFadeOn);
                Serial.print("Analogwert"); Serial.println(brightness);
                analogWrite(pinLED, brightness);
                brightness += fadeAmount;
            }
        }
        
}

void leds::pulsate(int delay_ms)
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillisPulsate <= (delay_ms))
    {
        previousMillisPulsate = currentMillis;
        brightness += fadeAmount;
        if(brightness == 0 || brightness == 255)
        {
            // vorzeichen ändern
            fadeAmount = -fadeAmount;
        }
        analogWrite(pinLED, brightness);
    }
}