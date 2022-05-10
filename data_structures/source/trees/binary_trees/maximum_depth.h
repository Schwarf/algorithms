//
// Created by andreas on 10.05.22.
//

#ifndef MAXIMUM_DEPTH_H
#define MAXIMUM_DEPTH_H
#include "tree_node.h"
#include <queue>
#include <algorithm>

int maximum_depth_recursive(TreeNode<int>* root)
{
	if (!root)
		return 0;
	return 1 + std::max(maximum_depth_recursive(root->left), maximum_depth_recursive(root->right));
}


int maximum_depth(TreeNode<int>* root)
{
	auto nodes_per_level = std::queue<TreeNode<int> *>();
	int node_count{};
	if (!root)
		return 0;
	nodes_per_level.push(root);
	int height{};
	while (!nodes_per_level.empty())
	{
		height++;
		node_count = nodes_per_level.size();
		while(node_count--)
		{
			auto node = nodes_per_level.front();
			if (node->left)
				nodes_per_level.push(node->left);
			if (node->right)
				nodes_per_level.push(node->right);
			nodes_per_level.pop();
		}
	}
	return height;
}


#endif //MAXIMUM_DEPTH_H
