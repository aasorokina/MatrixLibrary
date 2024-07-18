#include "s21_matrix_test.h"

TEST(MulMatrixTest, MultiplyIdentityMatrix) {
  S21Matrix m1(3, 3);
  m1(0, 0) = 1;
  m1(0, 1) = 0;
  m1(0, 2) = 0;
  m1(1, 0) = 0;
  m1(1, 1) = 1;
  m1(1, 2) = 0;
  m1(2, 0) = 0;
  m1(2, 1) = 0;
  m1(2, 2) = 1;

  S21Matrix m2(3, 3);
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(0, 2) = 3;
  m2(1, 0) = 4;
  m2(1, 1) = 5;
  m2(1, 2) = 6;
  m2(2, 0) = 7;
  m2(2, 1) = 8;
  m2(2, 2) = 9;

  m1.MulMatrix(m2);

  S21Matrix expected(3, 3);
  expected(0, 0) = 1;
  expected(0, 1) = 2;
  expected(0, 2) = 3;
  expected(1, 0) = 4;
  expected(1, 1) = 5;
  expected(1, 2) = 6;
  expected(2, 0) = 7;
  expected(2, 1) = 8;
  expected(2, 2) = 9;

  EXPECT_EQ(m1, expected);
}

TEST(MulMatrixTest, MultiplyZeroMatrix) {
  S21Matrix m1(3, 3);
  m1(0, 0) = 0;
  m1(0, 1) = 0;
  m1(0, 2) = 0;
  m1(1, 0) = 0;
  m1(1, 1) = 0;
  m1(1, 2) = 0;
  m1(2, 0) = 0;
  m1(2, 1) = 0;
  m1(2, 2) = 0;

  S21Matrix m2(3, 3);
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(0, 2) = 3;
  m2(1, 0) = 4;
  m2(1, 1) = 5;
  m2(1, 2) = 6;
  m2(2, 0) = 7;
  m2(2, 1) = 8;
  m2(2, 2) = 9;

  m1.MulMatrix(m2);

  S21Matrix expected(3, 3);
  expected(0, 0) = 0;
  expected(0, 1) = 0;
  expected(0, 2) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;
  expected(1, 2) = 0;
  expected(2, 0) = 0;
  expected(2, 1) = 0;
  expected(2, 2) = 0;

  EXPECT_EQ(m1, expected);
}

TEST(MulMatrixTest, MultiplyIncompatibleMatrices) {
  S21Matrix m1(2, 3);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(0, 2) = 3;
  m1(1, 0) = 4;
  m1(1, 1) = 5;
  m1(1, 2) = 6;

  S21Matrix m2(4, 2);
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(1, 0) = 3;
  m2(1, 1) = 4;
  m2(2, 0) = 5;
  m2(2, 1) = 6;
  m2(3, 0) = 7;
  m2(3, 1) = 8;

  EXPECT_THROW(m1.MulMatrix(m2), std::invalid_argument);
}

TEST(MulMatrixTest, MultiplyMatricesNormal) {
  S21Matrix m1(1, 3);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(0, 2) = 3;

  S21Matrix m2(3, 3);
  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(0, 2) = 3;
  m2(1, 0) = 4;
  m2(1, 1) = 5;
  m2(1, 2) = 6;
  m2(2, 0) = 7;
  m2(2, 1) = 8;
  m2(2, 2) = 9;

  m1.MulMatrix(m2);

  S21Matrix expected(1, 3);
  expected(0, 0) = 30;
  expected(0, 1) = 36;
  expected(0, 2) = 42;

  EXPECT_EQ(m1, expected);
}

TEST(MulMatrixTest, MultiplyMatricesNormal_2) {
  S21Matrix m1(2, 3);
  m1(0, 0) = 1.5;
  m1(0, 1) = 2.7;
  m1(0, 2) = -3.2;
  m1(1, 0) = 4.1;
  m1(1, 1) = -5.8;
  m1(1, 2) = 6.3;

  S21Matrix m2(3, 2);
  m2(0, 0) = 0.2;
  m2(0, 1) = -0.7;
  m2(1, 0) = 1.1;
  m2(1, 1) = 2.5;
  m2(2, 0) = -3.4;
  m2(2, 1) = 4.6;

  S21Matrix expected(2, 2);
  expected(0, 0) = 14.15;
  expected(0, 1) = -9.02;
  expected(1, 0) = -26.98;
  expected(1, 1) = 11.61;

  m1.MulMatrix(m2);

  int res = m1.EqMatrix(expected);
  EXPECT_EQ(1, res);
}

TEST(MulMatrixTest, MultiplyMatricesNormal_3) {
  S21Matrix m1(3, 2);
  m1(0, 0) = 0.0;
  m1(0, 1) = 1.2;
  m1(1, 0) = -3.4;
  m1(1, 1) = 0.0;
  m1(2, 0) = 5.6;
  m1(2, 1) = 0.0;

  S21Matrix m2(2, 4);
  m2(0, 0) = 2.1;
  m2(0, 1) = 0.0;
  m2(0, 2) = -4.7;
  m2(0, 3) = 0.0;
  m2(1, 0) = 0.0;
  m2(1, 1) = 3.3;
  m2(1, 2) = 0.0;
  m2(1, 3) = 6.8;

  S21Matrix expected(3, 4);
  expected(0, 0) = 0.0;
  expected(0, 1) = 3.96;
  expected(0, 2) = 0.0;
  expected(0, 3) = 8.16;
  expected(1, 0) = -7.14;
  expected(1, 1) = 0.0;
  expected(1, 2) = 15.98;
  expected(1, 3) = 0.0;
  expected(2, 0) = 11.76;
  expected(2, 1) = 0.0;
  expected(2, 2) = -26.32;
  expected(2, 3) = 0.0;

  m1.MulMatrix(m2);

  int res = m1.EqMatrix(expected);
  EXPECT_EQ(1, res);
}

TEST(MulMatrixTest, MultiplyMatrices_1x1) {
  S21Matrix m1(1, 1);
  m1(0, 0) = 2;

  S21Matrix m2(1, 1);
  m2(0, 0) = 3;

  S21Matrix expected(1, 1);
  expected(0, 0) = 6;

  m1.MulMatrix(m2);
  EXPECT_EQ(m1, expected);
}

TEST(MulMatrixTest, MultiplyMatrices_0x0) {
  S21Matrix m1(0, 0);
  S21Matrix m2(0, 0);

  S21Matrix expected(0, 0);

  m1.MulMatrix(m2);
  EXPECT_EQ(m1, expected);
}

TEST(MulMatrixTest, MultiplyMatricesWithZeroColumns) {
  S21Matrix m1(2, 0);
  S21Matrix m2(0, 4);

  S21Matrix expected(2, 4);

  m1.MulMatrix(m2);
  EXPECT_EQ(m1, expected);
}