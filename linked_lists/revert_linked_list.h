//
// Created by andreas on 21.07.22.
//

#ifndef REVERT_LINKED_LIST_H
#define REVERT_LINKED_LIST_H

#include "simple_sinlge_linked_list.h"

// Non-invasive iterative implementation
template <typename T>
Node<T> * revert_linked_list(Node<T> * head)
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
Node<T> *revert_linked_list_recursive(Node<T> * head)
{
	if(!head)
		return nullptr;
	if(!head->next)
		return head;
	auto rest = revert_linked_list_recursive(head->next);
	head->next->next =head;
	head->next = nullptr;
	return rest;
}




#endif //REVERT_LINKED_LIST_H
