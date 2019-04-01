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
    PhysicalNumber(double value, ariel::Unit unit);

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
    double WTconvertDivision(double value,int times, int units);
    double LconvertDivision(double value,int times);
};

} // namespace ariel