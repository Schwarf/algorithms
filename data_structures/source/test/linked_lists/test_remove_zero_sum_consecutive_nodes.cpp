//
// Created by andreas on 12.03.24.
//

#include "setup_singly_linked_lists.h"
#include "linked_lists/remove_zero_sum_consecutive_nodes.h"

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesSimple1)
{
	const std::vector<int> input{1, 2, -3, 3, 1};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes(head);
	const std::vector<int> expected_vector{3, 1};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesSimple2)
{
	const std::vector<int> input{1, 2, 3, -3, 4};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes(head);
	const std::vector<int> expected_vector{1, 2, 4};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesSimple3)
{
	const std::vector<int> input{1, 2, 3, -3, -2};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes(head);
	const std::vector<int> expected_vector{1};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesSimple4)
{
	const std::vector<int> input{1, 2, 3, 4};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes(head);
	const std::vector<int> expected_vector{1, 2, 3, 4};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesSimple5)
{
	const std::vector<int> input{-1, 3, 5, 1, 4, 0, 5, 4, -3, 4, 5, -5, 2};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes(head);
	const std::vector<int> expected_vector{-1, 3, 5, 1, 4, 5, 4, -3, 4, 2};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesComplex1)
{
	const std::vector<int> input
		{10, 6, 10, 5, 5, -2, 7, 6, -7, 6, -10, 2, 0, -1, 10, -7, 8, 7, -8, -2, -10, -2, 9, 3, 0, -1, 2, 2, -3, 7,
		 -7, -9, 8, 5, 0, 1, 1, -3, -10, -3, 6, -7, 4, 2, 8, 8, 9, 9, -10, 0, 8, -10, -5, 2, 7, -5, 8, -1, -6, 1, 6,
		 -4, 7, 2, -10, -2, -8, 8, -9, 8, 8, -9, -7, 1, 0, 4, -2, 10, 9, -8, 10, -1, 5, -2, -4, -3, -4, 9, 2, -7, 1,
		 8, 8, -10, -5, -2, 7, 2, 9, -6, -7, 4, -2, 0, 5, -8, -6, -7, -10, 0, 0, -4, -7, -2, -3, 0, -3, -8, -2, 1,
		 2, -6, 9, 2, 6, 4, 8, 6, -10, -8, 5, 6, -10, 3, 3, -8, -10, 2, 3, -7, -7, -6, 0, -6, 4, -8, 8, -9, 6, -4,
		 8, 6, -2, 3, -2, 4, 10, 6, -10, 0, -9, 7, -3, 2, 9, -6, -2, -7, -10, -1, 5, 3, 10, 10, 10, 1, 7, 10, -7, 7,
		 -6, -5, -2, -9, -8, -2, 10, -6, -9, -9, -1, 2, 1, -7, -5, 1, 3, 7, 9, -4, -2, -1, -5, -8, -9, 0, 5, -2, -6,
		 -9, -5, -10, -2, -5, 0, -7, -4, 0, 3, 8, 9, -1, -5, -2, -7, -1, -4, 9, -7, -2, -3, 10, -10, -4, 6, -9, -3,
		 -6, -8, 1, -4, 2, 6, -2, 6, -4, 0, -7, 7, 2, 1, -2, 8, -10, 7, 1, 8, 3, -5, -10, -10, -4, 6, -1, 5, -9, 7,
		 7, 5, -9, 1, 10, 6, 3, -3, 4, 10, 2, -1, -3, 4, 2, 9, 2, 10, -7, -4, -4, -8, -5, -8, -9, -7, -10, 5, -6,
		 -1, -2, 6, -5, -9, 4, 5, -9, -3, 4, -7, 3, 2, 7, 3, 10, -4, -8, -3, 4, 4, -4, 0, 7, -3, 10, -2, -1, -9, -5,
		 5, -2, 8, -3, -3, -8, 10, -1, 0, 3, 5, -9, 1, -8, 10, -3, -1, 6, -3, 0, -5, -2, 7, -9, 4, -4, 0, 4, 1, 3, 3,
		 -1, 2, 6, 2, 10, 7, -7, -6, 9, -9, -9, -9, -6, -6, 7, 2, 5, -5, 3, 1, 9, 7, 0, -7, -5, 0, -2, 5, -10, 9, 2, 8,
		 -5, 10, -5, 8, 10, -8, 0, -3, -10, -4, -4, -4, -8, 2, 8, -5, 3, -2, -10, 8, 8, -9, 6, 10, -5, -7, -9, 5, 8,
		 -1, -3, 5, 4, -1, 1, 10, 4, 9, 0, 3, -7, -9, -9, -7, 8, -9, -10, -8, -3, 7, 10, -2, 10, -7, 3, 3, -7, 3, 10,
		 9, 8, 0, -7, -6, 10, -5, 1, -7, -7, -1, -4, -3, 10, 8, -5, -6, -8, -1, -9, 1, 0, -2, -10, 6, -8, -8, 1, -5, 9,
		 3, 1, -2, -7, -2, 8, -8, -8, -4, 1, -3, -1, 1, -1, 10, 6, -2, -6, -8, 1, -10, 5, -3, 8, -7, 1, 0, -8, 4, 1, 6,
		 9, 6, 6, 2, -1, -10, -6, 3, -2, 7, -3, 9, -8, 6, 0, 6, -5, 2, 3, 5, -4, -6, -10, 8, 10, 1, -7, 4, 5, 4, 2, -3,
		 8, 0, -3, -6, -3, -7, -4, -7, -6, 2, -3, 2, 6, -9, -3, 10, -3, 9, 6, -4, -6, -3, 1, -1, -7, -3, 8, 5, 5, 10,
		 6, -8, -1, -8, -2, 1, -4, 10, -3, -5, 9, -10, 5, -5, 6, -1, 2, -10, -4, 8, -4, -6, -7, 4, -2, -1, -4, 5, -2,
		 -5, 9, 10, -8, -8, 4, 7, 2, 10, -8, 4, 9, -10, -9, 3, -3, 8, 10, 1, -2, 1, 2, -4, -10, -3, 3, 5, 4, -2, 8, 7,
		 -7, 0, 10, 10, 2, 9, -9, 1, -8, -3, -3, -1, 4, 0, -4, 9, -3, 10, 8, 6, -5, -1, -1, -9, 5, -7, 3, -9, 0, 2,
		 -10, 5, 8, 7, -10, -6, -9, -4, 9, -4, 0, -5, 0, 5, 9, 2, -3, 4, -1, -4, 4, -2, 4, 9, 9, -4, 3, -8, 3, 1, 0,
		 6, 3, 2, -6, -1, -1, -2, -2, 9, -8, 8, 8, -7, 1, -2, -10, -3, 2, -6, -8, -5, 0, -5, -7, -9, 9, 3, 2, 1, -6,
		 6, -10, 6, -2, -7, 5, 4, 8, 1, 1, -8, 9, 3, -6, -1, -10, 4, -6, 0, -8, 1, -3, 7, 2, 5, -1, 0, 5, 7, -10, -6,
		 7, 4, -3, -8, 8, -10, -9, -10, 0, 4, -8, -8, -2, -10, -4, -5, 4, 3, -7, -1, -9, -6, 4, -5, 7, -5, 4, 4, -9,
		 6, -5, -6, -3, 2, -1, -2, 2, 9, -6, -7, 10, 7, -3, 8, 6, 0, -2, -10, 2, -5, 9, -7, -10, 4, 7, -10, -8, 8, 6,
		 7, 5, -2, -9, 1, 2, -6, -1, -1, -1, -10, 5, 8, 3, -6, -7, -6, -5, -2, -9, -5, -5, 6, 6, -10, 7, 4, -9, 7, 6,
		 10, 3, -6, 8, -4, -10, -7, 2, -2, 7, 10, 3, 4, 4, 5, 0, -6, 10, -1, 6, -7, -9, 6, 8, -9, 2, 0, -4, 7, -5, 0,
		 -7, 5, -1, -1, 4, -8, 9, 9, 5, 5, 2, 1, 6, 0, -10, 4, 1, -7, 7, -7, -3, -8, -7, -7, -10, -10, -3, -10, 10, 2,
		 3, 2, -4, -5, -4, 5, -10, -6, 9, 4, 2, -9, 10, 8, 7, -8, -10, -9, -3, 8, -1, 5, -6, -9, -4, -7, -9, 4, 10, -7,
		 9, -8, 8, -2, 5, 10, -8, -4, -3, -3, -5, -6, -6, 5, 0, 8, -10, -8, 8, -6, -2, 1, -8, 0, 10, 4, -5, 6, 6, 1, 8,
		 5, -2, 9, 10, 2, -5, 9, -10, -7, 6, -5, -1, 3, 1, -7, 2, 6, -4, 1, 10, 3, -4, 8, -8, 3, 0, -2, -3, -6, -2, -3,
		 7, -9, -3, -7, 8};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes(head);
	const std::vector<int> expected_vector
		{-6, -9, -5, -10, -2, -5, -5, -8, -7, -7, -7, -1, 3, 1, -2, -10, -3, 2, -6, -8, -5, -10, -6, 8, -10, -9, -10, 4,
		 -8, -8, -2, -10, -4, 1, 1, -7, -3, -8, -7, -7, -10, -10, -8, 3, -2, -3, -6, -2, -3, 7, -9, -3, -7, 8};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}


TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesOptimizedSimple1)
{
	const std::vector<int> input{1, 2, -3, 3, 1};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes_optimized(head);
	const std::vector<int> expected_vector{3, 1};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesOptimizedSimple2)
{
	const std::vector<int> input{1, 2, 3, -3, 4};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes_optimized(head);
	const std::vector<int> expected_vector{1, 2, 4};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesOptimizedSimple3)
{
	const std::vector<int> input{1, 2, 3, -3, -2};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes_optimized(head);
	const std::vector<int> expected_vector{1};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesOptimizedSimple4)
{
	const std::vector<int> input{1, 2, 3, 4};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes_optimized(head);
	const std::vector<int> expected_vector{1, 2, 3, 4};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesOptimizedSimple5)
{
	const std::vector<int> input{-1, 3, 5, 1, 4, 0, 5, 4, -3, 4, 5, -5, 2};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes_optimized(head);
	const std::vector<int> expected_vector{-1, 3, 5, 1, 4, 5, 4, -3, 4, 2};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}

TEST_F(SetupSinglyLinkedLists, TestRemoveZeroSumConsecutiveNodesOptimizedComplex1)
{
	const std::vector<int> input
		{10, 6, 10, 5, 5, -2, 7, 6, -7, 6, -10, 2, 0, -1, 10, -7, 8, 7, -8, -2, -10, -2, 9, 3, 0, -1, 2, 2, -3, 7,
		 -7, -9, 8, 5, 0, 1, 1, -3, -10, -3, 6, -7, 4, 2, 8, 8, 9, 9, -10, 0, 8, -10, -5, 2, 7, -5, 8, -1, -6, 1, 6,
		 -4, 7, 2, -10, -2, -8, 8, -9, 8, 8, -9, -7, 1, 0, 4, -2, 10, 9, -8, 10, -1, 5, -2, -4, -3, -4, 9, 2, -7, 1,
		 8, 8, -10, -5, -2, 7, 2, 9, -6, -7, 4, -2, 0, 5, -8, -6, -7, -10, 0, 0, -4, -7, -2, -3, 0, -3, -8, -2, 1,
		 2, -6, 9, 2, 6, 4, 8, 6, -10, -8, 5, 6, -10, 3, 3, -8, -10, 2, 3, -7, -7, -6, 0, -6, 4, -8, 8, -9, 6, -4,
		 8, 6, -2, 3, -2, 4, 10, 6, -10, 0, -9, 7, -3, 2, 9, -6, -2, -7, -10, -1, 5, 3, 10, 10, 10, 1, 7, 10, -7, 7,
		 -6, -5, -2, -9, -8, -2, 10, -6, -9, -9, -1, 2, 1, -7, -5, 1, 3, 7, 9, -4, -2, -1, -5, -8, -9, 0, 5, -2, -6,
		 -9, -5, -10, -2, -5, 0, -7, -4, 0, 3, 8, 9, -1, -5, -2, -7, -1, -4, 9, -7, -2, -3, 10, -10, -4, 6, -9, -3,
		 -6, -8, 1, -4, 2, 6, -2, 6, -4, 0, -7, 7, 2, 1, -2, 8, -10, 7, 1, 8, 3, -5, -10, -10, -4, 6, -1, 5, -9, 7,
		 7, 5, -9, 1, 10, 6, 3, -3, 4, 10, 2, -1, -3, 4, 2, 9, 2, 10, -7, -4, -4, -8, -5, -8, -9, -7, -10, 5, -6,
		 -1, -2, 6, -5, -9, 4, 5, -9, -3, 4, -7, 3, 2, 7, 3, 10, -4, -8, -3, 4, 4, -4, 0, 7, -3, 10, -2, -1, -9, -5,
		 5, -2, 8, -3, -3, -8, 10, -1, 0, 3, 5, -9, 1, -8, 10, -3, -1, 6, -3, 0, -5, -2, 7, -9, 4, -4, 0, 4, 1, 3, 3,
		 -1, 2, 6, 2, 10, 7, -7, -6, 9, -9, -9, -9, -6, -6, 7, 2, 5, -5, 3, 1, 9, 7, 0, -7, -5, 0, -2, 5, -10, 9, 2, 8,
		 -5, 10, -5, 8, 10, -8, 0, -3, -10, -4, -4, -4, -8, 2, 8, -5, 3, -2, -10, 8, 8, -9, 6, 10, -5, -7, -9, 5, 8,
		 -1, -3, 5, 4, -1, 1, 10, 4, 9, 0, 3, -7, -9, -9, -7, 8, -9, -10, -8, -3, 7, 10, -2, 10, -7, 3, 3, -7, 3, 10,
		 9, 8, 0, -7, -6, 10, -5, 1, -7, -7, -1, -4, -3, 10, 8, -5, -6, -8, -1, -9, 1, 0, -2, -10, 6, -8, -8, 1, -5, 9,
		 3, 1, -2, -7, -2, 8, -8, -8, -4, 1, -3, -1, 1, -1, 10, 6, -2, -6, -8, 1, -10, 5, -3, 8, -7, 1, 0, -8, 4, 1, 6,
		 9, 6, 6, 2, -1, -10, -6, 3, -2, 7, -3, 9, -8, 6, 0, 6, -5, 2, 3, 5, -4, -6, -10, 8, 10, 1, -7, 4, 5, 4, 2, -3,
		 8, 0, -3, -6, -3, -7, -4, -7, -6, 2, -3, 2, 6, -9, -3, 10, -3, 9, 6, -4, -6, -3, 1, -1, -7, -3, 8, 5, 5, 10,
		 6, -8, -1, -8, -2, 1, -4, 10, -3, -5, 9, -10, 5, -5, 6, -1, 2, -10, -4, 8, -4, -6, -7, 4, -2, -1, -4, 5, -2,
		 -5, 9, 10, -8, -8, 4, 7, 2, 10, -8, 4, 9, -10, -9, 3, -3, 8, 10, 1, -2, 1, 2, -4, -10, -3, 3, 5, 4, -2, 8, 7,
		 -7, 0, 10, 10, 2, 9, -9, 1, -8, -3, -3, -1, 4, 0, -4, 9, -3, 10, 8, 6, -5, -1, -1, -9, 5, -7, 3, -9, 0, 2,
		 -10, 5, 8, 7, -10, -6, -9, -4, 9, -4, 0, -5, 0, 5, 9, 2, -3, 4, -1, -4, 4, -2, 4, 9, 9, -4, 3, -8, 3, 1, 0,
		 6, 3, 2, -6, -1, -1, -2, -2, 9, -8, 8, 8, -7, 1, -2, -10, -3, 2, -6, -8, -5, 0, -5, -7, -9, 9, 3, 2, 1, -6,
		 6, -10, 6, -2, -7, 5, 4, 8, 1, 1, -8, 9, 3, -6, -1, -10, 4, -6, 0, -8, 1, -3, 7, 2, 5, -1, 0, 5, 7, -10, -6,
		 7, 4, -3, -8, 8, -10, -9, -10, 0, 4, -8, -8, -2, -10, -4, -5, 4, 3, -7, -1, -9, -6, 4, -5, 7, -5, 4, 4, -9,
		 6, -5, -6, -3, 2, -1, -2, 2, 9, -6, -7, 10, 7, -3, 8, 6, 0, -2, -10, 2, -5, 9, -7, -10, 4, 7, -10, -8, 8, 6,
		 7, 5, -2, -9, 1, 2, -6, -1, -1, -1, -10, 5, 8, 3, -6, -7, -6, -5, -2, -9, -5, -5, 6, 6, -10, 7, 4, -9, 7, 6,
		 10, 3, -6, 8, -4, -10, -7, 2, -2, 7, 10, 3, 4, 4, 5, 0, -6, 10, -1, 6, -7, -9, 6, 8, -9, 2, 0, -4, 7, -5, 0,
		 -7, 5, -1, -1, 4, -8, 9, 9, 5, 5, 2, 1, 6, 0, -10, 4, 1, -7, 7, -7, -3, -8, -7, -7, -10, -10, -3, -10, 10, 2,
		 3, 2, -4, -5, -4, 5, -10, -6, 9, 4, 2, -9, 10, 8, 7, -8, -10, -9, -3, 8, -1, 5, -6, -9, -4, -7, -9, 4, 10, -7,
		 9, -8, 8, -2, 5, 10, -8, -4, -3, -3, -5, -6, -6, 5, 0, 8, -10, -8, 8, -6, -2, 1, -8, 0, 10, 4, -5, 6, 6, 1, 8,
		 5, -2, 9, 10, 2, -5, 9, -10, -7, 6, -5, -1, 3, 1, -7, 2, 6, -4, 1, 10, 3, -4, 8, -8, 3, 0, -2, -3, -6, -2, -3,
		 7, -9, -3, -7, 8};
	auto head = get_single_list_from_vector(input);
	auto result = remove_zero_sum_consecutive_nodes_optimized(head);
	const std::vector<int> expected_vector
		{-6, -9, -5, -10, -2, -5, -5, -8, -7, -7, -7, -1, 3, 1, -2, -10, -3, 2, -6, -8, -5, -10, -6, 8, -10, -9, -10, 4,
		 -8, -8, -2, -10, -4, 1, 1, -7, -3, -8, -7, -7, -10, -10, -8, 3, -2, -3, -6, -2, -3, 7, -9, -3, -7, 8};
	auto expected_result = get_single_list_from_vector(expected_vector);
	while (result || expected_result) {
		EXPECT_EQ(result->value, expected_result->value);
		result = result->next;
		expected_result = expected_result->next;
	}
}