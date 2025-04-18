//
// Created by andreas on 19.03.23.
//
#include "setup_singly_linked_lists.h"
#include "linked_lists/add_two_numbers.h"

TEST_F(SetupSinglyLinkedLists, add_two_numbers)
{
    std::vector<int> summand1{1, 2, 3};
    std::vector<int> summand2{3, 2, 1};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{4, 4, 4};
    auto result = add_two_numbers_recursive(head1, head2);
    int index{};
    while (result)
    {
        EXPECT_EQ(result->value, expected_result[index++]);
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, add_two_numbers2)
{
    std::vector<int> summand1{1, 2, 3, 6};
    std::vector<int> summand2{3, 2, 1};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{4, 4, 4, 6};
    auto result = add_two_numbers_recursive(head1, head2);
    for (int i{}; i < expected_result.size(); ++i)
    {
        EXPECT_EQ(result->value, expected_result[i]);
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, add_two_numbers3)
{
    std::vector<int> summand1{1, 2, 3};
    std::vector<int> summand2{3, 2, 1, 6, 7};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{4, 4, 4, 6, 7};
    auto result = add_two_numbers_recursive(head1, head2);
    for (int i{}; i < expected_result.size(); ++i)
    {
        EXPECT_EQ(result->value, expected_result[i]);
        result = result->next;
    }
}


TEST_F(SetupSinglyLinkedLists, add_two_numbers4)
{
    std::vector<int> summand1{9, 9, 9};
    std::vector<int> summand2{3, 2, 1, 6, 7};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{2, 2, 1, 7, 7};
    auto result = add_two_numbers_recursive(head1, head2);
    for (int i{}; i < expected_result.size(); ++i)
    {
        EXPECT_EQ(result->value, expected_result[i]);
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, add_two_numbers5)
{
    std::vector<int> summand1{9, 9, 9, 9, 9};
    std::vector<int> summand2{3, 2, 1, 6, 7};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{2, 2, 1, 6, 7, 1};
    auto result = add_two_numbers_recursive(head1, head2);
    for (int i{}; i < expected_result.size(); ++i)
    {
        EXPECT_EQ(result->value, expected_result[i]);
        result = result->next;
    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEST_F(SetupSinglyLinkedLists, add_two_numbers_iteratively)
{
    std::vector<int> summand1{1, 2, 3};
    std::vector<int> summand2{3, 2, 1};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{4, 4, 4};
    auto result = add_two_numbers_iteratively(head1, head2);
    int index{};
    while (result)
    {
        EXPECT_EQ(result->value, expected_result[index++]);
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, add_two_numbers_iteratively2)
{
    std::vector<int> summand1{1, 2, 3, 6};
    std::vector<int> summand2{3, 2, 1};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{4, 4, 4, 6};
    auto result = add_two_numbers_iteratively(head1, head2);
    for (int i{}; i < expected_result.size(); ++i)
    {
        EXPECT_EQ(result->value, expected_result[i]);
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, add_two_numbers_iteratively3)
{
    std::vector<int> summand1{1, 2, 3};
    std::vector<int> summand2{3, 2, 1, 6, 7};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{4, 4, 4, 6, 7};
    auto result = add_two_numbers_iteratively(head1, head2);
    for (int i{}; i < expected_result.size(); ++i)
    {
        EXPECT_EQ(result->value, expected_result[i]);
        result = result->next;
    }
}


TEST_F(SetupSinglyLinkedLists, add_two_numbers_iteratively4)
{
    std::vector<int> summand1{9, 9, 9};
    std::vector<int> summand2{3, 2, 1, 6, 7};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{2, 2, 1, 7, 7};
    auto result = add_two_numbers_iteratively(head1, head2);
    for (int i{}; i < expected_result.size(); ++i)
    {
        EXPECT_EQ(result->value, expected_result[i]);
        result = result->next;
    }
}

TEST_F(SetupSinglyLinkedLists, add_two_numbers_iteratively5)
{
    std::vector<int> summand1{9, 9, 9, 9, 9};
    std::vector<int> summand2{3, 2, 1, 6, 7};
    auto head1 = get_single_list_from_vector(summand1);
    auto head2 = get_single_list_from_vector(summand2);
    std::vector<int> expected_result{2, 2, 1, 6, 7, 1};
    auto result = add_two_numbers_iteratively(head1, head2);
    for (int i{}; i < expected_result.size(); ++i)
    {
        EXPECT_EQ(result->value, expected_result[i]);
        result = result->next;
    }
}
