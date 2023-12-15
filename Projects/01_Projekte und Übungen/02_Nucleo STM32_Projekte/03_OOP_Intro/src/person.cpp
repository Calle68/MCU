#include "person.h"


person::person(String _forename, String _lastname, int _age, int _height, String _sex){
    forename = _forename;
    lastname = _lastname;
    age = _age;
    height = _height;
    sex = _sex;
}

void person::printPersonDetail(){
    Serial.printf("Name: %s Nachname: %s Alter: %d Größe: %d Geschlecht: %s \n",forename ,lastname,  age, height, sex);
}

void person::setNachname(String _lastname){
    lastname = _lastname;
}

void person::setAge(int _age){
    if (_age > 100)
    age = 00;
    else
    age = _age;
}