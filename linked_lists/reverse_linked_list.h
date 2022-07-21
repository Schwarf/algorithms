//
// Created by andreas on 21.07.22.
//

#ifndef REVERSE_LINKED_LIST_H
#define REVERSE_LINKED_LIST_H

#include "simple_sinlge_linked_list.h"

template <typename T>
Node<T> * reverse_linked_list(Node<T> * head)
{
	if(!head)
		return nullptr;
	Node<T> * previous = nullptr;
	auto next = head;
	while(head)
	{
		next = next->next;
		head->next = previous;
		previous = head;
		head = next;
	}
	return previous;
}

template <typename T>
Node<T> *reverse_linked_list_recursive(Node<T> * head)
{
	if(!head)
		return nullptr;
	if(!head->next)
		return head;
	auto rest = reverse_linked_list_recursive(head->next);
	head->next->next =head;
	head->next = nullptr;
	return rest;
}




#endif //REVERSE_LINKED_LIST_H
