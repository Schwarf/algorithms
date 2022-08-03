//
// Created by andreas on 09.05.22.
//

#include "setup_binary_tree.h"
#include "./../../../trees/binary_trees/pre_order_traversal.h"


TEST_F(SetupBinaryTree, test_preorder_traversal)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = pre_order_traversal(root);
	for (size_t index = 0; index < inorder.size(); ++index) {
		EXPECT_EQ(result.at(index), preorder.at(index));
	}
}

TEST_F(SetupBinaryTree, test_recursive_preorder_traversal)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = pre_order_traversal_recursive(root);
	for (size_t index = 0; index < inorder.size(); ++index) {
		EXPECT_EQ(result.at(index), preorder.at(index));
	}
}
