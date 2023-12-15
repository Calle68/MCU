#include <Arduino.h>

#include <Encoder.h>

const int CLK = 6;
const int DT = 5;
const int SW = 3;

Encoder encoder(CLK, DT);

boolean pressed = false;

int buttonState;
int lastButtonStade = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
long oldPosition = -999;

void setup()
{
    Serial.begin(115200);
    pinMode(SW, INPUT_PULLUP);
}

void loop()
{
    debounceDelay;

    int reading = digitalRead(SW);
    if (reading = digitalRead(SW))
        lastDebounceTime = millis();
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        if (reading != buttonState)
            buttonState = reading;
    }
    lastButtonStade = reading;

    if (!buttonState && !pressed)
    {
        pressed = true;
        Serial.println("Encoder switch pressed.");
    }
    if (buttonState)
        pressed = false;

    long newPosition = encoder.read();
    if (newPosition != oldPosition)
    {
        oldPosition = newPosition;
        Serial.println(newPosition);
    }
}