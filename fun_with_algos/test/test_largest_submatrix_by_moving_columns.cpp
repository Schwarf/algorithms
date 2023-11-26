//
// Created by andreas on 26.11.23.
//
#include "gtest/gtest.h"
#include "../largest_submatrix_by_moving_columns.h"

TEST(LargetSubmatrixMyMovingColumns, simple1)
{
	const std::vector<std::vector<int>> input{{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
	constexpr int expected_result{4};
	EXPECT_EQ(expected_result, largest_submatrix(input));
}

TEST(LargetSubmatrixMyMovingColumns, simple2)
{
	const std::vector<std::vector<int>> input{{1, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 0, 1}};
	constexpr int expected_result{9};
	EXPECT_EQ(expected_result, largest_submatrix(input));
}

TEST(LargetSubmatrixMyMovingColumns, simple3)
{
	const std::vector<std::vector<int>> input{{1, 0, 1, 1}};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, largest_submatrix(input));
}

TEST(LargetSubmatrixMyMovingColumns, simple4)
{
	const std::vector<std::vector<int>> input{{1, 1, 0}, {1, 0, 1}};
	constexpr int expected_result{2};
	EXPECT_EQ(expected_result, largest_submatrix(input));
}

TEST(LargetSubmatrixMyMovingColumns, complex1)
{
	const std::vector<std::vector<int>> input
		{{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
		  0},
		 {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
		  1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
		  1},
		 {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
		  1},
		 {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1,
		  1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1,
		  1},
		 {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0,
		  1},
		 {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1,
		  1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
		  1},
		 {1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
		  0}};
	constexpr int expected_result{75};
	EXPECT_EQ(expected_result, largest_submatrix(input));
}
