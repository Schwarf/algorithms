//
// Created by andreas on 10.12.22.
//

#ifndef MAXIMUM_DIFFERENCE_BETWEE_NODE_AND_ANCESTOR_H
#define MAXIMUM_DIFFERENCE_BETWEE_NODE_AND_ANCESTOR_H
// Given the root of a binary tree, find the maximum valueue v for which there exist different nodes a and b
// where v = |a.value - b.value| and a is an ancestor of b.
// A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
#include <algorithm>
#include "tree_node.h"

void get_max_diff(TreeNode<int> *node, const int &root_value, int &max_diff)
{
	if (!node || node->value == root_value)
		return;
	max_diff = std::max(max_diff, std::abs(node->value - root_value));
	get_max_diff(node->left, root_value, max_diff);
	get_max_diff(node->right, root_value, max_diff);
}

void get_max_diff_for_node(TreeNode<int> *node, int &max)
{
	if (!node)
		return;
	int max_left{};
	int max_right{};
	get_max_diff(node->left, node->value, max_left);
	get_max_diff(node->right, node->value, max_right);
	auto local_max = std::max(max_left, max_right);
	max = std::max(local_max, max);
	get_max_diff_for_node(node->left, max);
	get_max_diff_for_node(node->right, max);
}

// O(N^2)
int brute_force(TreeNode<int> *root)
{
	int max{};
	get_max_diff_for_node(root, max);
	return max;
}

#endif //MAXIMUM_DIFFERENCE_BETWEE_NODE_AND_ANCESTOR_H

