//
// Created by andreas on 04.11.23.
//
#include "gtest/gtest.h"
#include "trees/binary_trees/find_two_sum_in_binary_tree.h"
#include "setup_binary_tree.h"

TEST_F(SetupBinaryTree, find_two_sum_in_binray_tree_found1)
{
	constexpr int target{102};
	EXPECT_TRUE(find_target_two_sum(binary_tree_root(), target));
}

TEST_F(SetupBinaryTree, find_two_sum_in_binray_tree_not_found1)
{
	constexpr int target{103};
	EXPECT_FALSE(find_target_two_sum(binary_tree_root(), target));
}


TEST_F(SetupBinaryTree, find_two_sum_in_binray_tree_not_found2)
{
	constexpr int target{10};
	EXPECT_FALSE(find_target_two_sum(new TreeNode<int>(10), target));
}

TEST_F(SetupBinaryTree, find_two_sum_in_binray_tree_not_found3)
{
	constexpr int target{10};
	TreeNode<int> *null = nullptr;
	EXPECT_FALSE(find_target_two_sum(null, target));
}

TEST_F(SetupBinaryTree, find_two_sum_in_binray_tree_found2)
{
	constexpr int target{9};
	EXPECT_TRUE(find_target_two_sum(imbalanced_right_tree(), target));
}

TEST_F(SetupBinaryTree, find_two_sum_in_binray_tree_found3)
{
	constexpr int target{40};
	EXPECT_TRUE(find_target_two_sum(binary_tree_root(), target));
}
