//
// Created by andreas on 11.11.23.
//

#ifndef DESIGN_GRAPH_WITH_SHORTEST_PATH_CALCULATOR_H
#define DESIGN_GRAPH_WITH_SHORTEST_PATH_CALCULATOR_H

#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>
// A directed weighted graph that consists of n nodes numbered from 0 to n - 1.
// The edges of the graph are initially represented by the given array edges where edges[i] = [from, to, weight]
// meaning that there is an edge from 'from' to 'to' with the cost 'weight'.
// Implement the Graph class:
//	- Graph(int n, vector<vector<int>> edges) initializes the object with n nodes and the given edges.
//  - void addEdge(vector<int> edge) adds an edge to the list of edges.
//    It is guaranteed that there is no edge between the two nodes before adding this one.
//  - int shortestPath(int start_node, int end_node) returns the minimum cost of a path from start_node to end_node.
//    If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.

template<typename T> requires std::is_unsigned_v<T>
class Graph
{
public:
	Graph(int number_of_nodes, const std::vector<std::vector<T>> &edges_with_weights)
		: number_of_edges_{number_of_nodes}
	{
		for (const auto triple: edges_with_weights) {
			graph[triple[0]].push_back({triple[1], triple[2]});
		}
	}

	void add_edge(const std::vector<T> &triple)
	{
		graph[triple[0]].push_back({triple[1], triple[2]});
		number_of_edges_++;
	}

	int shortest_path(T start_node, T end_node)
	{
		std::priority_queue<std::pair<T, T>, std::vector<std::pair<T, T>>, std::greater<std::pair<T, T>>> q;
		// ew need to track the costs since the shortest path must not be the cheaped
		std::vector cost_for_node(number_of_edges_, std::numeric_limits<T>::max());
		q.push({0, start_node});
		while (!q.empty()) {
			auto [current_cost, current_node] = q.top();
			if (current_cost > cost_for_node[current_node])
				continue;
			if (current_node == end_node)
				return current_cost;
			for (const auto &neighbor: graph[current_node]) {
				T neighbor_node = neighbor.first;
				T cost = neighbor.second;
				T new_cost = current_cost + cost;
				if (new_cost < cost_for_node[neighbor_node]) {
					cost_for_node[neighbor_node] = new_cost;
					q.push({new_cost, neighbor_node});
				}
			}
		}
		return -1;
	}


private:
	int number_of_edges_;
	std::unordered_map<T, std::vector<std::pair<T, T>>> graph;
};

#endif //DESIGN_GRAPH_WITH_SHORTEST_PATH_CALCULATOR_H
