#include "s21_matrix_test.h"

TEST(SumMatrixTest, NormalSumMatrix) {
  S21Matrix m1(3, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(2, 0) = 7.0;
  m1(2, 1) = 8.0;
  m1(2, 2) = 9.0;

  S21Matrix m2(3, 3);
  m2(0, 0) = 9.0;
  m2(0, 1) = 8.0;
  m2(0, 2) = 7.0;
  m2(1, 0) = 6.0;
  m2(1, 1) = 5.0;
  m2(1, 2) = 4.0;
  m2(2, 0) = 3.0;
  m2(2, 1) = 2.0;
  m2(2, 2) = 1.0;

  S21Matrix expected(3, 3);
  expected(0, 0) = 10.0;
  expected(0, 1) = 10.0;
  expected(0, 2) = 10.0;
  expected(1, 0) = 10.0;
  expected(1, 1) = 10.0;
  expected(1, 2) = 10.0;
  expected(2, 0) = 10.0;
  expected(2, 1) = 10.0;
  expected(2, 2) = 10.0;

  m1.SumMatrix(m2);

  EXPECT_TRUE(m1.EqMatrix(expected));
}

TEST(SumMatrixTest, DifferentSizes) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 2);

  EXPECT_THROW(m1.SumMatrix(m2), std::invalid_argument);
}

TEST(SumMatrixTest, AddToZero) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(0, 2) = 3.0;
  m2(1, 0) = 4.0;
  m2(1, 1) = 5.0;
  m2(1, 2) = 6.0;
  m2(2, 0) = 7.0;
  m2(2, 1) = 8.0;
  m2(2, 2) = 9.0;

  m1.SumMatrix(m2);

  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(SumMatrixTest, AddInf) {
  S21Matrix m1(3, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = INFINITY;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(2, 0) = 7.0;
  m1(2, 1) = INFINITY;
  m1(2, 2) = 9.0;

  S21Matrix m2(3, 3);

  m2.SumMatrix(m1);

  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(SumMatrixTest, Matrix_1x1) {
  S21Matrix m1(1, 1);
  m1(0, 0) = 5.0;

  S21Matrix m2(1, 1);
  m2(0, 0) = 3.0;

  S21Matrix expected(1, 1);
  expected(0, 0) = 8.0;

  m1.SumMatrix(m2);

  EXPECT_TRUE(m1.EqMatrix(expected));
}