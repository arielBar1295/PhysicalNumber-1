#include <iostream>
#include "PhysicalNumber.h"
#include <string>
#include <vector>

int main() {
    ariel::PhysicalNumber a(60, ariel::KM);
    ariel::PhysicalNumber b(1000, ariel::CM);
    ariel::PhysicalNumber bb(1000, ariel::CM);
    ariel::PhysicalNumber t1(2, ariel::Unit::KM);
    ariel::PhysicalNumber t2(300, ariel::Unit::M);

   // ariel::PhysicalNumber c = a+b+b;
   // std::cout << c.getValue() <<" "<< c << std::endl;
   
    //ariel::PhysicalNumber h = a;
    //h.value = 3;
    
    std::cout << t1+t2 <<" "<< a << std::endl;

//     stringstream ssa("bla bla");
//     string s;

// while (getline(ssa, s, ' ')) {
//  cout << s << endl;
// }
    //std::cout << (s) << std::endl;
    return 0;
}