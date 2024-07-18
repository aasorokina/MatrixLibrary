#ifndef S21MATRIX_OOP_H
#define S21MATRIX_OOP_H

#include <cmath>
#include <iostream>
#include <stdexcept>

#define EPS 1E-7

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  // constructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // main methods
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double number);
  bool operator==(const S21Matrix& other) const noexcept;
  S21Matrix& operator=(const S21Matrix& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double number);
  double& operator()(int i, int j);

  // accessor and mutator methods
  int get_rows() const;
  int get_cols() const;
  void set_rows(int rows);
  void set_cols(int cols);

  // additional methods
  void print();
  bool eq_sizes(const S21Matrix& other);
  bool is_square();
  S21Matrix get_minor(int row, int column);
  bool available_to_mul(const S21Matrix& other);
  bool max_in_column(const S21Matrix& A, int row, int column);
  bool swap_rows(S21Matrix& A, int n);
};

#endif