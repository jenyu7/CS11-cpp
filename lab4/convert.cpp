#include "units.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// The main program for the unit covnerter. Takes in user input and
// tries to convert the specified units

/** Initializes the conversions in the UnitConverter based on
 *  the conversions in a file. Throws an error if file cannot be accessed.
 *  @param filename name of file to read in the conversions from
 *  @return Returns a UnitConverter with initialized conversions
   */
UnitConverter init_converter(string filename) {
  ifstream ifs{filename};
  // check if filename is valid
  if (!ifs) {
    string msg = "Couldn't open file";
    throw invalid_argument(msg);
  }
  UnitConverter uconvert = UnitConverter();
  while (ifs) {
    string from_units;
    double multiplier;
    string to_units;
    // reads in the from_units, multiplier, and to_units from file
    ifs >> from_units >> multiplier >> to_units;
    // adds the conversion to the UnitConverter
    uconvert.add_conversion(from_units, multiplier, to_units);
  }
  return uconvert;
}

/** Main program runs the UnitConverter. The user gives a value with units
 * and the program converts it to units specified by the user if possible. */
int main() {
  cout << "Loading units from rules.txt\n";
  UnitConverter u = init_converter("rules.txt");
  cout << "Enter value with units: ";
  double value;
  string units;
  cin >> value >> units;
  UValue old = UValue(value, units);
  cout << "Convert to units: ";
  string to_units;
  cin >> to_units;
  try {
    // converts the inputted value to to_units if possible
    UValue val = u.convert_to(old, to_units);
    cout << "Converted to: " << val.get_value() << " " << val.get_units() << "\n";
  }
  // otherwise gives an error message
  catch (const invalid_argument& e) {
    cout << e.what() << "\n";
    return 1;
    }
  return 0;
}
