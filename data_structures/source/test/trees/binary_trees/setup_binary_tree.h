//
// Created by andreas on 09.05.22.
//

#ifndef SETUP_BINARY_TREE_H
#define SETUP_BINARY_TREE_H
#include "gtest/gtest.h"
#include <vector>
#include "./../../../trees/binary_trees/tree_node.h"


class SetupBinaryTree: public testing::Test
{
public:
	SetupBinaryTree() = default;
protected:
	std::vector<int> insertion{25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
	std::vector<int> inorder{4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90};
	std::vector<int> preorder{25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 31, 44, 70, 66, 90};
	std::vector<int> postorder{4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25};
	int depth{4};

	static TreeNode<int> * inverted_tree()
	{
		auto root = new TreeNode<int>(25);
		auto left= root->add_left(50);
		auto right = root->add_right(15);

		auto left_left = left->add_left(70);
		auto left_right = left->add_right(35);

		auto right_left = right->add_left(22);
		auto right_right = right->add_right(10);

		left_left->add_left(90);
		left_left->add_right(66);

		left_right->add_left(44);
		left_right->add_right(31);


		right_left->add_left(24);
		right_left->add_right(18);

		right_right->add_left(12);
		right_right->add_right(4);
		return root;
	}
	static TreeNode<int> * binary_tree_root()
	{
		auto root = new TreeNode<int>(25);
		auto left= root->add_left(15);
		auto right = root->add_right(50);

		auto left_left = left->add_left(10);
		auto left_right = left->add_right(22);

		auto right_left = right->add_left(35);
		auto right_right = right->add_right(70);

		left_left->add_left(4);
		left_left->add_right(12);

		left_right->add_left(18);
		left_right->add_right(24);


		right_left->add_left(31);
		right_left->add_right(44);

		right_right->add_left(66);
		right_right->add_right(90);

		//		binary_tree->root()->add_child(15);
//		binary_tree->root()->add_child(50);
//		binary_tree->root()->children.at(0)->add_child(10);
//		binary_tree->root()->children.at(0)->add_child(22);
//		binary_tree->root()->children.at(1)->add_child(35);
//		binary_tree->root()->children.at(1)->add_child(70);
//		binary_tree->root()->children.at(0)->children.at(0)->add_child(4);
//		binary_tree->root()->children.at(0)->children.at(0)->add_child(12);
//		binary_tree->root()->children.at(0)->children.at(1)->add_child(18);
//		binary_tree->root()->children.at(0)->children.at(1)->add_child(24);
//		binary_tree->root()->children.at(1)->children.at(0)->add_child(31);
//		binary_tree->root()->children.at(1)->children.at(0)->add_child(44);
//		binary_tree->root()->children.at(1)->children.at(1)->add_child(66);
//		binary_tree->root()->children.at(1)->children.at(1)->add_child(90);

		return root;
	}

};

#endif //SETUP_BINARY_TREE_H

