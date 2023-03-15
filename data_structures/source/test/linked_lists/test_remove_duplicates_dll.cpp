//
// Created by andreas on 15.03.23.
//

#include "test_setup_doubly_linked_lists.h"
#include "linked_lists/remove_duplicates_dll.h"
TEST_F(SetupDoublyLinkedLists, remove_duplicates1)
{
	std::vector<int> input_with_duplicates1{1, 2, 4, 2, 6, 7, 6};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates1);
	auto result = remove_duplicates(head);
	std::vector<int> result_without_duplicates1{1, 2, 4, 6 ,7};
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates1[index++], result->value);
		result = result->next;
	}
}

TEST_F(SetupDoublyLinkedLists, remove_duplicates2)
{
	std::vector<int> input_with_duplicates2{1, 2, 2, 2, 6, 7, 8};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates2);
	auto result = remove_duplicates(head);
	std::vector<int> result_without_duplicates2{1, 2, 6, 7, 8};
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates2[index++], result->value);
		result = result->next;
	}
}


TEST_F(SetupDoublyLinkedLists, remove_duplicates3)
{
	std::vector<int> input_with_duplicates3{1, 1, 1, 1};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates3);
	auto result = remove_duplicates(head);
	std::vector<int> result_without_duplicates3{1};
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates3[index++], result->value);
		result = result->next;
	}
}

TEST_F(SetupDoublyLinkedLists, remove_duplicates4)
{
	std::vector<int> input_with_duplicates4{1, 1};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates4);
	auto result = remove_duplicates(head);
	int index{};
	std::vector<int> result_without_duplicates4{1};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates4[index++], result->value);
		result = result->next;
	}
}

TEST_F(SetupDoublyLinkedLists, empty_list)
{
	NodeDLL<double> * head = nullptr;
	auto result = remove_duplicates(head);
	EXPECT_TRUE(result == nullptr);
}

TEST_F(SetupDoublyLinkedLists, input_with_no_duplicates1)
{
	std::vector<int> input_with_no_duplicates1{3, 1};
	auto head = get_doubly_list_head_from_vector(input_with_no_duplicates1);
	auto result = remove_duplicates(head);
	int index{};
	while(result)
	{
		EXPECT_EQ(input_with_no_duplicates1[index++], result->value);
		result = result->next;
	}
}

TEST_F(SetupDoublyLinkedLists, input_with_no_duplicates2)
{
	std::vector<int> input_with_no_duplicates2{3, 1, 2, 5, 7};
	auto head = get_doubly_list_head_from_vector(input_with_no_duplicates2);
	auto result = remove_duplicates(head);
	int index{};
	while(result)
	{
		EXPECT_EQ(input_with_no_duplicates2[index++], result->value);
		result = result->next;
	}
}
