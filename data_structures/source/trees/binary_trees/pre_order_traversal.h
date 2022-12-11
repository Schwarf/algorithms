//
// Created by andreas on 09.05.22.
//

#ifndef PRE_ORDER_TRAVERSAL_H
#define PRE_ORDER_TRAVERSAL_H
#include "tree_node.h"
#include <vector>
#include <stack>
// For Preorder, you traverse from the root to the left subtree then to the right subtree.
// Preorder => Root, Left, Right aka parents get processed before children
template<typename T>
std::vector<T> pre_order_traversal(TreeNode<T> *root)
{
	if (!root)
		return {};
	std::vector<T> result;
	std::stack<TreeNode<T> *> remember_right_nodes;
	while (root || !remember_right_nodes.empty()) {
		while (root) {
			result.push_back(root->value);
			if (root->right)
				remember_right_nodes.push(root->right);
			root = root->left;
		}
		if (!remember_right_nodes.empty()) {
			root = remember_right_nodes.top();
			remember_right_nodes.pop();
		}
	}
	return result;
}

template<typename T>
void pre_order_traversal(std::vector<T> &result, TreeNode<T> *root)
{
	if (!root)
		return;
	result.push_back(root->value);
	pre_order_traversal(result, root->left);
	pre_order_traversal(result, root->right);
}

template<typename T>
std::vector<T> pre_order_traversal_recursive(TreeNode<T> *root)
{
	std::vector<T> answer;
	pre_order_traversal(answer, root);
	return answer;
}


#endif //PRE_ORDER_TRAVERSAL_H
