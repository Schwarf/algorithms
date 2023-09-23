//
// Created by andreas on 23.09.23.
//
#include "gtest/gtest.h"
#include "longest_string_chain.h"
TEST(TestLongestStringChain, simple1)
{
	std::vector<std::string> words{"a", "b", "ba", "bca", "bda", "bdca"};
	constexpr int expected_result{4};
	EXPECT_EQ(expected_result, longest_string_chain(words));
}