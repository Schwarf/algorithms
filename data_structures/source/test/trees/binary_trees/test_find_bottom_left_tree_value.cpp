//
// Created by andreas on 28.02.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/find_bottom_left_tree_value.h"

TEST_F(SetupBinaryTree, simple1)
{
	auto tree = small_binary_tree_root();
	constexpr unsigned int expected_value{15};
	EXPECT_EQ(expected_value, find_bottom_left_value(tree));
}

TEST_F(SetupBinaryTree, simple2)
{
	auto tree = binary_tree_root();
	constexpr unsigned int expected_value{4};
	EXPECT_EQ(expected_value, find_bottom_left_value(tree));
}


TEST_F(SetupBinaryTree, simple3)
{
	auto tree = inverted_tree();
	constexpr unsigned int expected_value{90};
	EXPECT_EQ(expected_value, find_bottom_left_value(tree));
}

TEST_F(SetupBinaryTree, simple4)
{
	auto tree = imbalanced_right_tree();
	constexpr unsigned int expected_value{12};
	EXPECT_EQ(expected_value, find_bottom_left_value(tree));
}


TEST_F(SetupBinaryTree, simple5)
{
	auto tree = palindromic_tree2();
	constexpr unsigned int expected_value{1};
	EXPECT_EQ(expected_value, find_bottom_left_value(tree));
}


TEST_F(SetupBinaryTree, simple_bfs1)
{
	auto tree = small_binary_tree_root();
	constexpr unsigned int expected_value{15};
	EXPECT_EQ(expected_value, find_bottom_left_value_bfs(tree));
}


TEST_F(SetupBinaryTree, simple_bfs2)
{
	auto tree = binary_tree_root();
	constexpr unsigned int expected_value{4};
	EXPECT_EQ(expected_value, find_bottom_left_value_bfs(tree));
}


TEST_F(SetupBinaryTree, simple_bfs3)
{
	auto tree = inverted_tree();
	constexpr unsigned int expected_value{90};
	EXPECT_EQ(expected_value, find_bottom_left_value_bfs(tree));
}

TEST_F(SetupBinaryTree, simple_bfs4)
{
	auto tree = imbalanced_right_tree();
	constexpr unsigned int expected_value{12};
	EXPECT_EQ(expected_value, find_bottom_left_value_bfs(tree));
}


TEST_F(SetupBinaryTree, simple_bfs5)
{
	auto tree = palindromic_tree2();
	constexpr unsigned int expected_value{1};
	EXPECT_EQ(expected_value, find_bottom_left_value_bfs(tree));
}
