#include "s21_matrix_test.h"

TEST(MulNumberTest, NormalMultiply) {
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

  double number = 2.0;
  m.MulNumber(number);

  S21Matrix expected(3, 3);
  expected(0, 0) = 2.0;
  expected(0, 1) = 4.0;
  expected(0, 2) = 6.0;
  expected(1, 0) = 8.0;
  expected(1, 1) = 10.0;
  expected(1, 2) = 12.0;
  expected(2, 0) = 14.0;
  expected(2, 1) = 16.0;
  expected(2, 2) = 18.0;

  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(MulNumberTest, NormalMultiply_2) {
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

  double number = -2.5;
  m.MulNumber(number);

  S21Matrix expected(3, 3);
  expected(0, 0) = -2.5;
  expected(0, 1) = -5.0;
  expected(0, 2) = -7.5;
  expected(1, 0) = -10.0;
  expected(1, 1) = -12.5;
  expected(1, 2) = -15.0;
  expected(2, 0) = -17.5;
  expected(2, 1) = -20.0;
  expected(2, 2) = -22.5;

  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(MulNumberTest, MultiplyByZero) {
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

  double number = 0.0;
  m.MulNumber(number);

  S21Matrix expected(3, 3);

  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(MulNumberTest, MultiplyByInf) {
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

  double number = INFINITY;
  m.MulNumber(number);

  S21Matrix expected(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expected(i, j) = INFINITY;
    }
  }

  EXPECT_TRUE(m.EqMatrix(expected));
  EXPECT_NO_THROW(m.MulNumber(INFINITY));
}

TEST(MulNumberTest, MultiplyByNan) {
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

  double number = NAN;
  m.MulNumber(number);

  S21Matrix expected(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expected(i, j) = NAN;
    }
  }

  EXPECT_TRUE(m.EqMatrix(expected));
  EXPECT_NO_THROW(m.MulNumber(NAN));
}
