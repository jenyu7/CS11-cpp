#include "units.h"
#include <string>
  
using namespace std;
// This file contains the functions of the unit converter. 
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
 
// returns value of UValue 
double UValue::get_value() {
  return value;
}
 
// returns units of UValue 
string UValue::get_units() {
  return units;
}
 
// converts an inputted UValue to the specified units
// uses the compare() operation to compare strings (== 0 if strings are equal)
UValue convert_to(UValue input, string to_units) {
  if (input.get_units().compare("lb") == 0 && to_units.compare("kg") == 0) {
    return UValue{input.get_value() * 0.45, to_units}; 
  } 
  if (input.get_units().compare("gal") == 0 && to_units.compare("L") == 0) { 
    return UValue{input.get_value() * 3.79, to_units}; 
  } 
  if (input.get_units().compare("mi") == 0 && to_units.compare("km") == 0) { 
    return UValue{input.get_value() * 1.6, to_units}; 

  }
  return input;
}
