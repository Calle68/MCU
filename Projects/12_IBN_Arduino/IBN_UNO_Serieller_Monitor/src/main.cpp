#include <Arduino.h>

void setup(){
  Serial.begin(9600);
  while (!Serial){}
  Serial.println("Hier sollte ein Text stehen");
  Serial.println("Dann hat der PC konntakt zum Arduino UNO");
}

void loop(){
  
}