//
// Created by andreas on 07.05.24.
//
#include "setup_singly_linked_lists.h"
#include "linked_lists/remove_larger_nodes.h"

TEST_F(SetupSinglyLinkedLists, RemoveLargerNodesSimple1)
{
    auto input = get_single_list_from_vector(std::vector<int>{5,2,13,3,8});
    auto expected_output = get_single_list_from_vector(std::vector<int>{13, 8});
    auto result = remove_larger_nodes(input);
    while(expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, RemoveLargerNodesSimple2)
{
    auto input = get_single_list_from_vector(std::vector<int>{1,1,1,1,1,1});
    auto expected_output = get_single_list_from_vector(std::vector<int>{1,1,1,1,1,1});
    auto result = remove_larger_nodes(input);
    while(expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, RemoveLargerNodesSimple3)
{
    auto input = get_single_list_from_vector(std::vector<int>{1,2,3,4,5,6});
    auto expected_output = get_single_list_from_vector(std::vector<int>{6});
    auto result = remove_larger_nodes(input);
    while(expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, RemoveLargerNodesSimple4)
{
    auto input = get_single_list_from_vector(std::vector<int>{6,5,4,3,2,1});
    auto expected_output = get_single_list_from_vector(std::vector<int>{6,5,4,3,2,1});
    auto result = remove_larger_nodes(input);
    while(expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, RemoveLargerNodesSimple5)
{
    auto input = get_single_list_from_vector(std::vector<int>{6,50,41,390,221,12});
    auto expected_output = get_single_list_from_vector(std::vector<int>{390,221,12});
    auto result = remove_larger_nodes(input);
    while(expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, RemoveLargerNodesSimple6)
{
    auto input = get_single_list_from_vector(std::vector<int>{6,50,41,48,34,12, 36});
    auto expected_output = get_single_list_from_vector(std::vector<int>{50,48,36});
    auto result = remove_larger_nodes(input);
    while(expected_output)
    {
        EXPECT_EQ(expected_output->value, result->value);
        expected_output = expected_output->next;
        result = result->next;
    }
}