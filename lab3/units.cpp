#include "units.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <set>

using namespace std;

// default constructor
UValue::UValue() {
  value = 0;
  units = "";
}

// constructor that sets value and units
UValue::UValue(double value, const string &units){
  this->value = value;
  this->units = units;
}

// returns value of UValue
double UValue::get_value() const {
  return value;
}

// returns units of UValue
string UValue::get_units() const {
  return units;
}

// UnitConverter Class

UnitConverter::UnitConverter(){
}

UnitConverter::~UnitConverter() {
}

// checks if a conversion already exists
void UnitConverter::not_in_conversions(const string &from_units, const string &to_units) {
  // if from_units or to_units are empty strings, ignore
  if (from_units == "" || to_units == "") {
    return;
  }
   // loop through all conversions and see if one already exists
  for (Conversion c : conversions) {
      // throws invalid argument exception if conversion already exists
      if (c.from_units == from_units && c.to_units == to_units) {
	string msg = "Already have a conversion from " + from_units + " to " + to_units;
	throw invalid_argument(msg);
      }
  }
}

// adds a conversion given from_units, multiplier and to_units
void UnitConverter::add_conversion(const string &from_units, double multiplier, const string &to_units) {
  not_in_conversions(from_units, to_units);
  // add in the conversion if it doesn't yet exist
  conversions.push_back({from_units, multiplier, to_units});
  //add in the opposite conversion if it doesn't yet exist
  not_in_conversions(to_units, from_units);
  conversions.push_back({to_units, 1 / multiplier, from_units});
}

// converts an inputted UValue to the specified units
// wrapper function for recursive function
UValue UnitConverter::convert_to(const UValue &input, const string &to_units) {
  set<string> seen = set<string>{};
  return convert_to(input, to_units, seen);
}

// converts a value to another unit if a path exists between the units (may involve multiple conversions)
UValue UnitConverter::convert_to(const UValue &input, const string &to_units, set<string> &seen) {
  // add the units of the input (seen)
  seen.insert(input.get_units());
  for (Conversion c : conversions){
    // if the conversion can be made to the originally specified to_units, do it!
    if (c.from_units == input.get_units() && c.to_units == to_units) {
      return UValue{input.get_value() * c.multiplier, to_units};
    }
    else {
      // convert from the current from_units to whatever conversion is available
      // provided that this conversion hasn't already been made
      if (c.from_units == input.get_units() && seen.count(c.to_units) == 0) {
	try {
	  UValue tmp = UValue{input.get_value() * c.multiplier, c.to_units};
	  return convert_to(tmp, to_units, seen);
	}
	// catch invalid conversions
	catch (const invalid_argument &e) {
	}
      }
    }
  }
  // throws error if no conversions were able to be made
  string msg = "Couldn't convert to " + to_units + "!\n";
  msg += "Don't know how to convert from " + input.get_units() + " to " + to_units;
  throw invalid_argument(msg);
}
