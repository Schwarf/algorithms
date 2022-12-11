//
// Created by andreas on 11.12.22.
//

#ifndef MAXIMUM_PATH_SUM_H
#define MAXIMUM_PATH_SUM_H
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge
// connecting them. A node can only appear in the sequence at most once. Note that the path does not
// need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.
#include "tree_node.h"
#include <climits>
#include <algorithm>

template<typename T>
int sum_of_path_in_subtree(TreeNode<T> *node, int &max_sum);

template<typename T>
int max_path_sum(TreeNode<T> *root)
{
	int max_sum{INT_MIN};
	sum_of_path_in_subtree(root, max_sum);
	return max_sum;
}

template<typename T>
int sum_of_path_in_subtree(TreeNode<T> *node, int &max_sum)
{
	if (!node)
		return {};
	int path_sum_left = std::max(sum_of_path_in_subtree(node->left, max_sum), 0);
	int path_sum_right = std::max(sum_of_path_in_subtree(node->right, max_sum), 0);
	max_sum = std::max(max_sum, path_sum_left + path_sum_right + node->value);
	return std::max(path_sum_left + node->value, path_sum_right + node->value);
}

#endif //MAXIMUM_PATH_SUM_H
