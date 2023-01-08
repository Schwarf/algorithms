//
// Created by andreas on 08.01.23.
//

#ifndef PRIMS_ALGORITHM_H
#define PRIMS_ALGORITHM_H
#include "weighted_graph.h"
#include <map>
template<typename id_T, typename data_T, typename weight_T>
std::map<id_T, std::pair<id_T, weight_T>> prims_algorithm(const WeightedGraph<id_T, data_T, weight_T> &graph,
														  const GraphNodePtr<id_T, data_T> &start_vertex)
{
	graph.reset_all_vertex_properties();
	std::map<id_T, std::pair<id_T, weight_T>> minimum_spanning_tree;
	auto current_vertex_id = start_vertex->id;
	weight_T current_edge_weight{};
	while (!graph.get_vertex_by_id(current_vertex_id)->discovered) {

		graph.get_vertex_by_id(current_vertex_id)->discovered = true;
		bool weight_init{};
		for (const auto &neighbor_id: graph.get_neighbors(current_vertex_id)) {
			if (!graph.get_vertex_by_id(neighbor_id)->discovered) {
				current_edge_weight = graph.get_edge_weight(current_vertex_id, neighbor_id);
				if (!weight_init) {
					minimum_spanning_tree[current_vertex_id] = std::make_pair(neighbor_id, current_edge_weight);
					weight_init = true;
					continue;
				}
				if (current_edge_weight < minimum_spanning_tree[current_vertex_id].second)
					minimum_spanning_tree[current_vertex_id] = std::make_pair(neighbor_id, current_edge_weight);
			}
		}

	}
	return minimum_spanning_tree;
}

#endif //PRIMS_ALGORITHM_H
