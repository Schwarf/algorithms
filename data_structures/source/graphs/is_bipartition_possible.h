//
// Created by andreas on 21.12.22.
//

#ifndef IS_BIPARTITION_POSSIBLE_H
#define IS_BIPARTITION_POSSIBLE_H
#include <vector>
#include <queue>
#include "graph.h"
// We want to split a group of n objects (labeled from 1 to n) into two groups of any size.
// Each object in one goup may be connected with some other objects of the other group BUT not related to the objects
// of the OWN group.
// Given the integer n and the graph, return true if it is possible to split all objects into two groups in this way.

bool breadth_first_search(int source_vertex_id, Graph<int, int> &graph, std::vector<int> &vertex_colors)
{
	std::queue<int> bfs_queue;

	bfs_queue.push(source_vertex_id);
	vertex_colors[source_vertex_id] = 0; // source vertex is always red
	while (!bfs_queue.empty()) {
		auto current_vertex_id = bfs_queue.front();
		bfs_queue.pop();
		for (const auto &neighbor_id: graph.get_neighbors(current_vertex_id)) {
			// in a bipartite graph neighbors do not have the same color
			if (vertex_colors[current_vertex_id] == vertex_colors[neighbor_id])
				return false;
			if (vertex_colors[neighbor_id] == -1) {
				vertex_colors[neighbor_id] = 1 - vertex_colors[current_vertex_id];
				bfs_queue.push(neighbor_id);
			}
		}
	}
	return true;
}

bool is_bi_partition_possible(Graph<int, int> &graph)
{
	// we have two colors red and blue. Red is represented by '0', blue by '1'
	// The
	std::vector<int> vertex_colors(graph.number_of_vertices() + 1, -1);
	for (size_t id = 1; id <= graph.number_of_vertices(); ++id) {
		if (vertex_colors[id] == -1) {
			if (!breadth_first_search(id, graph, vertex_colors))
				return false;
		}
	}
	return true;

}

#endif //IS_BIPARTITION_POSSIBLE_H
