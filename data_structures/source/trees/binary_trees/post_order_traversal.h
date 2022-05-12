//
// Created by andreas on 09.05.22.
//

#ifndef POST_ORDER_TRAVERSAL_H
#define POST_ORDER_TRAVERSAL_H
#include "tree_node.h"
#include <vector>
#include <stack>
#include <algorithm>

// For Post order, you traverse from the left subtree to the right subtree then to the root.
// Postorder => Left, Right, Root.
std::vector<int> post_order_traversal(TreeNode<int> *root)
{
	if (!root)
		return {};
	auto result = std::vector<int>();
	auto remember = std::stack<TreeNode<int> *>();
	remember.push(root);
	while (!remember.empty()) {
		root = remember.top();
		remember.pop();
		result.push_back(root->value);
		if (root->left)
			remember.push(root->left);
		if (root->right)
			remember.push(root->right);
	}
	std::reverse(result.begin(), result.end());
	return result;
}

void post_order_traversal(std::vector<int> & result, TreeNode<int> *root)
{
	if(!root)
		return;
	post_order_traversal(result, root->left);
	post_order_traversal(result, root->right);
	result.push_back(root->value);
}

std::vector<int> post_order_traversal_recursive(TreeNode<int> *root)
{
	std::vector<int> result;
	post_order_traversal(result, root);
	return result;
}

#endif //POST_ORDER_TRAVERSAL_H
