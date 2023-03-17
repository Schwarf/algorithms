//
// Created by andreas on 17.03.23.
//

#ifndef KTH_TO_LAST_H
#define KTH_TO_LAST_H
// find kth to last element of a linked list

#include "node.h"

template <typename T>
Node<T> * kth_to_last_element(Node<T> * head, int k)
{
	if(!head)
		return head;
	int steps{k};
	auto forward = head;
	while(forward && steps)
	{
		forward = forward->next;
		steps--;
	}
	if(!forward)
		return nullptr;
	auto backward = head;
	while(forward)
	{
		forward = forward->next;
		backward = backward->next;
	}
	return backward;
}

#endif //KTH_TO_LAST_H
