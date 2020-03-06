#include <string>
#include <stdexcept>

/* Mutable class that represents a Matrix */
class Matrix {
  /** Rows in the matrix */
  int r;
  /** Columns in the matrix */
  int c;
  /** Matrix */
  int *elems;

 public:
  Matrix(int rows = 0, int cols = 0);
  ~Matrix();
  Matrix(const Matrix &m);
  Matrix(Matrix &&m);
  Matrix& operator=(const Matrix &m);
  Matrix& operator=(Matrix &&m);
  /** Returns the number of rows. */
  int numRows() const {
    return r;
  }
  /** Returns the number of columns. */
  int numCols() const {
    return c;
  }
  /** Gets the value of an index in the matrix. */
  int get(int i, int j) const {
    if (i < 0 || i >= r || j < 0 || j >= c) {
      std::string msg = "Index out of bounds.";
      throw std::invalid_argument(msg);
    }
    return elems[i * c + j];
  }
  
  /** Sets the value of an index in the matrix. */
  int set(int i, int j, int val) {
    if (i < 0 || i >= r || j < 0 || j >= c) {
      std::string msg = "Index out of bounds.";
      throw std::invalid_argument(msg);
    }
    elems[i * c + j] = val;
    return val;
  }
  // (+=) operator overload
  Matrix & operator+=(const Matrix &rhs);
  // (-=) operator overload
  Matrix & operator-=(const Matrix &rhs);
  // (*=) operator overload
  Matrix & operator*=(const Matrix &rhs);
  // (/=) operator overload
  Matrix & operator/=(const Matrix &rhs);
};

/** Non member functions */
bool operator==(const Matrix& m1, const Matrix& m2);
bool operator!=(const Matrix& m1, const Matrix& m2);
// addition 
Matrix operator+(const Matrix &lhs, const Matrix &rhs);
// subtraction
Matrix operator-(const Matrix &lhs, const Matrix &rhs);
// multiplication
Matrix operator*(const Matrix &lhs, const Matrix &rhs);
// division
Matrix operator/(const Matrix &lhs, const Matrix &rhs);
