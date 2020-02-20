#include <string>
#include <iostream>

/* Mutable class that represents a Rational number */
class Rational {
  /** Numerator of the Rational */
  int numerator;
  /** Denominator of the Rational */
  int denominator;

 public:
  Rational(int n = 0, int d = 1);

  // gets the value of the numerator
  int num() const;
  // gets the units of the denominator
  int denom() const;
  // gets the reciprocal of the Rational
  Rational reciprocal() const;
  // reduces the rational to simplest terms
  void reduce();
  // (+=) operator overload
  Rational & operator+=(const Rational &rhs);
  // (-=) operator overload
  Rational & operator-=(const Rational &rhs);
  // (*=) operator overload
  Rational & operator*=(const Rational &rhs);
  // (/=) operator overload
  Rational & operator/=(const Rational &rhs);
 private:
  // returns the greatest common denominator of two numbers
  int gcd(int a, int b) const;
};

// Non-member operator functions

// addition 
Rational operator+(const Rational &lhs, const Rational &rhs);
// subtraction
Rational operator-(const Rational &lhs, const Rational &rhs);
// multiplication
Rational operator*(const Rational &lhs, const Rational &rhs);
// division
Rational operator/(const Rational &lhs, const Rational &rhs);

// stream operator
std::ostream& operator<<(std::ostream &os, const Rational &r);
