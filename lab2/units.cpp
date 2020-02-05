#include "units.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

// default constructor
UValue::UValue() {
  value = 0;
  units = "";
}

// constructor that sets value and units
UValue::UValue(double value, string units){
  this->value = value;
  this->units = units;
}

// destructor
UValue::~UValue() {
  //nothing to do
}

// returns value of UValue
double UValue::get_value() {
  return value;
}

// returns units of UValue
string UValue::get_units() {
  return units;
}

// UnitConverter Class

UnitConverter::UnitConverter(){
}

UnitConverter::~UnitConverter() {
}

void UnitConverter::not_in_conversions(string from_units, string to_units) {
   // loop through all conversions and see if one already exists
  for (Conversion c : conversions) {
      // throws invalid argument exception if conversion already exists
      if (c.from_units == from_units && c.to_units == to_units) {
	string msg = "Already have a conversion from " + from_units + " to " + to_units;
	throw invalid_argument(msg);
      }
  }
}

void UnitConverter::add_conversion(string from_units, double multiplier, string to_units) {
  not_in_conversions(from_units, to_units);
  // add in the conversion if it doesn't yet exist
  conversions.push_back({from_units, multiplier, to_units});
  //add in the opposite conversion if it doesn't yet exist
  not_in_conversions(to_units, from_units);
  conversions.push_back({to_units, 1 / multiplier, from_units});
}

// converts an inputted UValue to the specified units
// uses the compare() operation to compare strings (== 0 if strings are equal)
UValue UnitConverter::convert_to(UValue input, string to_units) {
  for (Conversion c : conversions){
    if (c.from_units == input.get_units() && c.to_units == to_units) {
      return UValue(input.get_value() * c.multiplier, to_units);
    }
  }
  string msg = "Couldn't convert to " + to_units + "!\n";
  msg += "Don't know how to convert from " + input.get_units() + " to " + to_units;
  throw invalid_argument(msg);
  
}
