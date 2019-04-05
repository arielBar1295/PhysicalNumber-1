#include "PhysicalNumber.h"

using namespace ariel;

PhysicalNumber::PhysicalNumber(double value, Unit unit)
{
    this->value = value;
    this->unit = unit;
}

PhysicalNumber::PhysicalNumber(const PhysicalNumber &other) : PhysicalNumber(other.value, other.unit) {}


PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &b)
{
    if (!sameUnits(b))
        error(b.unit);

    double newValue = value + addSubstruct(b);
    return PhysicalNumber(newValue, unit);
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &b)
{
    PhysicalNumber temp = (*this + b);
    value = temp.value;

    return *this;
}

PhysicalNumber PhysicalNumber::operator+() const {return *this; }

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &b)
{
    if (!sameUnits(b))
        error(b.unit);

    double newValue = value - addSubstruct(b);
    return PhysicalNumber(newValue, unit);
}

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &b)
{
    PhysicalNumber temp = (*this - b);
    value = temp.value;

    return *this;
}
PhysicalNumber PhysicalNumber::operator-() const { return PhysicalNumber(value* -1, unit); }

bool PhysicalNumber::operator>=(const PhysicalNumber &b) const
{
    if (!sameUnits(b))
        error(b.unit);

    double aValue;
    double myValue;
    normalize(myValue, aValue, b);

    return myValue >= aValue;
}

bool PhysicalNumber::operator>(const PhysicalNumber &b) const{ return !(*this <= b); }

bool PhysicalNumber::operator<=(const PhysicalNumber &b) const
{
    if (!sameUnits(b))
        error(b.unit);

    double aValue;
    double myValue;
    normalize(myValue, aValue, b);

    return myValue <= aValue;
}
bool PhysicalNumber::operator<(const PhysicalNumber &b) const{return !(*this >= b);}
bool PhysicalNumber::operator!=(const PhysicalNumber &b) const{return (*this > b) || (*this < b);}
bool PhysicalNumber::operator==(const PhysicalNumber &b) const{return !(*this < b) && !(*this > b);}

PhysicalNumber &PhysicalNumber::operator++(){
    value++;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator++(int){
    PhysicalNumber temp(*this);
    value++;
    return temp;
}

PhysicalNumber &PhysicalNumber::operator--(){
    value--;
    return *this;
}
PhysicalNumber &PhysicalNumber::operator--(int){
    PhysicalNumber temp(*this);
    value--;
    return temp;
}

bool PhysicalNumber::sameUnits(const PhysicalNumber &b) const{
    int bgroupUnit = b.unit / 3;
    int agroupUnit = unit / 3;

    if (bgroupUnit == agroupUnit)
        return true;
    return false;
}

double PhysicalNumber::secTo(Unit type, double value) const{
    switch (type)
    {
    case MIN:
        return value / 60;

    case HOUR:
        return value / 3600;
    default:
        return value;
    }
}

double PhysicalNumber::toSec(Unit type, double value) const{
    switch (type)
    {
    case MIN:
        return value * 60;
    case HOUR:
        return value * 3600;
    default:
        return value;
    }
}

double PhysicalNumber::toCM(Unit type, double value) const
{
    switch (type)
    {
    case M:
        return value * 100;
    case KM:
        return value * 100000;
    default:
        return value;
    }
}
double PhysicalNumber::CMto(Unit type, double value) const
{
    switch (type)
    {
    case M:
        return value / 100;
    case KM:
        return value / 100000;
    default:
        return value;
    }
}

double PhysicalNumber::toG(Unit type, double value) const
{
    switch (type)
    {
    case KG:
        return value * 1000;
    case TON:
        return value * 1000000;
    default:
        return value;
    }
}
double PhysicalNumber::Gto(Unit type, double value) const
{
    switch (type)
    {
    case KG:
        return value / 1000;
    case TON:
        return value / 1000000;
    default:
        return value;
    }
}

void PhysicalNumber::normalize(double &a, double &b, const PhysicalNumber &other) const
{
    switch (unit / 3)
    {
    case 0:
        b = toCM(other.unit, other.value);
        a = toCM(unit, value);
        break;
    case 1:
        b = toSec(other.unit, other.value);
        a = toSec(unit, value);
        break;
    case 2:
        b = toG(other.unit, other.value);
        a = toG(unit, value);
        break;
    }
}

double PhysicalNumber::addSubstruct(const PhysicalNumber &b)
{
    double newValue;
    switch (unit / 3)
    {
    case 0:
        newValue = CMto(unit, toCM(b.unit, b.value));
        break;
    case 1:
        newValue = secTo(unit, toSec(b.unit, b.value));
        break;
    case 2:
        newValue = Gto(unit, toG(b.unit, b.value));
        break;
    }
    return newValue;
}

void PhysicalNumber::error(Unit other) const {
    throw std::runtime_error("Units do not match - ["+names[other]+"] cannot be converted to ["+ names[unit]+"]");
}

std::ostream &ariel::operator<<(ostream &os, const PhysicalNumber &a)
{
    os << a.value << "[" << names[a.unit] << "]";
    return os;
}

std::istream &ariel::operator>>(istream &is, PhysicalNumber &a)
{
    double val;
    char check;
    string s;
    if (!(is >> val) || !a.checkChar(is, '[') || !(is >> s))
        throw std::runtime_error("String type not acceptable!");

    int n = s.find(']');
    if (n == -1)
        throw std::runtime_error("String type not acceptable!");

    string checkName = s.substr(0, n);

    Unit un;
    bool found = false;
    for (int i = 0; i < size && !found; i++)
    {
        if (checkName.compare(names[i]) == 0)
        {
            a.unit = static_cast<Unit>(i);
            a.value = val;
            found = true;
        }
    }
    if (!found)
        throw std::runtime_error("String type not acceptable!");

    return is;
}

istream &PhysicalNumber::checkChar(istream &is, char expected) const
{
    char acutal;
    if (!(is >> acutal))
        return is;

    if (acutal != expected)
        is.setstate(ios::failbit);

    return is;
}
