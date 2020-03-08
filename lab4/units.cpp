#include "units.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <set>

using namespace std;
// this file contains the UValue class and the UnitConverter class

/** Default constructor */
UValue::UValue() {
  value = 0;
  units = "";
}

/** Constructor that sets value and units 
 *  @param value A double representing the value
 *  @param units A string representing the units
 *  @return Returns a UValue with the specified value and units
*/
UValue::UValue(double value, const string &units){
  this->value = value;
  this->units = units;
}

/** Const function that gets the value 
 *  @return Returns the value of the UValue
 */
double UValue::get_value() const {
  return value;
}

/** Const function that gets the units
 *  @return Returns units of UValue 
 */
string UValue::get_units() const {
  return units;
}

// UnitConverter Class

UnitConverter::UnitConverter(){
}

/** This function checks if a conversion already exists. If the 
 * from_units and to_units already have a conversion, then this throws 
 * an invalid argument exception. It does this by looping through all the
 * conversions in the vector of conversions to see if the inputted one
 * already exists. 
 * @param from_units takes in the current units
 * @param to_units takes in the desired units for conversion
 * @return Does not return anything, but throws an error if the conversion exists. 
*/
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

/** This function adds a conversion given from_units, multiplier and to_units 
 * if it doesn't yet exist. It also adds in the opposite direction from 
 * to_units -> from_units with 1/multiplier if that conversion isn't 
 * already present. 
 * @param from_units takes in the current units
 * @param multiplier takes in the multiplier of conversion
 * @param to_units takes in the desired units for conversion
 * @returns Does not return anything, but modifies the vector of conversions.
*/
void UnitConverter::add_conversion(const string &from_units, double multiplier, const string &to_units) {
  not_in_conversions(from_units, to_units);
  // add in the conversion if it doesn't yet exist
  conversions.push_back({from_units, multiplier, to_units});
  // add in the opposite conversion if it doesn't yet exist
  not_in_conversions(to_units, from_units);
  conversions.push_back({to_units, 1 / multiplier, from_units});
}

/** This converts an inputted UValue to the specified units
 * and acts as wrapper function for recursive function 
 * @param input takes in the UValue to be converted
 * @param to_units takes in the desired units for conversion
 * @returns a UValue that converted to the original UValue to the desired units.
*/
UValue UnitConverter::convert_to(const UValue &input, const string &to_units) {
  set<string> seen = set<string>{};
  return convert_to(input, to_units, seen);
}

/** This is the recursive function for converting a value to another unit if a path exist
 * between the units, which may involve multiple conversions. The units of the input 
 * are added to a list of already encountered units (to prevent revisting the same 
 * conversions over and over again). Then we loop through the list of conversions, and 
 * if one exists from_units -> to_units, then the conversion is made. Otherwise, we 
 * convert from the current from_units to whatever conversion is available, provided that
 * the conversion hasn't already been made and try again.  
 * If no conversions are able to be made, an error is thrown. 
 * @param input takes in the UValue to be converted
 * @param to_units takes in the desired units for conversion
 * @param seen is a vector that keeps track of which conversions have been reached
 * @returns a UValue that is converted to the desired units from the original UValue
*/
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
