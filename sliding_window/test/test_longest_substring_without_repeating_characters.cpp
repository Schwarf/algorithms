//
// Created by andreas on 12.01.24.
//

#include "gtest/gtest.h"
#include "longest_substring_without_repeating_characters.h"

TEST(TestLongestSubstringWithoutRepeatingCharacters, simple1)
{
	const std::string input{"acabnhjkbahb"};
	constexpr int expected_result{7};
	EXPECT_EQ(expected_result, longest_substring_without_repeating_character(input));
}

TEST(TestLongestSubstringWithoutRepeatingCharacters, simple2)
{
const std::string input{"bbbbb"};
constexpr int expected_result{1};
EXPECT_EQ(expected_result, longest_substring_without_repeating_character(input));
}

TEST(TestLongestSubstringWithoutRepeatingCharacters, simple3)
{
	const std::string input{""};
	constexpr int expected_result{0};
	EXPECT_EQ(expected_result, longest_substring_without_repeating_character(input));
}

TEST(TestLongestSubstringWithoutRepeatingCharacters, simple4)
{
	const std::string input{"pwwkew"};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, longest_substring_without_repeating_character(input));
}

TEST(TestLongestSubstringWithoutRepeatingCharacters, simple5)
{
	const std::string input{"aab"};
	constexpr int expected_result{2};
	EXPECT_EQ(expected_result, longest_substring_without_repeating_character(input));
}