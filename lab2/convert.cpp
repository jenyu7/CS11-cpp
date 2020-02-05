#include "units.h"
#include <string>
#include <iostream>

using namespace std;

UnitConverter init_converter() {
  UnitConverter uconvert = UnitConverter();
  uconvert.add_conversion("mi", 5280, "ft");
  uconvert.add_conversion("mi", 1.6, "km");
  uconvert.add_conversion("ft", 12, "in");
  uconvert.add_conversion("in", 2.54, "cm");
  uconvert.add_conversion("lb", 0.45, "kg");
  uconvert.add_conversion("stone", 14, "lb");
  uconvert.add_conversion("lb", 16, "oz");
  uconvert.add_conversion("kg", 1000, "g");
  uconvert.add_conversion("gal", 3.79, "L");
  uconvert.add_conversion("bushel", 9.3, "gal");
  uconvert.add_conversion("ft^3", 7.5, "gal");
  uconvert.add_conversion("L", 1000, "ml");
  return uconvert;
}
int main() {
  UnitConverter u = init_converter();
  cout << "Enter value with units: ";
  double value;
  string units;
  cin >> value >> units;
  UValue old = UValue(value, units);
  cout << "Convert to units: ";
  string to_units;
  cin >> to_units;
  try {
    UValue val = u.convert_to(old, to_units);
    cout << "Converted to: " << val.get_value() << " " << val.get_units() << "\n";
  }
  catch (invalid_argument e) {
    cout << e.what() << "\n";
  }
  return 0;
}
