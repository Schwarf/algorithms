// Created by andreas on 13.08.23.
//
#include "gtest/gtest.h"
#include "unique_paths_with_obstacles.h"
TEST(UniquePathsWithObstaclesRecursive, simple1)
{
	const std::vector<std::vector<int>> matrix{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	constexpr int expected_paths{2};
	EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple2)
{
	const std::vector<std::vector<int>> matrix{{0, 1}, {0, 0}};
	constexpr int expected_paths{1};
	EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple3)
{
	const std::vector<std::vector<int>> matrix{{0, 0, 0}, {1, 1, 1}, {0, 0, 0}};
	constexpr int expected_paths{0};
	EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple4)
{
	const std::vector<std::vector<int>> matrix{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	constexpr int expected_paths{6};
	EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple5)
{
	const std::vector<std::vector<int>> matrix{{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
	constexpr int expected_paths{7};
	EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple6)
{
	const std::vector<std::vector<int>> matrix{{0}};
	constexpr int expected_paths{1};
	EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}


TEST(UniquePathsWithObstaclesRecursive, complex1)
{
	const std::vector<std::vector<int>> matrix{{0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
											   {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
											   {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
											   {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
											   {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
											   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
											   {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
											   {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
											   {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
											   {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
											   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
											   {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
											   {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
											   {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
											   {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
											   {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
											   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
											   {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
											   {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0},
											   {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
											   {0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
											   {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0},
											   {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
											   {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
											   {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
											   {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
											   {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
											   {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
											   {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}};
	constexpr int expected_paths{13594824};
	EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}
