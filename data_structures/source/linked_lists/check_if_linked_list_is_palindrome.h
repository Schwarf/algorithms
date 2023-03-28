//
// Created by andreas on 28.03.23.
//

#ifndef CHECK_IF_LINKED_LIST_IS_PALINDROME_H
#define CHECK_IF_LINKED_LIST_IS_PALINDROME_H

#include "node.h"

template <typename T>
Node<T> * revert(Node<T> * head)
{
	Node<T> * new_head = nullptr;
	while(head)
	{
		auto node = new Node<T>(head->value);
		node->next = new_head;
		new_head =node;
		head =head->next;
	}
	return new_head;
}


template <typename T>
bool is_palindrome(Node<T> * head)
{
	auto new_head = revert(head);
	while(head)
	{
		if(new_head->value != head->value)
			return false;
		head = head->next;
		new_head = new_head->next;
	}
	return true;

}


#endif //CHECK_IF_LINKED_LIST_IS_PALINDROME_H
