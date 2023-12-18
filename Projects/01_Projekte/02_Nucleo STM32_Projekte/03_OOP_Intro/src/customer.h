#ifndef customer_h
#define customer_h

#include <Arduino.h>
#include "person.h"

class customer : public person
{
private:
    int born;
    int sales;
public:
    using person::person;
    void setBornDate(int _born);
    void sumUmsatz(int _eingang);
    void printPersonDetail();
};

#endif