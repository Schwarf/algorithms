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
	std::vector<std::vector<int>> levelorder{{25}, {15, 50}, {10, 22, 35, 70}, {4, 12, 18, 24, 31, 44, 66, 90}};
	int depth{4};

	static TreeNode<int> *inverted_tree()
	{
		auto root = new TreeNode<int>(25);
		root->left = new TreeNode<int>(50);
		root->right = new TreeNode<int>(15);

		root->left->left = new TreeNode<int>(70);
		root->left->right = new TreeNode<int>(35);

		root->right->left = new TreeNode<int>(22);
		root->right->right = new TreeNode<int>(10);

		root->left->left->left = new TreeNode<int>(90);
		root->left->left->right = new TreeNode<int>(66);

		root->left->right->left = new TreeNode<int>(44);
		root->left->right->right = new TreeNode<int>(31);

		root->right->left->left = new TreeNode<int>(24);
		root->right->left->right = new TreeNode<int>(18);

		root->right->right->left = new TreeNode<int>(12);
		root->right->right->right = new TreeNode<int>(4);

		return root;
	}
	static TreeNode<int> *binary_tree_root()
	{
		auto root = new TreeNode<int>(25);
		root->left = new TreeNode<int>(15);
		root->right = new TreeNode<int>(50);

		root->left->left = new TreeNode<int>(10);
		root->left->right = new TreeNode<int>(22);

		root->right->left = new TreeNode<int>(35);
		root->right->right = new TreeNode<int>(70);

		root->left->left->left = new TreeNode<int>(4);
		root->left->left->right = new TreeNode<int>(12);

		root->left->right->left = new TreeNode<int>(18);
		root->left->right->right = new TreeNode<int>(24);

		root->right->left->left = new TreeNode<int>(31);
		root->right->left->right = new TreeNode<int>(44);

		root->right->right->left = new TreeNode<int>(66);
		root->right->right->right = new TreeNode<int>(90);

		return root;
	}

};

#endif //SETUP_BINARY_TREE_H

