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
				  const GraphNodePtr<id_T, data_T> &destination_vertex)
	{
		if (vertices_.find(source_vertex->id) == vertices_.end())
			vertices_[source_vertex->id] = source_vertex;
		if (vertices_.find(destination_vertex->id) == vertices_.end())
			vertices_[destination_vertex->id] = destination_vertex;
		add_edge(source_vertex->id, destination_vertex->id);
	}

	void add_edge(const id_T &source_vertex_id,
				  const id_T &destination_vertex_id)
	{
		if (vertices_.find(source_vertex_id) == vertices_.end())
			throw std::invalid_argument(
				"The vertex id " + std::to_string(source_vertex_id) + "does not exist in the graph!");
		if (vertices_.find(destination_vertex_id) == vertices_.end())
			throw std::invalid_argument(
				"The vertex id " + std::to_string(destination_vertex_id) + "does not exist in the graph!");
		edges_[source_vertex_id].insert(destination_vertex_id);
		if (!directed_)
			edges_[destination_vertex_id].insert(source_vertex_id);
	}

	void reset_all_vertex_properties()
	{
		for (auto &[id, vertex]: vertices_) {
			vertex->discovered = false;
			vertex->processe = false;
		}
		has_cycle_ = false;
	}

	std::size_t number_of_vertices() const
	{
		return vertices_.size();
	}

	void add_vertex(const GraphNodePtr<id_T, data_T> &vertex)
	{
		vertices_[vertex->id] = vertex;
	}

	bool erase_edge(const id_T &source_vertex_id, const id_T &destination_vertex_id)
	{
		if (does_edge_exist(source_vertex_id, destination_vertex_id)) {
			vertices_[source_vertex_id].erase(destination_vertex_id);
			vertices_[destination_vertex_id].erase(source_vertex_id);
			return true;
		}
		return false;
	}

	bool does_edge_exist(const id_T &source_vertex_id, const id_T &destination_vertex_id)
	{
		bool is_source_vertex_in_graph = edges_.find(source_vertex_id) != edges_.end();
		bool is_source_vertex_in_vertices = vertices_.find(source_vertex_id) != vertices_.end();

		bool is_destination_vertex_in_graph = edges_.find(destination_vertex_id) != edges_.end();
		bool is_destination_vertex_in_vertices = vertices_.find(destination_vertex_id) != vertices_.end();

		if (!is_source_vertex_in_vertices || !is_destination_vertex_in_vertices || !is_destination_vertex_in_graph
			|| !is_source_vertex_in_graph)
			return false;

		return (vertices_[source_vertex_id].find(destination_vertex_id) != vertices_.end())
			&& (vertices_[destination_vertex_id].find(source_vertex_id) != vertices_.end());
	}

	bool erase_vertex(id_T id)
	{
		bool is_in_graph = edges_.find(id) != edges_.end();
		bool is_in_vertices = vertices_.find(id) != vertices_.end();
		if (!is_in_graph && !is_in_vertices)
			return false;

		if (is_in_vertices)
			vertices_.erase(id);

		if (is_in_graph) {
			auto affected_neighbors = get_neighbors(id);
			edges_.erase(id);
			for (const auto &neighbor_id: affected_neighbors) {
				auto iterator =
					std::find_if(edges_[neighbor_id].begin(),
								 edges_[neighbor_id].end(),
								 [id](const id_T &vertex_id)
								 { return vertex_id == id; });
				edges_[neighbor_id].erase(iterator);
			}

		}
		return true;
	}

private:
	// Here we store the relations between vertexs/vertices if they exist.
	std::unordered_map<id_T, std::set<id_T>> edges_;
	// Here we store all graph-vertexs (id, data) pairs, that can be retrieved using the id. A vertex might be isolated.
	// not participating in any relations with other vertexs
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> vertices_;
	bool has_cycle_{};

};

#endif //GRAPH_H


