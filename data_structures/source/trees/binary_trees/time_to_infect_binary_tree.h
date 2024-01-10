//
// Created by andreas on 10.01.24.
//

#ifndef TIME_TO_INFECT_BINARY_TREE_H
#define TIME_TO_INFECT_BINARY_TREE_H
// You are given the root of a binary tree with unique values, and an integer start. At minute 0,
// an infection starts from the node with value start.
// Each minute, a node becomes infected if:
// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

// Follow up what happens if I have multiple nodes infected initially?
#include <vector>
#include <unordered_map>
#include <queue>
#include "tree_node.h"
using Node = TreeNode<int>;
int time_to_infect_binary_tree(Node *root, int start_value)
{
	// convert tree to graph
	std::unordered_map<int, std::vector<int>> graph;
	std::queue<Node *> q{{root}};
	q.push(nullptr);
	while (!q.empty()) {
		if (q.front() != nullptr) {
			while (q.front() != nullptr) {
				auto current = q.front();
				q.pop();
				if (current->left) {
					graph[current->value].push_back(current->left->value);
					graph[current->left->value].push_back(current->value);
					q.push(current->left);
				}
				if (current->right) {
					graph[current->value].push_back(current->right->value);
					graph[current->right->value].push_back(current->value);
					q.push(current->right);
				}
			}
		}
		else
			q.pop();
	}
}

#endif //TIME_TO_INFECT_BINARY_TREE_H
