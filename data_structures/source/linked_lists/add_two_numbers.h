//
// Created by andreas on 19.03.23.
//

#ifndef ADD_TWO_NUMBERS_H
#define ADD_TWO_NUMBERS_H
#include "node.h"

template<typename T>
Node<T> *add_two_numbers_recursive(Node<T> *head1, Node<T> *head2, int carry_over = 0)
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
			add_two_numbers_recursive(head1 ? head1->next : nullptr, head2 ? head2->next : nullptr, carry_over);
		result->next = next;
	}
	return result;
}

template<typename T>
Node<T> *add_two_numbers_iteratively(Node<T> *head1, Node<T> *head2)
{
	if (!head1 && !head2)
		return nullptr;
	if (!head1)
		return head2;
	if (!head2)
		return head1;
	Node<T> *result = nullptr;
	Node<T> *result_head = nullptr;
	int carry_over{};
	int sum{};
	while (head1 && head2) {
		sum = (head1->value + head2->value + carry_over) % 10;
		carry_over = (head1->value + head2->value + carry_over) / 10;
		if (!result) {
			result = new Node<T>(sum);
			result_head = result;
		}
		else {
			result->next = new Node<T>(sum);
			result = result->next;
		}
		head1 = head1->next;
		head2 = head2->next;

	}
	while (head1) {
		sum = (head1->value + carry_over) % 10;
		carry_over = (head1->value + carry_over) / 10;
		result->next = new Node<T>(sum);
		result = result->next;
		head1 = head1->next;

	}
	while (head2) {
		sum = (head2->value + carry_over) % 10;
		carry_over = (head2->value + carry_over) / 10;
		result->next = new Node<T>(sum);
		result = result->next;
		head2 = head2->next;
	}

	if (carry_over != 0) {
		result->next = new Node<T>(carry_over);
	}
	return result_head;
}
#endif //ADD_TWO_NUMBERS_H
