//
// Created by andreas on 29.03.23.
//

#ifndef ARE_LINKED_LISTS_INTERSECTING_H
#define ARE_LINKED_LISTS_INTERSECTING_H
#include "node.h"

template<typename T>
bool are_linked_lists_intersecting(Node<T> *head1, Node<T> *head2, Node<T> *&node)
{
	node = nullptr;
	if (!head1 || !head2)
		return false;
	int size1{1};
	int size2{1};
	auto node1 = head1;
	auto node2 = head2;
	while (node1->next) {
		node1 = node1->next;
		size1++;
	}
	while (node2->next) {
		node2 = node2->next;
		size2++;
	}
	if (node1 != node2)
		return false;

	node1 = head1;
	node2 = head2;
	int steps{};
	if (size1 > size2) {
		steps = size1 - size2;
		while (steps) {
			node1 = node1->next;
			steps--;
		}
	}
	else if (size1 < size2) {
		steps = size2 - size1;
		while (steps) {
			node2 = node2->next;
			steps--;
		}
	}
	while (node1 != node2) {
		node1 = node1->next;
		node2 = node2->next;
	}
	node = node1;
	return true;
}


#endif //ARE_LINKED_LISTS_INTERSECTING_H
