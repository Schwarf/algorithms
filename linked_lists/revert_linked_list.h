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
	Node<T> * previous = nullptr;
	auto next = head->next;
	while(head)
	{
		head->next = previous;
		previous = head;
		head = next;
		next = next->next;
	}
	return head;
}



#endif //REVERT_LINKED_LIST_H
