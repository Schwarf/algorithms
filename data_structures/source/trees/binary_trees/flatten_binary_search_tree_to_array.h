//
// Created by andreas on 03.08.22.
//

#ifndef FLATTEN_BINARY_SEARCH_TREE_TO_ARRAY_H
#define FLATTEN_BINARY_SEARCH_TREE_TO_ARRAY_H
#include "tree_node.h"
#include <vector>

template<typename T>
int help_flatten_binary_search_tree(TreeNode<T> *root, std::vector<int> &result, int index)
{
	if (!root)
		return index;
	index = help_flatten_binary_search_tree(root->left, result, index);
	if (result.empty())
		result.resize(1);
	else if (index > result.size() - 1)
		result.resize(index + 1);
	result[index] = root->value;
	index = help_flatten_binary_search_tree(root->right, result, index + 1);
	return index;
}

template<typename T>
std::vector<T> flatten_binary_search_tree(TreeNode<T> *root)
{
	std::vector<T> result;
	help_flatten_binary_search_tree(root, result, 0);
	return result;
}

#endif //FLATTEN_BINARY_SEARCH_TREE_TO_ARRAY_H
