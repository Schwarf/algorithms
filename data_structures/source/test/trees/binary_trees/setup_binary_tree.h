//
// Created by andreas on 09.05.22.
//

#ifndef SETUP_BINARY_TREE_H
#define SETUP_BINARY_TREE_H
#include "gtest/gtest.h"
#include <vector>
#include "trees/binary_trees/tree_node.h"


class SetupBinaryTree: public testing::Test
{
public:
	SetupBinaryTree() = default;
protected:
	std::vector<unsigned int> insertion{25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
	std::vector<unsigned int> inorder{4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90};
	std::vector<unsigned int> preorder{25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 31, 44, 70, 66, 90};
	std::vector<unsigned int> postorder{4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25};
	std::vector<std::vector<unsigned int>> levelorder{{25}, {15, 50}, {10, 22, 35, 70}, {4, 12, 18, 24, 31, 44, 66, 90}};
	std::vector<std::vector<unsigned int>>
		levelorder_inverted_tree{{25}, {50, 15}, {70, 35, 22, 10}, {90, 66, 44, 31, 24, 18, 12, 4}};
	std::vector<std::vector<unsigned int>> levelorder_small_tree{{3}, {9, 20}, {15, 7}};
	int depth{4};

	static TreeNode<unsigned int> *inverted_tree()
	{
		auto root = new TreeNode<unsigned int>(25);
		root->left = new TreeNode<unsigned int>(50);
		root->right = new TreeNode<unsigned int>(15);

		root->left->left = new TreeNode<unsigned int>(70);
		root->left->right = new TreeNode<unsigned int>(35);

		root->right->left = new TreeNode<unsigned int>(22);
		root->right->right = new TreeNode<unsigned int>(10);

		root->left->left->left = new TreeNode<unsigned int>(90);
		root->left->left->right = new TreeNode<unsigned int>(66);

		root->left->right->left = new TreeNode<unsigned int>(44);
		root->left->right->right = new TreeNode<unsigned int>(31);

		root->right->left->left = new TreeNode<unsigned int>(24);
		root->right->left->right = new TreeNode<unsigned int>(18);

		root->right->right->left = new TreeNode<unsigned int>(12);
		root->right->right->right = new TreeNode<unsigned int>(4);

		return root;
	}
	static TreeNode<unsigned int> *binary_tree_root()
	{
		auto root = new TreeNode<unsigned int>(25);
		root->left = new TreeNode<unsigned int>(15);
		root->right = new TreeNode<unsigned int>(50);

		root->left->left = new TreeNode<unsigned int>(10);
		root->left->right = new TreeNode<unsigned int>(22);

		root->right->left = new TreeNode<unsigned int>(35);
		root->right->right = new TreeNode<unsigned int>(70);

		root->left->left->left = new TreeNode<unsigned int>(4);
		root->left->left->right = new TreeNode<unsigned int>(12);

		root->left->right->left = new TreeNode<unsigned int>(18);
		root->left->right->right = new TreeNode<unsigned int>(24);

		root->right->left->left = new TreeNode<unsigned int>(31);
		root->right->left->right = new TreeNode<unsigned int>(44);

		root->right->right->left = new TreeNode<unsigned int>(66);
		root->right->right->right = new TreeNode<unsigned int>(90);

		return root;
	}
	static TreeNode<unsigned int> *small_binary_tree_root()
	{
		auto root = new TreeNode<unsigned int>(3);
		root->left = new TreeNode<unsigned int>(9);
		root->right = new TreeNode<unsigned int>(20);
		root->right->left = new TreeNode<unsigned int>(15);
		root->right->right = new TreeNode<unsigned int>(7);
		return root;
	}

	static TreeNode<unsigned int> *inverted_small_binary_tree_root()
	{
		auto root = new TreeNode<unsigned int>(3);
		root->left = new TreeNode<unsigned int>(20);
		root->right = new TreeNode<unsigned int>(9);
		root->left->left = new TreeNode<unsigned int>(7);
		root->left->right = new TreeNode<unsigned int>(15);
		return root;
	}

	static TreeNode<unsigned int> *small_tree_with_subtree_duplicates()
	{
		auto root = new TreeNode<unsigned int>(1);
		root->left = new TreeNode<unsigned int>(2);
		root->right = new TreeNode<unsigned int>(2);
		return root;
	}

	static TreeNode<unsigned int> *medium_tree_with_subtree_duplicates1()
	{
		auto root = new TreeNode<unsigned int>(1);
		root->left = new TreeNode<unsigned int>(2);
		root->right = new TreeNode<unsigned int>(3);
		root->left->left = new TreeNode<unsigned int>(4);
		root->right->left = new TreeNode<unsigned int>(2);
		root->right->left->left = new TreeNode<unsigned int>(4);
		root->right->right = new TreeNode<unsigned int>(4);
		return root;
	}

	static TreeNode<unsigned int> *medium_tree_with_subtree_duplicates2()
	{
		auto root = new TreeNode<unsigned int>(1);
		root->left = new TreeNode<unsigned int>(2);
		root->right = new TreeNode<unsigned int>(2);
		root->left->left = new TreeNode<unsigned int>(3);
		root->right->left = new TreeNode<unsigned int>(3);
		return root;
	}

	static TreeNode<unsigned int> *medium_tree_with_subtree_duplicates3()
	{
		auto root = new TreeNode<unsigned int>(2);
		root->left = new TreeNode<unsigned int>(1);
		root->right = new TreeNode<unsigned int>(1);
		root->left->left = new TreeNode<unsigned int>(2);
		root->left->right = new TreeNode<unsigned int>(3);
		root->right->left = new TreeNode<unsigned int>(4);
		root->right->right = new TreeNode<unsigned int>(5);
		return root;
	}
	static TreeNode<unsigned int> *imbalanced_right_tree()
	{
		auto root = new TreeNode<unsigned int>(2);
		root->right = new TreeNode<unsigned int>(1);
		root->right->left = new TreeNode<unsigned int>(4);
		root->right->right = new TreeNode<unsigned int>(5);
		root->right->right->right = new TreeNode<unsigned int>(12);
		return root;
	}

};

#endif //SETUP_BINARY_TREE_H

