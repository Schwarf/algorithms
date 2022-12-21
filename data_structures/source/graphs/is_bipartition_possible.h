//
// Created by andreas on 21.12.22.
//

#ifndef IS_BIPARTITION_POSSIBLE_H
#define IS_BIPARTITION_POSSIBLE_H
#include <vector>
#include <queue>
#include "graph.h"
// We want to split a group of n objects (labeled from 1 to n) into two groups of any size.
// Each object may be connected with some other objects and not related to the objects of the other group.
// Given the integer n and the graph, return true if it is possible to split all objects into two groups in this way.

bool breadth_first_search(int source_node_id, BidirectionalGraph<int, int> & graph, std::vector<int> &node_colors)
{
	std::queue<GraphNodePtr<int, int>> bfs_queue;

	bfs_queue.push(graph.get_node_by_id(source_node_id));
	node_colors[source_node_id] = 0; // source node is always red
	while(!bfs_queue.empty()) {
		auto current_node = bfs_queue.front();
		bfs_queue.pop();
		for (const auto &neighbor: graph.get_neighbors(current_node))
		{
			// in a bipartite graph neighbors do not have the same color
			if(node_colors[current_node->id] == node_colors[neighbor->id])
				return false;
			if(node_colors[neighbor->id] == -1)
			{
				node_colors[neighbor->id] = 1 - node_colors[current_node->id];
				bfs_queue.push(neighbor);
			}
		}
	}
	return true;
}

bool is_bi_partition_possible(BidirectionalGraph<int, int> & graph)
{
	// we have two colors red and blue. Red is represented by '0', blue by '1'
	// The
	std::vector<int> node_colors(graph.size() + 1, -1);
	for (size_t id = 1; id <= graph.size(); ++id)
	{
		if(node_colors[id] == -1)
		{
			if(!breadth_first_search(id, graph, node_colors))
				return false;
		}
	}
	return true;

}

#endif //IS_BIPARTITION_POSSIBLE_H
