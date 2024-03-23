//
// Created by andreas on 23.03.24.
//

#ifndef REORDER_LIST_H
#define REORDER_LIST_H
// You are given the head of a singly linked-list. The list can be represented as:
// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//You may not modify the values in the list's nodes. Only nodes themselves may be changed.
#include "node.h"

template<typename T>
Node<T> *reverse(Node<T> *head)
{
	Node<T> *prev = nullptr;
	while (head) {
		auto next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}

// This is not the classic merge as we know that list2.size() <= list1.size()
template<typename T>
void merge(Node<T> *list1, Node<T> *list2)
{
	while (list2) {
		auto next1 = list1->next;
		list1->next = list2;
		list1 = list2;
		list2 = next1;
	}
}

template<typename T>
void reorder_list(Node<T> *head)
{
	if (!head || !head->next)
		return;
	auto slow = head;
	auto fast = head;
	auto previous = head;
	while (fast && fast->next) {
		previous = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	// Split the list
	previous->next = nullptr;
	auto list1 = head;
	auto list2 = reverse(slow);
	merge(list1, list2);
}

#endif //REORDER_LIST_H
