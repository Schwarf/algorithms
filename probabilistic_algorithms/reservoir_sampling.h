//
// Created by andreas on 10.03.23.
//

#ifndef RESERVOIR_SAMPLING_H
#define RESERVOIR_SAMPLING_H

#include <vector>
#include <random>

// Algorithm R for std::vector
template<typename T>
std::vector<T> reservoir_sampling(const std::vector<T> &input_stream, size_t reservoir_size)
{
	std::vector<T> reservoir(reservoir_size);
	size_t element_index{};
	std::random_device random_device;
	std::mt19937 generator(random_device());
	for (const auto &element: input_stream) {
		if (element_index < reservoir_size)
			reservoir[element_index] = element;
		else {
			std::uniform_int_distribution<size_t> distribution(0, element_index);
			size_t reservoir_index = distribution(generator);
			if (reservoir_index < reservoir_size)
				reservoir[reservoir_index] = element;
		}
		element_index++;
	}
	return reservoir;
}

// Algorithm R for linked list of unknown size
template<typename T>
struct Node
{
	Node *next;
	T value;
};
template<typename T>
std::vector<T> reservoir_sampling(const Node<T> *head, size_t reservoir_size)
{
	std::vector<Node<T> *> reservoir(reservoir_size);
	size_t element_index{};
	std::random_device random_device;
	std::mt19937 generator(random_device());
	for (auto current_node = head; current_node; current_node = current_node->next, ++element_index) {
		if (element_index < reservoir_size)
			reservoir[element_index] = current_node;
		else {
			std::uniform_int_distribution<size_t> distribution(0, element_index);
			size_t reservoir_index = distribution(generator);
			if (reservoir_index < reservoir_size)
				reservoir[reservoir_index] = current_node;
		}
	}
	return reservoir;
}


#endif //RESERVOIR_SAMPLING_H
