//
// Created by andreas on 22.03.23.
//

#ifndef FIND_SMALLEST_EDGE_IN_SUBGRAPH_H
#define FIND_SMALLEST_EDGE_IN_SUBGRAPH_H
#include "used_concepts.h"
#include <vector>
#include <queue>
#include <stdexcept>
// Given a disconnected graph and two vertices. Find the smallest edge in the sub-graph that contains the two vertices.
// Each edge is given as std::vector of size 3 with [vertex_1, vertex_2, edge-length].
// All vertices are listed between 1 and n where n is the size of the input-vector.
// As function template we have to provide the maximal edge value as 4th argument.
// As function template we have to provide the default value if the vertices are not connected as 5th argument.

template<typename VertexType>
requires VertexRequirement<VertexType>
VertexType find_smallest_edge_in_sub_graph_bfs(const std::vector<std::vector<VertexType>> &vertices,
											   const VertexType &start_vertex,
											   const VertexType &end_vertex,
											   const VertexType &max_edge_value,
											   const VertexType &not_connected_value)
{

	if (vertices.empty())
		throw std::invalid_argument("Empty vector in find_smallest_edge_in_sub_graph_bfs!");
	if (vertices.size() == 1)
		return vertices[0][2];
	// Transform into graph representation with adjacency list
	std::vector<std::vector<std::pair<VertexType, VertexType>>> graph(vertices.size() + 1);
	for (const auto &edge: vertices) {
		graph[edge[0]].push_back({edge[1], edge[2]});
		graph[edge[1]].push_back({edge[0], edge[2]});
	}
	std::queue<VertexType> q;
	q.push(start_vertex);
	VertexType minimum{max_edge_value};
	std::vector<bool> visited(vertices.size() + 1);
	bool end_vertex_found{};
	while (!q.empty()) {
		auto node = q.front();
		q.pop();
		for (const auto &edge: graph[node]) {
			if (!visited[edge.first]) {
				visited[edge.first] = true;
				minimum = std::min(minimum, edge.second);
				if (edge.first == end_vertex)
					end_vertex_found = true;
			}
		}
	}
	return end_vertex_found ? minimum : not_connected_value;
};


#endif //FIND_SMALLEST_EDGE_IN_SUBGRAPH_H
