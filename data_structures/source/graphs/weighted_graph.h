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

	std::set<id_T> get_neighbors(const GraphNodePtr<id_T, data_T> &node)
	{
		return this->edges_[node->id];
	}
	std::set<id_T> get_neighbors(id_T id)
	{
		return this->edges_[id];
	}

	GraphNodePtr<id_T, data_T> get_node_by_id(id_T id)
	{
		return vertices_[id];
	}

	void add_edge(const GraphNodePtr<id_T, data_T> &source_node,
				  const GraphNodePtr<id_T, data_T> &destination_node, const weight_T &weight)
	{
		if (vertices_.find(source_node->id) == vertices_.end())
			vertices_[source_node->id] = source_node;
		if (vertices_.find(destination_node->id) == vertices_.end())
			vertices_[destination_node->id] = destination_node;
		add_edge(source_node->id, destination_node->id, weight);
	}

	void add_vertex(const GraphNodePtr<id_T, data_T> &node)
	{
		vertices_[node->id] = node;
	}

	std::size_t number_of_vertices() const
	{
		return vertices_.size();
	}

	void add_edge(const id_T &source_node_id,
				  const id_T &destination_node_id, const weight_T &weight)
	{
		if (vertices_.find(source_node_id) == vertices_.end())
			throw std::invalid_argument(
				"The node id " + std::to_string(source_node_id) + "does not exist in the graph!");
		if (vertices_.find(destination_node_id) == vertices_.end())
			throw std::invalid_argument(
				"The node id " + std::to_string(destination_node_id) + "does not exist in the graph!");
		edges_[source_node_id].insert(destination_node_id);
		weights_[std::make_pair(source_node_id, destination_node_id)] = weight;
		if (!directed_)
			edges_[destination_node_id].insert(source_node_id);
	}
	void reset_all_node_properties()
	{
		for (auto &[id, node]: vertices_) {
			node->discovered = false;
			node->processe = false;
		}
		has_cycle_ = false;
	}

	bool has_cycle()
	{
		return has_cycle_;
	}

	weight_T get_edge_weight(const id_T &source_node_id, const id_T &destination_node_id)
	{
		if (vertices_.find(source_node_id) == vertices_.end())
			throw std::invalid_argument(
				"The node id " + std::to_string(source_node_id) + " does not exist in the graph!");
		if (vertices_.find(destination_node_id) == vertices_.end())
			throw std::invalid_argument(
				"The node id " + std::to_string(destination_node_id) + " does not exist in the graph!");
		auto id_pair = std::make_pair(source_node_id, destination_node_id);
		if (weights_.find(id_pair) == weights_.end())
			throw std::invalid_argument(
				"The edge with source id " + std::to_string(source_node_id) + " and destination id "
					+ std::to_string(destination_node_id) + " does not exist in the graph!");
		return weights_[id_pair];
	}

	bool erase_node(id_T id_to_erase)
	{
		bool is_in_graph = edges_.find(id_to_erase) != edges_.end();
		bool is_in_nodes = vertices_.find(id_to_erase) != vertices_.end();
		if (!is_in_graph && !is_in_nodes)
			return false;

		if (is_in_nodes)
			vertices_.erase(id_to_erase);

		if (is_in_graph) {
			auto affected_neighbors = get_neighbors(id_to_erase);
			edges_.erase(id_to_erase);
			for (const auto &neighbor_id: affected_neighbors) {
				auto id_iterator =
					std::find_if(edges_[neighbor_id].begin(),
								 edges_[neighbor_id].end(),
								 [id_to_erase](const id_T &node_id)
								 { return node_id == id_to_erase; });

				edges_[neighbor_id].erase(id_iterator);
				weights_.erase(std::make_pair(id_to_erase, neighbor_id));
			}

		}
		return true;
	}

private:
	// Here we store the relations between nodes/vertices if they exist including the weights.
	std::unordered_map<id_T, std::set<id_T>> edges_;
	// Store the weights
	std::unordered_map<std::pair<id_T, id_T>, weight_T, id_T_pair_hash> weights_;
	// Here we store all graph-nodes (id, data) pairs, that can be retrieved using the id. A node might be isolated.
	// not participating in any relations with other nodes
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> vertices_;
	bool has_cycle_{};

};


#endif //WEIGHTED_GRAPH_H
