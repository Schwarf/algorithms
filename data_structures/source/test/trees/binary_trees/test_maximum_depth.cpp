//
// Created by andreas on 12.05.22.
//

#include "setup_binary_tree.h"
#include "./../../../../trees/binary_trees/maximum_depth.h"


TEST_F(SetupBinaryTree, test_maximum_depth)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = maximum_depth(root);
	EXPECT_EQ(result, depth);
}

TEST_F(SetupBinaryTree, test_maximum_depth_recursive)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = maximum_depth_recursive(root);
	EXPECT_EQ(result, depth);
}
