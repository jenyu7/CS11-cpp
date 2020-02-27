#include "matrix.h"
#include <string>

using namespace std;

// Matrix Class
/** Constructor that takes in number of rows and columns for matrix. 
  * rows and columns must have nonnegative value.   
  */
Matrix::Matrix(int rows, int cols) {
  if (rows < 0 || cols < 0) {
    string msg = "Rows and columns need to be positive.";
    throw invalid_argument(msg);
  }
  r = rows;
  c = cols;
  elems = new int[rows*cols];
  for (int i = 0; i < rows*cols; i ++) {
    elems[i] = 0;
  }
}

/** Copy constructor that performs a deep copy. */
Matrix::Matrix(const Matrix &m) {
  r = m.r;
  c = m.c;
  elems = new int[r*c];
  for (int i = 0; i < r*c; i++) {
    elems[i] = m.elems[i];
  }
}

/** Assignment operator for matrices */
Matrix& Matrix::operator=(const Matrix &m) {
  // Detect and handle self-assignment
  if (this == &m)
    return *this;
  delete[] elems; // Release old memory
  r = m.r;
  c = m.c;
  elems = new int[r*c];
  for (int i = 0; i < r*c; i++) {
    elems[i] = m.elems[i];
  }
  return *this;
}

/** Destructor for Matrix elements */
Matrix::~Matrix() {
  delete[] elems;
}

/** Equality comparison operator for two matrices. */
bool operator==(const Matrix& m1, const Matrix &m2) {
  if (m1.numCols() != m2.numCols() || m1.numRows() != m2.numRows()) {
    return false;
  }
  int r = m1.numRows();
  int c = m1.numCols();
  for (int i = 0; i < r; i ++) {
    for (int j = 0; j < c; j ++) {
      if (m1.get(i, j) != m2.get(i, j)) {
	return false;
      }
    }
  }
  return true;
}

/** Checks if two matrices are not equal */
bool operator!=(const Matrix& m1, const Matrix& m2) {
  return !(m1 == m2);
}


