//
// Created by andreas on 10.02.24.
//
#include "gtest/gtest.h"
#include "./../count_palindromic_substrings.h"

TEST(TestCountPalindromicSubstringsNoDP, simple1)
{
    const std::string input{"abc"};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, count_palindromic_substrings_no_dynamic_programming(input));
}

TEST(TestCountPalindromicSubstringsNoDP, simple2)
{
    const std::string input{"aaa"};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, count_palindromic_substrings_no_dynamic_programming(input));
}

TEST(TestCountPalindromicSubstringsNoDP, simple3)
{
    const std::string input{"longtimenosee"};
    constexpr int expected_result{14};
    EXPECT_EQ(expected_result, count_palindromic_substrings_no_dynamic_programming(input));
}

TEST(TestCountPalindromicSubstringsNoDP, simple4)
{
    const std::string input{"dnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvg"};
    constexpr int expected_result{77};
    EXPECT_EQ(expected_result, count_palindromic_substrings_no_dynamic_programming(input));
}

TEST(TestCountPalindromicSubstringsNoDP, simple5)
{
    const std::string input{"cuuedxumdolqdytmcudgqmxcwelatcphpvmqqgahbgjklekehgsulsyuhdxaggumsqpktltsytkoo"};
    constexpr int expected_result{84};
    EXPECT_EQ(expected_result, count_palindromic_substrings_no_dynamic_programming(input));
}

TEST(TestCountPalindromicSubstringsNoDP, simple7)
{
    const std::string input{"ttttttttttttttttttttt"};
    constexpr int expected_result{231};
    EXPECT_EQ(expected_result, count_palindromic_substrings_no_dynamic_programming(input));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestCountPalindromicSubstringsWithDP, simple1)
{
    const std::string input{"abc"};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, count_palindromic_substrings_with_dp(input));
}

TEST(TestCountPalindromicSubstringsWithDP, simple2)
{
    const std::string input{"aaa"};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, count_palindromic_substrings_with_dp(input));
}

TEST(TestCountPalindromicSubstringsWithDP, simple3)
{
    const std::string input{"longtimenosee"};
    constexpr int expected_result{14};
    EXPECT_EQ(expected_result, count_palindromic_substrings_with_dp(input));
}

TEST(TestCountPalindromicSubstringsWithDP, simple4)
{
    const std::string input{"dnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvg"};
    constexpr int expected_result{77};
    EXPECT_EQ(expected_result, count_palindromic_substrings_with_dp(input));
}

TEST(TestCountPalindromicSubstringsWithDP, simple5)
{
    const std::string input{"cuuedxumdolqdytmcudgqmxcwelatcphpvmqqgahbgjklekehgsulsyuhdxaggumsqpktltsytkoo"};
    constexpr int expected_result{84};
    EXPECT_EQ(expected_result, count_palindromic_substrings_with_dp(input));
}

TEST(TestCountPalindromicSubstringsWithDP, simple6)
{
    const std::string input{"ttttttttttttttttttttt"};
    constexpr int expected_result{231};
    EXPECT_EQ(expected_result, count_palindromic_substrings_with_dp(input));
}
