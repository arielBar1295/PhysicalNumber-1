#include <iostream>
#include "Unit.h"
#include <string>

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
  PhysicalNumber &operator+=(const PhysicalNumber &b);
  PhysicalNumber operator+();
  PhysicalNumber operator-(const PhysicalNumber &b);
  PhysicalNumber &operator-=(const PhysicalNumber &b);
  PhysicalNumber operator-();

  bool operator>=(const PhysicalNumber &b);
  bool operator>(const PhysicalNumber &b);
  bool operator<=(const PhysicalNumber &b);
  bool operator<(const PhysicalNumber &b);
  bool operator!=(const PhysicalNumber &b);
  bool operator==(const PhysicalNumber &b);

  PhysicalNumber &operator++();
  PhysicalNumber &operator--();

  friend istream &operator>>(istream &is, const PhysicalNumber &a) {return is;}
  friend ostream &operator<<(ostream &os, const PhysicalNumber &a)
  {
    os << a.getValue() << "[" << a.getName() << "]";
    return os;
  }

  Unit getUnit() { return unit; }
  double getValue() const { return value; }
  string getName() const { return name; }

private:
  bool sameUnits(const PhysicalNumber &b);
  double secTo(Unit type, double value);
  double toSec(Unit type, double value);
  double toCM(Unit type, double value);
  double CMto(Unit type, double value);
  double toG(Unit type, double value);
  double Gto(Unit type, double value);

  string getEnumName(int i)
  {
    return names[i];
  }
};

} // namespace ariel
