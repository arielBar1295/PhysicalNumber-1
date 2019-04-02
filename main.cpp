#include <iostream>
#include "PhysicalNumber.h"

int main() {
    ariel::PhysicalNumber a(60, ariel::SEC);
    ariel::PhysicalNumber b(1, ariel::SEC);
    ariel::PhysicalNumber c = a+b;
    std::cout << c.getValue() <<" " << c.getUnit() << c << std::endl;
    return 0;
}