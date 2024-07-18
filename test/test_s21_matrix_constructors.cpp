#include "s21_matrix_test.h"

TEST(ConstructorTest, DefaultConstructor) {
  S21Matrix m;
  EXPECT_EQ(m.get_rows(), 0);
  EXPECT_EQ(m.get_cols(), 0);
}

TEST(ConstructorTest, ParameterizedConstructor) {
  S21Matrix m(2, 4);
  EXPECT_EQ(m.get_rows(), 2);
  EXPECT_EQ(m.get_cols(), 4);
}

TEST(ConstructorTest, ParameterizedConstructorNegative) {
  EXPECT_THROW(S21Matrix(-1, 2), std::invalid_argument);
  EXPECT_THROW(S21Matrix(2, -1), std::invalid_argument);
  EXPECT_THROW(S21Matrix(-1, -1), std::invalid_argument);
}

TEST(ConstructorTest, CopyConstructor) {
  S21Matrix m1(2, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;

  S21Matrix m2(m1);
  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(ConstructorTest, MoveConstructor) {
  S21Matrix m1(2, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;

  S21Matrix m2(std::move(m1));
  EXPECT_EQ(m1.get_rows(), 0);
  EXPECT_EQ(m1.get_cols(), 0);
  EXPECT_EQ(m2.get_rows(), 2);
  EXPECT_EQ(m2.get_cols(), 3);
}