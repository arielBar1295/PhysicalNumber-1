#include <iostream>

using namespace std;

namespace ariel
{


enum Unit
{
   CM,
    M,
    KM,
    SEC,
    MIN,
    HOUR,
    G,
    KG,
    TON
};


class PhysicalNumber
{
    private:
    double value;
    Unit unit;

    public:
    PhysicalNumber(double value, Unit unit);

    PhysicalNumber operator+(const PhysicalNumber &b);
    PhysicalNumber& operator+=(const PhysicalNumber &b);
    PhysicalNumber operator+();
    PhysicalNumber operator-(const PhysicalNumber &b);
    PhysicalNumber& operator-=(const PhysicalNumber &b);
    PhysicalNumber operator-();

    bool operator>=(const PhysicalNumber &b);
    bool operator>(const PhysicalNumber &b);
    bool operator<=(const PhysicalNumber &b);
    bool operator<(const PhysicalNumber &b);
    bool operator!=(const PhysicalNumber &b);
    bool operator==(const PhysicalNumber &b);

    PhysicalNumber& operator++ ();
    PhysicalNumber& operator-- ();
    
    friend istream& operator>>(istream& os, const PhysicalNumber& a);
    friend ostream& operator<<(ostream& os, const PhysicalNumber& a);

    Unit getUnit() {return unit;}
    double getValue () {return value;}


    private:
    bool sameUnits(const PhysicalNumber &b);
     double secTo(Unit type, double value);
     double toSec(Unit type, double value);
    
};


} // namespace ariel
