//
// Created by andreas on 03.04.22.
//

#include "setup_n-ary_tree.h"

TEST_F(SetupN_aryTree, test_preorder_traversal)
{
	auto binary_tree = new N_aryTree<int, 2>();
	for(const auto & element: insertion)
	{
		binary_tree->insert(element);
	}

	auto help = HelperClass<int>();
	binary_tree->traverse_preorder(std::ref(help));
	for(size_t index =0; index < inorder.size(); ++index)
	{
		std::cout<< index << std::endl;
		EXPECT_EQ(help.result().at(index), preorder.at(index));
	}
}
