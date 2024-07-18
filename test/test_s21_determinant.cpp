#include "s21_matrix_test.h"

TEST(DeterminantTest, SquareMatrix_2x2) {
  S21Matrix m(2, 2);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;

  double expected = -2.0;
  double result = m.Determinant();
  EXPECT_NEAR(result, expected, EPS);
}

TEST(DeterminantTest, SquareMatrix_3x3) {
  S21Matrix m(3, 3);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 4;
  m(1, 1) = 5;
  m(1, 2) = 6;
  m(2, 0) = 7;
  m(2, 1) = 8;
  m(2, 2) = 9;

  double expected = 0.0;
  double result = m.Determinant();
  EXPECT_NEAR(result, expected, EPS);
}

TEST(DeterminantTest, SquareMatrix_3x3_2) {
  S21Matrix m(3, 3);
  m(0, 0) = 1.5;
  m(0, 1) = -2.7;
  m(0, 2) = 3.2;
  m(1, 0) = 4.1;
  m(1, 1) = -5.8;
  m(1, 2) = 6.3;
  m(2, 0) = 7.9;
  m(2, 1) = -8.6;
  m(2, 2) = 9.4;

  double expected = 2.961;
  double result = m.Determinant();
  EXPECT_NEAR(result, expected, EPS);
}

TEST(DeterminantTest, NonSquareMatrix) {
  S21Matrix m(2, 3);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 4;
  m(1, 1) = 5;
  m(1, 2) = 6;

  EXPECT_THROW(m.Determinant(), std::invalid_argument);
}