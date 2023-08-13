//
// Created by andreas on 13.08.23.
//

#include "gtest/gtest.h"
#include "./../unique_paths.h"

TEST(UniquePathsRecursive, simple1)
{
	constexpr int rows{3};
	constexpr int columns{7};
	constexpr int expected_paths{28};
	EXPECT_EQ(expected_paths, unique_paths_recursive(rows, columns));
}

TEST(UniquePathsRecursive, simple2)
{
	constexpr int rows{2};
	constexpr int columns{3};
	constexpr int expected_paths{3};
	EXPECT_EQ(expected_paths, unique_paths_recursive(rows, columns));
}

TEST(UniquePathsRecursive, simple3)
{
	constexpr int rows{1};
	constexpr int columns{1};
	constexpr int expected_paths{1};
	EXPECT_EQ(expected_paths, unique_paths_recursive(rows, columns));
}

TEST(UniquePathsRecursive, complex1)
{
	constexpr int rows{14};
	constexpr int columns{10};
	constexpr int expected_paths{497420};
	EXPECT_EQ(expected_paths, unique_paths_recursive(rows, columns));
}


TEST(UniquePathsRecursive, complex2)
{
	constexpr int rows{7};
	constexpr int columns{30};
	constexpr int expected_paths{1623160};
	EXPECT_EQ(expected_paths, unique_paths_recursive(rows, columns));
}


TEST(UniquePathsTopDown, simple1)
{
	constexpr int rows{3};
	constexpr int columns{7};
	constexpr int expected_paths{28};
	EXPECT_EQ(expected_paths, unique_paths_top_down(rows, columns));
}

TEST(UniquePathsTopDown, simple2)
{
	constexpr int rows{2};
	constexpr int columns{3};
	constexpr int expected_paths{3};
	EXPECT_EQ(expected_paths, unique_paths_top_down(rows, columns));
}

TEST(UniquePathsTopDown, simple3)
{
	constexpr int rows{1};
	constexpr int columns{1};
	constexpr int expected_paths{1};
	EXPECT_EQ(expected_paths, unique_paths_top_down(rows, columns));
}

TEST(UniquePathsTopDown, complex1)
{
	constexpr int rows{14};
	constexpr int columns{10};
	constexpr int expected_paths{497420};
	EXPECT_EQ(expected_paths, unique_paths_top_down(rows, columns));
}


TEST(UniquePathsTopDown, complex2)
{
	constexpr int rows{7};
	constexpr int columns{30};
	constexpr int expected_paths{1623160};
	EXPECT_EQ(expected_paths, unique_paths_top_down(rows, columns));
}
