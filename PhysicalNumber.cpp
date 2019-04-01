#include "PhysicalNumber.h"


using namespace ariel;

    PhysicalNumber::PhysicalNumber(double value, Unit unit) {
        this->value = value;
        this->unit = unit;
    }
  

    PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &b) {
        if(!sameUnits(b)) 
             throw std::runtime_error("Not same units!");

        double newValue;
        if(b.unit == unit) {
            newValue = b.value + value;
        }
        else if(b.unit > unit) {
            if(b.unit/3==0) {
                
            }
            else if(b.unit/3 == 1) {
                newValue = WTconvertDivision(b.value,b.unit-unit,60) + value;
            }
            else {
                newValue = WTconvertDivision(b.value,b.unit-unit,1000) + value;

            }
        }
        else {
            
        }

        
    }

    PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &b) {

    }
    PhysicalNumber PhysicalNumber::operator+() {

    }
    PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &b) {

    }
    PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &b) {

    }
    PhysicalNumber PhysicalNumber::operator-() {

    }

    bool PhysicalNumber::operator>=(const PhysicalNumber &b){}
    bool PhysicalNumber::operator>(const PhysicalNumber &b){}
    bool PhysicalNumber::operator<=(const PhysicalNumber &b){}
    bool PhysicalNumber::operator<(const PhysicalNumber &b){}
    bool PhysicalNumber::operator!=(const PhysicalNumber &b){}
    bool PhysicalNumber::operator==(const PhysicalNumber &b){}

    PhysicalNumber& PhysicalNumber::operator++ (){}
    PhysicalNumber& PhysicalNumber::operator-- (){}
    
     istream& operator>>(istream& os, const PhysicalNumber& a){}
     ostream& operator<<(ostream& os, const PhysicalNumber& a){}

    bool PhysicalNumber::sameUnits(const PhysicalNumber &b) {
        int bgroupUnit = b.unit/3;
        int agroupUnit = unit/3;
        
        if(bgroupUnit == agroupUnit) return true;
        return false;
        
    }

    double PhysicalNumber::WTconvertDivision(double value,int times, int units) {

    }
