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
        switch(unit/3) {
           // case 0 :

            case 1 :
           newValue =  secTo(unit,toSec(b.unit,b.value)) + value;
            break;
            // case 2 :
        }

        PhysicalNumber a(newValue,unit);
        return a;
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

    double PhysicalNumber::secTo(Unit type, double value) {
        switch(type) {
            case 4 :
            return value/60;
 
            case 5 :
            return value/3600;
            default : return value;
        }

    }

        double PhysicalNumber::toSec(Unit type, double value) {
        switch(type) {
            case 4 :
            return value*60;
            case 5 :
            return value*3600;
            default : return value;
        }

    }

