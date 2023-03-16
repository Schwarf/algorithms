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
	NodeDLL<T> * next = nullptr;
	std::unordered_set<T> counter;
	while(current)
	{
		if(counter.find(current->value) != counter.end()) {
			next->previous = current->previous;
			if(current->previous)
				current->previous->next = next;
			delete current;
			current = next->previous;
		}
		else {
			next = current;
			counter.insert(current->value);
			current = current->previous;
		}

	}
	return tail;
}

// Remove all duplicates from a doubly linked list using NO additional space starting from head
// Runtime complexity: O(N^2)
template<typename T>
NodeDLL<T>* remove_duplicates_no_extra_space(NodeDLL<T>* head)
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
				if(right->next)
					right->next->previous = previous;
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

// Remove all duplicates from a doubly linked list using NO additional space starting from head
// Runtime complexity: O(N^2)
template<typename T>
NodeDLL<T>* remove_duplicates_no_extra_space_from_tail(NodeDLL<T>* tail)
{
	if(!tail)
		return tail;
	auto right = tail;

	while(right)
	{
		auto left = right->previous;
		auto next = right;
		while(left)
		{
			if(right->value == left->value) {
				next->previous = left->previous;
				if(left->previous)
					left->previous->next = next;
				delete left;
				left = next->previous;
			}
			else {
				next = left;
				left = left->previous;
			}
		}
		right = right->previous;
	}
	return tail;
}

#endif //REMOVE_DUPLICATES_DLL_H
