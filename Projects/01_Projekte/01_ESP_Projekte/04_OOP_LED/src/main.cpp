#include <Arduino.h>
#include <analogWrite.h>
#include "leds.h"
#include "IBN.h"

//Inbetriebnahme
IBN ibnLaufZeit;


unsigned long previousMillis = 0;

// Test LED's
leds yellow1(12);
leds blue1(14);
leds green1(27);
leds red1(19);
leds green2(18);
leds white1(5);


void setup()
{
  Serial.begin(115200);

  //yellow1.turnOn();
  //blue1.turnOn();
  green1.turnOn();
  //red1.turnOn();
  //green2.turnOn();
  //white1.turnOn();

}

void loop()
{
  //ibnLaufZeit.laufZeit();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 2000)
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    //yellow1.toggle();
  }

  //blue1.turnOffAfterDelay(5000, false);
  green1.turnOffAfterDelay(10000, false);

  red1.fadeOn(255000);

  //green2.pulsate(200);

}