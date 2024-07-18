#include "s21_matrix_test.h"

TEST(InverseMatrixTest, MatrixWithZeroDeterminant) {
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

  EXPECT_THROW(m.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixTest, MatrixWithZeroDeterminant_2) {
  S21Matrix m(3, 3);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(1, 0) = 4.0;
  m(1, 1) = 8.0;
  m(1, 2) = 12.0;
  m(2, 0) = 7.0;
  m(2, 1) = 14.0;
  m(2, 2) = 21.0;

  EXPECT_THROW(m.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixTest, IdentityMatrix) {
  S21Matrix m(3, 3);
  m(0, 0) = 1.0;
  m(0, 1) = 0.0;
  m(0, 2) = 0.0;
  m(1, 0) = 0.0;
  m(1, 1) = 1.0;
  m(1, 2) = 0.0;
  m(2, 0) = 0.0;
  m(2, 1) = 0.0;
  m(2, 2) = 1.0;

  S21Matrix inverse = m.InverseMatrix();
  EXPECT_TRUE(inverse.EqMatrix(m));
}

TEST(InverseMatrixTest, NonSquareMatrix) {
  S21Matrix m(2, 3);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(1, 0) = 4.0;
  m(1, 1) = 5.0;
  m(1, 2) = 6.0;

  EXPECT_THROW(m.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixTest, RegularMatrix_3x3) {
  S21Matrix m(3, 3);
  m(0, 0) = 2.0;
  m(0, 1) = 5.0;
  m(0, 2) = 7.0;
  m(1, 0) = 6.0;
  m(1, 1) = 3.0;
  m(1, 2) = 4.0;
  m(2, 0) = 5.0;
  m(2, 1) = -2.0;
  m(2, 2) = -3.0;

  S21Matrix expected(3, 3);
  expected(0, 0) = 1.0;
  expected(0, 1) = -1.0;
  expected(0, 2) = 1.0;
  expected(1, 0) = -38.0;
  expected(1, 1) = 41.0;
  expected(1, 2) = -34.0;
  expected(2, 0) = 27.0;
  expected(2, 1) = -29.0;
  expected(2, 2) = 24.0;

  EXPECT_EQ(m.InverseMatrix(), expected);
}

TEST(InverseMatrixTest, Matrix1x1) {
  S21Matrix m(1, 1);
  m(0, 0) = 5.0;

  S21Matrix expected(1, 1);
  expected(0, 0) = 1.0 / 5.0;

  S21Matrix inverse = m.InverseMatrix();

  EXPECT_TRUE(inverse.EqMatrix(expected));
}
