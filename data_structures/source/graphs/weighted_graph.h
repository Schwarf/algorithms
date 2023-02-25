//
// Created by andreas on 05.01.23.
//

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H
#include "graph.h"
#include <tuple>
#include <queue>

struct id_T_pair_hash
{
	template<typename id_T>
	std::size_t operator()(const std::array<id_T, 2> &id_pair) const
	{
		return std::hash<id_T>()(id_pair[0]) ^ std::hash<id_T>()(id_pair[1]);
	}
};

template<typename id_T, typename data_T, typename weight_T, bool directed_ = false>
class WeightedGraph
{
public:
	void set_has_cycle()
	{
		has_cycle_ = true;
	}

	std::set<id_T> get_neighbors(const GraphNodePtr<id_T, data_T> &vertex)
	{
		return this->edges_[vertex->id];
	}
	std::set<id_T> get_neighbors(id_T id)
	{
		return this->edges_[id];
	}

	GraphNodePtr<id_T, data_T> get_vertex_by_id(id_T id)
	{
		return vertices_[id];
	}

	void add_edge(const GraphNodePtr<id_T, data_T> &source_vertex,
				  const GraphNodePtr<id_T, data_T> &destination_vertex, const weight_T &weight)
	{
		if (vertices_.find(source_vertex->id) == vertices_.end())
			add_vertex(source_vertex);
		if (vertices_.find(destination_vertex->id) == vertices_.end())
			add_vertex(destination_vertex);
		add_edge(source_vertex->id, destination_vertex->id, weight);
	}

	void add_vertex(const GraphNodePtr<id_T, data_T> &vertex)
	{
		vertices_[vertex->id] = vertex;
	}

	std::size_t number_of_vertices() const
	{
		return vertices_.size();
	}

	void add_edge(const id_T &source_vertex_id,
				  const id_T &destination_vertex_id, const weight_T &weight)
	{
		if (vertices_.find(source_vertex_id) == vertices_.end())
			throw std::invalid_argument(
				"The source vertex id=" + std::to_string(source_vertex_id) + " does not exist in the graph!");
		if (vertices_.find(destination_vertex_id) == vertices_.end())
			throw std::invalid_argument(
				"The destination vertex id=" + std::to_string(destination_vertex_id) + " does not exist in the graph!");
		edges_[source_vertex_id].insert(destination_vertex_id);
		weights_[{source_vertex_id, destination_vertex_id}] = weight;
		if (!directed_) {
			edges_[destination_vertex_id].insert(source_vertex_id);
			weights_[{destination_vertex_id, source_vertex_id}] = weight;
		}
	}
	void reset_all_vertex_properties()
	{
		for (auto &[id, vertex]: vertices_) {
			vertex->discovered = false;
			vertex->processed = false;
		}
		has_cycle_ = false;
	}

	bool has_cycle()
	{
		return has_cycle_;
	}

	weight_T get_edge_weight(const id_T &source_vertex_id, const id_T &destination_vertex_id)
	{
		if (vertices_.find(source_vertex_id) == vertices_.end())
			throw std::invalid_argument(
				"The source vertex id=" + std::to_string(source_vertex_id) + " does not exist in the graph!");
		if (vertices_.find(destination_vertex_id) == vertices_.end())
			throw std::invalid_argument(
				"The destination vertex id=" + std::to_string(destination_vertex_id) + " does not exist in the graph!");
		std::array<id_T, 2> id_pair{source_vertex_id, destination_vertex_id};
		if (weights_.find(id_pair) == weights_.end())
			throw std::invalid_argument(
				"The edge with source id " + std::to_string(source_vertex_id) + " and destination id "
					+ std::to_string(destination_vertex_id) + " does not exist in the graph!");
		return weights_[id_pair];
	}

	bool erase_vertex(id_T id_to_erase)
	{
		bool is_in_graph = edges_.find(id_to_erase) != edges_.end();
		bool is_in_vertices = vertices_.find(id_to_erase) != vertices_.end();
		if (!is_in_graph && !is_in_vertices)
			return false;

		if (is_in_vertices)
			vertices_.erase(id_to_erase);

		if (is_in_graph) {
			auto affected_neighbors = get_neighbors(id_to_erase);
			edges_.erase(id_to_erase);
			for (const auto &neighbor_id: affected_neighbors) {
				auto id_iterator =
					std::find_if(edges_[neighbor_id].begin(),
								 edges_[neighbor_id].end(),
								 [id_to_erase](const id_T &vertex_id)
								 { return vertex_id == id_to_erase; });

				edges_[neighbor_id].erase(id_iterator);
				weights_.erase({id_to_erase, neighbor_id});
			}

		}
		return true;
	}

	// Simple prim algo is O(N^2), if we neglect the introduced overhead by data-structures (std::map,
	// std::unordered_map)
	std::map<id_T, std::pair<id_T, weight_T>> compute_minimum_spanning_tree_simple_prim(
		const GraphNodePtr<id_T, data_T> &start_vertex)
	{
		reset_all_vertex_properties();
		std::unordered_map<id_T, weight_T> minimum_weight_for_vertex_id;
		std::map<id_T, std::pair<id_T, weight_T>> parents;
		for (const auto &[id, id_sets]: edges_)
			minimum_weight_for_vertex_id[id] = std::numeric_limits<weight_T>::max();
		auto current_vertex_id = start_vertex->id;
		weight_T current_edge_weight;

		while (!get_vertex_by_id(current_vertex_id)->discovered) {

			get_vertex_by_id(current_vertex_id)->discovered = true;
			for (const auto &neighbor_id: get_neighbors(current_vertex_id)) {
				current_edge_weight = weights_[{current_vertex_id, neighbor_id}];
				// if new minimum weight is found in undiscovered vertex store weight in hashmap and update parent
				if (!get_vertex_by_id(neighbor_id)->discovered
					&& current_edge_weight < minimum_weight_for_vertex_id[neighbor_id]) {
					minimum_weight_for_vertex_id[neighbor_id] = current_edge_weight;
					parents[neighbor_id] = std::make_pair(current_vertex_id, current_edge_weight);
				}
			}
			// for the next for loop determine the absolute minimum weight across all id's
			weight_T minimum_weight = std::numeric_limits<weight_T>::max();
			for (const auto &[id, _]: edges_) {
				if (!get_vertex_by_id(id)->discovered
					&& minimum_weight_for_vertex_id[id] < minimum_weight) {
					minimum_weight = minimum_weight_for_vertex_id[id];
					current_vertex_id = id;
				}
			}
		}
		return parents;
	}

	// This function computes the shortest path to all vertices from the start vertex
	std::unordered_map<id_T, weight_T> primitive_dijkstra(const GraphNodePtr<id_T, data_T> &start_vertex)
	{
		reset_all_vertex_properties();
		std::unordered_map<id_T, weight_T> distance;
		for (const auto &[id, id_sets]: edges_)
			distance[id] = std::numeric_limits<weight_T>::max();
		auto current_vertex_id = start_vertex->id;
		weight_T current_edge_weight;
		distance[current_vertex_id] = 0;
		while (!get_vertex_by_id(current_vertex_id)->discovered) {

			get_vertex_by_id(current_vertex_id)->discovered = true;
			for (const auto &neighbor_id: get_neighbors(current_vertex_id)) {
				current_edge_weight = weights_[{current_vertex_id, neighbor_id}];
				// if the current neighbor distance is larger than the distance to the current vertex plus the weight
				// between neighbor and current-vertex
				if ((distance[current_vertex_id] + current_edge_weight)
					< distance[neighbor_id]) {
					distance[neighbor_id] =
						current_edge_weight + distance[current_vertex_id];
				}
			}
			// for the next for loop determine the absolute minimum weight across all id's
			weight_T minimum_weight = std::numeric_limits<weight_T>::max();
			for (const auto &[id, _]: edges_) {
				if (!get_vertex_by_id(id)->discovered
					&& distance[id] < minimum_weight) {
					minimum_weight = distance[id];
					current_vertex_id = id;
				}
			}
		}
		return distance;
	}

	std::unordered_map<id_T, weight_T> real_dijkstra(const GraphNodePtr<id_T, data_T> &start_vertex)
	{
		// this constructs a min-heap (std::greater) based on a tuple. The default comparison with std::greater is done
		// lexicographically
		std::priority_queue<std::tuple<weight_T, id_T>, std::vector<std::tuple<weight_T, id_T>>, std::greater<>> queue;
		std::unordered_map<id_T, weight_T> distances;
		for (const auto &[id, id_sets]: edges_)
			distances[id] = std::numeric_limits<weight_T>::max();

		queue.emplace(weight_T{}, start_vertex->id);
		while (!queue.empty()) {
			auto [current_distance, current_vertex_id] = queue.top();
			queue.pop();
			get_vertex_by_id(current_vertex_id)->discovered = true;
			for (const auto &neighbor_id: get_neighbors(current_vertex_id)) {
				auto new_distance = current_distance + weights_[{current_vertex_id, neighbor_id}];
				if (distances[neighbor_id] > new_distance) {
					distances[neighbor_id] = new_distance;
					queue.emplace(new_distance, neighbor_id);
				}
			}
		}
		return distances;
	}


private:
	// Here we store the relations between vertices/vertices if they exist including the weights.
	std::unordered_map<id_T, std::set<id_T>> edges_;
	// Store the weights
	std::unordered_map<std::array<id_T, 2>, weight_T, id_T_pair_hash> weights_;
	// Here we store all graph-vertices (id, data) pairs, that can be retrieved using the id. A vertex might be isolated.
	// not participating in any relations with other vertexs
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> vertices_;

	bool has_cycle_{};
};


#endif //WEIGHTED_GRAPH_H
