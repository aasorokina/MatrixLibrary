#include "../s21_matrix_oop.h"

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!this->eq_sizes(other)) {
    throw std::invalid_argument("SubMatrix: Matrices have different sizes");
  }

  S21Matrix temp(other);
  temp.MulNumber(-1.0);
  this->SumMatrix(temp);
}