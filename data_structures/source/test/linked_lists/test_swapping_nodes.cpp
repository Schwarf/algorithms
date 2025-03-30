//
// Created by andreas on 15.05.23.
//
#include "gtest/gtest.h"
#include "setup_singly_linked_lists.h"
#include "./linked_lists/swapping_nodes.h"

TEST_F(SetupSinglyLinkedLists, simple1)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected_output{1, 4, 3, 2, 5};
    constexpr int k{2};
    auto head1 = get_single_list_from_vector(input);
    auto expected = get_single_list_from_vector(expected_output);
    auto result = swapping_nodes(head1, k);
    while (result)
    {
        EXPECT_EQ(result->value, expected->value);
        expected = expected->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, simple2)
{
    std::vector<int> input{1, 2};
    std::vector<int> expected_output{2, 1};
    constexpr int k{1};
    auto head1 = get_single_list_from_vector(input);
    auto expected = get_single_list_from_vector(expected_output);
    auto result = swapping_nodes(head1, k);
    while (result)
    {
        EXPECT_EQ(result->value, expected->value);
        expected = expected->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, corner_case)
{
    std::vector<int> input{1};
    std::vector<int> expected_output{1};
    constexpr int k{1};
    auto head1 = get_single_list_from_vector(input);
    auto expected = get_single_list_from_vector(expected_output);
    auto result = swapping_nodes(head1, k);
    while (result)
    {
        EXPECT_EQ(result->value, expected->value);
        expected = expected->next;
        result = result->next;
    }
}


TEST_F(SetupSinglyLinkedLists, simple3)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6};
    std::vector<int> expected_output{1, 5, 3, 4, 2, 6};
    constexpr int k{5};
    auto head1 = get_single_list_from_vector(input);
    auto expected = get_single_list_from_vector(expected_output);
    auto result = swapping_nodes(head1, k);
    while (result)
    {
        EXPECT_EQ(result->value, expected->value);
        expected = expected->next;
        result = result->next;
    }
}
