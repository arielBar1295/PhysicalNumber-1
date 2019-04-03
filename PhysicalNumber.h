#include <iostream>
#include "Unit.h"
#include <string>
#define size 8

using namespace std;

namespace ariel
{
static string const names[] = {"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};

class PhysicalNumber
{
private:
  double value;
  Unit unit;
  string name;

public:
  PhysicalNumber(double value, Unit unit);

  PhysicalNumber operator+(const PhysicalNumber &b);
  PhysicalNumber& operator+=(const PhysicalNumber &b);
  PhysicalNumber operator+() const;
  PhysicalNumber operator-(const PhysicalNumber &b);
  PhysicalNumber& operator-=(const PhysicalNumber &b);
  PhysicalNumber operator-();

  bool operator>=(const PhysicalNumber &b);
  bool operator>(const PhysicalNumber &b);
  bool operator<=(const PhysicalNumber &b);
  bool operator<(const PhysicalNumber &b);
  bool operator!=(const PhysicalNumber &b);
  bool operator==(const PhysicalNumber &b);

  PhysicalNumber& operator++();
  PhysicalNumber& operator--();

  friend istream& operator>>(istream &is,  PhysicalNumber& a);
  friend ostream& operator<<(ostream& os, const PhysicalNumber& a);

  Unit getUnit() { return unit; }
  double getValue() const { return value; }
  string getName() const { return name; }


private:
  bool sameUnits(const PhysicalNumber &b) const;
  double secTo(Unit type, double value) const;
  double toSec(Unit type, double value) const;
  double toCM(Unit type, double value) const;
  double CMto(Unit type, double value) const;
  double toG(Unit type, double value) const;
  double Gto(Unit type, double value) const;
  double addSubstruct(const PhysicalNumber &b);
  void normalize(double& a, double& b,const PhysicalNumber& other);


  string getEnumName(int i)
  {
    return names[i];
  }

};

} // namespace ariel
