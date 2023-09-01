//
// Created by andreas on 01.09.23.
//
#include "gtest/gtest.h"
#include "counting_bits.h"

TEST(TestCountingBits, simple1)
{
	constexpr int n{0};
	const std::vector<int> expected_result{0};
	EXPECT_EQ(expected_result, counting_bits(n));
}

TEST(TestCountingBits, simple2)
{
	constexpr int n{2};
	const std::vector<int> expected_result{0, 1, 1};
	EXPECT_EQ(expected_result, counting_bits(n));
}


TEST(TestCountingBits, simple3)
{
	constexpr int n{5};
	const std::vector<int> expected_result{0, 1, 1, 2, 1, 2};
	EXPECT_EQ(expected_result, counting_bits(n));
}


TEST(TestCountingBits, complex1)
{
	constexpr int n{64};
	const std::vector<int> expected_result
		{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2,
		 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1};
	EXPECT_EQ(expected_result, counting_bits(n));
}

TEST(TestCountingBits, complex2)
{
	constexpr int n{127};
	const std::vector<int> expected_result
		{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2,
		 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3,
		 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
		 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7};
	EXPECT_EQ(expected_result, counting_bits(n));
}

