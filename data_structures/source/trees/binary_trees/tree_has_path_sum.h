//
// Created by andreas on 30.04.22.
//

#ifndef TREE_ALGORITHMS_H
#define TREE_ALGORITHMS_H


// Given the root of a binary tree and an integer targetSum, return true if the tree has a
// root-to-leaf path such that adding up all the values along the path equals targetSum
#include "tree_node.h"
bool has_path_sum(TreeNode<int> *root, int target)
{
	if (!root)
		return false;
	// has to be leaf node
	if (root->left == nullptr && root->right == nullptr && root->value == target)
		return true;
	target = target - root->value;
	return has_path_sum(root->left, target) || has_path_sum(root->right, target);
}


#endif //TREE_ALGORITHMS_H
