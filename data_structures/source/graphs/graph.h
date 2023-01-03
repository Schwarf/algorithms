//
// Created by andreas on 19.12.22.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <set>
#include <memory>


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
};

template<typename id_T, typename data_T>
using GraphNodePtr = std::shared_ptr<GraphNode<id_T, data_T>>;

template<typename id_T, typename data_T>
class BidirectionalGraph
{
public:
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

	void add_edge(const GraphNodePtr<id_T, data_T> &node1,
				  const GraphNodePtr<id_T, data_T> &node2)
	{
		if (vertices_.find(node1->id) == vertices_.end())
			vertices_[node1->id] = node1;
		if (vertices_.find(node2->id) == vertices_.end())
			vertices_[node2->id] = node2;
		add_edge(node1->id, node2->id);
	}

	void add_edge(const id_T &node1_id,
				  const id_T &node2_id)
	{
		if (vertices_.find(node1_id) == vertices_.end())
			throw std::invalid_argument("The node id " + std::to_string(node1_id) + "does not exist in the graph!");
		if (vertices_.find(node2_id) == vertices_.end())
			throw std::invalid_argument("The node id " + std::to_string(node2_id) + "does not exist in the graph!");
		edges_[node1_id].insert(node2_id);
		edges_[node2_id].insert(node1_id);

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
	// Here we store the relations between nodes if they exist.
	std::unordered_map<id_T, std::set<id_T>> edges_;
	// Here we store all graph-nodes (id, data) pairs, that can be retrieved using the id. A node might be isolated.
	// not participating in any relations with other nodes
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> vertices_;

};

#endif //GRAPH_H
