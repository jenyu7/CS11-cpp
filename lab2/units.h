#include <string>
#include <vector>

// Header file that holds definitions for UValue and UnitConverter classes

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

// UnitConverter class responsible for converting UValues
class UnitConverter {
  // Conversion struct stores the units from->to and the multiplier
  struct Conversion {
    std::string from_units;
    double multiplier;
    std::string to_units;
  };
  // vector of conversions
  std::vector<Conversion> conversions;

 public:
  // default constructor and destructor
  UnitConverter();
  ~UnitConverter();
  
  // adds a conversion to the list
  void add_conversion(std::string from_units, double multiplier, std::string to_units);
  // checks if a conversion is already in the list
  void not_in_conversions(std::string from_units, std::string to_units);
  // converts a UValue
  UValue convert_to(UValue input, std::string to_units);
};
