//
// Created by andreas on 15.03.23.
//

#include "test_setup_doubly_linked_lists.h"
#include "linked_lists/remove_duplicates_dll.h"

TEST_F(SetupDoublyLinkedLists, remove_duplicates_head1)
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

TEST_F(SetupDoublyLinkedLists, remove_duplicates_head2)
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


TEST_F(SetupDoublyLinkedLists, remove_duplicates_head3)
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

TEST_F(SetupDoublyLinkedLists, remove_duplicates_head4)
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

TEST_F(SetupDoublyLinkedLists, empty_list_head)
{
	NodeDLL<double> * head = nullptr;
	auto result = remove_duplicates(head);
	EXPECT_TRUE(result == nullptr);
}

TEST_F(SetupDoublyLinkedLists, input_with_no_duplicates_head1)
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

TEST_F(SetupDoublyLinkedLists, input_with_no_duplicates_head2)
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


TEST_F(SetupDoublyLinkedLists, remove_duplicates_tail1)
{
	std::vector<int> input_with_duplicates1{1, 2, 4, 2, 6, 7, 6};
	auto tail = get_doubly_list_tail_from_vector(input_with_duplicates1);
	auto result = remove_duplicates_from_tail(tail);
	std::vector<int> result_without_duplicates1 = {1, 4, 2, 7, 6};
	std::ranges::reverse(result_without_duplicates1);
	int index{};

	while(result)
	{
		EXPECT_EQ(result_without_duplicates1[index++], result->value);
		result = result->previous;
	}
}

TEST_F(SetupDoublyLinkedLists, remove_duplicates_tail2)
{
	std::vector<int> input_with_duplicates2{1, 2, 2, 2, 6, 7, 8};
	auto tail = get_doubly_list_tail_from_vector(input_with_duplicates2);
	auto result = remove_duplicates_from_tail(tail);
	std::vector<int> result_without_duplicates2{1, 2, 6, 7, 8};
	std::ranges::reverse(result_without_duplicates2);
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates2[index++], result->value);
		result = result->previous;
	}
}


TEST_F(SetupDoublyLinkedLists, remove_duplicates_tail3)
{
	std::vector<int> input_with_duplicates3{1, 1, 1, 1};
	auto tail = get_doubly_list_tail_from_vector(input_with_duplicates3);
	auto result = remove_duplicates_from_tail(tail);
	std::vector<int> result_without_duplicates3{1};
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates3[index++], result->value);
		result = result->previous;
	}
}

TEST_F(SetupDoublyLinkedLists, remove_duplicates_tail4)
{
	std::vector<int> input_with_duplicates4{1, 1};
	auto tail = get_doubly_list_tail_from_vector(input_with_duplicates4);
	auto result = remove_duplicates_from_tail(tail);
	int index{};
	std::vector<int> result_without_duplicates4{1};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates4[index++], result->value);
		result = result->previous;
	}
}

TEST_F(SetupDoublyLinkedLists, empty_list_tail)
{
	NodeDLL<double> * tail = nullptr;
	auto result = remove_duplicates_from_tail(tail);
	EXPECT_TRUE(result == nullptr);
}

TEST_F(SetupDoublyLinkedLists, input_with_no_duplicates_tail1)
{
	std::vector<int> input_with_no_duplicates1{3, 1};
	auto tail = get_doubly_list_tail_from_vector(input_with_no_duplicates1);
	auto result = remove_duplicates_from_tail(tail);
	std::ranges::reverse(input_with_no_duplicates1);
	int index{};
	while(result)
	{
		EXPECT_EQ(input_with_no_duplicates1[index++], result->value);
		result = result->previous;
	}
}

TEST_F(SetupDoublyLinkedLists, input_with_no_duplicates_tail2)
{
	std::vector<int> input_with_no_duplicates2{3, 1, 2, 5, 7};
	auto tail = get_doubly_list_tail_from_vector(input_with_no_duplicates2);
	auto result = remove_duplicates_from_tail(tail);
	std::ranges::reverse(input_with_no_duplicates2);
	int index{};
	while(result)
	{
		EXPECT_EQ(input_with_no_duplicates2[index++], result->value);
		result = result->next;
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEST_F(SetupDoublyLinkedLists, remove_duplicates_no_extra_space_head1)
{
	std::vector<int> input_with_duplicates1{1, 2, 4, 2, 6, 7, 6};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates1);
	auto result = remove_duplicates_no_extra_space(head);
	std::vector<int> result_without_duplicates1{1, 2, 4, 6 ,7};
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates1[index++], result->value);
		result = result->next;
	}
}

TEST_F(SetupDoublyLinkedLists, remove_duplicates_no_extra_space_head2)
{
	std::vector<int> input_with_duplicates2{1, 2, 2, 2, 6, 7, 8};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates2);
	auto result = remove_duplicates_no_extra_space(head);
	std::vector<int> result_without_duplicates2{1, 2, 6, 7, 8};
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates2[index++], result->value);
		result = result->next;
	}
}


TEST_F(SetupDoublyLinkedLists, remove_duplicates_no_extra_space_head3)
{
	std::vector<int> input_with_duplicates3{1, 1, 1, 1};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates3);
	auto result = remove_duplicates_no_extra_space(head);
	std::vector<int> result_without_duplicates3{1};
	int index{};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates3[index++], result->value);
		result = result->next;
	}
}

TEST_F(SetupDoublyLinkedLists, remove_duplicates_no_extra_space_head4)
{
	std::vector<int> input_with_duplicates4{1, 1};
	auto head = get_doubly_list_head_from_vector(input_with_duplicates4);
	auto result = remove_duplicates_no_extra_space(head);
	int index{};
	std::vector<int> result_without_duplicates4{1};
	while(result)
	{
		EXPECT_EQ(result_without_duplicates4[index++], result->value);
		result = result->next;
	}
}

TEST_F(SetupDoublyLinkedLists, empty_list_no_extra_head)
{
	NodeDLL<double> * head = nullptr;
	auto result = remove_duplicates_no_extra_space(head);
	EXPECT_TRUE(result == nullptr);
}

TEST_F(SetupDoublyLinkedLists, input_with_no_duplicates_no_extra_head1)
{
	std::vector<int> input_with_no_duplicates1{3, 1};
	auto head = get_doubly_list_head_from_vector(input_with_no_duplicates1);
	auto result = remove_duplicates_no_extra_space(head);
	int index{};
	while(result)
	{
		EXPECT_EQ(input_with_no_duplicates1[index++], result->value);
		result = result->next;
	}
}

TEST_F(SetupDoublyLinkedLists, input_with_no_duplicates_no_extra_head2)
{
	std::vector<int> input_with_no_duplicates2{3, 1, 2, 5, 7};
	auto head = get_doubly_list_head_from_vector(input_with_no_duplicates2);
	auto result = remove_duplicates_no_extra_space(head);
	int index{};
	while(result)
	{
		EXPECT_EQ(input_with_no_duplicates2[index++], result->value);
		result = result->next;
	}
}
