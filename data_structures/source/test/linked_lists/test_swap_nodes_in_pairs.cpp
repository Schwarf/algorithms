//
// Created by andreas on 16.05.23.
//
#include "gtest/gtest.h"
#include "setup_singly_linked_lists.h"
#include "linked_lists/swap_nodes_in_pairs.h"

TEST_F(SetupSinglyLinkedLists, swap_nodes_in_pairs_simple)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6};
    std::vector<int> output{2, 1, 4, 3, 6, 5};
    auto head = get_single_list_from_vector(input);
    auto expected_result = get_single_list_from_vector(output);
    auto result = swap_nodes_in_pairs(head);
    while (result)
    {
        EXPECT_EQ(result->value, expected_result->value);
        result = result->next;
        expected_result = expected_result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, swap_nodes_in_pairs_simple2)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> output{2, 1, 4, 3, 5};
    auto head = get_single_list_from_vector(input);
    auto expected_result = get_single_list_from_vector(output);
    auto result = swap_nodes_in_pairs(head);
    while (result)
    {
        EXPECT_EQ(result->value, expected_result->value);
        result = result->next;
        expected_result = expected_result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, swap_nodes_in_pairs_simple3)
{
    std::vector<int> input{1};
    std::vector<int> output{1};
    auto head = get_single_list_from_vector(input);
    auto expected_result = get_single_list_from_vector(output);
    auto result = swap_nodes_in_pairs(head);
    while (result)
    {
        EXPECT_EQ(result->value, expected_result->value);
        result = result->next;
        expected_result = expected_result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, swap_nodes_in_pairs_iterative_simple)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6};
    std::vector<int> output{2, 1, 4, 3, 6, 5};
    auto head = get_single_list_from_vector(input);
    auto expected_result = get_single_list_from_vector(output);
    auto result = swap_nodes_in_pairs_iterative(head);
    while (result)
    {
        EXPECT_EQ(result->value, expected_result->value);
        result = result->next;
        expected_result = expected_result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, swap_nodes_in_pairs_iterative_simple2)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> output{2, 1, 4, 3, 5};
    auto head = get_single_list_from_vector(input);
    auto expected_result = get_single_list_from_vector(output);
    auto result = swap_nodes_in_pairs_iterative(head);
    while (result)
    {
        EXPECT_EQ(result->value, expected_result->value);
        result = result->next;
        expected_result = expected_result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, swap_nodes_in_pairs_iterative_simple3)
{
    std::vector<int> input{1};
    std::vector<int> output{1};
    auto head = get_single_list_from_vector(input);
    auto expected_result = get_single_list_from_vector(output);
    auto result = swap_nodes_in_pairs_iterative(head);
    while (result)
    {
        EXPECT_EQ(result->value, expected_result->value);
        result = result->next;
        expected_result = expected_result->next;
    }
}
