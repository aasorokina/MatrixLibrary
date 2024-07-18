#include <gtest/gtest.h>

#include "s21_matrix_test.h"

TEST(TransposeTest, SquareMatrix) {
  S21Matrix m(3, 3);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(1, 0) = 4.0;
  m(1, 1) = 5.0;
  m(1, 2) = 6.0;
  m(2, 0) = 7.0;
  m(2, 1) = 8.0;
  m(2, 2) = 9.0;

  S21Matrix expected(3, 3);
  expected(0, 0) = 1.0;
  expected(0, 1) = 4.0;
  expected(0, 2) = 7.0;
  expected(1, 0) = 2.0;
  expected(1, 1) = 5.0;
  expected(1, 2) = 8.0;
  expected(2, 0) = 3.0;
  expected(2, 1) = 6.0;
  expected(2, 2) = 9.0;

  S21Matrix transpose = m.Transpose();

  EXPECT_TRUE(transpose.EqMatrix(expected));
}

TEST(TransposeTest, NonSquareMatrix) {
  S21Matrix m(2, 3);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(1, 0) = 4.0;
  m(1, 1) = 5.0;
  m(1, 2) = 6.0;

  S21Matrix expected(3, 2);
  expected(0, 0) = 1.0;
  expected(0, 1) = 4.0;
  expected(1, 0) = 2.0;
  expected(1, 1) = 5.0;
  expected(2, 0) = 3.0;
  expected(2, 1) = 6.0;

  S21Matrix transpose = m.Transpose();

  EXPECT_TRUE(transpose.EqMatrix(expected));
}

TEST(TransposeTest, Matrix1x1) {
  S21Matrix m(1, 1);
  m(0, 0) = 5.0;

  S21Matrix expected(1, 1);
  expected(0, 0) = 5.0;

  S21Matrix transpose = m.Transpose();

  EXPECT_TRUE(transpose.EqMatrix(expected));
}
