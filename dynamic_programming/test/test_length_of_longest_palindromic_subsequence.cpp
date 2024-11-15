//
// Created by andreas on 14.04.23.
//
#include "gtest/gtest.h"
#include "length_of_longest_palindromic_subsequence.h"

TEST(LengthOfLongestPalindromicSubsequence, short1)
{
    std::string input{"bbac"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence(input));
}

TEST(LengthOfLongestPalindromicSubsequence, short2)
{
    std::string input{"abbac"};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence(input));
}

TEST(LengthOfLongestPalindromicSubsequence, short3)
{
    std::string input{"abbacbba"};
    constexpr int expected_result{7};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence(input));
}

TEST(LengthOfLongestPalindromicSubsequence, medium1)
{
    std::string input{"0abcdecba0"};
    constexpr int expected_result{9};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence(input));
}

TEST(LengthOfLongestPalindromicSubsequence, medium2)
{
    std::string input{"jjk0abcd1234567890ecba0hlpkiopj00j"};
    constexpr int expected_result{15};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence(input));
}


TEST(LengthOfLongestPalindromicSubsequence, long1)
{
    std::string input
    {
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
    };
    constexpr int expected_result{494};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence(input));
}


TEST(LengthOfLongestPalindromicSubsequenceBottomUp, short1)
{
    std::string input{"bbac"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUp, short2)
{
    std::string input{"abbac"};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUp, short3)
{
    std::string input{"abbacbba"};
    constexpr int expected_result{7};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUp, medium1)
{
    std::string input{"0abcdecba0"};
    constexpr int expected_result{9};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUp, medium2)
{
    std::string input{"jjk0abcd1234567890ecba0hlpkiopj00j"};
    constexpr int expected_result{15};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUp, long1)
{
    std::string input
    {
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
    };
    constexpr int expected_result{494};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up(input));
}


TEST(LengthOfLongestPalindromicSubsequenceBottomUpLessMemory, short1)
{
    std::string input{"bbac"};
    int expected_result{2};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up_less_memory(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUpLessMemory, short2)
{
    std::string input{"abbac"};
    int expected_result{4};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up_less_memory(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUpLessMemory, short3)
{
    std::string input{"abbacbba"};
    int expected_result{7};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up_less_memory(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUpLessMemory, long1)
{
    std::string input
    {
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
    };
    int expected_result{494};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up_less_memory(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUpLessMemory, medium1)
{
    std::string input{"0abcdecba0"};
    int expected_result{9};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up_less_memory(input));
}

TEST(LengthOfLongestPalindromicSubsequenceBottomUpLessMemory, medium2)
{
    std::string input{"jjk0abcd1234567890ecba0hlpkiopj00j"};
    int expected_result{15};
    EXPECT_EQ(expected_result, length_of_longest_palindromic_subsequence_bottom_up_less_memory(input));
}
