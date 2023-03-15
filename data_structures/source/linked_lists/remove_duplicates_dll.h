//
// Created by andreas on 15.03.23.
//

#ifndef REMOVE_DUPLICATES_DLL_H
#define REMOVE_DUPLICATES_DLL_H
#include "node_dll.h"
#include <unordered_set>

// Remove all duplicates from a doubly linked list using additional space, starting from head
// Runtime complexity: O(N)
// Space complexity: O(N)
template<typename T>
NodeDLL<T>* remove_duplicates(NodeDLL<T>* head)
{
	if(!head)
		return head;
	auto current = head;
	NodeDLL<T> * previous = nullptr;
	std::unordered_set<T> counter;
	while(current)
	{
		if(counter.find(current->value) != counter.end()) {
			previous->next = current->next;
			if(current->next)
				current->next->previous = previous;
		}
		else {
			previous = current;
			counter.insert(current->value);
		}
		current = current->next;
	}
	return head;
}


// Remove all duplicates from a doubly linked list using additional space, starting from tail
// Runtime complexity: O(N)
// Space complexity: O(N)
template<typename T>
NodeDLL<T>* remove_duplicates_from_tail(NodeDLL<T>* tail)
{
	if(!tail)
		return tail;
	auto current = tail;
	// This points behind tail
	NodeDLL<T> * previous = nullptr;
	std::unordered_set<T> counter;
	while(current)
	{
		if(counter.find(current->value) != counter.end()) {
			previous->previous = current->previous;
			if(current->previous)
				current->previous->next = previous;
		}
		else {
			previous = current;
			counter.insert(current->value);
		}
		current = current->previous;
	}
	return tail;
}


#endif //REMOVE_DUPLICATES_DLL_H
