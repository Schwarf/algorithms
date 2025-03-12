//
// Created by andreas on 12.03.25.
//
#include "./../min_swaps_for_palindrome.h"
#include "gtest/gtest.h"

TEST(TestMinSwapsForPalindrome, simple1)
{
    std::vector<int> input = {1, 0, 1, 0};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, min_swaps_for_palindrome(input));
}

TEST(TestMinSwapsForPalindrome, simple2)
{
    std::vector<int> input = {1, 0, 1, 0, 0, 0, 0};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, min_swaps_for_palindrome(input));
}

TEST(TestMinSwapsForPalindrome, simple3)
{
    std::vector<int> input = {1, 1, 1, 0, 0, 0, 0};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, min_swaps_for_palindrome(input));
}

TEST(TestMinSwapsForPalindrome, simple4)
{
    std::vector<int> input = {0, 0, 0, 0};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, min_swaps_for_palindrome(input));
}
