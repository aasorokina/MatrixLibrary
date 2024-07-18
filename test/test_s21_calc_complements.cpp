#include "s21_matrix_test.h"

TEST(CalcComplementsTest, NonSquareMatrix) {
  S21Matrix m(2, 3);
  ASSERT_THROW(m.CalcComplements(), std::invalid_argument);
}

TEST(CalcComplementsTest, SquareMatrix_2x2) {
  S21Matrix m(2, 2);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;

  S21Matrix expected(2, 2);
  expected(0, 0) = 4;
  expected(0, 1) = -3;
  expected(1, 0) = -2;
  expected(1, 1) = 1;

  ASSERT_EQ(m.CalcComplements(), expected);
}

TEST(CalcComplementsTest, SquareMatrix_2x2_2) {
  S21Matrix m(2, 2);
  m(0, 0) = 0.0;
  m(0, 1) = 2.5;
  m(1, 0) = -3.7;
  m(1, 1) = 0.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 0.0;
  expected(0, 1) = 3.7;
  expected(1, 0) = -2.5;
  expected(1, 1) = 0.0;

  S21Matrix result = m.CalcComplements();
  EXPECT_EQ(result, expected);
}

TEST(CalcComplementsTest, SquareMatrix_3x3) {
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

  S21Matrix expected(3, 3);
  expected(0, 0) = -3;
  expected(0, 1) = 6;
  expected(0, 2) = -3;
  expected(1, 0) = 6;
  expected(1, 1) = -12;
  expected(1, 2) = 6;
  expected(2, 0) = -3;
  expected(2, 1) = 6;
  expected(2, 2) = -3;

  ASSERT_EQ(m.CalcComplements(), expected);
}

TEST(CalcComplementsTest, SquareMatrix_3x3_2) {
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

  S21Matrix expected(3, 3);
  expected(0, 0) = -0.34;
  expected(0, 1) = 11.23;
  expected(0, 2) = 10.56;
  expected(1, 0) = -2.14;
  expected(1, 1) = -11.18;
  expected(1, 2) = -8.43;
  expected(2, 0) = 1.55;
  expected(2, 1) = 3.67;
  expected(2, 2) = 2.37;

  S21Matrix result = m.CalcComplements();
  EXPECT_EQ(result, expected);
}

TEST(CalcComplementsTest, Matrix_0x0) {
  S21Matrix m(0, 0);
  EXPECT_NO_THROW(m.CalcComplements());
}

TEST(CalcComplementsTest, Matrix_1x1) {
  S21Matrix m(1, 1);
  m(0, 0) = 5.0;
  S21Matrix expected(1, 1);
  expected(0, 0) = 1;
  EXPECT_NO_THROW(m.CalcComplements());
  EXPECT_EQ(m.CalcComplements(), expected);
}