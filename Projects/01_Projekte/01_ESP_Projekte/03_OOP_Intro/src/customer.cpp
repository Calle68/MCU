#include <Arduino.h>
#include "customer.h"


void customer::setBornDate(int alter){
    born = 2023-alter;
}

void customer::sumUmsatz(int _eingang){
    sales += _eingang;
}

void customer::printPersonDetail(){
    Serial.printf("Name: %s Nachname: %s Sales: %d \n", forename, lastname, sales);
}