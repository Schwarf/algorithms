//
// Created by andreas on 10.02.24.
//
#include "gtest/gtest.h"
#include "heaps/sort_characters_by_frequency.h"

TEST(SortCharactersByFrequency, simple1)
{
	const std::string input{"tree"};
	const std::string expected_result{"eert"};
	EXPECT_EQ(expected_result, sort_by_frequencies(input));
}