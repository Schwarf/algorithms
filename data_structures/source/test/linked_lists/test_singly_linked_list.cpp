//
// Created by andreas on 29.01.22.
//

#include <algorithm>
#include "gtest/gtest.h"
#include "./../../linked_lists/singly_linked_list.h"

class SetupLinkedList: public testing::Test
{
public:
	SetupLinkedList()
	{
		linked_list = new SinglyLinkedList<int64_t>();
	}
protected:
	SinglyLinkedList<int64_t> *linked_list;
	std::vector<int64_t> input{1, 2, 3, 4, 5};
};


TEST_F(SetupLinkedList, test_push_at_front)
{
	for (const auto &element: input) {
		linked_list->push_at_front(element);
	}
	int64_t value{};
	std::reverse(input.begin(), input.end());
	for (size_t index = 0; index < input.size(); ++index) {
		linked_list->get(index, value);
		EXPECT_EQ(value, input[index]);
	}
}

TEST_F(SetupLinkedList, test_push_at_back)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	int64_t value{};

	for (size_t index = 0; index < input.size(); ++index) {
		linked_list->get(index, value);
		EXPECT_EQ(value, input[index]);
	}
}


TEST_F(SetupLinkedList, test_add_at_index_1_and_index_3)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	int64_t value{};
	input.insert(input.begin() + 1, 10);
	input.insert(input.begin() + 3, 20);
	linked_list->add_at_index(10, 1);
	linked_list->add_at_index(20, 3);
	EXPECT_EQ(7, input.size());

	for (size_t index = 0; index < input.size(); ++index) {
		linked_list->get(index, value);
		EXPECT_EQ(value, input[index]);
	}
}


TEST_F(SetupLinkedList, test_invalid_index)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	int64_t value{};
	size_t out_of_range_index = 7;
	std::string message = "The index is linked list is out of range in method 'get'";
	try {
		linked_list->get(out_of_range_index, value);
		FAIL() << "Expected std::out_of_range";
	}
	catch (std::out_of_range const &err) {
		EXPECT_TRUE(err.what() == message);
	}
}

TEST_F(SetupLinkedList, test_pop_front)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	EXPECT_EQ(linked_list->pop_front(), input[0]);
	EXPECT_EQ(linked_list->size(), input.size() - 1);
	EXPECT_EQ(linked_list->pop_front(), input[1]);
	EXPECT_EQ(linked_list->size(), input.size() - 2);
	EXPECT_EQ(linked_list->pop_front(), input[2]);
	EXPECT_EQ(linked_list->size(), input.size() - 3);
	EXPECT_EQ(linked_list->pop_front(), input[3]);
	EXPECT_EQ(linked_list->size(), input.size() - 4);
	EXPECT_EQ(linked_list->pop_front(), input[4]);
	EXPECT_EQ(linked_list->size(), input.size() - 5);
}

TEST_F(SetupLinkedList, test_pop_front_invalid_list_empty)
{
	std::string message = "Singly linked list is empty (pop_front).";
	try {
		linked_list->pop_front();
		FAIL() << "Empty";
	}
	catch (std::out_of_range const &err) {
		EXPECT_TRUE(err.what() == message);
	}
}

TEST_F(SetupLinkedList, test_pop_back_invalid_list_empty)
{
	std::string message = "Singly linked list is empty (pop_back).";
	try {
		linked_list->pop_back();
		FAIL() << "Empty";
	}
	catch (std::out_of_range const &err) {
		EXPECT_TRUE(err.what() == message);
	}
}

TEST_F(SetupLinkedList, test_pop_back)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	EXPECT_EQ(linked_list->pop_back(), input[4]);
	EXPECT_EQ(linked_list->size(), input.size() - 1);
	EXPECT_EQ(linked_list->pop_back(), input[3]);
	EXPECT_EQ(linked_list->size(), input.size() - 2);
	EXPECT_EQ(linked_list->pop_back(), input[2]);
	EXPECT_EQ(linked_list->size(), input.size() - 3);
	EXPECT_EQ(linked_list->pop_back(), input[1]);
	EXPECT_EQ(linked_list->size(), input.size() - 4);
	EXPECT_EQ(linked_list->pop_back(), input[0]);
	EXPECT_EQ(linked_list->size(), input.size() - 5);
}

TEST_F(SetupLinkedList, test_is_empty)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	EXPECT_FALSE(linked_list->is_empty());
	linked_list->pop_front();
	linked_list->pop_back();
	linked_list->pop_front();
	linked_list->pop_back();
	linked_list->pop_front();
	EXPECT_TRUE(linked_list->is_empty());
}

TEST_F(SetupLinkedList, test_pop_at_index)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	size_t index = 2;
	EXPECT_EQ(linked_list->pop_at_index(index), input[index]);
	input.erase(input.begin() + 2);
	EXPECT_EQ(linked_list->pop_at_index(index), input[index]);
	input.erase(input.begin() + 2);

	int64_t value{};
	for (index = 2; index < input.size(); ++index) {
		linked_list->get(index, value);
		EXPECT_EQ(value, input[index]);

	}
}

TEST_F(SetupLinkedList, test_pop_at_index_1st_element)
{
	linked_list->push_at_back(input[0]);
	size_t index = 0;
	EXPECT_EQ(linked_list->pop_at_index(index), input[index]);
	EXPECT_TRUE(linked_list->is_empty());
	EXPECT_EQ(linked_list->size(), 0);
}


TEST_F(SetupLinkedList, test_pop_at_index_2nd_element)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	size_t index = 1;
	EXPECT_EQ(linked_list->pop_at_index(index), input[index]);
	EXPECT_FALSE(linked_list->is_empty());
	EXPECT_EQ(linked_list->size(), 4);
}

TEST_F(SetupLinkedList, test_pop_at_index_last_element)
{
	for (const auto &element: input) {
		linked_list->push_at_back(element);
	}
	size_t index = 4;
	EXPECT_EQ(linked_list->pop_at_index(index), input[index]);
	EXPECT_FALSE(linked_list->is_empty());
	EXPECT_EQ(linked_list->size(), 4);
}
