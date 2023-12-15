#include <Arduino.h>

struct person
{
  String name;
  int alter;
  bool programmierer;
  long kontostandInEuroCent;
};

void setup()
{
  Serial.begin(115200);
  person heribert = {"Heribert Walnöfer", 25, true, 17000};
  
  Serial.println(heribert.name);
}


void loop()
{
  delay(10);
}
