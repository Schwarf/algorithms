//
// Created by andreas on 24.09.22.
//

#ifndef PATH_SUM_BINARY_TREE_H
#define PATH_SUM_BINARY_TREE_H
/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node
values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
 */
#include <vector>

template <typename T>
struct Node{
	explicit Node(const T & val)
	{
		value =val;
	}
	Node* left = nullptr;
	Node* right = nullptr;
	T value;
};

template <typename T>
class Solution {
public:
	std::vector<std::vector<T>> result;
	void sum(Node<T> * node, T target, std::vector<T> & path)
	{
		if(!node)
			return;
		path.push_back(node->val);
		target -= node->val;
		if(node->left ==nullptr && node-> right ==nullptr)
		{
			if (target ==0)
				result.push_back(path);
		}
		else{
			sum(node->left, target, path);
			sum(node->right, target, path);
		}
		path.pop_back();

	}

	std::vector<std::vector<T>> pathSum(Node<T>* root, T targetSum) {
		std::vector<T> path;
		sum(root, targetSum, path);
		return result;
	}
};
#endif //PATH_SUM_BINARY_TREE_H

