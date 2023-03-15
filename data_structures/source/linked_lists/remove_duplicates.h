//
// Created by andreas on 15.03.23.
//

#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H
#include "node.h"
#include <unordered_set>


// Remove all duplicates from a single linked list using additional space
// Runtime complexity: O(N)
// Space complexity: O(N)
template<typename T>
Node<T>* remove_duplicates(Node<T>* head)
{
	if(!head)
		return head;
	auto current = head;
	Node<T> * previous = nullptr;
	std::unordered_set<T> counter;
	while(current)
	{
		if(counter.find(current->value) != counter.end()) {
			previous->next = current->next;
			delete current;
			current = previous->next;
		}
		else {
			previous = current;
			counter.insert(current->value);
			current = current->next;
		}

	}
	return head;
}

// Remove all duplicates from a single linked list using NO additional space
// Runtime complexity: O(N^2)
template<typename T>
Node<T>* remove_duplicates_no_extra_space(Node<T>* head)
{
	if(!head)
		return head;
	auto left = head;

	while(left)
	{
		auto right = left->next;
		auto previous = left;
		while(right)
		{
			if(right->value == left->value) {
				previous->next = right->next;
				delete right;
				right = previous->next;
			}
			else {
				previous = right;
				right = right->next;
			}
		}
		left = left->next;
	}
	return head;
}



#endif //REMOVE_DUPLICATES_H
