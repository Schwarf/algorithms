//
// Created by andreas on 07.05.24.
//
#include "linked_lists/double_number.h"
#include "setup_singly_linked_lists.h"

TEST_F(SetupSinglyLinkedLists, DoubleNumberWithStackSimple1)
{
    auto input = get_single_list_from_vector(std::vector<int>{1, 2, 3, 4});
    auto expected_output = get_single_list_from_vector(std::vector<int>{2, 4, 6, 8});
    auto result = double_number_stack(input);
    while (expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, DoubleNumberWithStackSimple2)
{
    auto input = get_single_list_from_vector(std::vector<int>{1, 8, 9});
    auto expected_output = get_single_list_from_vector(std::vector<int>{3, 7, 8});
    auto result = double_number_stack(input);
    while (expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, DoubleNumberWithStackSimple3)
{
    auto input = get_single_list_from_vector(std::vector<int>{9, 9, 9});
    auto expected_output = get_single_list_from_vector(std::vector<int>{1, 9, 9, 8});
    auto result = double_number_stack(input);
    while (expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, DoubleNumberWithStackSimple4)
{
    auto input = get_single_list_from_vector(std::vector<int>{
        9, 1, 9, 5, 0, 5, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9
    });
    auto expected_output = get_single_list_from_vector(std::vector<int>{
        1, 8, 3, 9, 0, 1, 0, 3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8
    });
    auto result = double_number_stack(input);
    while (expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, DoubleNumberSimple1)
{
    auto input = get_single_list_from_vector(std::vector<int>{1, 2, 3, 4});
    auto expected_output = get_single_list_from_vector(std::vector<int>{2, 4, 6, 8});
    auto result = double_number(input);
    while (expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, DoubleNumberSimple2)
{
    auto input = get_single_list_from_vector(std::vector<int>{1, 8, 9});
    auto expected_output = get_single_list_from_vector(std::vector<int>{3, 7, 8});
    auto result = double_number(input);
    while (expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, DoubleNumberSimple3)
{
    auto input = get_single_list_from_vector(std::vector<int>{9, 9, 9});
    auto expected_output = get_single_list_from_vector(std::vector<int>{1, 9, 9, 8});
    auto result = double_number(input);
    while (expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, DoubleNumberSimple4)
{
    auto input = get_single_list_from_vector(std::vector<int>{
        9, 1, 9, 5, 0, 5, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9
    });
    auto expected_output = get_single_list_from_vector(std::vector<int>{
        1, 8, 3, 9, 0, 1, 0, 3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8
    });
    auto result = double_number(input);
    while (expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}
