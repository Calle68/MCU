#include <Arduino.h>

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600);
Serial.println("Hallo vom Setup");
}

void loop() {
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Hallo vom Loop Version 2");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}
  
