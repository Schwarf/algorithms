//
// Created by andreas on 14.07.22.
//

#include "setup_binary_tree.h"
#include "./../../../trees/binary_trees/level_order_traversal.h"


TEST_F(SetupBinaryTree, test_level_order_traversal)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = level_order_traversal(root);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j)
			EXPECT_EQ(result[i][j], levelorder[i][j]);
	}

}