//
// Created by andreas on 17.03.23.
//
#include "setup_singly_linked_lists.h"
#include "linked_lists/kth_to_last.h"
#include <vector>

TEST_F(SetupSinglyLinkedLists, next_to_last)
{
    std::vector<int> input{8, 7, 6, 5, 4, 3, 2, 1};
    auto head = get_single_list_from_vector(input);
    int k{2};
    auto result = kth_to_last_element(head, k);
    int expected_node_value{2};
    EXPECT_EQ(result->value, expected_node_value);
}

TEST_F(SetupSinglyLinkedLists, tenth_to_last)
{
    std::vector<int> input{8, 7, 6, 5, 4, 3, 2, 1};
    auto head = get_single_list_from_vector(input);
    int k{10};
    auto result = kth_to_last_element(head, k);
    int expected_node_value{8};
    EXPECT_EQ(result->value, expected_node_value);
}

TEST_F(SetupSinglyLinkedLists, k_is_zero)
{
    std::vector<int> input{8, 7, 6, 5, 4, 3, 2, 1};
    auto head = get_single_list_from_vector(input);
    int k{};
    auto result = kth_to_last_element(head, k);
    while (result)
    {
        EXPECT_EQ(result->value, head->value);
        result = result->next;
        head = head->next;
    }
}

TEST_F(SetupSinglyLinkedLists, eighth_element)
{
    std::vector<int> input{8, 7, 6, 5, 4, 3, 2, 1};
    auto head = get_single_list_from_vector(input);
    int k{8};
    auto result = kth_to_last_element(head, k);
    int expected_node_value{8};
    EXPECT_EQ(result->value, expected_node_value);
}
