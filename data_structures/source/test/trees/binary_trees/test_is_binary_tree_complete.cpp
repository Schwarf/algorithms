//
// Created by andreas on 15.03.23.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/is_binary_tree_complete.h"


TEST_F(SetupBinaryTree, is_binary_tree_complete_small_tree_false)
{
	auto tree = small_binary_tree_root();
	auto expected_result = false;
	EXPECT_TRUE(expected_result == is_tree_complete(tree));
}

TEST_F(SetupBinaryTree, is_binary_tree_complete_small_tree_true)
{
	auto tree = inverted_small_binary_tree_root();
	auto expected_result = true;
	EXPECT_TRUE(expected_result == is_tree_complete(tree));
}

TEST_F(SetupBinaryTree, is_binary_tree_complete_nullptr)
{
	TreeNode<double> * tree = nullptr;
	auto expected_result = true;
	EXPECT_TRUE(expected_result == is_tree_complete(tree));
}


TEST_F(SetupBinaryTree, is_binary_tree_complete_medium_tree_false)
{
	auto tree = medium_tree_with_subtree_duplicates1();
	auto expected_result = false;
	EXPECT_TRUE(expected_result == is_tree_complete(tree));
}

TEST_F(SetupBinaryTree, is_binary_tree_complete_medium_tree_true)
{
	auto tree = binary_tree_root();
	auto expected_result = true;
	EXPECT_TRUE(expected_result == is_tree_complete(tree));
}
