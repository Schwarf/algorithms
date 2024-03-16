//
// Created by andreas on 16.03.24.
//
#include "gtest/gtest.h"
#include "k_radius_subarray_averages.h"

TEST(TestKRadiusSubarrayAveragesPrefixSum, simple1)
{
	const std::vector<int> input{7, 4, 3, 9, 1, 8, 5, 2, 6};
	constexpr int k{3};
	const std::vector<int> expected_result{-1, -1, -1, 5, 4, 4, -1, -1, -1};
	EXPECT_EQ(get_averages_prefix_sum(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesPrefixSum, simple2)
{
	const std::vector<int> input{7, 4, 3, 9, 1, 11, 13, 46, 10, 19, 8, 5, 2, 6};
	constexpr int k{2};
	const std::vector<int> expected_result{-1, -1, 4, 5, 7, 16, 16, 19, 19, 17, 8, 8, -1, -1};
	EXPECT_EQ(get_averages_prefix_sum(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesPrefixSum, simple3)
{
	const std::vector<int> input{7};
	constexpr int k{};
	const std::vector<int> expected_result{7};
	EXPECT_EQ(get_averages_prefix_sum(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesPrefixSum, simple4)
{
	const std::vector<int> input{7, 4, 3, 9};
	constexpr int k{1};
	const std::vector<int> expected_result{-1, 4, 5, -1};
	EXPECT_EQ(get_averages_prefix_sum(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesPrefixSum, simple5)
{
	const std::vector<int> input{7, 4, 3, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	constexpr int k{30};
	const std::vector<int> expected_result(16, -1);
	EXPECT_EQ(get_averages_prefix_sum(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesSlidingWindow, simple1)
{
	const std::vector<int> input{7, 4, 3, 9, 1, 8, 5, 2, 6};
	constexpr int k{3};
	const std::vector<int> expected_result{-1, -1, -1, 5, 4, 4, -1, -1, -1};
	EXPECT_EQ(get_averages_sliding_window(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesSlidingWindow, simple2)
{
	const std::vector<int> input{7, 4, 3, 9, 1, 11, 13, 46, 10, 19, 8, 5, 2, 6};
	constexpr int k{2};
	const std::vector<int> expected_result{-1, -1, 4, 5, 7, 16, 16, 19, 19, 17, 8, 8, -1, -1};
	EXPECT_EQ(get_averages_sliding_window(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesSlidingWindow, simple3)
{
	const std::vector<int> input{7};
	constexpr int k{};
	const std::vector<int> expected_result{7};
	EXPECT_EQ(get_averages_sliding_window(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesSlidingWindow, simple4)
{
	const std::vector<int> input{7, 4, 3, 9};
	constexpr int k{1};
	const std::vector<int> expected_result{-1, 4, 5, -1};
	EXPECT_EQ(get_averages_sliding_window(input, k), expected_result);
}

TEST(TestKRadiusSubarrayAveragesSlidingWindow, simple5)
{
	const std::vector<int> input{7, 4, 3, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	constexpr int k{30};
	const std::vector<int> expected_result(16, -1);
	EXPECT_EQ(get_averages_sliding_window(input, k), expected_result);
}
