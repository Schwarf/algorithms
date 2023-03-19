//
// Created by andreas on 19.03.23.
//

#ifndef ADD_DIGITS_VIA_LINKED_LIST_H
#define ADD_DIGITS_VIA_LINKED_LIST_H
#include "node.h"

template<typename T>
Node<T> *add_reversed_order(Node<T> *head1, Node<T> *head2)
{
	if (!head1 && !head2)
		return nullptr;
	if (!head1)
		return head2;
	if (!head2)
		return head1;

	int carry_over{};
	int sum{};
	auto node1 = head1;
	auto node2 = head2;
	while (node1 && node2) {
		sum = (node1->value + node2->value + carry_over) % 10;
		carry_over = (node1->value + node2->value + carry_over) / 10;
		node1->value = sum;
		node1 = node1->next;
		node2 = node2->next;
	}
	while (node1) {
		sum = (node1->value + carry_over) % 10;
		carry_over = (node1->value + carry_over) / 10;
		node1->value = sum;
		node1 = node1->next;
	}
	while (node2) {
		sum = (node2->value + carry_over) % 10;
		carry_over = (node2->value + carry_over) / 10;
		node2->value = sum;
		node1->next = node2;
		node2 = node2->next;
	}

	if (carry_over != 0) {
		node1->next = new Node<T>(carry_over);
	}
	return head1;
}
#endif //ADD_DIGITS_VIA_LINKED_LIST_H
