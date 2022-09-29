//
// Created by andreas on 29.09.22.
//
#include "basics.h"
#include <queue>
#include <iostream>

template <typename T>
Graph<T> generate_random_graph()
{
	constexpr int number_of_vertices = 10;
	constexpr int probability_to_create_edge = 15; // in percent
	auto graph = Graph<T>("first_graph", number_of_vertices);
	create_edges_in_graph(graph, probability_to_create_edge);
	return graph;
}

template <typename T>
bool search_if_nodes_are_connected(const Graph<T> & graph,  Node<T> * start_node, Node<T> * end_node)
{
	if (start_node == end_node)
		return true;
	auto help = std::queue<Node<T>*>();
	for(const auto & node : graph.nodes)
		node->state = Unvisited;

	start_node->state = Visiting;
	help.push(start_node);
	auto node = start_node;
	while(!help.empty())
	{
		node = help.front();
		help.pop();
		if(node != nullptr)
		{
			for(const auto & child : node->children)
			{
				if(child == end_node)
					return true;
				else
				{
					child->state = Visiting;
					help.push(child);
				}
			}
		}
	}
	return false;
}


int main()
{
	auto graph = generate_random_graph<int>();
	auto start_node = graph.nodes[0];
	auto end_node = graph.nodes[7];
	print_graph_in_DOT_language(graph);
	std::cout << search_if_nodes_are_connected(graph, start_node, end_node) << std::endl;
}