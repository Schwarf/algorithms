//
// Created by andreas on 19.12.22.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <set>
#include <memory>
#include <algorithm>

template<typename id_T, typename data_T>
struct GraphNode
{
	GraphNode(const id_T &id, const data_T &data)
	{
		this->data = data;
		this->id = id;
	}
	data_T data;
	id_T id;
	bool discovered{};
	bool processed{};
};

template<typename id_T, typename data_T>
using GraphNodePtr = std::shared_ptr<GraphNode<id_T, data_T>>;

template<typename id_T, typename data_T, bool directed_ = false>
class Graph
{
public:
	void set_has_cycle()
	{
		has_cycle_ = true;
	}

	bool has_cycle()
	{
		return has_cycle_;
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
				  const GraphNodePtr<id_T, data_T> &destination_node)
	{
		if (vertices_.find(source_node->id) == vertices_.end())
			vertices_[source_node->id] = source_node;
		if (vertices_.find(destination_node->id) == vertices_.end())
			vertices_[destination_node->id] = destination_node;
		add_edge(source_node->id, destination_node->id);
	}

	void add_edge(const id_T &source_node_id,
				  const id_T &destination_node_id)
	{
		if (vertices_.find(source_node_id) == vertices_.end())
			throw std::invalid_argument(
				"The node id " + std::to_string(source_node_id) + "does not exist in the graph!");
		if (vertices_.find(destination_node_id) == vertices_.end())
			throw std::invalid_argument(
				"The node id " + std::to_string(destination_node_id) + "does not exist in the graph!");
		edges_[source_node_id].insert(destination_node_id);
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

	std::size_t number_of_vertices() const
	{
		return vertices_.size();
	}

	void add_vertex(const GraphNodePtr<id_T, data_T> &node)
	{
		vertices_[node->id] = node;
	}

	bool erase_node(id_T id)
	{
		bool is_in_graph = edges_.find(id) != edges_.end();
		bool is_in_nodes = vertices_.find(id) != vertices_.end();
		if (!is_in_graph && !is_in_nodes)
			return false;

		if (is_in_nodes)
			vertices_.erase(id);

		if (is_in_graph) {
			auto affected_neighbors = get_neighbors(id);
			edges_.erase(id);
			for (const auto &neighbor_id: affected_neighbors) {
				auto iterator =
					std::find_if(edges_[neighbor_id].begin(),
								 edges_[neighbor_id].end(),
								 [id](const id_T &node_id)
								 { return node_id == id; });
				edges_[neighbor_id].erase(iterator);
			}

		}
		return true;
	}

private:
	// Here we store the relations between nodes/vertices if they exist.
	std::unordered_map<id_T, std::set<id_T>> edges_;
	// Here we store all graph-nodes (id, data) pairs, that can be retrieved using the id. A node might be isolated.
	// not participating in any relations with other nodes
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> vertices_;
	bool has_cycle_{};

};

#endif //GRAPH_H


