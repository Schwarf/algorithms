//
// Created by andreas on 28.02.24.
//

#ifndef FIND_BOTTOM_LEFT_TREE_VALUE_H
#define FIND_BOTTOM_LEFT_TREE_VALUE_H
// Given the root of a binary tree, return the leftmost value in the last row of the tree.
#include <queue>
#include "tree_node.h"

template<typename T>
T find_bottom_left_value(TreeNode<T> *root)
{

	std::queue<TreeNode<T> *> q;
	q.push(root);
	int candidate{};
	while (!q.empty()) {
		q.push(nullptr);
		bool first{true};
		while (q.front()) {
			if (first && q.front()->left == nullptr) {
				candidate = q.front()->value;
				first = false;
			}
			if (q.front()->left) {
				q.push(q.front()->left);
			}
			if (q.front()->right) {
				q.push(q.front()->right);
			}
			q.pop();
		}
		q.pop();
	}
	return candidate;

}

// alternative is a simple BFS where the right node is visited before the left node (so in principal reversed). Same would work with DFS
template<typename T>
T find_bottom_left_value_bfs(TreeNode<T> *root)
{
	std::queue<TreeNode<T> *> q;
	q.push(root);
	T candidate{};
	while (!q.empty()) {
		candidate = q.front()->value;
		if (q.front()->right)
			q.push(q.front()->right);
		if (q.front()->left)
			q.push(q.front()->left);

		q.pop();
	}
	return candidate;
}


#endif //FIND_BOTTOM_LEFT_TREE_VALUE_H
