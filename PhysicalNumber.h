#include <iostream>
#include "Unit.h"
#include <string>
#define size 9

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

  PhysicalNumber operator+(const PhysicalNumber& b);
  PhysicalNumber& operator+=(const PhysicalNumber& b);
  PhysicalNumber operator+() const;
  PhysicalNumber operator-(const PhysicalNumber& b);
  PhysicalNumber& operator-=(const PhysicalNumber& b);
  PhysicalNumber operator-() const;

  bool operator>=(const PhysicalNumber& b) const;
  bool operator>(const PhysicalNumber& b) const;
  bool operator<=(const PhysicalNumber& b) const;
  bool operator<(const PhysicalNumber& b) const;
  bool operator!=(const PhysicalNumber& b) const;
  bool operator==(const PhysicalNumber& b) const;

  PhysicalNumber& operator++();
  PhysicalNumber& operator--();

  friend istream& operator>>(istream& is, PhysicalNumber& a);
  friend ostream& operator<<(ostream& os, const PhysicalNumber& a);


private:
  bool sameUnits(const PhysicalNumber &b) const;
  double secTo(Unit type, double value) const;
  double toSec(Unit type, double value) const;
  double toCM(Unit type, double value) const;
  double CMto(Unit type, double value) const;
  double toG(Unit type, double value) const;
  double Gto(Unit type, double value) const;
  double addSubstruct(const PhysicalNumber &b);
  void normalize(double& a, double& b,const PhysicalNumber& other) const;
  istream& checkChar(istream& is, char check) const;
  void error(Unit other) const;

};

} // namespace ariel
