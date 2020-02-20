#include "rational.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
  Rational r = Rational{4, 5};
  Rational r1 = Rational{4, 5};
  try {
    r /= r1;
    cout << r;
  }
  // otherwise gives an error message
  catch (const invalid_argument& e) {
    cout << e.what() << "\n";
    return 1;
    }
  return 0;
}
