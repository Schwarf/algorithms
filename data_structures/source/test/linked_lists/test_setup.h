//
// Created by andreas on 15.03.23.
//

#ifndef TEST_SETUP_H
#define TEST_SETUP_H
#include "gtest/gtest.h"
#include <vector>
#include "linked_lists/node.h"


class SetupLinkedLists: public testing::Test
{
public:
	SetupLinkedLists() = default;
protected:
	std::vector<int> input_with_duplicates5{3, 1, 1};
	std::vector<int> input_with_no_duplicates1{3, 1};
	std::vector<int> input_with_no_duplicates2{3, 1, 2, 5, 7};

	template <typename T>
	Node<T> *get_single_list_from_vector(const std::vector<T>& input)
	{
		auto head = new Node<T>(input[0]);
		auto node = head;
		for (size_t i{1}; i < input.size(); ++i)
		{
			node->next = new Node<T>(input[i]);
			node = node->next;
		}
		return head;
	}
};
#endif //TEST_SETUP_H
