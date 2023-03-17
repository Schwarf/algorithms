//
// Created by andreas on 15.03.23.
//

#ifndef SETUP_SINGLY_LINKED_LISTS_H
#define SETUP_SINGLY_LINKED_LISTS_H
#include "gtest/gtest.h"
#include <vector>
#include "linked_lists/node.h"

class SetupSinglyLinkedLists: public testing::Test
{
public:
	SetupSinglyLinkedLists() = default;
protected:
	template<typename T>
	Node<T> *get_single_list_from_vector(const std::vector<T> &input)
	{
		auto head = new Node<T>(input[0]);
		auto node = head;
		for (size_t i{1}; i < input.size(); ++i) {
			node->next = new Node<T>(input[i]);
			node = node->next;
		}
		return head;
	}
	template<typename T>
	size_t get_size(Node<T> *head)
	{
		size_t size{};
		while (head) {
			size++;
			head = head->next;
		}
		return size;
	}

};
#endif //SETUP_SINGLY_LINKED_LISTS_H
