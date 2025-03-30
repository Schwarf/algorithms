//
// Created by andreas on 29.01.22.
//

#include <algorithm>
#include "gtest/gtest.h"
#include "linked_lists/singly_linked_list.h"

class SetupSinlgyLinkedList : public testing::Test
{
public:
    SetupSinlgyLinkedList()
    {
        linked_list = new SinglyLinkedList<int64_t>();
    }

protected:
    SinglyLinkedList<int64_t>* linked_list;
    std::vector<int64_t> input{1, 2, 3, 4, 5};
};


TEST_F(SetupSinlgyLinkedList, test_push_front)
{
    for (const auto& element : input)
    {
        linked_list->push_front(element);
    }
    std::reverse(input.begin(), input.end());
    for (size_t index = 0; index < input.size(); ++index)
    {
        EXPECT_EQ(linked_list->get(index), input[index]);
    }
}

TEST_F(SetupSinlgyLinkedList, test_push_back)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    for (size_t index = 0; index < input.size(); ++index)
    {
        EXPECT_EQ(linked_list->get(index), input[index]);
    }
}


TEST_F(SetupSinlgyLinkedList, test_add_at_index_1_and_index_3)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    input.insert(input.begin() + 1, 10);
    input.insert(input.begin() + 3, 20);
    linked_list->push_at(1, 10);
    linked_list->push_at(3, 20);
    EXPECT_EQ(7, input.size());

    for (size_t index = 0; index < input.size(); ++index)
    {
        EXPECT_EQ(linked_list->get(index), input[index]);
    }
}


TEST_F(SetupSinlgyLinkedList, test_invalid_index)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    size_t out_of_range_index = 7;
    std::string message = "The index in singly linked list is out of range in method 'get'";
    try
    {
        linked_list->get(out_of_range_index);
        FAIL() << "Expected std::out_of_range";
    }
    catch (std::out_of_range const& err)
    {
        EXPECT_TRUE(err.what() == message);
    }
}

TEST_F(SetupSinlgyLinkedList, test_pop_front)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    EXPECT_EQ(linked_list->pop_front(), input[0]);
    EXPECT_EQ(linked_list->size(), input.size() - 1);
    EXPECT_EQ(linked_list->pop_front(), input[1]);
    EXPECT_EQ(linked_list->size(), input.size() - 2);
    EXPECT_EQ(linked_list->pop_front(), input[2]);
    EXPECT_EQ(linked_list->size(), input.size() - 3);
    EXPECT_EQ(linked_list->pop_front(), input[3]);
    EXPECT_EQ(linked_list->size(), input.size() - 4);
    EXPECT_EQ(linked_list->pop_front(), input[4]);
    EXPECT_EQ(linked_list->size(), input.size() - 5);
}

TEST_F(SetupSinlgyLinkedList, test_pop_front_invalid_list_empty)
{
    std::string message = "Singly linked list is empty (pop_front).";
    try
    {
        linked_list->pop_front();
        FAIL() << "Empty";
    }
    catch (std::out_of_range const& err)
    {
        EXPECT_TRUE(err.what() == message);
    }
}

TEST_F(SetupSinlgyLinkedList, test_pop_back_invalid_list_empty)
{
    std::string message = "Singly linked list is empty (pop_back).";
    try
    {
        linked_list->pop_back();
        FAIL() << "Empty";
    }
    catch (std::out_of_range const& err)
    {
        EXPECT_TRUE(err.what() == message);
    }
}

TEST_F(SetupSinlgyLinkedList, test_pop_back)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    EXPECT_EQ(linked_list->pop_back(), input[4]);
    EXPECT_EQ(linked_list->size(), input.size() - 1);
    EXPECT_EQ(linked_list->pop_back(), input[3]);
    EXPECT_EQ(linked_list->size(), input.size() - 2);
    EXPECT_EQ(linked_list->pop_back(), input[2]);
    EXPECT_EQ(linked_list->size(), input.size() - 3);
    EXPECT_EQ(linked_list->pop_back(), input[1]);
    EXPECT_EQ(linked_list->size(), input.size() - 4);
    EXPECT_EQ(linked_list->pop_back(), input[0]);
    EXPECT_EQ(linked_list->size(), input.size() - 5);
}

TEST_F(SetupSinlgyLinkedList, test_is_empty)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    EXPECT_FALSE(linked_list->is_empty());
    linked_list->pop_front();
    linked_list->pop_back();
    linked_list->pop_front();
    linked_list->pop_back();
    linked_list->pop_front();
    EXPECT_TRUE(linked_list->is_empty());
}

TEST_F(SetupSinlgyLinkedList, test_pop_at_index)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    size_t index = 2;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    input.erase(input.begin() + 2);
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    input.erase(input.begin() + 2);
    for (index = 2; index < input.size(); ++index)
    {
        ;
        EXPECT_EQ(linked_list->get(index), input[index]);
    }
}

TEST_F(SetupSinlgyLinkedList, test_pop_at_index_1st_element)
{
    linked_list->push_back(input[0]);
    size_t index = 0;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    EXPECT_TRUE(linked_list->is_empty());
    EXPECT_EQ(linked_list->size(), 0);
}


TEST_F(SetupSinlgyLinkedList, test_pop_at_index_2nd_element)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    size_t index = 1;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    EXPECT_FALSE(linked_list->is_empty());
    EXPECT_EQ(linked_list->size(), 4);
}

TEST_F(SetupSinlgyLinkedList, test_pop_at_index_last_element)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    size_t index = 4;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    EXPECT_FALSE(linked_list->is_empty());
    EXPECT_EQ(linked_list->size(), 4);
}


TEST_F(SetupSinlgyLinkedList, test_pop_at_2nd_index_with_length_2)
{
    linked_list->push_back(input[0]);
    linked_list->push_back(input[1]);
    size_t index = 1;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    EXPECT_FALSE(linked_list->is_empty());
    EXPECT_EQ(linked_list->size(), 1);
    EXPECT_EQ(linked_list->get(0), input[0]);
    EXPECT_EQ(linked_list->pop_back(), input[0]);
}

TEST_F(SetupSinlgyLinkedList, test_pop_at_1st_index_with_length_2)
{
    linked_list->push_back(input[0]);
    linked_list->push_back(input[1]);
    size_t index = 0;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    EXPECT_FALSE(linked_list->is_empty());
    EXPECT_EQ(linked_list->size(), 1);
    EXPECT_EQ(linked_list->get(0), input[1]);
    EXPECT_EQ(linked_list->pop_front(), input[1]);
}
