#include "s21_matrix_test.h"

TEST(OperatorTest, Sum) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 6.0;
  expected(0, 1) = 8.0;
  expected(1, 0) = 10.0;
  expected(1, 1) = 12.0;

  S21Matrix result = m1 + m2;
  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorTest, Subtraction) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = -4.0;
  expected(0, 1) = -4.0;
  expected(1, 0) = -4.0;
  expected(1, 1) = -4.0;

  S21Matrix result = m1 - m2;
  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorTest, MultiplicationMatrix) {
  S21Matrix m1(2, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;

  S21Matrix m2(3, 2);
  m2(0, 0) = 7.0;
  m2(0, 1) = 8.0;
  m2(1, 0) = 9.0;
  m2(1, 1) = 10.0;
  m2(2, 0) = 11.0;
  m2(2, 1) = 12.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 58.0;
  expected(0, 1) = 64.0;
  expected(1, 0) = 139.0;
  expected(1, 1) = 154.0;

  S21Matrix result = m1 * m2;
  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorTest, MultiplicationNumber) {
  S21Matrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  double number = 2.5;

  S21Matrix expected(2, 2);
  expected(0, 0) = 2.5;
  expected(0, 1) = 5.0;
  expected(1, 0) = 7.5;
  expected(1, 1) = 10.0;

  S21Matrix result = m * number;
  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorTest, EqualityOperator) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2(2, 2);
  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(1, 0) = 3.0;
  m2(1, 1) = 4.0;

  S21Matrix m3(2, 2);
  m3(0, 0) = 5.0;
  m3(0, 1) = 6.0;
  m3(1, 0) = 7.0;
  m3(1, 1) = 8.0;

  EXPECT_TRUE(m1 == m2);
  EXPECT_FALSE(m1 == m3);
}

TEST(OperatorTest, AssignmentOperator) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2(3, 3);
  m2 = m1;

  EXPECT_EQ(m2.get_rows(), 2);
  EXPECT_EQ(m2.get_cols(), 2);
  EXPECT_TRUE(m1 == m2);
}

TEST(OperatorTest, SelfAssignment) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2 = m1;
  m1 = m1;

  EXPECT_TRUE(m1 == m2);
}

TEST(OperatorTest, AdditionAssignment) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 6.0;
  expected(0, 1) = 8.0;
  expected(1, 0) = 10.0;
  expected(1, 1) = 12.0;

  m1 += m2;
  EXPECT_TRUE(m1.EqMatrix(expected));
}

TEST(OperatorTest, SubtractionAssignment) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = -4.0;
  expected(0, 1) = -4.0;
  expected(1, 0) = -4.0;
  expected(1, 1) = -4.0;

  m1 -= m2;
  EXPECT_TRUE(m1.EqMatrix(expected));
}

TEST(OperatorTest, MatrixMultiplicationAssignment) {
  S21Matrix m1(2, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;

  S21Matrix m2(3, 2);
  m2(0, 0) = 7.0;
  m2(0, 1) = 8.0;
  m2(1, 0) = 9.0;
  m2(1, 1) = 10.0;
  m2(2, 0) = 11.0;
  m2(2, 1) = 12.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 58.0;
  expected(0, 1) = 64.0;
  expected(1, 0) = 139.0;
  expected(1, 1) = 154.0;

  m1 *= m2;
  EXPECT_TRUE(m1.EqMatrix(expected));
}

TEST(OperatorTest, NumberMultiplicationAssignment) {
  S21Matrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  double number = 2.5;

  S21Matrix expected(2, 2);
  expected(0, 0) = 2.5;
  expected(0, 1) = 5.0;
  expected(1, 0) = 7.5;
  expected(1, 1) = 10.0;

  m *= number;
  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(OperatorTest, AccessElement) {
  S21Matrix m(2, 3);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(1, 0) = 4.0;
  m(1, 1) = 5.0;
  m(1, 2) = 6.0;

  EXPECT_EQ(m(0, 0), 1.0);
  EXPECT_EQ(m(0, 1), 2.0);
  EXPECT_EQ(m(0, 2), 3.0);
  EXPECT_EQ(m(1, 0), 4.0);
  EXPECT_EQ(m(1, 1), 5.0);
  EXPECT_EQ(m(1, 2), 6.0);
}

TEST(OperatorTest, ModifyElement) {
  S21Matrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  m(0, 0) = 10.0;
  m(1, 1) = 20.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 10.0;
  expected(0, 1) = 2.0;
  expected(1, 0) = 3.0;
  expected(1, 1) = 20.0;

  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(OperatorTest, OutOfRangeRow) {
  S21Matrix m(2, 2);
  EXPECT_THROW(m(2, 0), std::out_of_range);
  EXPECT_THROW(m(-1, 0), std::out_of_range);
}

TEST(OperatorTest, OutOfRangeColumn) {
  S21Matrix m(2, 2);
  EXPECT_THROW(m(0, 2), std::out_of_range);
  EXPECT_THROW(m(0, -1), std::out_of_range);
}
