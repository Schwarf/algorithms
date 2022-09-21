//
// Created by andreas on 21.09.22.
//

#ifndef BASICS_H
#define BASICS_H
#include <vector>
#include <cstdlib>
#include <ctime>

template<typename T>
struct Node
{
	Node(T val)
		: value(val)
	{}
	T value;
	std::vector<Node<T> *> children;

};

template<typename T>
struct Graph
{
	std::vector<Node<T> *> nodes;
};

int main()
{
	srand(time(NULL));
	auto graph = Graph<int>();
	for(int i{}; i < 100; ++i) {
		graph.nodes.push_back(new Node<int>(i));
	}
	return 0;
}
#endif //BASICS_H
