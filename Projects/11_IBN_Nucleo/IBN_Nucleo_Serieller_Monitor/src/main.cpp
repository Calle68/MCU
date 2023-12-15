#include <Arduino.h>

void setup(){
  Serial.begin(115200);
  while (!Serial){}
  Serial.println("Hier sollte ein Text stehen");
  Serial.println("Dann hat der PC konntakt zum Nucleo F411RE");
}

void loop(){
  
}