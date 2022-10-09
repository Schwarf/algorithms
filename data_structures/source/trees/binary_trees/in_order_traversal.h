//
// Created by andreas on 09.05.22.
//

#ifndef IN_ORDER_TRAVERSAL_H
#define IN_ORDER_TRAVERSAL_H
#include "tree_node.h"
#include <vector>
#include <stack>

// For Inorder, you traverse from the left subtree to the root then to the right subtree.
// Inorder => Left, Root, Right.

template <typename T>
std::vector<T> in_order_traversal(TreeNode<T> *root)
{
	if (!root)
		return {};
	std::vector<T> result;
	std::stack<TreeNode<T> *> remember_left_nodes;
	while (root || !remember_left_nodes.empty()) {
		while (root) {
			remember_left_nodes.push(root);
			root = root->left;
		}
		root = remember_left_nodes.top();
		remember_left_nodes.pop();
		result.push_back(root->value);
		root = root->right;
	}
	return result;
}

template <typename T>
void in_order_traversal(std::vector<T> &result, TreeNode<T> *root)
{
	if (!root)
		return;
	in_order_traversal(result, root->left);
	result.push_back(root->value);
	in_order_traversal(result, root->right);
}

template <typename T>
std::vector<T> in_order_traversal_recursive(TreeNode<T> *root)
{
	std::vector<T> result;
	in_order_traversal(result, root);
	return result;
}


#endif //IN_ORDER_TRAVERSAL_H
