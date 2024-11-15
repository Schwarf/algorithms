//
// Created by andreas on 13.01.24.
//

#include "gtest/gtest.h"
#include "./../sort_string_by_character_frequency.h"

bool has_same_character_frequencies(const std::string &input, const std::string &output) {
	std::unordered_map<char, int> input_freq, output_freq;
	for (char c : input) input_freq[c]++;
	for (char c : output) output_freq[c]++;
	return input_freq == output_freq;
}

TEST(SortStringByCharacterFrequency, simple1)
{
	const std::string input{"tree"};
	const std::string output = sorted_by_character_frequency(input);
	EXPECT_TRUE(has_same_character_frequencies(input, output));
	EXPECT_EQ(output.size(), input.size());
}

TEST(SortStringByCharacterFrequency, simple2)
{
	const std::string input{"aaaccc"};
	const std::string output = sorted_by_character_frequency(input);
	EXPECT_TRUE(has_same_character_frequencies(input, output));
	EXPECT_EQ(output.size(), input.size());
}

TEST(SortStringByCharacterFrequency, simple3)
{
	const std::string input{"abbcccdddd"};
	const std::string output = sorted_by_character_frequency(input);
	EXPECT_TRUE(has_same_character_frequencies(input, output));
	EXPECT_EQ(output.size(), input.size());
	}
