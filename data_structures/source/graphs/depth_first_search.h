//
// Created by andreas on 03.01.23.
//

#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H
#include <stack>
#include <map>
#include <vector>
#include "graph.h"

template<typename id_T, typename data_T>
std::map<id_T, id_T> get_depth_first_search_tree(Graph<id_T, data_T> &graph,
												 const GraphNodePtr<id_T, data_T> &start_node)
{
	std::stack<id_T> dfs_stack;
	dfs_stack.push(start_node->id);
	std::map<id_T, id_T> dfs_tree;
	while (!dfs_stack.empty()) {
		auto current_node_id = dfs_stack.top();
		dfs_stack.pop();
		graph.get_node_by_id(current_node_id)->discovered = true;
		for (const auto &neighbor_id: graph.get_neighbors(current_node_id)) {
			if (graph.get_node_by_id(neighbor_id)->processed)
				continue;
			if (graph.get_node_by_id(neighbor_id)->discovered) {
				if (dfs_tree.find(neighbor_id) != dfs_tree.end() && current_node_id != dfs_tree[neighbor_id])
					graph.set_has_cycle();
				continue;
			}
			graph.get_node_by_id(neighbor_id)->discovered = true;
			dfs_stack.push(neighbor_id);
			dfs_tree[neighbor_id] = current_node_id;
		}
		graph.get_node_by_id(current_node_id)->processed = true;
	}
	return dfs_tree;
}

#endif //DEPTH_FIRST_SEARCH_H
