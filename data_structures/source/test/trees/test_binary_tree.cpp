//
// Created by andreas on 03.04.22.
//

#include "setup_n-ary_tree.h"



TEST_F(SetupN_aryTree, test_preorder_traversal)
{
	auto binary_tree = SetupN_aryTree::binary_tree();
	auto help = HelperClass<int>();
	binary_tree->traverse_preorder(std::ref(help));
	for(size_t index =0; index < inorder.size(); ++index)
	{
		EXPECT_EQ(help.result().at(index), preorder.at(index));
	}
}


TEST_F(SetupN_aryTree, test_inorder_traversal)
{
	auto binary_tree = SetupN_aryTree::binary_tree();

	auto help = HelperClass<int>();
	binary_tree->traverse_inorder(std::ref(help));
	for(size_t index =0; index < inorder.size(); ++index)
	{
		EXPECT_EQ(help.result().at(index), inorder.at(index));
	}
}
