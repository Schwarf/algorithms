//
// Created by andreas on 11.09.23.
//
#include "gtest/gtest.h"
#include "linked_lists/split_linked_list_in_parts.h"
#include "setup_singly_linked_lists.h"

TEST_F(SetupSinglyLinkedLists, split_linked_list1)
{
    std::vector<int> sub_list1{1};
    std::vector<int> sub_list2{2};
    std::vector<int> sub_list3{};
    std::vector<int> sub_list4{};
    constexpr int k{4};
    const auto linked_list1 = get_single_list_from_vector(sub_list1);
    const auto linked_list2 = get_single_list_from_vector(sub_list2);
    const auto linked_list3 = get_single_list_from_vector(sub_list3);
    const auto linked_list4 = get_single_list_from_vector(sub_list4);
    const std::vector<Node<int>*> expected_result{linked_list1, linked_list2, linked_list3, linked_list4};
    std::vector<int> input{1, 2, 3, 4};
    auto input_list = get_single_list_from_vector(input);
    auto result = split_linked_list_in_parts(input_list, k);
    EXPECT_EQ(result.size(), expected_result.size());
    EXPECT_EQ(k, expected_result.size());
    for (int i{}; i < k; ++i)
    {
        if (result[i])
        {
            auto head_result = result[i];
            auto head_expected_result = expected_result[i];
            while (head_result && head_expected_result)
            {
                EXPECT_EQ(head_result->value, head_expected_result->value);
                head_result = head_result->next;
                head_expected_result = head_expected_result->next;
            }
        }
        else
            EXPECT_EQ(expected_result[i], nullptr);
    }
}


TEST_F(SetupSinglyLinkedLists, split_linked_list2)
{
    std::vector<int> sub_list1{1, 2, 3};
    std::vector<int> sub_list2{4, 5};
    std::vector<int> sub_list3{6, 7};
    std::vector<int> sub_list4{8, 9};
    constexpr int k{4};
    const auto linked_list1 = get_single_list_from_vector(sub_list1);
    const auto linked_list2 = get_single_list_from_vector(sub_list2);
    const auto linked_list3 = get_single_list_from_vector(sub_list3);
    const auto linked_list4 = get_single_list_from_vector(sub_list4);
    const std::vector<Node<int>*> expected_result{linked_list1, linked_list2, linked_list3, linked_list4};
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto input_list = get_single_list_from_vector(input);
    auto result = split_linked_list_in_parts(input_list, k);
    EXPECT_EQ(result.size(), expected_result.size());
    EXPECT_EQ(k, expected_result.size());
    for (int i{}; i < k; ++i)
    {
        if (result[i])
        {
            auto head_result = result[i];
            auto head_expected_result = expected_result[i];
            while (head_result && head_expected_result)
            {
                EXPECT_EQ(head_result->value, head_expected_result->value);
                head_result = head_result->next;
                head_expected_result = head_expected_result->next;
            }
        }
        else
            EXPECT_EQ(expected_result[i], nullptr);
    }
}


TEST_F(SetupSinglyLinkedLists, split_linked_list3)
{
    std::vector<int> sub_list1{1, 2, 3};
    std::vector<int> sub_list2{4, 5, 6};
    std::vector<int> sub_list3{7, 8, 9};
    constexpr int k{3};
    const auto linked_list1 = get_single_list_from_vector(sub_list1);
    const auto linked_list2 = get_single_list_from_vector(sub_list2);
    const auto linked_list3 = get_single_list_from_vector(sub_list3);
    const std::vector<Node<int>*> expected_result{linked_list1, linked_list2, linked_list3};
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto input_list = get_single_list_from_vector(input);
    auto result = split_linked_list_in_parts(input_list, k);
    EXPECT_EQ(result.size(), expected_result.size());
    EXPECT_EQ(k, expected_result.size());
    for (int i{}; i < k; ++i)
    {
        if (result[i])
        {
            auto head_result = result[i];
            auto head_expected_result = expected_result[i];
            while (head_result && head_expected_result)
            {
                EXPECT_EQ(head_result->value, head_expected_result->value);
                head_result = head_result->next;
                head_expected_result = head_expected_result->next;
            }
        }
        else
            EXPECT_EQ(expected_result[i], nullptr);
    }
}
