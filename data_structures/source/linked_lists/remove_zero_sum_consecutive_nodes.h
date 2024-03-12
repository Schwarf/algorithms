//
// Created by andreas on 12.03.24.
//

#ifndef REMOVE_ZERO_SUM_CONSECUTIVE_NODES_H
#define REMOVE_ZERO_SUM_CONSECUTIVE_NODES_H
// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that
// sum to 0 until there are no such sequences.
// After doing so, return the head of the final linked list.  You may return any such answer.
#include "node.h"

template<typename T>
requires std::is_arithmetic_v<T>
Node<T> *remove_zero_sum_consecutive_nodes(Node<T> *head)
{
	auto front = new Node<T>(T{});
	front->next = head;
	auto left = front;
	while (left) {
		// we start with head (since left==front previous head)
		auto right = left->next;
		int sum{};
		while (right) {
			sum += right->value;
			if (sum == 0) {
				left->next = right->next;
			}
			right = right->next;
		}
		left = left->next;
	}
	return front->next;
}
#endif //REMOVE_ZERO_SUM_CONSECUTIVE_NODES_H
