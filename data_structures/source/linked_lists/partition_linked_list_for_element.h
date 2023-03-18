//
// Created by andreas on 18.03.23.
//

#ifndef PARTITION_LINKED_LIST_FOR_ELEMENT_H
#define PARTITION_LINKED_LIST_FOR_ELEMENT_H
#include "node.h"
template<typename T>
void partition_linked_list_for_element(Node<T> *head, const T &element)
{
	if (!head)
		return;
	auto back = head;
	while (back->value != element)
		back = back->next;
	auto middle = back;
	auto tail = back->next;
	while (tail) {
		if (tail->value < element) {
			auto new_head = new Node<T>(tail->value);
			new_head->next = head;
			head = new_head;
			back->next = tail->next;
			delete tail;
			tail = back->next;
		}
		else {
			back = tail;
			tail = tail->next;
		}
	}
	auto node = head;
	Node<T> *previous = nullptr;
	while (node != middle) {
		if (node->value > element) {
			tail->next = new Node<T>(node->value);
			tail = tail->next;
			previous->next = node->next;
			delete node;
			node = previous->next;
		}
		else {
			previous = node;
			node = node->next;
		}
	}
	return head;
}

#endif //PARTITION_LINKED_LIST_FOR_ELEMENT_H
