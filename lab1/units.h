#include <string>
 
/* Immutable class that holds a value and its units */
class UValue {
  // value of the object
  double value;
  // units of the value
  std::string units;
 
 public:
  UValue();
  UValue(double value, std::string units);
 
  double get_value();
  std::string get_units();
};
 
UValue convert_to(UValue input, std::string to_units);
