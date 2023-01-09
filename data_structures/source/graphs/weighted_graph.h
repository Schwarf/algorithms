//
// Created by andreas on 05.01.23.
//

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H
#include "graph.h"

struct id_T_pair_hash
{
	template<typename id_T>
	std::size_t operator()(const std::pair<id_T, id_T> &id_pair) const
	{
		return std::hash<id_T>()(id_pair.first) ^ std::hash<id_T>()(id_pair.second);
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
				"The vertex id " + std::to_string(source_vertex_id) + "does not exist in the graph!");
		if (vertices_.find(destination_vertex_id) == vertices_.end())
			throw std::invalid_argument(
				"The vertex id " + std::to_string(destination_vertex_id) + "does not exist in the graph!");
		edges_[source_vertex_id].insert(destination_vertex_id);
		weights_[std::make_pair(source_vertex_id, destination_vertex_id)] = weight;
		if (!directed_) {
			edges_[destination_vertex_id].insert(source_vertex_id);
			weights_[std::make_pair(destination_vertex_id, source_vertex_id)] = weight;
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
				"The vertex id " + std::to_string(source_vertex_id) + " does not exist in the graph!");
		if (vertices_.find(destination_vertex_id) == vertices_.end())
			throw std::invalid_argument(
				"The vertex id " + std::to_string(destination_vertex_id) + " does not exist in the graph!");
		auto id_pair = std::make_pair(source_vertex_id, destination_vertex_id);
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
				weights_.erase(std::make_pair(id_to_erase, neighbor_id));
			}

		}
		return true;
	}

private:
	// Here we store the relations between vertices/vertices if they exist including the weights.
	std::unordered_map<id_T, std::set<id_T>> edges_;
	// Store the weights
	std::unordered_map<std::pair<id_T, id_T>, weight_T, id_T_pair_hash> weights_;
	// Here we store all graph-vertices (id, data) pairs, that can be retrieved using the id. A vertex might be isolated.
	// not participating in any relations with other vertexs
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> vertices_;
	bool has_cycle_{};
};


#endif //WEIGHTED_GRAPH_H
