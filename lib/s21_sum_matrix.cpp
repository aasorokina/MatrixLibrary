#include "../s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!this->eq_sizes(other)) {
    throw std::invalid_argument("SumMatrix: Matrices have different sizes");
  }

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}