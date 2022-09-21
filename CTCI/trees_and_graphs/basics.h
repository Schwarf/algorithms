//
// Created by andreas on 21.09.22.
//

#ifndef BASICS_H
#define BASICS_H
#include <vector>
#include <type_traits>
#include <random>

template <typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
static inline T get_random(const T & lower_bound, const T & upper_bound)
{
	auto int_distribution_ = std::uniform_int_distribution<T>(lower_bound, upper_bound);
	std::random_device device;
	auto generator = std::mt19937 (device());
	return int_distribution_(generator);
}

template<typename T>
struct Node
{
	explicit Node(T val)
		: value(val)
	{}
	T value;
	std::vector<Node<T> *> children;

};

template<typename T>
struct DirectedGraph
{
	explicit DirectedGraph(int number_of_vertices)
	{
		for(int vertex{}; vertex < number_of_vertices; ++vertex)
			nodes.push_back(new Node<int>(vertex));
	}
	std::vector<Node<T> *> nodes;
};

template <typename T >
void create_edges_in_graph(DirectedGraph<T> & graph, int probability_for_edge_in_percent)
{
	int probability{};
	for(auto & node : graph.nodes) // here we call node and vertex the same
	{

		for(int vertex{}; vertex < graph.nodes.size(); ++vertex) {
			if(vertex == node->value)
				continue;
			probability = get_random(0, 100);
			if (probability <= probability_for_edge_in_percent) {
				node->children.push_back(graph.nodes[vertex]);
			}
		}
	}
}

#endif //BASICS_H
