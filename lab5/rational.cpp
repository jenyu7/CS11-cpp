#include "rational.h"
#include <string>
#include <iostream>

using namespace std;

// Rational Class
/** Constructor that takes in n and d for a Rational number n/d 
 * @param n The numerator of the rational
 * @param d The denominator of the rational 
*/
Rational::Rational(int n, int d) {
  if (d == 0) {
    string msg = "Denominator cannot be 0.";
    throw invalid_argument(msg);
  }
  if (d < 0) {
    numerator = -1 * n;
    denominator = -1 * d;
  }
  else {
    numerator = n;
    denominator = d;
  }
}

/** Member function that returns the numerator 
 *  @return The numerator of the rational
*/
int Rational::num() const {
  return numerator;
}

/** Member function that returns the denominator 
 *  @return The denominator of the rational 
*/
int Rational::denom() const {
  return denominator;
}

/** Member function that returns the reciprocal, but leaves the
 * Rational number unchanged. 
 * @return The reciprocal of the rational number
*/
Rational Rational::reciprocal() const {
  return Rational{denominator, numerator};
}

/** Private function that finds the gcd of two numbers
 * given that a > b. 
 * @param a The larger number 
 * @param b The smaller number
 * @return The greatest common denominator of a and b 
*/
int Rational::gcd(int a, int b) const{
  if (b == 0) {
      return a;
  }
  return gcd(b, a % b);  
}

/** Member function that reduces the rational number such that the 
 * gcd of the numerator and denominator is 1. Mutates the Rational.
 * @param Mutates the Rational which calls it
*/
void Rational::reduce() {
  int d = 1;
  if (numerator == 0) {
    denominator = 1;
  }
  else if (numerator > denominator) {
    d = gcd(numerator, denominator);
  }
  else if (numerator < denominator) {
    d = gcd(denominator, numerator);
  }
  else {
    d = numerator;
  }
  this->numerator = this->numerator / d;
  this->denominator = this->denominator / d;
}
 
/** (+) overloading with non-member operator 
 * @param lhs The left hand side of the equation
 * @param rhs The right hand side of the equation
 * @return A Rational that is the sum of the lhs and rhs
*/
Rational operator+(const Rational &lhs, const Rational &rhs) {
  return Rational{lhs} += rhs;
}

/** (-) overloading with non-member operator 
 * @param lhs The left hand side of the equation
 * @param rhs The right hand side of the equation
 * @return A Rational that is the difference of the lhs and rhs
*/
Rational operator-(const Rational &lhs, const Rational &rhs) {
  return Rational{lhs} -= rhs;
}

/** (*) overloading with non-member operator 
 * @param lhs The left hand side of the equation
 * @param rhs The right hand side of the equation
 * @return A Rational that is the product of the lhs and rhs
*/
Rational operator*(const Rational &lhs, const Rational &rhs) {
  return Rational{lhs} *= rhs;
}

/** (/) overloading with non-member operator 
 * @param lhs The left hand side of the equation
 * @param rhs The right hand side of the equation
 * @return A Rational that is the quotient of the lhs and rhs
*/
Rational operator/(const Rational &lhs, const Rational &rhs) {
  return Rational{lhs} /= rhs;
}

/** (+=) overloading with member operator 
 * @param rhs The right hand side of the equation (LHS is the current 
 * rational on the left hand side)
 * @return The current Rational modified to be the sum of the current 
 * Rational and rhs
*/
Rational & Rational::operator+=(const Rational &rhs) {
  numerator = numerator*rhs.denom() + rhs.num()*denominator;
  denominator = denominator*rhs.denom();
  reduce();
  return *this;
}

/** (-=) overloading with member operator 
* @param rhs The right hand side of the equation (LHS is the current 
 * rational on the left hand side)
 * @return The current rational modified to be the difference of the 
 * current Rational and rhs
*/
Rational & Rational::operator-=(const Rational &rhs) {
  return *this += (Rational{-1, 1} * rhs);
}

/** (*=) overloading with member operator 
* @param rhs The right hand side of the equation (LHS is the current 
 * rational on the left hand side)
 * @return The current Rational modified to be the product of the current
 * Rational and rhs
*/
Rational & Rational::operator*=(const Rational &rhs) {
  numerator = numerator*rhs.num();
  denominator = denominator*rhs.denom();
  reduce();
  return *this;
}

/** (/=) overloading with member operator 
* @param rhs The right hand side of the equation (LHS is the current 
 * rational on the left hand side)
 * @return The current Rational modified to be the quotient of the curren
 * t Rational and rhs
*/
Rational & Rational::operator/=(const Rational &rhs) {
  return *this *= rhs.reciprocal();
}

/** Overload stream operator to print out Rationals 
 * @param os an OStream object
 * @param r A Rational to print   
 * @return An OStream to print numerator / denominator of r
*/
ostream& operator<<(ostream &os, const Rational &r) {
  if (r.denom() == 1) {
    os << r.num();
  }
  else {
    os << r.num() << "/" << r.denom();
  }
  return os;
}
