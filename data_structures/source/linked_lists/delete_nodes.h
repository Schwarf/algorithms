//
// Created by andreas on 17.03.23.
//

#ifndef DELETE_NODES_H
#define DELETE_NODES_H
#include "node.h"

template<typename T>
void delete_given_node_but_not_last_node(Node<T> *node_to_delete)
{
	if (!node_to_delete) {
		return;
	}
	auto next = node_to_delete->next;
	node_to_delete->value = next->value;
	node_to_delete->next = next->next;
	delete next;

}

// Here we hae no acces to head but only to the middle node, the one that shall be deleted
template<typename T>
void delete_middle_node(Node<T> *middle_node)
{
	auto previous = middle_node;
	while (middle_node->next) {
		middle_node->value = middle_node->next->value;
		previous = middle_node;
		middle_node = middle_node->next;
	}
	delete middle_node;
	previous->next = nullptr;
}

#endif //DELETE_NODES_H
