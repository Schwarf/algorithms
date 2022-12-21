//
// Created by andreas on 19.12.22.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
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
	std::vector<GraphNodePtr<id_T, data_T>> get_neighbors(const GraphNodePtr<id_T, data_T> &node)
	{
		return this->graph_[node];
	}

	void add_edge(const GraphNodePtr<id_T, data_T> &node1,
				  const GraphNodePtr<id_T, data_T> &node2)
	{
		graph_[node1].push_back(node2);
		graph_[node2].push_back(node1);
	}

private:
	std::unordered_map<GraphNodePtr<id_T, data_T>, std::vector<GraphNodePtr<id_T, data_T>>>
		graph_;

};

#endif //GRAPH_H
