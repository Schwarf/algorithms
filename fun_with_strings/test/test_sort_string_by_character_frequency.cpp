//
// Created by andreas on 13.01.24.
//

#include "gtest/gtest.h"
#include "./../sort_string_by_character_frequency.h"

TEST(SortStringByCharacterFrequency, simple1)
{
	const std::string input{"tree"};
	const std::string expected_output{"eetr"};
	EXPECT_EQ(expected_output, sorted_by_character_frequency(input));
}

TEST(SortStringByCharacterFrequency, simple2)
{
	const std::string input{"aaaccc"};
	const std::string expected_output{"cccaaa"};
	EXPECT_EQ(expected_output, sorted_by_character_frequency(input));
}

TEST(SortStringByCharacterFrequency, simple3)
{
	const std::string input{"abbcccdddd"};
	const std::string expected_output{"ddddcccbba"};
	EXPECT_EQ(expected_output, sorted_by_character_frequency(input));
}