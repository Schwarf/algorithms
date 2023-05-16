
// Given a linked list swap each (2*i)th node with each (2*i+1)th node and return the list with swapped nodes.
// Swap the nodes not swap the values

#include "node.h"

// O(N) time and space
template<typename T>
Node<T> *swap_nodes_in_pairs(Node<T> *head)
{
	if (!head || !head->next)
		return;
	auto first = new Node<T>(head->next->value);
	auto second = new Node<T>(head->value);
	first->next = second;
	first->next->next = swap_nodes_in_pairs(head->next->next);
	return first;
}


