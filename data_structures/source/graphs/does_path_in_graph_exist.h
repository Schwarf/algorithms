//
// Created by andreas on 19.12.22.
//

#ifndef DOES_PATH_IN_GRAPH_EXIST_H
#define DOES_PATH_IN_GRAPH_EXIST_H
#include "graph.h"
#include <queue>

template<typename id_T, typename data_T>
bool does_path_exist(Graph<id_T, data_T> &graph,
					 const GraphNodePtr<id_T, data_T> &source_node,
					 const GraphNodePtr<id_T, data_T> &destination_node)
{
	std::queue<id_T> bfs_queue;
	std::unordered_map<id_T, bool> visited;
	bfs_queue.push(source_node->id);
//	visited[source_node] = true;
	while (!bfs_queue.empty()) {
		const auto current_node_id = bfs_queue.front();
		bfs_queue.pop();
		if (current_node_id == destination_node->id)
			return true;
		for (const auto next_node_id: graph.get_neighbors(current_node_id)) {
			if (!visited[next_node_id]) {
				bfs_queue.push(next_node_id);
				visited[next_node_id] = true;
			}
		}

	}
	return false;
}

#endif //DOES_PATH_IN_GRAPH_EXIST_H
