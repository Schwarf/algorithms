//
// Created by andreas on 14.03.24.
//
#include "gtest/gtest.h"
#include "./../count_subarrays_with_target.h"

TEST(TestCountSubArraysWithTarget, simple1)
{
	const std::vector<int> input{1, 0, 1, 0, 1};
	constexpr int target{2};
	constexpr int expected_result{4};
	EXPECT_EQ(expected_result, count_subarrays_with_target(input, target));
}

TEST(TestCountSubArraysWithTarget, simple2)
{
	const std::vector<int> input{0, 0, 0, 0, 0};
	constexpr int target{0};
	constexpr int expected_result{15};
	EXPECT_EQ(expected_result, count_subarrays_with_target(input, target));
}

TEST(TestCountSubArraysWithTarget, simple3)
{
	const std::vector<int> input{1, 1, 1, 1, 1};
	constexpr int target{3};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, count_subarrays_with_target(input, target));
}

TEST(TestCountSubArraysWithTarget, simple4)
{
	const std::vector<int> input{1, 1, 1, 1, 1};
	constexpr int target{2};
	constexpr int expected_result{4};
	EXPECT_EQ(expected_result, count_subarrays_with_target(input, target));
}

TEST(TestCountSubArraysWithTarget, simple5)
{
	const std::vector<int> input{1, 1, 1, 1, 1};
	constexpr int target{1};
	constexpr int expected_result{5};
	EXPECT_EQ(expected_result, count_subarrays_with_target(input, target));
}


TEST(TestCountSubArraysWithTarget, medium1)
{
	const std::vector<int> input{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	constexpr int target{0};
	constexpr int expected_result{67};
	EXPECT_EQ(expected_result, count_subarrays_with_target(input, target));
}

TEST(TestCountSubArraysWithTarget, medium2)
{
	const std::vector<int> input{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	constexpr int target{1};
	constexpr int expected_result{59};
	EXPECT_EQ(expected_result, count_subarrays_with_target(input, target));
}

TEST(TestCountSubArraysWithTarget, medium3)
{
	const std::vector<int> input{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	constexpr int target{0};
	constexpr int expected_result{325};
	EXPECT_EQ(expected_result, count_subarrays_with_target(input, target));
}

