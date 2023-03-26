//
// Created by andreas on 26.03.23.
//

#ifndef MINIMUM_NUMBER_OF_EGDES_TO_CREATE_CONNECTED_GRAPH_H
#define MINIMUM_NUMBER_OF_EGDES_TO_CREATE_CONNECTED_GRAPH_H
// Given is a graph with disconnected sub-graphs with n cable connections.
// Determine if the n cables can be rearranged
// to make the graph a connected graph. If there are not enough cables return -1;
#include "used_concepts.h"
#include <vector>
#include <queue>

template<VertexRequirement VertexType>
void breadth_first_search(VertexType node,
						  const std::vector<std::vector<VertexType>> &graph,
						  std::vector<bool> &visited)
{
	std::queue<VertexType> q({node});
	visited[node] = true;
	while (!q.empty()) {
		auto current_node = q.front();
		q.pop();
		for (const auto &neighbor: graph[current_node]) {
			if (!visited[neighbor]) {
				q.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
}

template<VertexRequirement VertexType>
int minimum_number_of_edges_to_create_connected_graph(VertexType n, std::vector<std::vector<VertexType>> connections)
{
	VertexType cables = connections.size();
	if (n < 1 || cables < n - 1)
		return -1;
	std::vector<std::vector<VertexType>> graph(n);

	for (const auto &connection: connections) {
		graph[connection[0]].push_back(connection[1]);
		graph[connection[1]].push_back(connection[0]);
	}

	std::vector<bool> visited(n);
	int number_of_connected_vertices{};
	for (VertexType i{}; i < n; ++i) {
		if (!visited[i]) {
			number_of_connected_vertices++;
			breadth_first_search(i, graph, visited);
		}
	}
	return number_of_connected_vertices;

}


#endif //MINIMUM_NUMBER_OF_EGDES_TO_CREATE_CONNECTED_GRAPH_H
