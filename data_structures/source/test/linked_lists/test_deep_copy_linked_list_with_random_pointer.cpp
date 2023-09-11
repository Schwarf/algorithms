//
// Created by andreas on 11.09.23.
//
#include "gtest/gtest.h"
#include "linked_lists/deep_copy_linked_list_with_random_pointer.h"
#include "setup_singly_linked_lists.h"

TEST_F(SetupSinglyLinkedLists, deep_copy_with_pointer1)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6};
	std::unordered_map<int, int> from_to{{1, 3}, {2, 3}, {5, 6}};
	auto original_head = get_single_list_with_random_pointer_from_vector_and_value_pairs(input, from_to);
	auto result_head = deep_copy_linked_list_with_random_pointer(original_head);

	while (result_head && original_head) {
		EXPECT_NE(original_head, result_head);
		EXPECT_EQ(original_head->value, result_head->value);
		if (original_head->random)
			EXPECT_EQ(original_head->random->value, result_head->random->value);
		else
			EXPECT_EQ(result_head->random, nullptr);
		result_head = result_head->next;
		original_head = original_head->next;
	}
}

TEST_F(SetupSinglyLinkedLists, deep_copy_with_pointer2)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6};
	std::unordered_map<int, int> from_to{};
	auto original_head = get_single_list_with_random_pointer_from_vector_and_value_pairs(input, from_to);
	auto result_head = deep_copy_linked_list_with_random_pointer(original_head);

	while (result_head && original_head) {
		EXPECT_NE(original_head, result_head);
		EXPECT_EQ(original_head->value, result_head->value);
		if (original_head->random)
			EXPECT_EQ(original_head->random->value, result_head->random->value);
		else
			EXPECT_EQ(result_head->random, nullptr);
		result_head = result_head->next;
		original_head = original_head->next;
	}
}


TEST_F(SetupSinglyLinkedLists, deep_copy_with_pointer3)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6};
	std::unordered_map<int, int> from_to{{2, 1}, {3, 1}, {6, 1}};
	auto original_head = get_single_list_with_random_pointer_from_vector_and_value_pairs(input, from_to);
	auto result_head = deep_copy_linked_list_with_random_pointer(original_head);

	while (result_head && original_head) {
		EXPECT_NE(original_head, result_head);
		EXPECT_EQ(original_head->value, result_head->value);
		if (original_head->random)
			EXPECT_EQ(original_head->random->value, result_head->random->value);
		else
			EXPECT_EQ(result_head->random, nullptr);
		result_head = result_head->next;
		original_head = original_head->next;
	}
}

TEST_F(SetupSinglyLinkedLists, deep_copy_with_pointer4)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6};
	std::unordered_map<int, int> from_to{{2, 1}, {1, 2}, {3, 4}};
	auto original_head = get_single_list_with_random_pointer_from_vector_and_value_pairs(input, from_to);
	auto result_head = deep_copy_linked_list_with_random_pointer(original_head);

	while (result_head && original_head) {
		EXPECT_NE(original_head, result_head);
		EXPECT_EQ(original_head->value, result_head->value);
		if (original_head->random)
			EXPECT_EQ(original_head->random->value, result_head->random->value);
		else
			EXPECT_EQ(result_head->random, nullptr);
		result_head = result_head->next;
		original_head = original_head->next;
	}
}


TEST_F(SetupSinglyLinkedLists, deep_copy_with_pointer5)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6};
	std::unordered_map<int, int> from_to{{3, 1}, {2, 1}, {4, 1}, {5, 1}};
	auto original_head = get_single_list_with_random_pointer_from_vector_and_value_pairs(input, from_to);
	auto result_head = deep_copy_linked_list_with_random_pointer(original_head);

	while (result_head && original_head) {
		EXPECT_NE(original_head, result_head);
		EXPECT_EQ(original_head->value, result_head->value);
		if (original_head->random)
			EXPECT_EQ(original_head->random->value, result_head->random->value);
		else
			EXPECT_EQ(result_head->random, nullptr);
		result_head = result_head->next;
		original_head = original_head->next;
	}
}
