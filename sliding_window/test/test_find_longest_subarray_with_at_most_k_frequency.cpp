//
// Created by andreas on 28.03.24.
//
#include "gtest/gtest.h"
#include "find_longest_subarray_with_at_most_k_frequency.h"

TEST(TestFindLongestSubArray, simple1)
{
	const std::vector<int> input{1, 2, 3, 1, 2, 3, 1, 2};
	constexpr int max_frequency{2};
	constexpr int expected_result{6};
	EXPECT_EQ(max_subarray_length(input, max_frequency), expected_result);
}

TEST(TestFindLongestSubArray, simple2)
{
	const std::vector<int> input{1, 2, 1, 2, 1, 2, 1, 2};
	constexpr int max_frequency{1};
	constexpr int expected_result{2};
	EXPECT_EQ(max_subarray_length(input, max_frequency), expected_result);
}

TEST(TestFindLongestSubArray, simple3)
{
	const std::vector<int> input{1, 2, 1, 2, 1, 2, 1, 2};
	constexpr int max_frequency{4};
	constexpr int expected_result{8};
	EXPECT_EQ(max_subarray_length(input, max_frequency), expected_result);
}

TEST(TestFindLongestSubArray, simple4)
{
	const std::vector<int> input{5, 5, 5, 5, 5, 5};
	constexpr int max_frequency{4};
	constexpr int expected_result{4};
	EXPECT_EQ(max_subarray_length(input, max_frequency), expected_result);
}


TEST(TestFindLongestSubArray, simple5)
{
	const std::vector<int> input
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	constexpr int max_frequency{10};
	constexpr int expected_result{10};
	EXPECT_EQ(max_subarray_length(input, max_frequency), expected_result);
}
