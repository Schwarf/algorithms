//
// Created by andreas on 10.04.23.
//

#ifndef CLONE_GRAPH_H
#define CLONE_GRAPH_H
#include <vector>
#include <unordered_map>
#include <queue>
template<typename T>
struct Node
{
	explicit Node(T val)
		: value(val)
	{}
	T value;
	std::vector<Node *> neighbors;
};

template<typename T>
Node<T> *clone_graph(Node<T> *node)
{
	if (node == nullptr)
		return node;
	std::queue<Node<T> *> q{{node}};
	std::unordered_map<Node<T> *, Node<T> *> mapping{{node, new Node(node->value)}};
	while(!q.empty())
	{
		auto current_node = q.front();
		q.pop();
		for(const auto &neighbor : current_node->neighbors)
		{
			if(!mapping[neighbor])
			{
				mapping[neighbor] = new Node<T>(neighbor->value);
				q.push(neighbor);
			}
			mapping[current_node]->neighbors.push_back(mapping[neighbor]);
		}

	}
	return mapping[node]
}

#endif //CLONE_GRAPH_H
