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
	const std::vector<int> expected_result{0,1,1};
	EXPECT_EQ(expected_result, counting_bits(n));
}

TEST(TestCountingBits, simple3)
{
	constexpr int n{5};
	const std::vector<int> expected_result{0,1,1,2,1,2};
	EXPECT_EQ(expected_result, counting_bits(n));
}