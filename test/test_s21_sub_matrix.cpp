#include "s21_matrix_test.h"

TEST(SubMatrixTest, NormalSubMatrix) {
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
  expected(0, 0) = -8.0;
  expected(0, 1) = -6.0;
  expected(0, 2) = -4.0;
  expected(1, 0) = -2.0;
  expected(1, 1) = 0.0;
  expected(1, 2) = 2.0;
  expected(2, 0) = 4.0;
  expected(2, 1) = 6.0;
  expected(2, 2) = 8.0;

  m1.SubMatrix(m2);

  EXPECT_TRUE(m1.EqMatrix(expected));
}

TEST(SubMatrixTest, NormalSubtMatrix_2) {
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

  S21Matrix expected(3, 3);

  m1.SubMatrix(m1);

  EXPECT_TRUE(m1.EqMatrix(expected));
}

TEST(SubMatrixTest, DifferentSizes) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 2);

  EXPECT_THROW(m1.SubMatrix(m2), std::invalid_argument);
}

TEST(SubMatrixTest, SubtractFromZero) {
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

  S21Matrix expected(3, 3);
  expected(0, 0) = -1.0;
  expected(0, 1) = -2.0;
  expected(0, 2) = -3.0;
  expected(1, 0) = -4.0;
  expected(1, 1) = -5.0;
  expected(1, 2) = -6.0;
  expected(2, 0) = -7.0;
  expected(2, 1) = -8.0;
  expected(2, 2) = -9.0;

  m1.SubMatrix(m2);

  EXPECT_TRUE(m1.EqMatrix(expected));
}