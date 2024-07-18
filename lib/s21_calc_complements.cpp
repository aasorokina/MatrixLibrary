#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (!this->is_square()) {
    throw std::invalid_argument("CalcComplements: The matrix is not square");
  }

  int size = this->rows_;
  S21Matrix result(size, size);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      S21Matrix minor(this->get_minor(i, j));
      double det = minor.Determinant();
      result.matrix_[i][j] = det * pow(-1, (i + j));
    }
  }

  return result;
}