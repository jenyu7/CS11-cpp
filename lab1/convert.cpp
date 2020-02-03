#include "units.h"
#include <string>
#include <iostream>
  
using namespace std;
// The main program for the unit converter. Takes in user input and 
// tries to convert to the specified units
int main() {
  // asks for user input
  cout << "Enter value with units: ";
  double value;
  string units;
  cin >> value >> units;
  UValue old{value, units}; 
  // asks for the units the user wants to convert to
  cout << "Convert to units: ";
  string to_units;
  cin >> to_units;
  UValue val = convert_to(old, to_units);
  // if the units didn't change, then the conversion was unsuccessful
  if (old.get_units().compare(val.get_units()) == 0) {
    cout << "Couldn't convert to " << to_units << "!\n";
  }
  // otherwise, tell the user the result 
  else {
    cout << "Converted to: " << val.get_value() << " "
         << val.get_units() << "\n";
  }
  return 0;
}