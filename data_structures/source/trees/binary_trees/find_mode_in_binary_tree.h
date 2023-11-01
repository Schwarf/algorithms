//
// Created by andreas on 01.11.23.
//

#ifndef FIND_MODE_IN_BINARY_TREE_H
#define FIND_MODE_IN_BINARY_TREE_H
// Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
// If the tree has more than one mode, return them in any order.
#include <type_traits>
#include <unordered_map>
#include <vector>
#include "tree_node.h"
template<typename T>
requires std::is_arithmetic_v<T>
void parse(TreeNode<T> *root, std::unordered_map<T, int> &count)
{
	if (!root)
		return;
	count[root->val]++;
	parse(root->left, count);
	parse(root->right, count);
}

template<typename T>
requires std::is_arithmetic_v<T>
std::vector<T> find_mode_dfs_recursive(TreeNode<T> *root)
{
	std::unordered_map<T, int> count;
	parse(root, count);
	int max{};
	for (const auto &[value, frequency]: count) {
		max = std::max(max, frequency);
	}
	std::vector<T> result;
	for (const auto &[value, frequency]: count) {
		if (frequency == max)
			result.push_back(value);
	}
	return result;
}


#endif //FIND_MODE_IN_BINARY_TREE_H
