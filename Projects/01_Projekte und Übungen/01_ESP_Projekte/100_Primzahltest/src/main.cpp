#include <Arduino.h>

#include <iostream>

#include "userinput.h"
#include "primemath.h"

void setup() {
  
} 

void loop() {

}

int main()
{
  while (true) {
    int64_t val = enter_prime_candidate();

    if (val == 0) 
      return 0;

    int64_t smallest_div = smallest_divisor(val);

    std::cout << "Die Zahl " << val << " ist ";
    if (smallest_div == val)
      std::cout << "eine Primzahl." << std::endl;
    else
      std::cout << "keine Primzahl: " << smallest_div << " ist ein Teiler." << std::endl;
  }
}
