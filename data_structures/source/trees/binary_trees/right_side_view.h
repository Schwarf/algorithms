//
// Created by andreas on 11.07.22.
//

#ifndef RIGHT_SIDE_VIEW_H
#define RIGHT_SIDE_VIEW_H
#include "tree_node.h"
#include <vector>

// Given the root of a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.

// THE TEST INCORPORATES ITERATIVE SOLUTION
template <typename T>
void depth_first_search(TreeNode<T> *root, int depth, std::vector<T> &result)
{
	if (!root)
		return;
	if (result.size() == depth)
		result.push_back(root->value);
	depth_first_search(root->right, depth + 1, result);
	depth_first_search(root->left, depth + 1, result);

}

template <typename T>
std::vector<T> right_side_view(TreeNode<T> *root)
{
	std::vector<T> result;
	depth_first_search(root, 0, result);
	return result;
}

#endif //RIGHT_SIDE_VIEW_H
