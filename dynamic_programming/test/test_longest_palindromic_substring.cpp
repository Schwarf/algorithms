//
// Created by andreas on 09.07.23.
//

#include "gtest/gtest.h"
#include "longest_palindromic_substring.h"

TEST(LongestPalindromicSubstring, simple1_tabulation)
{
    const std::string input_string{"babad"};
    const std::string expected_result1{"bab"};
    const std::string expected_result2{"aba"};
    EXPECT_TRUE(expected_result1 == longest_palindromic_substring_with_tabulation(input_string)
        || expected_result2 == longest_palindromic_substring_with_tabulation(input_string));
}

TEST(LongestPalindromicSubstring, simple2_tabulation)
{
    const std::string input_string{"cbbd"};
    const std::string expected_result{"bb"};
    EXPECT_EQ(expected_result, longest_palindromic_substring_with_tabulation(input_string));
}

TEST(LongestPalindromicSubstring, simple3_tabulation)
{
    const std::string input_string{"cbbdabbabba"};
    const std::string expected_result{"abbabba"};
    EXPECT_EQ(expected_result, longest_palindromic_substring_with_tabulation(input_string));
}

TEST(LongestPalindromicSubstring, simple4_tabulation)
{
    const std::string input_string{"cbbdabbabbabttttttttttttttttttttttttttttt"};
    const std::string expected_result{"ttttttttttttttttttttttttttttt"};
    EXPECT_EQ(expected_result, longest_palindromic_substring_with_tabulation(input_string));
}


TEST(LongestPalindromicSubstring, simple5_tabulation)
{
    const std::string input_string{"12"};
    const std::string expected_result1{"1"};
    const std::string expected_result2{"2"};
    EXPECT_TRUE(expected_result1 == longest_palindromic_substring_with_tabulation(input_string) ||
        expected_result2 == longest_palindromic_substring_with_tabulation(input_string));
}
