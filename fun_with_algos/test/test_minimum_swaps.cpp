//
// Created by andreas on 12.03.25.
//
#include "./../minimum_swaps.h"
#include "gtest/gtest.h"

TEST(minimum_swaps, simple1)
{
    std::vector<int> input = {9, 10, 1, 3, 2};
    constexpr int expected_result{4};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

TEST(minimum_swaps, simple2)
{
    std::vector<int> input = {9, 1, 10, 3, 2};
    constexpr int expected_result{3};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

TEST(minimum_swaps, simple3)
{
    std::vector<int> input = {5, 3, 1};
    constexpr int expected_result{3};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}
