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
	std::set<GraphNodePtr<id_T, data_T>> get_neighbors(const GraphNodePtr<id_T, data_T> &node)
	{
		return this->graph_[node->id];
	}
	std::set<GraphNodePtr<id_T, data_T>> get_neighbors(id_T id)
	{
		return this->graph_[id];
	}

	GraphNodePtr<id_T, data_T> get_node_by_id(id_T id)
	{
		return nodes_[id];
	}

	void add_edge(const GraphNodePtr<id_T, data_T> &node1,
				  const GraphNodePtr<id_T, data_T> &node2)
	{
		nodes_[node1->id] = node1;
		nodes_[node2->id] = node2;
		graph_[node1->id].insert(node2);
		graph_[node2->id].insert(node1);

	}

	std::size_t number_of_nodes() const
	{
		return nodes_.size();
	}

	void add_node(const GraphNodePtr<id_T, data_T> &node)
	{
		nodes_[node->id] = node;
	}

	bool erase_node(id_T id)
	{
		bool is_in_graph = graph_.find(id) != graph_.end();
		bool is_in_nodes = nodes_.find(id) != nodes_.end();
		if (!is_in_graph && !is_in_nodes)
			return false;

		if (is_in_nodes)
			nodes_.erase(id);

		if (is_in_graph) {
			auto affected_neighbors = get_neighbors(id);
			graph_.erase(id);
			for (const auto &neighbor: affected_neighbors) {
				auto iterator =
					std::find_if(graph_[neighbor->id].begin(),
								 graph_[neighbor->id].end(),
								 [id](const GraphNodePtr<id_T, data_T> &node)
								 { return node->id == id; });
				graph_[neighbor->id].erase(iterator);
			}

		}
		return true;
	}

private:
	std::unordered_map<id_T, std::set<GraphNodePtr<id_T, data_T>>> graph_;
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> nodes_;

};

#endif //GRAPH_H
