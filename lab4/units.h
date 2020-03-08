#include <string>
#include <vector>
#include <set>

/* Immutable class that holds a value and its units */
class UValue {
  // value of the object
  double value;
  // units of the value
  std::string units;

 public:
  UValue();
  UValue(double value, const std::string &units);

  // gets the value of the UValue
  double get_value() const;
  // gets the units of the UValue
  std::string get_units() const;
};

/** Class that performs the conversions between UValues */
class UnitConverter {
  /** Conversion struct stores the units from->to and the multiplier */
  struct Conversion {
    /** Units to convert from */
    std::string from_units;
    /** Multiplier for conversion */
    double multiplier;
    /** Units to convert to */
    std::string to_units;
  };
  /** vector of conversions */
  std::vector<Conversion> conversions;

 public:
  /** default constructor */
  UnitConverter();
  
  // adds a conversion to the list
  void add_conversion(const std::string &from_units, double multiplier, const std::string &to_units);
  // checks if a conversion is already in the list
  void not_in_conversions(const std::string &from_units, const std::string &to_units);
  //converts a UValue
  UValue convert_to(const UValue &input, const std::string &to_units);
  UValue convert_to(const UValue &input, const std::string &to_units, std::set<std::string> &seen);
};
