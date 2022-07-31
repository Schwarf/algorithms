//
// Created by andreas on 21.07.22.
//

#ifndef REVERSE_LINKED_LIST_BETWEEN_POSITIONS_H
#define REVERSE_LINKED_LIST_BETWEEN_POSITIONS_H

#include "simple_single_linked_list.h"

template<typename T>
Node<T> *reverse_linked_list_between_positions(Node<T> *head, int left_index, int right_index)
{
	if (!head)
		return nullptr;

	auto current = head;
	Node<T> *previous = nullptr;
	while (left_index > 1) {
		previous = current;
		current = current->next;
		left_index--;
		right_index--;
	}
	// this node is the one before the left index
	auto node_before_left_index = previous;
	// tail points to element at left_index
	auto node_left_index = current;
	Node<T> *next = nullptr;
	// move forward until 'previous' points to last element in reverseed section(at right_index)
	while (right_index > 0) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
		right_index--;
	}
	// attach
	if (node_before_left_index != nullptr)
		node_before_left_index->next = previous;
	else
		head = previous;
	node_left_index->next = current;
	return head;

}


#endif //REVERSE_LINKED_LIST_BETWEEN_POSITIONS_H
