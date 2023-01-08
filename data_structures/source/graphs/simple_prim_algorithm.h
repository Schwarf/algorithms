//
// Created by andreas on 08.01.23.
//

#ifndef SIMPLE_PRIM_ALGORITHM_H
#define SIMPLE_PRIM_ALGORITHM_H
#include "weighted_graph.h"
#include <map>

template<typename id_T>
struct MinimumSpanningTreeNode
{
	explicit MinimumSpanningTreeNode(id_T init_id)
	{
		id = init_id;
	}
	id_T id;
	MinimumSpanningTreeNode *next;
};

template<typename id_T, typename data_T, typename weight_T>
std::map<id_T, std::pair<id_T, weight_T>> simple_prim_algorithm(WeightedGraph<id_T, data_T, weight_T> &graph,
																const GraphNodePtr<id_T, data_T> &start_vertex)
{
	graph.reset_all_vertex_properties();
	auto head = MinimumSpanningTreeNode(start_vertex->id);
	std::map<id_T, std::pair<id_T, weight_T>> minimum_spanning_tree;
	auto current_vertex_id = start_vertex->id;
	auto next_vertex_id = start_vertex->id;
	weight_T current_edge_weight{};
	while (!graph.get_vertex_by_id(current_vertex_id)->discovered) {

		graph.get_vertex_by_id(current_vertex_id)->discovered = true;
		bool weight_init{};
		for (const auto &neighbor_id: graph.get_neighbors(current_vertex_id)) {
			if (graph.get_vertex_by_id(neighbor_id)->discovered)
				continue;
			current_edge_weight = graph.get_edge_weight(current_vertex_id, neighbor_id);
			if (!weight_init) {
				minimum_spanning_tree[current_vertex_id] = std::make_pair(neighbor_id, current_edge_weight);
				next_vertex_id = neighbor_id;
				weight_init = true;
				continue;
			}
			if (current_edge_weight < minimum_spanning_tree[current_vertex_id].second) {
				minimum_spanning_tree[current_vertex_id] = std::make_pair(neighbor_id, current_edge_weight);
				next_vertex_id = neighbor_id;
			}
		}
		current_vertex_id = next_vertex_id;

	}
	return minimum_spanning_tree;
}

#endif //SIMPLE_PRIM_ALGORITHM_H
