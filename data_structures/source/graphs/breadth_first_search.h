//
// Created by andreas on 03.01.23.
//

#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H
#include <queue>
#include <map>
#include <vector>
#include "graph.h"

template<typename id_T, typename data_T>
std::map<id_T, id_T> get_breadth_first_search_tree(Graph<id_T, data_T> &graph,
												   const GraphNodePtr<id_T, data_T> &start_node)
{
	std::queue<id_T> bfs_queue;
	bfs_queue.push(start_node->id);
	std::map<id_T, id_T> bfs_tree;
	while (!bfs_queue.empty()) {
		id_T node_id = bfs_queue.front();
		graph.get_node_by_id(node_id)->discovered = true;
		bfs_queue.pop();
		for (const auto &neighbor_id: graph.get_neighbors(node_id)) {
			if (graph.get_node_by_id(neighbor_id)->discovered)
				continue;
			bfs_tree[neighbor_id] = node_id;
			bfs_queue.push(neighbor_id);
			graph.get_node_by_id(neighbor_id)->discovered = true;

		}
		graph.get_node_by_id(node_id)->processed = true;
	}
	return bfs_tree;
}

#endif //BREADTH_FIRST_SEARCH_H
