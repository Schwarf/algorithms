//
// Created by andreas on 11.09.23.
//

#ifndef SPLIT_LINKED_LIST_IN_PARTS_H
#define SPLIT_LINKED_LIST_IN_PARTS_H
#include "node.h"
#include <vector>
template<typename T>
std::vector<Node<T> *> split_linked_list_in_parts(Node<T> *head, int k)
{
	std::vector<Node<T> *> result(k);

	int size{};
	auto current = head;
	while (current) {
		size++;
		current = current->next;
	}
	int nodes_per_list = size / k;
	int additional_nodes = size % k;
	current = head;
	Node<T> *previous = nullptr;
	for (int i{}; i < k; ++i, --additional_nodes) {
		result[i] = current;
		for (int j{}; j < nodes_per_list + (additional_nodes > 0); ++j) {
			previous = current;
			current = current->next;
		}
		if (previous)
			previous->next = nullptr;
	}
	return result;
}

#endif //SPLIT_LINKED_LIST_IN_PARTS_H
