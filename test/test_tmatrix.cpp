#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length) {
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix) {
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length) {
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix) {
  TMatrix<int> m(5);
  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) {
  TMatrix<int> v(10);
  TMatrix<int> v1(v);
  EXPECT_EQ(v, v1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory) {
  TMatrix<int> v(10);
  TMatrix<int> v1(v);
  EXPECT_NE(&v, &v1);
}

TEST(TMatrix, can_get_size) {
  TMatrix<int> v(4);
  EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element) {
  TMatrix<int> mv(4);
  mv[1][1] = 10;
  EXPECT_EQ(10, mv[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index) {
  TMatrix<int> mv(5);
  ASSERT_ANY_THROW(mv[-5][0] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index) {
  TMatrix<int> mv(5);
  ASSERT_ANY_THROW(mv[10][0] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself) {
  TMatrix<int> mv(4);
  ASSERT_NO_THROW(mv = mv);
}


TEST(TMatrix, can_assign_matrices_of_equal_size) {
  TMatrix<int> mv(3);
  TMatrix<int> mv1(3);
  ASSERT_NO_THROW(mv = mv1);
}


TEST(TMatrix, assign_operator_change_matrix_size) {
  TMatrix<int> mv(10);
  TMatrix<int> mv1(20);
  mv1 = mv;
  EXPECT_EQ(mv1.GetSize(), 10);
}

TEST(TMatrix, can_assign_matrices_of_different_size) {
  TMatrix<int> mv(10);
  TMatrix<int> mv1(20);
  ASSERT_NO_THROW(mv1 = mv);
}

TEST(TMatrix, compare_equal_matrices_return_true) {
  TMatrix<int> mv(5);
  TMatrix<int> mv1(mv);
  EXPECT_TRUE(mv == mv1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true) {
  TMatrix<int> mv(5);
  EXPECT_TRUE(mv == mv);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal) {
  TMatrix<int> mv(10);
  TMatrix<int> mv1(15);
  EXPECT_FALSE(mv == mv1);
}

TEST(TMatrix, can_add_matrices_with_equal_size) {
  TMatrix<int> mv(10);
  TMatrix<int> mv1(10);
  ASSERT_NO_THROW(mv + mv1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size) {
  TMatrix<int> mv(10);
  TMatrix<int> mv1(15);
  ASSERT_ANY_THROW(mv + mv1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size) {
  TMatrix<int> mv1(15);
  TMatrix<int> mv2(15);
  ASSERT_NO_THROW(mv1 - mv2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size) {
  TMatrix<int> mv1(15);
  TMatrix<int> mv2(10);
  ASSERT_ANY_THROW(mv1 - mv2);
}
