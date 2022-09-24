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

template<typename T>
struct Node
{
	explicit Node(const T &val)
	{
		value = val;
	}
	Node *left = nullptr;
	Node *right = nullptr;
	T value;
};

template<typename T>
class Solution
{
public:
	std::vector<std::vector<T>> result;
	void sum(Node<T> *node, T target_path_sum, std::vector<T> &path)
	{
		if (!node)
			return;
		path.push_back(node->val);
		target_path_sum -= node->val;
		if (node->left == nullptr && node->right == nullptr) {
			if (target_path_sum == 0)
				result.push_back(path);
		}
		else {
			sum(node->left, target_path_sum, path);
			sum(node->right, target_path_sum, path);
		}
		// pop back to evaluate all branches of given node
		path.pop_back();
	}

	std::vector<std::vector<T>> pathSum(Node<T> *root, T target_path_sum)
	{
		std::vector<T> path;
		sum(root, target_path_sum, path);
		return result;
	}
};
#endif //PATH_SUM_BINARY_TREE_H

