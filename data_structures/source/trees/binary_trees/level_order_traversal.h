//
// Created by andreas on 14.07.22.
//

#ifndef LEVEL_ORDER_TRAVERSAL_H
#define LEVEL_ORDER_TRAVERSAL_H
#include <vector>
#include <queue>
#include "tree_node.h"


template<typename T>
std::vector<std::vector<T>> level_order_traversal(TreeNode<T> *root)
{
	if (!root)
		return {};
	auto result = std::vector<std::vector<T>>();
	std::queue<TreeNode<T> *> help;
	help.push(root);
	help.push(nullptr);
	auto node = root;
	while (!help.empty()) {
		auto insert = std::vector<T>();
		if (help.front() != nullptr) {
			while (help.front() != nullptr) {
				node = help.front();
				insert.push_back(node->value);
				help.pop();
				if (node->left)
					help.push(node->left);
				if (node->right)
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

template<typename T>
std::vector<std::vector<T>> concise_level_order_traversal(TreeNode<T> *root)
{
	if(!root)
		return{};
	std::queue<TreeNode<T>* > q{{root}};
	std::vector<std::vector<T>> result;
	while(!q.empty())
	{
		int size = q.size();
		std::vector<int> level(size);
		for(int i{}; i < size; ++i)
		{
			auto node = q.front();
			q.pop();
			level[i] = node->val;
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
		result.push_back(level);
		level.clear();
	}
	return result;
}
#endif //LEVEL_ORDER_TRAVERSAL_H
