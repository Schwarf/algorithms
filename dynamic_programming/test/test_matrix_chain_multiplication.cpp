//
// Created by andreas on 24.06.24.
//

#include "gtest/gtest.h"
#include "./../matrix_chain_multiplication.h"

TEST(TestMatrixChainMultiplication, simple1)
{
    std::vector<int> dimensions{40, 20, 30, 10, 30};
    constexpr int expected_answer{26000};
    EXPECT_EQ(minimal_matrix_chain_multiplications(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplication, simple2)
{
    std::vector<int> dimensions{10, 100, 5, 50};
    constexpr int expected_answer{7500};
    EXPECT_EQ(minimal_matrix_chain_multiplications(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplication, simple3)
{
    std::vector<int> dimensions{10, 20, 30};
    constexpr int expected_answer{6000};
    EXPECT_EQ(minimal_matrix_chain_multiplications(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplication, simple4)
{
    std::vector<int> dimensions{1, 2, 3, 4, 3};
    constexpr int expected_answer{30};
    EXPECT_EQ(minimal_matrix_chain_multiplications(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplicationTopDown, simple1)
{
    std::vector<int> dimensions{40, 20, 30, 10, 30};
    constexpr int expected_answer{26000};
    EXPECT_EQ(top_down_approach(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplicationTopDown, simple2)
{
    std::vector<int> dimensions{10, 100, 5, 50};
    constexpr int expected_answer{7500};
    EXPECT_EQ(top_down_approach(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplicationTopDown, simple3)
{
    std::vector<int> dimensions{10, 20, 30};
    constexpr int expected_answer{6000};
    EXPECT_EQ(top_down_approach(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplicationTopDown, simple4)
{
    std::vector<int> dimensions{1, 2, 3, 4, 3};
    constexpr int expected_answer{30};
    EXPECT_EQ(top_down_approach(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplicationTopDown, medium1)
{
    std::vector<int> dimensions{30, 35, 15, 5, 10, 20, 25, 30, 45, 50, 5};
    constexpr int expected_answer{33750};
    EXPECT_EQ(minimal_matrix_chain_multiplications(dimensions), expected_answer);
}

TEST(TestMatrixChainMultiplicationBottomUp, medium1)
{
    std::vector<int> dimensions{30, 35, 15, 5, 10, 20, 25, 30, 45, 50, 5};
    constexpr int expected_answer{33750};
    EXPECT_EQ(bottom_up_approach(dimensions), expected_answer);
}
