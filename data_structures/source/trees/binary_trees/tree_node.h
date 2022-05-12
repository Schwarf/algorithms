//
// Created by andreas on 30.04.22.
//

#ifndef TREE_NODE_H
#define TREE_NODE_H

template<typename T>
struct TreeNode
{
	T value;
	TreeNode *left;
	TreeNode *right;
	TreeNode()
		:
		value(T{}),
		left(nullptr),
		right(nullptr)
	{
	}
	TreeNode(const T &val)
		:
		value(val),
		left(nullptr),
		right(nullptr)
	{
	}
	TreeNode(const T &val, TreeNode *left, TreeNode *right)
		:
		value(val),
		left(left),
		right(right)
	{
	}
	TreeNode<int> *add_left(const T &val)
	{
		this->left = new TreeNode<int>(val);
		return this->left;
	}
	TreeNode<int> *add_right(const T &val)
	{
		this->right = new TreeNode<int>(val);
		return this->right;
	}

};

#endif //TREE_NODE_H
