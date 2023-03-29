//
// Created by andreas on 29.03.23.
//
#include "setup_singly_linked_lists.h"
#include "linked_lists/does_linked_list_have_loop.h"

TEST_F(SetupSinglyLinkedLists, does_linked_list_have_loop_yes)
{
	std::vector<short> input{1, 2, 3, 4, 5};
	auto head = get_single_list_from_vector(input);
	head->next->next->next->next->next = head->next;
	auto expected_node = head->next;
	Node<short> *result_node;
	EXPECT_TRUE(does_linked_list_have_loop(head, result_node));
	EXPECT_EQ(result_node, expected_node);
}

TEST_F(SetupSinglyLinkedLists, does_linked_list_have_loop_yes_on_head)
{
	std::vector<short> input{1, 2, 3, 4, 5};
	auto head = get_single_list_from_vector(input);
	head->next->next->next->next->next = head;
	auto expected_node = head;
	Node<short> *result_node;
	EXPECT_TRUE(does_linked_list_have_loop(head, result_node));
	EXPECT_EQ(result_node, expected_node);

}

TEST_F(SetupSinglyLinkedLists, does_linked_list_have_loop_yes_on_tail)
{
	std::vector<short> input{1, 2, 3, 4, 5};
	auto head = get_single_list_from_vector(input);
	head->next->next->next->next->next = head->next->next->next->next;
	auto expected_node = head->next->next->next->next;
	Node<short> *result_node;
	EXPECT_TRUE(does_linked_list_have_loop(head, result_node));
	EXPECT_EQ(result_node, expected_node);

}

TEST_F(SetupSinglyLinkedLists, does_linked_list_have_loop_no)
{
	std::vector<short> input{1, 2, 3, 4, 5};
	auto head = get_single_list_from_vector(input);
	Node<short> *expected_node = nullptr;
	Node<short> *result_node;
	EXPECT_FALSE(does_linked_list_have_loop(head, result_node));
	EXPECT_EQ(result_node, expected_node);
}