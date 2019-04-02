#include <iostream>
#include "PhysicalNumber.h"

int main() {
    ariel::PhysicalNumber a(60, ariel::SEC);
    ariel::PhysicalNumber b(1, ariel::HOUR);
    ariel::PhysicalNumber c = a+b;
    std::cout << c.getValue() <<" " << c.getUnit() << std::endl;
    return 0;
}