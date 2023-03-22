//
// Created by andreas on 22.03.23.
//

#ifndef FIND_SHORTEST_EDGE_IN_SUBGRAPH_H
#define FIND_SHORTEST_EDGE_IN_SUBGRAPH_H
#include "used_concepts.h"
#include <vector>
#include <stdexcept>
// Given a disconnected graph and two vertices. Find the shortest edge in the sub-graph that contains the two vertices.
// Each edge is given as std::vector of size 3 with [vertex_1, vertex_2, edge-length].
// All vertices are listed between n where n is the size of the input-vector.

template<typename VertexType>
requires VertexRequirement<VertexType>
VertexType find_shortest_edge_in_sub_graph_bfs(const std::vector<std::vector<VertexType>> &vertices,
											   const VertexType &start_vertex,
											   const VertexType &end_vertex)
{

	if (vertices.empty())
		throw std::invalid_argument("Empty vector in find_shortest_edge_in_sub_graph_bfs!");
	if (vertices.size() == 1)
		return vertices[0][2];
	// Transform into graph representation with adjacency list
	std::vector<std::vector<std::pair<VertexType, VertexType>>> graph(vertices.size() + 1);
	for (const auto &edge: vertices) {
		graph[edge[0]].push_back({edge[1], edge[2]});
		graph[edge[1]].push_back({edge[0], edge[2]});
	}
	
};


#endif //FIND_SHORTEST_EDGE_IN_SUBGRAPH_H
