
#include "gtest/gtest.h"
#include "./../find_pivot_integer.h"


TEST(TestFindPivotInteger, simple_linear1)
{
	constexpr int input{1};
	constexpr int expected_result{1};
	EXPECT_EQ(expected_result, pivot_integer_linear(input));
}

TEST(TestFindPivotInteger, simple_linear2)
{
	constexpr int input{2};
	constexpr int expected_result{-1};
	EXPECT_EQ(expected_result, pivot_integer_linear(input));
}

TEST(TestFindPivotInteger, simple_linear3)
{
	constexpr int input{3};
	constexpr int expected_result{-1};
	EXPECT_EQ(expected_result, pivot_integer_linear(input));
}


TEST(TestFindPivotInteger, simple_linear4)
{
	constexpr int input{8};
	constexpr int expected_result{6};
	EXPECT_EQ(expected_result, pivot_integer_linear(input));
}


TEST(TestFindPivotInteger, simple_logarithmic1)
{
	constexpr int input{1};
	constexpr int expected_result{1};
	EXPECT_EQ(expected_result, pivot_integer_logarithmic(input));
}

TEST(TestFindPivotInteger, simple_logarithmic2)
{
	constexpr int input{2};
	constexpr int expected_result{-1};
	EXPECT_EQ(expected_result, pivot_integer_logarithmic(input));
}

TEST(TestFindPivotInteger, simple_logarithmic3)
{
	constexpr int input{3};
	constexpr int expected_result{-1};
	EXPECT_EQ(expected_result, pivot_integer_logarithmic(input));
}


TEST(TestFindPivotInteger, simple_logarithmic4)
{
	constexpr int input{8};
	constexpr int expected_result{6};
	EXPECT_EQ(expected_result, pivot_integer_logarithmic(input));
}



TEST(TestFindPivotInteger, simple_math1)
{
	constexpr int input{1};
	constexpr int expected_result{1};
	EXPECT_EQ(expected_result, pivot_integer_math(input));
}

TEST(TestFindPivotInteger, simple_math2)
{
	constexpr int input{2};
	constexpr int expected_result{-1};
	EXPECT_EQ(expected_result, pivot_integer_math(input));
}

TEST(TestFindPivotInteger, simple_math3)
{
	constexpr int input{3};
	constexpr int expected_result{-1};
	EXPECT_EQ(expected_result, pivot_integer_math(input));
}


TEST(TestFindPivotInteger, simple_math4)
{
	constexpr int input{8};
	constexpr int expected_result{6};
	EXPECT_EQ(expected_result, pivot_integer_math(input));
}



