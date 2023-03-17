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
void delete_middle_node_in_list_with_ate_least_two_elements(Node<T> *head)
{
	Node<T> *previous = nullptr;
	auto slow = head;
	auto fast = head;
	while (fast->next && fast->next->next) {
		previous = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (previous) {
		previous->next = slow->next;
	}
	delete slow;

}

#endif //DELETE_NODES_H
