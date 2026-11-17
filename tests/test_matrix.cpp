#include <gtest/gtest.h>
#include "matrix.h"
#include <stdexcept>

TEST(MatrixTest, CreateMatrix_NormalCase) {
    Matrix A = create_matrix(3, 4);
    EXPECT_EQ(A.rows, 3);
    EXPECT_EQ(A.cols, 4);
    EXPECT_NE(A.data, nullptr);
    free_matrix(A);
}

TEST(MatrixTest, Addition_NormalCase) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[1][0] = 3; A.data[1][1] = 4;
    B.data[0][0] = 5; B.data[0][1] = 6; B.data[1][0] = 7; B.data[1][1] = 8;
    Matrix C = matrix_add(A, B);
    EXPECT_DOUBLE_EQ(C.data[0][0], 6.0);
    EXPECT_DOUBLE_EQ(C.data[1][1], 12.0);
    free_matrix(A); free_matrix(B); free_matrix(C);
}

TEST(MatrixTest, CreateMatrix_ZeroRows) {
    EXPECT_THROW(create_matrix(0, 3), std::invalid_argument);
}

TEST(MatrixTest, Addition_SizeMismatch) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3);
    EXPECT_THROW(matrix_add(A, B), std::invalid_argument);
    free_matrix(A); free_matrix(B);
}

TEST(MatrixTest, Compare_Task27) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[1][0] = 3; A.data[1][1] = 4;
    B.data[0][0] = 1; B.data[0][1] = 5; B.data[1][0] = 3; B.data[1][1] = 4;
    
    testing::internal::CaptureStdout();
    matrix_compare(A, B);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Element [0][1]: 2 (A) != 5 (B)"), std::string::npos);
    free_matrix(A); free_matrix(B);
}
