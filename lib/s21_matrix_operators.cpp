#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double number) {
  S21Matrix result(*this);
  result.MulNumber(number);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) const noexcept {
  S21Matrix temp(*this);
  return temp.EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) noexcept {
  if (!this->EqMatrix(other)) {
    for (int i = 0; i < this->rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;

    S21Matrix temp(other);

    this->cols_ = temp.cols_;
    this->rows_ = temp.rows_;
    this->matrix_ = std::move(temp.matrix_);
    temp.matrix_ = nullptr;
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double number) {
  this->MulNumber(number);
  return *this;
}

double& S21Matrix::operator()(int row, int column) {
  if (row < 0 || row >= this->rows_ || column < 0 || column >= this->cols_) {
    throw std::out_of_range("Index is outside the matrix");
  }
  return this->matrix_[row][column];
}