//
// Created by andreas on 29.03.23.
//
#include "setup_singly_linked_lists.h"
#include "linked_lists/are_linked_lists_intersecting.h"

TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_yes_list1_longer)
{
	std::vector<int> input{1, 2, 3, 4, 5};
	std::vector<int> input2{0};
	auto head1 = get_single_list_from_vector(input);
	auto head2 = get_single_list_from_vector(input2);
	head2->next = head1->next->next->next;
	auto expected_node = head2->next;
	Node<int> *result_node;
	EXPECT_TRUE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, expected_node);
}

TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_list2_longer)
{
	std::vector<int> input{1, 2, 3, 4, 5};
	std::vector<int> input2{0};
	auto head1 = get_single_list_from_vector(input2);
	auto head2 = get_single_list_from_vector(input);
	head1->next = head2->next->next->next;
	auto expected_node = head1->next;
	Node<int> *result_node;
	EXPECT_TRUE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, expected_node);
}

TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_lists_equal)
{
	std::vector<int> input1{1, 2, 3, 4, 5};
	std::vector<int> input2{-1, -2};
	auto head1 = get_single_list_from_vector(input1);
	auto head2 = get_single_list_from_vector(input2);
	head2->next->next = head1->next->next;
	auto expected_node = head1->next->next;
	Node<int> *result_node;
	EXPECT_TRUE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, expected_node);
}


TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_no)
{
	std::vector<int> input{1, 2, 3, 4, 5};
	std::vector<int> input2{0, 1, 2, 3, 3};
	auto head1 = get_single_list_from_vector(input);
	auto head2 = get_single_list_from_vector(input2);
	Node<int> *result_node;
	EXPECT_FALSE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, nullptr);
}


TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_yes_on_head)
{
	std::vector<int> input{1, 2, 3, 4, 5};
	auto head1 = get_single_list_from_vector(input);
	auto head2 = head1;
	auto expected_node = head2;
	Node<int> *result_node;
	EXPECT_TRUE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, expected_node);
}


TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_yes_on_tail)
{
	std::vector<int> input1{1, 2, 3, 4};
	std::vector<int> input2{1, 2, 3};
	auto head1 = get_single_list_from_vector(input1);
	auto head2 = get_single_list_from_vector(input2);
	head2->next->next->next = head1->next->next->next;
	auto expected_node = head2->next->next->next;
	Node<int> *result_node;
	EXPECT_TRUE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, expected_node);
}


TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_no_nullptr1)
{
	std::vector<int> input2{1, 2, 3};
	Node<int> *head1 = nullptr;
	auto head2 = get_single_list_from_vector(input2);
	auto expected_node = nullptr;
	Node<int> *result_node;
	EXPECT_FALSE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, expected_node);
}

TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_no_nullptr2)
{
	std::vector<int> input2{1, 2, 3};
	auto head1 = get_single_list_from_vector(input2);
	Node<int> *head2 = nullptr;
	auto expected_node = nullptr;
	Node<int> *result_node;
	EXPECT_FALSE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, expected_node);
}

TEST_F(SetupSinglyLinkedLists, are_linked_lists_intersecting_no_both_nullptr)
{
	Node<int> *head1 = nullptr;
	Node<int> *head2 = nullptr;
	auto expected_node = nullptr;
	Node<int> *result_node;
	EXPECT_FALSE(are_linked_lists_intersecting(head1, head2, result_node));
	EXPECT_EQ(result_node, expected_node);
}
