//
// Created by andreas on 18.03.23.
//

#ifndef PARTITION_LINKED_LIST_FOR_ELEMENT_H
#define PARTITION_LINKED_LIST_FOR_ELEMENT_H
#include "node.h"
template<typename T>
Node<T> *partition_linked_list_for_element(Node<T> *head, const T &element)
{
	if (!head)
		return head;

	Node<T> *new_head = head;
	Node<T> *new_tail = head;
	while (head) {
		auto next = head->next;
		if (head->value < element) {
			head->next = new_head;
			new_head = head;
		}
		else {
			new_tail->next = head;
			new_tail = head;
		}
		head = next;

	}
	new_tail->next = nullptr;
	return new_head;
}
#endif //PARTITION_LINKED_LIST_FOR_ELEMENT_H
