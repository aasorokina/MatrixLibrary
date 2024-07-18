#include "s21_matrix_test.h"

TEST(SetterGetterTest, IncreaseRows) {
  S21Matrix m(2, 3);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(1, 0) = 4.0;
  m(1, 1) = 5.0;
  m(1, 2) = 6.0;

  m.set_rows(4);

  S21Matrix expected(4, 3);
  expected(0, 0) = 1.0;
  expected(0, 1) = 2.0;
  expected(0, 2) = 3.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 5.0;
  expected(1, 2) = 6.0;
  expected(2, 0) = 0.0;
  expected(2, 1) = 0.0;
  expected(2, 2) = 0.0;
  expected(3, 0) = 0.0;
  expected(3, 1) = 0.0;
  expected(3, 2) = 0.0;

  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(SetterGetterTest, DecreaseRows) {
  S21Matrix m(4, 3);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(1, 0) = 4.0;
  m(1, 1) = 5.0;
  m(1, 2) = 6.0;
  m(2, 0) = 7.0;
  m(2, 1) = 8.0;
  m(2, 2) = 9.0;
  m(3, 0) = 10.0;
  m(3, 1) = 11.0;
  m(3, 2) = 12.0;

  m.set_rows(2);

  S21Matrix expected(2, 3);
  expected(0, 0) = 1.0;
  expected(0, 1) = 2.0;
  expected(0, 2) = 3.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 5.0;
  expected(1, 2) = 6.0;

  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(SetterGetterTest, NegativeRows) {
  S21Matrix m(3, 3);

  EXPECT_THROW(m.set_rows(-1), std::out_of_range);
}

TEST(SetterGetterTest, IncreaseColumns) {
  S21Matrix m(3, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;
  m(2, 0) = 5.0;
  m(2, 1) = 6.0;

  m.set_cols(4);

  S21Matrix expected(3, 4);
  expected(0, 0) = 1.0;
  expected(0, 1) = 2.0;
  expected(0, 2) = 0.0;
  expected(0, 3) = 0.0;
  expected(1, 0) = 3.0;
  expected(1, 1) = 4.0;
  expected(1, 2) = 0.0;
  expected(1, 3) = 0.0;
  expected(2, 0) = 5.0;
  expected(2, 1) = 6.0;
  expected(2, 2) = 0.0;
  expected(2, 3) = 0.0;

  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(SetterGetterTest, DecreaseColumns) {
  S21Matrix m(3, 4);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(0, 3) = 4.0;
  m(1, 0) = 5.0;
  m(1, 1) = 6.0;
  m(1, 2) = 7.0;
  m(1, 3) = 8.0;
  m(2, 0) = 9.0;
  m(2, 1) = 10.0;
  m(2, 2) = 11.0;
  m(2, 3) = 12.0;

  m.set_cols(2);

  S21Matrix expected(3, 2);
  expected(0, 0) = 1.0;
  expected(0, 1) = 2.0;
  expected(1, 0) = 5.0;
  expected(1, 1) = 6.0;
  expected(2, 0) = 9.0;
  expected(2, 1) = 10.0;

  EXPECT_TRUE(m.EqMatrix(expected));
}

TEST(SetterGetterTest, NegativeColumns) {
  S21Matrix m(3, 3);

  EXPECT_THROW(m.set_cols(-1), std::out_of_range);
}

TEST(SetterGetterTest, NonEmptyMatrix) {
  S21Matrix m(3, 4);
  EXPECT_EQ(m.get_rows(), 3);
  EXPECT_EQ(m.get_cols(), 4);
}

TEST(SetterGetterTest, ChangeRows) {
  S21Matrix m(2, 3);
  m.set_rows(4);
  EXPECT_EQ(m.get_rows(), 4);
  EXPECT_EQ(m.get_cols(), 3);
}

TEST(SetterGetterTest, ChangeCols) {
  S21Matrix m(3, 2);
  m.set_cols(5);
  EXPECT_EQ(m.get_rows(), 3);
  EXPECT_EQ(m.get_cols(), 5);
}

TEST(SetterGetterTest, SetZeroRowsCols) {
  S21Matrix m(3, 2);
  m.set_cols(0);
  m.set_rows(0);
  EXPECT_EQ(m.get_rows(), 0);
  EXPECT_EQ(m.get_cols(), 0);
}

TEST(MatrixUtilityTest, EqSizes) {
  S21Matrix m1(3, 4);
  S21Matrix m2(3, 4);
  S21Matrix m3(2, 3);

  EXPECT_TRUE(m1.eq_sizes(m2));
  EXPECT_FALSE(m1.eq_sizes(m3));
}

TEST(MatrixUtilityTest, AvailableToMul) {
  S21Matrix m1(3, 4);
  S21Matrix m2(4, 2);
  S21Matrix m3(2, 3);

  EXPECT_TRUE(m1.available_to_mul(m2));
  EXPECT_FALSE(m1.available_to_mul(m3));
}

TEST(MatrixUtilityTest, IsSquare) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 3);

  EXPECT_TRUE(m1.is_square());
  EXPECT_FALSE(m2.is_square());
}