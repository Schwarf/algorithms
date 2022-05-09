//
// Created by andreas on 09.05.22.
//

#ifndef PRE_ORDER_TRAVERSAL_H
#define PRE_ORDER_TRAVERSAL_H
#include "tree_node.h"
#include <vector>
#include <stack>

std::vector<int> pre_order_traversal(TreeNode<int>* root)
{
	std::vector<int> answer;
	std::stack<TreeNode<int>*> remember_right_leafs;
	while(root || !remember_right_leafs.empty())
	{
		while(root)
		{
			answer.push_back(root->value);
			if(root->right)
				remember_right_leafs.push(root->right);
			root = root->left;
		}
		if(!remember_right_leafs.empty()) {
			root = remember_right_leafs.top();
			remember_right_leafs.pop();
		}
	}
	return answer;
}

void pre_order_traversal(std::vector<int> & result, TreeNode<int>* root)
{
	if(!root)
		return;
	result.push_back(root->value);
	pre_order_traversal(result, root->left);
	pre_order_traversal(result, root->right);
}

std::vector<int> pre_order_traversal_recursive(TreeNode<int>* root)
{
	std::vector<int> answer;
	pre_order_traversal(answer, root);
	return answer;
}


#endif //PRE_ORDER_TRAVERSAL_H
