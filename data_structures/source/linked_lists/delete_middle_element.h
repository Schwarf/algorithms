//
// Created by andreas on 17.03.23.
//

#ifndef DELETE_MIDDLE_ELEMENT_H
#define DELETE_MIDDLE_ELEMENT_H
#include "node.h"

template <typename T>
Node<T> * delete_middle_element(Node<T>* head)
{
	auto slow = head;
	Node<T> * previous = nullptr;
	auto fast = head;
	while(fast->next && fast->next->next)
	{
		previous = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	previous->next = slow->next;
	delete slow;
	return head;
}

// Here we hae no acces to head but only to the middle node, the one that shall be deleted
template <typename T>
void delete_middle_node(Node<T>* middle_node)
{
	auto previous = middle_node;
	while(middle_node->next)
	{
		middle_node->value = middle_node->next->value;
		previous = middle_node;
		middle_node = middle_node->next;
	}
	delete middle_node;
	previous->next = nullptr;
}

#endif //DELETE_MIDDLE_ELEMENT_H
