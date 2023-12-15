#ifndef person_h
#define person_h

#include <Arduino.h>

class person
{
protected:
    int age;
    int height;
    String forename;
    String lastname;
    String sex;
    String adresse;
    String zipcode;
    String country;

public:
    person(String _forename, String _lastname, int _age, int _height, String _sex);
    void setNachname(String _lastname);
    void setAge(int _age);
    void printAll();
    void printPersonDetail();
};

#endif