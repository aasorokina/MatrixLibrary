#include "s21_matrix_test.h"

TEST(EqMatrixTest, EqualMatrices) {
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

  S21Matrix m2(m1);

  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(EqMatrixTest, EqualMatrices_2) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);

  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(2, 0) = 7.0;
  m1(2, 1) = 8.0;
  m1(2, 2) = 9.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(0, 2) = 3.0;
  m2(1, 0) = 4.0;
  m2(1, 1) = 5.0;
  m2(1, 2) = 6.0;
  m2(2, 0) = 7.0;
  m2(2, 1) = 8.0;
  m2(2, 2) = 9.0;

  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(EqMatrixTest, NotEqualMatrices) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);

  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(2, 0) = 7.0;
  m1(2, 1) = 8.0;
  m1(2, 2) = 9.0;

  m2(0, 0) = 13.0;
  m2(0, 1) = 2.0;
  m2(0, 2) = 31.0;
  m2(1, 0) = 4.0;
  m2(1, 1) = 65.0;
  m2(1, 2) = 6.0;
  m2(2, 0) = 7.0;
  m2(2, 1) = 8.0;
  m2(2, 2) = 10.0;

  EXPECT_FALSE(m1.EqMatrix(m2));
}

TEST(EqMatrixTest, DifferentSizes) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 2);

  EXPECT_FALSE(m1.EqMatrix(m2));
  EXPECT_NO_THROW(m1.EqMatrix(m2));
}
