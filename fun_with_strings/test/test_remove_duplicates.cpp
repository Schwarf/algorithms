//
// Created by andreas on 26.09.23.
//
#include "gtest/gtest.h"
#include "./../remove_duplicate_letters.h"
TEST(TestRemoveDuplicates, simple1)
{
	const std::string input{"bcabc"};
	const std::string expected_output{"abc"};
	EXPECT_EQ(remove_duplicate_letters(input), expected_output);
}