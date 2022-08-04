#include <iostream>
#include <vector>
#include "trees/binary_trees/tree_node.h"
#include "trees/binary_trees/in_order_traversal.h"
#include "trees/binary_trees/pre_order_traversal.h"
#include "trees/binary_trees/construct_binary_tree_from_preorder_and_inorder.h"



int main()
{
	auto root = new TreeNode<int>(1);
	root->add_left(2)->add_left(4)->add_left(6);
	root->left->add_right(5);
	root->add_right(3);
	std::vector<int> pre_order, in_order;
	in_order_traversal(in_order, root);
	pre_order_traversal(pre_order, root);
	std::cout << "Pre order:" << std::endl;
	for(const auto & element: pre_order)
		std::cout << element << ", " ;
	std::cout << std::endl;

	std::cout << "In order:" << std::endl;
	for(const auto & element: in_order)
		std::cout << element << ", " ;

	auto tree = construct_from_preorder_and_inorder(pre_order, in_order);
	int x =1;
	return 0;
}

