#include <iostream>
#include "PhysicalNumber.h"

int main() {
    ariel::PhysicalNumber a(60, ariel::KM);
    ariel::PhysicalNumber b(1000, ariel::CM);
    ariel::PhysicalNumber c = a+b;
    std::cout << c.getValue() <<" "<< c << std::endl;
    return 0;
}