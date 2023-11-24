//
// Created by andreas on 24.11.23.
//

#ifndef IS_GRAPH_VALID_TREE_H
#define IS_GRAPH_VALID_TREE_H
// Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes),
// write a function to check whether these edges make up a valid tree.
#include <vector>
#include <queue>
#include <concepts>
template<typename T>
requires std::is_unsigned_v<T>
bool is_graph_valid_tree(int number_of_nodes, const std::vector<std::vector<T>> &edges)
{
	std::vector<std::vector<T>> graph(number_of_nodes);
	for (const auto &edge: edges) {
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[2]);
	}
	std::queue<T> q{{0}};
	std::vector<bool> visited(number_of_nodes);
	while (!q.empty()) {
		auto current = q.front();
		q.pop();
		if (visited[current])
			return false;
		for (const auto &node: visited[current]) {
			q.push(node);
		}
		visited[current] = true;
	}
	return true;
}

#endif //IS_GRAPH_VALID_TREE_H
