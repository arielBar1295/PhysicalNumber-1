#include "PhysicalNumber.h"

using namespace ariel;

PhysicalNumber::PhysicalNumber(double value, Unit unit)
{
    this->value = value;
    this->unit = unit;
    name = getEnumName(unit);
}

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &b)
{
    if (!sameUnits(b))
        throw std::runtime_error("Not same units!");

    double newValue;
    switch (unit / 3)
    {
    case 0:
        newValue = CMto(unit, toCM(b.unit, b.value)) + value;
        break;
    case 1:
        newValue = secTo(unit, toSec(b.unit, b.value)) + value;
        break;
    case 2:
        newValue = Gto(unit, toG(b.unit, b.value)) + value;
        break;
    }

    PhysicalNumber a(newValue, unit);
    return a;
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &b)
{
    return *this;
}
PhysicalNumber PhysicalNumber::operator+()
{
    return *this;
}
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &b)
{
    return *this;
}
PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &b)
{
    return *this;
}
PhysicalNumber PhysicalNumber::operator-()
{
    return *this;
}

bool PhysicalNumber::operator>=(const PhysicalNumber &b) { return true; }
bool PhysicalNumber::operator>(const PhysicalNumber &b)
{
    if (!sameUnits(b))
        throw std::runtime_error("Not same units!");
    double aValue;
    double myValue;
    switch (unit / 3)
    {
    case 0:
        aValue = toCM(b.unit, b.value);
        myValue = toCM(unit,value);
        break;
    case 1:
        aValue = toSec(b.unit, b.value);
        myValue = toSec(unit,value);        break;
    case 2:
        aValue = toG(b.unit, b.value);
        myValue = toG(unit,value);        break;
    }
    

}
bool PhysicalNumber::operator<=(const PhysicalNumber &b) { return true; }
bool PhysicalNumber::operator<(const PhysicalNumber &b) { return true; }
bool PhysicalNumber::operator!=(const PhysicalNumber &b) { return true; }
bool PhysicalNumber::operator==(const PhysicalNumber &b) { return true; }

PhysicalNumber &PhysicalNumber::operator++() { return *this; }
PhysicalNumber &PhysicalNumber::operator--() { return *this; }

// istream& operator>>(istream &os, const PhysicalNumber &a) {}

// std::ostream& operator<<(ostream &os, const PhysicalNumber &a) {
//     os << a.getValue() <<"["<< a.getName() << "]";
//     return os;
// }

bool PhysicalNumber::sameUnits(const PhysicalNumber &b)
{
    int bgroupUnit = b.unit / 3;
    int agroupUnit = unit / 3;

    if (bgroupUnit == agroupUnit)
        return true;
    return false;
}

double PhysicalNumber::secTo(Unit type, double value)
{
    switch (type)
    {
    case 4:
        return value / 60;

    case 5:
        return value / 3600;
    default:
        return value;
    }
}

double PhysicalNumber::toSec(Unit type, double value)
{
    switch (type)
    {
    case 4:
        return value * 60;
    case 5:
        return value * 3600;
    default:
        return value;
    }
}

double PhysicalNumber::toCM(Unit type, double value)
{
    switch (type)
    {
    case 1:
        return value * 100;
    case 2:
        return value * 100000;
    default:
        return value;
    }
}
double PhysicalNumber::CMto(Unit type, double value)
{
    switch (type)
    {
    case 1:
        return value / 100;
    case 2:
        return value / 100000;
    default:
        return value;
    }
}

double PhysicalNumber::toG(Unit type, double value)
{
    switch (type)
    {
    case 7:
        return value * 1000;
    case 8:
        return value * 1000000;
    default:
        return value;
    }
}
double PhysicalNumber::Gto(Unit type, double value)
{
    switch (type)
    {
    case 7:
        return value / 1000;
    case 8:
        return value / 1000000;
    default:
        return value;
    }
}
