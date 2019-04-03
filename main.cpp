#include <iostream>
#include "PhysicalNumber.h"

int main() {
    ariel::PhysicalNumber a(60, ariel::KM);
    ariel::PhysicalNumber b(1000, ariel::CM);
    ariel::PhysicalNumber bb(1000, ariel::CM);
    ariel::PhysicalNumber c = a+b+b;
    std::cout << c.getValue() <<" "<< c << std::endl;
   
    ariel::PhysicalNumber h = a;
    //h.value = 3;

    std::cout << h <<" "<< a << std::endl;
    std::cout << (bb == b) << std::endl;
    return 0;
}