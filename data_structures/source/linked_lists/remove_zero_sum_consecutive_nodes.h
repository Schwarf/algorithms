//
// Created by andreas on 12.03.24.
//

#ifndef REMOVE_ZERO_SUM_CONSECUTIVE_NODES_H
#define REMOVE_ZERO_SUM_CONSECUTIVE_NODES_H
// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that
// sum to 0 until there are no such sequences.
// After doing so, return the head of the final linked list.  You may return any such answer.
#include "node.h"
#include <unordered_map>

// O(N^2) time, O(1) space
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

// O(N) time, O(N) space is missing
template<typename T>
Node<T> *remove_zero_sum_consecutive_nodes_optimized(Node<T> *head)
{
	auto front = new Node<T>();
	front->next = head;
	auto current = front;
	int prefix_sum = 0;
	std::unordered_map<T, Node<T> *> prefix_sum_to_node;
	prefix_sum_to_node[0] = front;

	// Calculate the prefix sum for each node and add to the hashmap
	// Each prefix_sum that appears multiple times e.g. two times at index i and index j means
	// that the sum between the two indices is zero (i+1 ... j)
	// [1,2,−3,3,−2] yields prefix-sum [1,3,0,3,1]
	while (current != nullptr) {
		prefix_sum += current->value;
		prefix_sum_to_node[prefix_sum] = current;
		current = current->next;
	}

	// Reset prefix sum and current
	prefix_sum = 0;
	current = front;

	// Delete zero sum consecutive sequences
	// by setting node before sequence to node after
	while (current != nullptr) {
		prefix_sum += current->value;
		// Here we replace to the latest appearance of prefix_sum in prefix_sum_to_node.
		current->next = prefix_sum_to_node[prefix_sum]->next;
		current = current->next;
	}
	return front->next;
}

#endif //REMOVE_ZERO_SUM_CONSECUTIVE_NODES_H
