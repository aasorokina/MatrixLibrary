#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  double det = this->Determinant();

  if (std::abs(det) < EPS) {
    throw std::invalid_argument(
        "InverseMatrix: The determinant of matrix equals 0");
  }

  S21Matrix temp(this->CalcComplements());
  S21Matrix res(temp.Transpose());
  double k = 1.0 / det;
  res.MulNumber(k);
  return res;
}