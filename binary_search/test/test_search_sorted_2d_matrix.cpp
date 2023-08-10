//
// Created by andreas on 10.08.23.
//
#include "gtest/gtest.h"
#include "./../search_sorted_2d_matrix.h"

TEST(SearchSorted2DMatrix, simple1)
{
	const std::vector<std::vector<short>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	constexpr short target{3};
	EXPECT_TRUE(search_matrix(matrix, target));
}

TEST(SearchSorted2DMatrix, simple2)
{
	const std::vector<std::vector<short>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	constexpr short target{13};
	EXPECT_FALSE(search_matrix(matrix, target));
}


TEST(SearchSorted2DMatrix, simple3)
{
	const std::vector<std::vector<double>> matrix
		{{-10.0, -9.0}, {-6.0, -4.0}, {-3.0, -1.0}, {0.0, 1.0}, {2.0, 2.0}, {4.0, 5.0}, {7.0, 8.0}, {9.0, 11.0},
		 {12.0, 13.0}, {15.0, 15.0}, {18.0, 20.0}, {21.0, 22.0},
		 {25.0, 27.0}, {30.0, 30.0}, {31.0, 31.0}, {34.0, 34.0}};
	constexpr double target{10.0};
	EXPECT_FALSE(search_matrix(matrix, target));
}

TEST(SearchSorted2DMatrix, simple4)
{
	const std::vector<std::vector<double>> matrix
		{{-10.0, -9.0}, {-6.0, -4.0}, {-3.0, -1.0}, {0.0, 1.0}, {2.0, 2.0}, {4.0, 5.0}, {7.0, 8.0}, {9.0, 11.0},
		 {12.0, 13.0}, {15.0, 15.0}, {18.0, 20.0}, {21.0, 22.0},
		 {25.0, 27.0}, {30.0, 30.0}, {31.0, 31.0}, {34.0, 34.0}};
	constexpr double target{27.0};
	EXPECT_TRUE(search_matrix(matrix, target));
}
