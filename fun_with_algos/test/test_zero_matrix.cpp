//
// Created by andreas on 14.06.25.
//
#include "gtest/gtest.h"
#include "./../zero_matrix.h"

TEST(TestZeroMatrix, simple1)
{
    std::vector<std::vector<int>> matrix{{1, 0}, {1, 1}};
    std::vector<std::vector<int>> expected_result{{0, 0}, {1, 0}};
    EXPECT_NE(expected_result, matrix);
    zero_matrix(matrix);
    EXPECT_EQ(expected_result, matrix);
}

TEST(TestZeroMatrix, simple2)
{
    std::vector<std::vector<int>> matrix{{1}};
    std::vector<std::vector<int>> expected_result{{1}};
    zero_matrix(matrix);
    EXPECT_EQ(expected_result, matrix);
}

TEST(TestZeroMatrix, simple3)
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> expected_result = matrix;
    zero_matrix(matrix);
    EXPECT_EQ(matrix, expected_result);
}

TEST(ZeroMatrixTest, simple4)
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> expected_result = {
        {1, 0, 3},
        {0, 0, 0},
        {7, 0, 9}
    };
    zero_matrix(matrix);
    EXPECT_EQ(matrix, expected_result);
}
