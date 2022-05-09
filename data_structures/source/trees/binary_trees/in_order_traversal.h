//
// Created by andreas on 09.05.22.
//

#ifndef IN_ORDER_TRAVERSAL_H
#define IN_ORDER_TRAVERSAL_H
#include "tree_node.h"
#include <vector>
#include <stack>

#include "tree_node.h"
// For Inorder, you traverse from the left subtree to the root then to the right subtree.
// Inorder => Left, Root, Right.

std::vector<int> in_order_traversal(TreeNode<int> *root)
{
	if(!root)
		return {};
	std::vector<int> result;
	std::stack<TreeNode<int> *> remember_left_nodes;
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

void in_order_traversal(std::vector<int> &result, TreeNode<int> *root)
{
	if (!root)
		return;
	in_order_traversal(result, root->left);
	result.push_back(root->value);
	in_order_traversal(result, root->right);
}

std::vector<int> in_order_traversal_recursive(TreeNode<int> *root)
{
	std::vector<int> result;
	in_order_traversal(result, root);
	return result;
}


#endif //IN_ORDER_TRAVERSAL_H
