#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  double det = 1.0;
  if (!this->is_square()) {
    throw std::invalid_argument("Determinant: The matrix is not square");
  }

  int size = this->rows_;
  S21Matrix temp(*this);
  int sign = 1;

  for (int k = 0; k < size - 1; k++) {
    if (!max_in_column(temp, k, k)) {
      if (swap_rows(temp, k)) sign *= -1;
    }
    if (std::abs(temp.matrix_[k][k]) < EPS) {
      det = 0.0;
      break;
    }
    for (int i = k + 1; i < size; i++) {
      double coefficient = temp.matrix_[i][k] / temp.matrix_[k][k];
      for (int j = k; j < size; j++) {
        temp.matrix_[i][j] -= (coefficient * temp.matrix_[k][j]);
      }
    }
  }

  if (std::abs(det) > EPS) {
    det = sign;
    for (int i = 0; i < size; i++) det *= temp.matrix_[i][i];
  }

  return det;
}