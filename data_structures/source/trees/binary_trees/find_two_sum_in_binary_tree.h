//
// Created by andreas on 09.10.22.
//

#ifndef FIND_TWO_SUM_IN_BINARY_TREE_H
#define FIND_TWO_SUM_IN_BINARY_TREE_H
#include "tree_node.h"
#include <unordered_set>

template<typename T>
std::unordered_set<T> help_find_target_two_sum;

template<typename T>
bool find_target_two_sum(TreeNode<T> *root, int target)
{
	if (!root)
		return false;
	if (help_find_target_two_sum<T>.find(target - root->value) != help_find_target_two_sum<T>.end())
		return true;
	help_find_target_two_sum<T>.insert(root->value);
	return find_target_two_sum(root->left, target) || find_target_two_sum(root->right, target);
};


#endif //FIND_TWO_SUM_IN_BINARY_TREE_H
