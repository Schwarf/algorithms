//
// Created by andreas on 15.03.23.
//

#ifndef SETUP_DOUBLY_LINKED_LISTS_H
#define SETUP_DOUBLY_LINKED_LISTS_H
#include "gtest/gtest.h"
#include "linked_lists/node_dll.h"
#include <vector>

class SetupDoublyLinkedLists: public testing::Test
{
public:
	SetupDoublyLinkedLists() = default;
protected:
	std::vector<int> input_with_duplicates5{3, 1, 1};
	std::vector<int> input_with_no_duplicates1{3, 1};
	std::vector<int> input_with_no_duplicates2{3, 1, 2, 5, 7};

	template<typename T>
	NodeDLL<T> *get_doubly_list_head_from_vector(const std::vector<T> &input)
	{
		auto head = new NodeDLL<T>(input[0]);
		auto node = head;
		for (size_t i{1}; i < input.size(); ++i) {
			node->next = new NodeDLL<T>(input[i]);
			node->next->previous = node;
			node = node->next;
		}
		return head;
	}

	template<typename T>
	NodeDLL<T> *get_doubly_list_tail_from_vector(const std::vector<T> &input)
	{
		auto head = new NodeDLL<T>(input[0]);
		auto node = head;
		for (size_t i{1}; i < input.size(); ++i) {
			node->next = new NodeDLL<T>(input[i]);
			node->next->previous = node;
			node = node->next;
		}
		return node;
	}

};

#endif //SETUP_DOUBLY_LINKED_LISTS_H
