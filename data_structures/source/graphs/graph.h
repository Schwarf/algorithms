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
		graph_[node1->id].insert(node2);
		graph_[node2->id].insert(node1);
		nodes_[node1->id] = node1;
		nodes_[node2->id] = node2;
	}

	std::size_t size() const
	{
		return graph_.size();
	}

private:
	std::unordered_map<id_T, std::set<GraphNodePtr<id_T, data_T>>> graph_;
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> nodes_;

};

#endif //GRAPH_H
