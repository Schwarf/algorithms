//
// Created by andreas on 27.01.24.
//
#include "gtest/gtest.h"
#include "./../knuth_morris_pratt_algo.h"

TEST(TestKnuthMorriPratt, simple1)
{
	const std::string input{"ABABDABABCABABCABAB"};
	const std::string pattern{"ABABCABAB"};
	const std::vector<int> expected_result{5, 10};
	EXPECT_EQ(expected_result, find_start_indices_of_pattern(input, pattern));
}

TEST(TestKnuthMorriPratt, simple2)
{
	const std::string input{"hello world"};
	const std::string pattern{"world"};
	const std::vector<int> expected_result{6};
	EXPECT_EQ(expected_result, find_start_indices_of_pattern(input, pattern));
	const std::vector<int> expected_result2{0};
	const std::string pattern2{"hello"};
	EXPECT_EQ(expected_result2, find_start_indices_of_pattern(input, pattern2));
}

TEST(TestKnuthMorriPratt, simple3)
{
	const std::string input{"aaaaaa"};
	const std::string pattern{"aaa"};
	const std::vector<int> expected_result{0, 1, 2, 3};
	EXPECT_EQ(expected_result, find_start_indices_of_pattern(input, pattern));
}
