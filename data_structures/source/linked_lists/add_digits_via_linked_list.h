//
// Created by andreas on 19.03.23.
//

#ifndef ADD_DIGITS_VIA_LINKED_LIST_H
#define ADD_DIGITS_VIA_LINKED_LIST_H
#include "node.h"

template<typename T>
Node<T> *add_reversed_order_recursive(Node<T> *head1, Node<T> *head2, int carry_over = 0)
{
	if (!head1 && !head2 && carry_over == 0)
		return nullptr;
	auto result = new Node<T>();
	int sum = carry_over;
	if (head1)
		sum += head1->value;
	if (head2)
		sum += head2->value;
	result->value = sum % 10;
	carry_over = sum / 10;
	if (head1 || head2) {
		auto next =
			add_reversed_order_recursive(head1 ? head1->next : nullptr, head2 ? head2->next : nullptr, carry_over);
		result->next = next;
	}
	return result;
}

template<typename T>
Node<T> *add_reversed_order_iteratively(Node<T> *head1, Node<T> *head2)
{
	if (!head1 && !head2)
		return nullptr;
	if (!head1)
		return head2;
	if (!head2)
		return head1;
	auto result = new Node<T>();
	auto result_head = result;
	int carry_over{};
	int sum{};
	while (head1 && head2) {
		sum = (head1->value + head2->value + carry_over) % 10;
		carry_over = (head1->value + head2->value + carry_over) / 10;
		result->value = sum;
		head1 = head1->next;
		head2 = head2->next;
		result->next = new Node<T>();
	}
	while (head1) {
		sum = (head1->value + carry_over) % 10;
		carry_over = (head1->value + carry_over) / 10;
		head1->value = sum;
		result->value = sum;
		head1 = head1->next;
		result->next = new Node<T>();
	}
	while (head2) {
		sum = (head2->value + carry_over) % 10;
		carry_over = (head2->value + carry_over) / 10;
		head2->value = sum;
		result->value = sum;
		head2 = head2->next;
		result->next = new Node<T>();
	}

	if (carry_over != 0) {
		result->next = new Node<T>(carry_over);
	}
	return result_head;
}
#endif //ADD_DIGITS_VIA_LINKED_LIST_H
