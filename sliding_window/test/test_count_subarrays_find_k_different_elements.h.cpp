//
// Created by andreas on 30.03.24.
//
#include "gtest/gtest.h"
#include "./../count_subarrays_with_exactly_k_different_elements.h"

TEST(TestCountSubArraysWIthExactlyKDifferentElements, simple1)
{
	const std::vector<unsigned int> input{1U, 2U, 1U, 2U, 3U};
	constexpr int k{2};
	constexpr int expected_result{7};
	EXPECT_EQ(count_subarrays_with_exactly_k_different_elements(input, k), expected_result);
}

TEST(TestCountSubArraysWIthExactlyKDifferentElements, simple2)
{
	const std::vector<unsigned short> input{1U, 2U, 1U, 2U, 3U};
	constexpr int k{1};
	constexpr int expected_result{5};
	EXPECT_EQ(count_subarrays_with_exactly_k_different_elements(input, k), expected_result);
}


TEST(TestCountSubArraysWIthExactlyKDifferentElements, simple3)
{
	const std::vector<int> input{1, 2, 1, 3, 4};
	constexpr int k{3};
	constexpr int expected_result{3};
	EXPECT_EQ(count_subarrays_with_exactly_k_different_elements(input, k), expected_result);
}

TEST(TestCountSubArraysWIthExactlyKDifferentElements, medium1)
{
	const std::vector<int> input{5, 7, 5, 2, 3, 3, 4, 1, 5, 2, 7, 4, 6, 6, 3, 3, 4, 4, 7};
	constexpr int k{7};
	constexpr int expected_result{52};
	EXPECT_EQ(count_subarrays_with_exactly_k_different_elements(input, k), expected_result);
}

TEST(TestCountSubArraysWIthExactlyKDifferentElements, medium2)
{
	const std::vector<int> input
		{27, 27, 43, 28, 11, 20, 1, 4, 49, 18, 37, 31, 31, 7, 3, 31, 50, 6, 50, 46, 4, 13, 31, 49, 15, 52, 25, 31, 35,
		 4, 11, 50, 40, 1, 49, 14, 46, 16, 11, 16, 39, 26, 13, 4, 37, 39, 46, 27, 49, 39, 49, 50, 37, 9, 30, 45, 51, 47,
		 18, 49, 24, 24, 46, 47, 18, 46, 52, 47, 50, 4, 39, 22, 50, 40, 3, 52, 24, 50, 38, 30, 14, 12, 1, 5, 52, 44, 3,
		 49, 45, 37, 40, 35, 50, 50, 23, 32, 1, 2};
	constexpr int k{20};
	constexpr int expected_result{149};
	EXPECT_EQ(count_subarrays_with_exactly_k_different_elements(input, k), expected_result);
}