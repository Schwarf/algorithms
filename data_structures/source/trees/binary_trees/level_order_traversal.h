//
// Created by andreas on 14.07.22.
//

#ifndef LEVEL_ORDER_TRAVERSAL_H
#define LEVEL_ORDER_TRAVERSAL_H
#include <vector>
#include <queue>
#include "tree_node.h"


template <typename T>
std::vector<std::vector<T>> level_order_traversal(TreeNode<T>* root) {
	if(!root)
		return {};
	auto result = std::vector<std::vector<T>>();
	std::queue<TreeNode<T>*> help;
	help.push(root);
	help.push(nullptr);
	auto node = root;
	while(!help.empty())
	{
		auto insert = std::vector<T>();
		if(help.front() != nullptr)
		{
			while(help.front() != nullptr)
			{
				node = help.front();
				insert.push_back(node->value);
				help.pop();
				if(node->left)
					help.push(node->left);
				if(node->right)
					help.push(node->right);
			}
			result.push_back(insert);
			help.push(nullptr);
		}
		else
			help.pop();
	}
	return result;
}

#endif //LEVEL_ORDER_TRAVERSAL_H
