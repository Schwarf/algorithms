//
// Created by andreas on 21.09.22.
//

#ifndef BASICS_H
#define BASICS_H
#include <utility>
#include <vector>
#include <type_traits>
#include <queue>
#include <random>
#include <ostream>
#include <fstream>
#include <iostream>
#include <exception>

template<typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
static inline T get_random(const T &lower_bound, const T &upper_bound)
{
	auto int_distribution_ = std::uniform_int_distribution<T>(lower_bound, upper_bound);
	std::random_device device;
	auto generator = std::mt19937(device());
	return int_distribution_(generator);
}

enum State {Unvisited, Visited, Visiting};

template<typename T>
struct Node
{
	explicit Node(T val)
		: value(val)
	{}
	T value;

	State state = Unvisited;
	std::vector<Node<T> *> children;

};

template<typename T>
struct TreeNode
{
	explicit TreeNode(T val)
		: value(val)
	{}
	T value;

	State state = Unvisited;
	TreeNode * left;
	TreeNode * right;

};


template<typename T>
struct Graph
{
	explicit Graph(std::string name, int number_of_vertices)
		:
		name(std::move(name))
	{
		for (int vertex{}; vertex < number_of_vertices; ++vertex)
			nodes.push_back(new Node<int>(vertex));
	}
	std::vector<Node<T> *> nodes;
	std::string name{};
};

template<typename T>
void print_graph_in_DOT_language(Graph<T> &graph)
{
	auto file_name = "/media/linux_data/projects/cpp/algorithms/CTCI/trees_and_graphs/" + graph.name + ".txt";
	std::ofstream output_file(file_name);

	if (output_file.is_open()) {
		output_file << "digraph G {" << std::endl;
		for (const auto &node: graph.nodes) {
			for (const auto &child: node->children)
				output_file << node->value << " -> " << child->value << " ;" << std::endl;
		}
		output_file << "}" << std::endl;
		output_file.close();
	}
}

template<typename T>
void create_edges_in_graph(Graph<T> &graph, int probability_for_edge_in_percent)
{
	int probability{};
	for (auto &node: graph.nodes) // here node and vertex denote the same entity
	{
		for (int vertex{}; vertex < graph.nodes.size(); ++vertex) {
			if (vertex == node->value)
				continue;
			probability = get_random(0, 100);
			if (probability <= probability_for_edge_in_percent) {
				node->children.push_back(graph.nodes[vertex]);
			}
		}
	}
}

template<typename T>
TreeNode<T> * generate_balanced_binary_tree_with_random_values(int index, int number_of_nodes)
{
	TreeNode<T> * root = nullptr;
	if(index < number_of_nodes) {
		root = new TreeNode<T>(get_random(0, number_of_nodes * 10));
		root->left =generate_balanced_binary_tree_with_random_values<T>(2 * index + 1, number_of_nodes);
		root->right = generate_balanced_binary_tree_with_random_values<T>(2 * index + 2, number_of_nodes);
	}
	return root;
}


template<typename T>
TreeNode<T> * generate_unbalanced_binary_tree_with_random_values(int index, int number_of_nodes)
{
	if(number_of_nodes < 4)
		throw std::invalid_argument("The number of nodes is smaller than 3. Unbalanced tree can not be generated.");
	auto root = generate_balanced_binary_tree_with_random_values<T>(index, number_of_nodes -3);
	auto node = root;
	if(node) {
		while (node->right)
			node = node->right;
	}
	for(int i{}; i < 3; ++i)
	{
		auto new_node = new TreeNode<int>(get_random(index, number_of_nodes));
		node->right = new_node;
		node = node->right;
	}
	return root;

	return root;
}

#endif //BASICS_H
