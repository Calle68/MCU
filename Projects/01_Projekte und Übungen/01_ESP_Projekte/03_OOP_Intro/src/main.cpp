#include <Arduino.h>
#include "person.h"
#include "customer.h"

person carsten = person("Carsten", "Fehlhaber", 55, 189, "M");
person sabine = person("Sabine", "Jenderzi", 49, 165, "W");
person joris = person("Joris", "Fehlhaber", 12 , 140, "M");
person gerrit = person("Gerrit", "Fehlhaber", 8, 135, "M");

customer heino = customer("Heino", "Fehlhaber", 84, 185,"M");

void setup()
{
  Serial.begin(115200);

  carsten.setAge(155);
  carsten.setNachname("Schreiner");
  heino.sumUmsatz(150);
  heino.sumUmsatz(100);
  heino.sumUmsatz(50);
  heino.sumUmsatz(500);
  
  
  Serial.println("-- Personen --");
  Serial.println(" ");
  carsten.printPersonDetail();
  sabine.printPersonDetail();
  joris.printPersonDetail();
  gerrit.printPersonDetail();
  heino.printPersonDetail();
  Serial.println(" ");
  delay(5000);
}

void loop()
{

}