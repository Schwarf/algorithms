//
// Created by andreas on 29.03.23.
//

#ifndef DOES_LINKED_LIST_HAVE_LOOP_H
#define DOES_LINKED_LIST_HAVE_LOOP_H
#include "node.h"

template<typename T>
bool does_linked_list_have_loop(Node<T> *head, Node<T> *&node)
{
	node = nullptr;
	if (!head)
		return false;
	auto fast = head;
	auto slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			break;
	}
	if (!fast || !fast->next)
		return false;

	fast = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	node = fast;
	return true;
}

#endif //DOES_LINKED_LIST_HAVE_LOOP_H

