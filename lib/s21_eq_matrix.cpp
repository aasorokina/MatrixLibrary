#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool equal = this->eq_sizes(other);

  if (equal) {
    for (int i = 0; i < this->rows_ && equal; i++) {
      for (int j = 0; j < this->cols_ && equal; j++) {
        if (std::abs(this->matrix_[i][j] - other.matrix_[i][j]) > EPS)
          equal = 0;
      }
    }
  }

  return equal;
}