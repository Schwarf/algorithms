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
#include <unordered_set>
template<typename T>
requires std::is_unsigned_v<T>
bool is_graph_valid_tree(int number_of_nodes, const std::vector<std::vector<T>> &edges)
{
	if (number_of_nodes == 0 || number_of_nodes - 1 != edges.size())
		return false;
	std::vector<std::vector<T>> graph(number_of_nodes);
	for (const auto &edge: edges) {
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);

	}
	std::queue<T> q{{0}};
	std::vector<bool> visited(number_of_nodes);
	std::vector<T> parent(number_of_nodes, -1);
	while (!q.empty()) {
		auto current = q.front();
		q.pop();
		if (visited[current])
			return false;
		for (const auto &node: graph[current]) {
			if (!visited[node]) {
				parent[node] = current;
				q.push(node);
			}
			else if (parent[current] != node)
				return false;
		}
		visited[current] = true;
	}
	return true;
}

template<typename T>
requires std::is_unsigned_v<T>
bool is_graph_valid_tree_with_set(int number_of_nodes, const std::vector<std::vector<T>> &edges)
{
	if (number_of_nodes == 0 || edges.size() != number_of_nodes - 1)
		return false;

	std::vector<std::vector<int>> graph(number_of_nodes);
	std::queue<int> q{{0}};
	std::unordered_set<int> seen{0};

	for (const auto &edge: edges) {
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}

	while (!q.empty()) {
		auto current = q.front();
		q.pop();
		for (const auto &node: graph[current])
			if (!seen.count(node)) {
				q.push(node);
				seen.insert(node);
			}
	}

	return seen.size() == number_of_nodes;
}


#endif //IS_GRAPH_VALID_TREE_H
