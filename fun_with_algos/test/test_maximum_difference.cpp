//
// Created by andreas on 16.06.25.
//
#include "gtest/gtest.h"
#include "./../maximum_difference.h"

TEST(TestMaximumDifference, simple1)
{
    std::vector<int> input{7, 1, 5, 4};
    constexpr int expected_result{4};
    EXPECT_EQ(maximum_difference(input), expected_result);
}

TEST(TestMaximumDifference, simple2)
{
    std::vector<int> input{9, 4, 3, 2};
    constexpr int expected_result{-1};
    EXPECT_EQ(maximum_difference(input), expected_result);
}

TEST(TestMaximumDifference, simple3)
{
    std::vector<int> input{1, 5, 2, 10};
    constexpr int expected_result{9};
    EXPECT_EQ(maximum_difference(input), expected_result);
}
