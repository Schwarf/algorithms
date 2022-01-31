//
// Created by andreas on 30.01.22.
//

#include <algorithm>
#include "gtest/gtest.h"
#include "./../../linked_lists/doubly_linked_list.h"

class SetupDoublyLinkedList: public testing::Test
{
public:
	SetupDoublyLinkedList()
	{
		linked_list = new DoublyLinkedList<int64_t>();
	}
protected:
	DoublyLinkedList<int64_t> *linked_list;
	std::vector<int64_t> input{1, 2, 3, 4, 5};

};

TEST_F(SetupDoublyLinkedList, test_push_at_front_get)
{
	for (const auto &element: input) {
		linked_list->push_at_front(element);
	}
	std::reverse(input.begin(), input.end());
	for (size_t index = 0; index < input.size(); ++index) {
		EXPECT_EQ(linked_list->get(index), input[index]);
	}
}

TEST_F(SetupDoublyLinkedList, test_push_at_front_get_from_back)
{
	for (const auto &element: input) {
		linked_list->push_at_front(element);
	}
	std::reverse(input.begin(), input.end());
	for (size_t index_from_back = input.size(); index_from_back--;) {
		EXPECT_EQ(linked_list->get_from_back(index_from_back), input[index_from_back]);
	}
}


TEST_F(SetupDoublyLinkedList, test_push_at_back_get)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	for (size_t index = 0; index < input.size(); ++index) {
		EXPECT_EQ(linked_list->get(index), input[index]);
	}
}


TEST_F(SetupDoublyLinkedList, test_push_at_back_get_from_back)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	for (size_t index_from_back = input.size(); index_from_back--;) {
		EXPECT_EQ(linked_list->get_from_back(index_from_back), input[index_from_back]);
	}
}


TEST_F(SetupDoublyLinkedList, test_push_at_back_pop_back)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	for (size_t index_from_back = input.size(); index_from_back--;) {
		EXPECT_EQ(linked_list->pop_back(), input[index_from_back]);
	}
}

TEST_F(SetupDoublyLinkedList, test_push_at_back_pop_front)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	for (size_t index = 0; index < input.size(); index++) {
		EXPECT_EQ(linked_list->pop_front(), input[index]);
	}
}
/*
TEST_F(SetupDoublyLinkedList, test_push_at_index_front)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	input.insert(input.begin(),0);
	linked_list->push_at_index()
	for (size_t index = 0; index < input.size(); index++) {
		EXPECT_EQ(linked_list->pop_front(), input[index]);
	}
}
*/