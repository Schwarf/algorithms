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

    auto result = remove_kth_to_last_node(k, input_list);
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

    auto result = remove_kth_to_last_node(k, input_list);
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

    auto result = remove_kth_to_last_node(k, input_list);
    EXPECT_FALSE(result);
}


TEST_F(SetupSinglyLinkedLists, TestRemoveKthToLastNodeRemovesTail)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected_output{1, 2, 3, 4};
    constexpr int k{1};

    auto input_list = get_single_list_from_vector(input);
    auto output_list = get_single_list_from_vector(expected_output);

    remove_kth_to_last_node(input_list, k);

    auto result = input_list;
    while (result)
    {
        EXPECT_NE(output_list, nullptr);
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }

    EXPECT_EQ(output_list, nullptr);
}

TEST_F(SetupSinglyLinkedLists, TestRemoveKthToLastNodeRemovesSecondToLastNode)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected_output{1, 2, 3, 5};
    constexpr int k{2};

    auto input_list = get_single_list_from_vector(input);
    auto output_list = get_single_list_from_vector(expected_output);

    remove_kth_to_last_node(input_list, k);

    auto result = input_list;
    while (result)
    {
        EXPECT_NE(output_list, nullptr);
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }

    EXPECT_EQ(output_list, nullptr);
}

TEST_F(SetupSinglyLinkedLists, TestRemoveKthToLastNodeRemovesMiddleNode)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected_output{1, 2, 4, 5};
    constexpr int k{3};

    auto input_list = get_single_list_from_vector(input);
    auto output_list = get_single_list_from_vector(expected_output);

    remove_kth_to_last_node(input_list, k);

    auto result = input_list;
    while (result)
    {
        EXPECT_NE(output_list, nullptr);
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }

    EXPECT_EQ(output_list, nullptr);
}

TEST_F(SetupSinglyLinkedLists, TestRemoveKthToLastNodeRemovesSecondNode)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected_output{1, 3, 4, 5};
    constexpr int k{4};

    auto input_list = get_single_list_from_vector(input);
    auto output_list = get_single_list_from_vector(expected_output);

    remove_kth_to_last_node(input_list, k);

    auto result = input_list;
    while (result)
    {
        EXPECT_NE(output_list, nullptr);
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }

    EXPECT_EQ(output_list, nullptr);
}

TEST_F(SetupSinglyLinkedLists, TestRemoveKthToLastNodeRemovesHead)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    std::vector<int> expected_output{2, 3, 4, 5};
    constexpr int k{5};

    auto input_list = get_single_list_from_vector(input);
    auto original_head = input_list;
    auto output_list = get_single_list_from_vector(expected_output);

    remove_kth_to_last_node(input_list, k);

    EXPECT_EQ(input_list, original_head);

    auto result = input_list;
    while (result)
    {
        EXPECT_NE(output_list, nullptr);
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }

    EXPECT_EQ(output_list, nullptr);
}

TEST_F(SetupSinglyLinkedLists, TestRemoveKthToLastNodeTwoNodesRemoveTail)
{
    std::vector<int> input{1, 2};
    std::vector<int> expected_output{1};
    constexpr int k{1};

    auto input_list = get_single_list_from_vector(input);
    auto output_list = get_single_list_from_vector(expected_output);

    remove_kth_to_last_node(input_list, k);

    auto result = input_list;
    while (result)
    {
        EXPECT_NE(output_list, nullptr);
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }

    EXPECT_EQ(output_list, nullptr);
}

TEST_F(SetupSinglyLinkedLists, TestRemoveKthToLastNodeTwoNodesRemoveHead)
{
    std::vector<int> input{1, 2};
    std::vector<int> expected_output{2};
    constexpr int k{2};

    auto input_list = get_single_list_from_vector(input);
    auto original_head = input_list;
    auto output_list = get_single_list_from_vector(expected_output);

    remove_kth_to_last_node(input_list, k);

    EXPECT_EQ(input_list, original_head);

    auto result = input_list;
    while (result)
    {
        EXPECT_NE(output_list, nullptr);
        EXPECT_EQ(result->value, output_list->value);
        result = result->next;
        output_list = output_list->next;
    }

    EXPECT_EQ(output_list, nullptr);
}