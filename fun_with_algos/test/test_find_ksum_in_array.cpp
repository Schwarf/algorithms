//
// Created by andreas on 01.03.25.
//
#include "gtest/gtest.h"
#include "find_ksum_in_array.h"

TEST(TestKSumInArray, simple1)
{
    std::vector<int> input{2,4, -2};
    constexpr int k{5};
    constexpr long long expected_result{2};
    EXPECT_EQ(expected_result, find_ksum_in_array(input, k));
}

TEST(TestKSumInArray, simple2)
{
    std::vector<int> input{1,-2,3,4,-10,12};
    constexpr int k{16};
    constexpr long long expected_result{10};
    EXPECT_EQ(expected_result, find_ksum_in_array(input, k));
}