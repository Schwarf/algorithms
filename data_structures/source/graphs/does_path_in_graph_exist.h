//
// Created by andreas on 19.12.22.
//

#ifndef DOES_PATH_IN_GRAPH_EXIST_H
#define DOES_PATH_IN_GRAPH_EXIST_H
#include "graph.h"
#include <queue>

template<typename id_T, typename data_T>
bool does_path_exist(Graph<id_T, data_T> &graph,
					 const GraphNodePtr<id_T, data_T> &source_vertex,
					 const GraphNodePtr<id_T, data_T> &destination_vertex)
{
	std::queue<id_T> bfs_queue;
	std::unordered_map<id_T, bool> visited;
	bfs_queue.push(source_vertex->id);
//	visited[source_vertex] = true;
	while (!bfs_queue.empty()) {
		const auto current_vertex_id = bfs_queue.front();
		bfs_queue.pop();
		if (current_vertex_id == destination_vertex->id)
			return true;
		for (const auto next_vertex_id: graph.get_neighbors(current_vertex_id)) {
			if (!visited[next_vertex_id]) {
				bfs_queue.push(next_vertex_id);
				visited[next_vertex_id] = true;
			}
		}

	}
	return false;
}

#endif //DOES_PATH_IN_GRAPH_EXIST_H
