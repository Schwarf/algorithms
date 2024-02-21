//
// Created by andreas on 21.02.24.
//
#include "gtest/gtest.h"
#include "bitwise_and_numbers_in_range.h"

TEST(TestBitwiseAndInRange, simple1)
{
	constexpr int left{5};
	constexpr int right{7};
	constexpr int expected_result{4};
	EXPECT_EQ(range_bitwise_and(left, right), expected_result);
}

TEST(TestBitwiseAndInRange, simple2)
{
	constexpr int left{0};
	constexpr int right{0};
	constexpr int expected_result{0};
	EXPECT_EQ(range_bitwise_and(left, right), expected_result);
}

TEST(TestBitwiseAndInRange, simple3)
{
	constexpr int left{1};
	constexpr int right{2147483647};
	constexpr int expected_result{0};
	EXPECT_EQ(range_bitwise_and(left, right), expected_result);
}

TEST(TestBitwiseAndInRange, simple4)
{
	constexpr int left{107};
	constexpr int right{28190};
	constexpr int expected_result{0};
	EXPECT_EQ(range_bitwise_and(left, right), expected_result);
}


TEST(TestBitwiseAndInRange, simple5)
{
	constexpr int left{22200000};
	constexpr int right{22222222};
	constexpr int expected_result{22151168};
	EXPECT_EQ(range_bitwise_and(left, right), expected_result);
}