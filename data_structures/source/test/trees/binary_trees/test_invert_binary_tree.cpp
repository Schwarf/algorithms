//
// Created by andreas on 12.05.22.
//
#include "setup_binary_tree.h"
#include "./../../../trees/binary_trees/invert_binary_tree.h"
#include "./../../../trees/binary_trees/post_order_traversal.h"

TEST_F(SetupBinaryTree, test_invert_binary_tree)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto inverted = invert_binary_tree(root);
	auto expected_result = post_order_traversal(SetupBinaryTree::inverted_tree());
	auto inverted_result = post_order_traversal(inverted);
	bool comparison = expected_result == inverted_result;
	EXPECT_TRUE(comparison);
}

