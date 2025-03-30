//
// Created by andreas on 10.08.24.
//

#include "gtest/gtest.h"
#include "linked_lists/remove_kth_to_last_node.h"
#include "setup_singly_linked_lists.h"

TEST_F(SetupSinglyLinkedLists, TestRemovekthToLastNodeSimple1)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected_output{1, 2, 3, 5};
    constexpr int k{2};
    auto input_list = get_single_list_from_vector(input);
    auto output_list = get_single_list_from_vector(expected_output);

    auto result = remove_kth_to_last_node(input_list, k);
    while (result)
    {
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }
}

TEST_F(SetupSinglyLinkedLists, TestRemovekthToLastNodeSimple2)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected_output{2, 3, 4, 5};
    constexpr int k{5};
    auto input_list = get_single_list_from_vector(input);
    auto output_list = get_single_list_from_vector(expected_output);

    auto result = remove_kth_to_last_node(input_list, k);
    while (result)
    {
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }
}


TEST_F(SetupSinglyLinkedLists, TestRemovekthToLastNodeSimple3)
{
    std::vector<int> input{1};
    std::vector<int> expected_output{};
    constexpr int k{1};
    auto input_list = get_single_list_from_vector(input);

    auto result = remove_kth_to_last_node(input_list, k);
    EXPECT_FALSE(result);
}
