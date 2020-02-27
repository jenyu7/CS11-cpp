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
  Matrix& operator=(const Matrix &m);
  int numRows() const {
    return r;
  }
  int numCols() const {
    return c;
  }
  int get(int i, int j) const {
    if (i < 0 || i >= r || j < 0 || j >= c) {
      std::string msg = "Index out of bounds.";
      throw std::invalid_argument(msg);
    }
    return elems[i * c + j];
  }
  int set(int i, int j, int val) {
    if (i < 0 || i >= r || j < 0 || j >= c) {
      std::string msg = "Index out of bounds.";
      throw std::invalid_argument(msg);
    }
    elems[i * c + j] = val;
    return val;
  }
};

/** Non member functions */
bool operator==(const Matrix& m1, const Matrix& m2);
bool operator!=(const Matrix& m1, const Matrix& m2);
