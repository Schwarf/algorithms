//
// Created by andreas on 13.04.23.
//
#include "gtest/gtest.h"
#include "./../find_longest_contiguous_subarray.h"

TEST(FindLongestContigouosSubarray, simple1)
{
	std::vector<int> input{0, 1};
	int expected_result{2};
	EXPECT_EQ(expected_result, find_longest_contiguous_subarray(input));
}

TEST(FindLongestContigouosSubarray, simple2)
{
	std::vector<int> input{1, 0, 1};
	int expected_result{2};
	EXPECT_EQ(expected_result, find_longest_contiguous_subarray(input));
}

TEST(FindLongestContigouosSubarray, simple3)
{
	std::vector<int> input{0, 1, 1, 1, 1, 1, 0, 0, 0};
	int expected_result{6};
	EXPECT_EQ(expected_result, find_longest_contiguous_subarray(input));
}

TEST(FindLongestContigouosSubarray, simple_result_2_again)
{
	std::vector<int> input{0,1,1,1,1,1};
	int expected_result{2};
	EXPECT_EQ(expected_result, find_longest_contiguous_subarray(input));
}

