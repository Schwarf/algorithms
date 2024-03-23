//
// Created by andreas on 23.03.24.
//
#include "linked_lists/reorder_list.h"
#include "setup_singly_linked_lists.h"

TEST_F(SetupSinglyLinkedLists, TestReorderList_simple1)
{
	auto input = get_single_list_from_vector<int>({1, 2, 3, 4});
	auto expected_list = get_single_list_from_vector<int>({1, 4, 2, 3});
	reorder_list(input);
	while (input) {
		EXPECT_EQ(expected_list->value, input->value);
		expected_list = expected_list->next;
		input = input->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestReorderList_simple2)
{
	auto input = get_single_list_from_vector<int>({1, 2, 3, 4, 5});
	auto expected_list = get_single_list_from_vector<int>({1, 5, 2, 4, 3});
	reorder_list(input);
	while (input) {
		EXPECT_EQ(expected_list->value, input->value);
		expected_list = expected_list->next;
		input = input->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestReorderList_simple3)
{
	auto input = get_single_list_from_vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
	auto expected_list = get_single_list_from_vector<int>({1, 11, 2, 10, 3, 9, 4, 8, 5, 7, 6});
	reorder_list(input);
	while (input) {
		EXPECT_EQ(expected_list->value, input->value);
		expected_list = expected_list->next;
		input = input->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestReorderList_simple4)
{
	auto input =
		get_single_list_from_vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
										  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
										  42, 43, 44, 45, 46, 47, 48, 49});
	auto expected_list =
		get_single_list_from_vector<int>({1, 49, 2, 48, 3, 47, 4, 46, 5, 45, 6, 44, 7, 43, 8, 42, 9, 41, 10, 40, 11, 39,
										  12, 38, 13, 37, 14, 36, 15, 35, 16, 34, 17, 33, 18, 32, 19, 31, 20, 30, 21,
										  29, 22, 28, 23, 27, 24, 26, 25});
	reorder_list(input);
	while (input) {
		EXPECT_EQ(expected_list->value, input->value);
		expected_list = expected_list->next;
		input = input->next;
	}
}
