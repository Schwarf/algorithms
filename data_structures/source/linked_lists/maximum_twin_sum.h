//
// Created by andreas on 17.05.23.
//

#ifndef MAXIMUM_TWIN_SUM_H
#define MAXIMUM_TWIN_SUM_H
#include "node.h"
#include <vector>
#include <stack>
// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.
// Given the head of a linked list with even length, return the maximum twin sum of the linked list.
template<typename T>
T maximum_twin_sum_with_vector(Node<T> *head)
{
	std::vector<T> help;
	while (head) {
		help.push_back(head->value);
		head = head->next;
	}
	int left{};
	int right = help.size() - 1;
	T max{};
	while (left < right)
		max = std::max(max, help[left++] + help[right--]);
	return max;
}

template<typename T>
T maximum_twin_sum_with_stack(Node<T> *head)
{
	std::stack<T> help;
	auto node = head;
	while (node) {
		help.push(head->value);
		node = node->next;
	}
	int half_size = help.size() >> 1;
	int count{};
	T max{};
	while (count++ <= half_size) {
		max = std::max(head->value + help.top(), max);
		help.pop();
	}

	return max;
}

#endif //MAXIMUM_TWIN_SUM_H
