//
// Created by andreas on 09.05.22.
//


#include "setup_binary_tree.h"
#include "./../../../../trees/binary_trees/in_order_traversal.h"


TEST_F(SetupBinaryTree, test_inorder_traversal)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = in_order_traversal(root);
	for(size_t index =0; index < inorder.size(); ++index)
	{
		EXPECT_EQ(result[index], inorder[index]);
	}
}

TEST_F(SetupBinaryTree, test_inorder_traversal_recursive)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = in_order_traversal_recursive(root);
	for(size_t index =0; index < inorder.size(); ++index)
	{
		EXPECT_EQ(result[index], inorder[index]);
	}
}
