//
// Created by andreas on 13.04.23.
//
#include "gtest/gtest.h"
#include "minimal_operations_to_get_zero.h"

TEST(MinimalOperationsToGetZero, simple1)
{
    std::vector<int> input{1, 1, 4, 2, 3};
    int target{5};
    int expected_result{2};
    EXPECT_EQ(expected_result, minimal_operations_to_get_zero(input, target));
}

TEST(MinimalOperationsToGetZero, simple2)
{
    std::vector<int> input{5, 6, 7, 8, 9};
    int target{4};
    int expected_result{-1};
    EXPECT_EQ(expected_result, minimal_operations_to_get_zero(input, target));
}

TEST(MinimalOperationsToGetZero, simple3)
{
    std::vector<int> input{3, 2, 20, 1, 1, 3};
    int target{10};
    int expected_result{5};
    EXPECT_EQ(expected_result, minimal_operations_to_get_zero(input, target));
}
