//
// Created by andreas on 30.01.22.
//

#include <algorithm>
#include "gtest/gtest.h"
#include "linked_lists/doubly_linked_list.h"

class SetupDoublyLinkedList : public testing::Test
{
public:
    SetupDoublyLinkedList()
    {
        linked_list = new DoublyLinkedList<int64_t>();
    }

protected:
    DoublyLinkedList<int64_t>* linked_list;
    std::vector<int64_t> input{1, 2, 3, 4, 5};
};

TEST_F(SetupDoublyLinkedList, test_push_front_get)
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

TEST_F(SetupDoublyLinkedList, test_push_front_get_from_back)
{
    for (const auto& element : input)
    {
        linked_list->push_front(element);
    }
    std::reverse(input.begin(), input.end());
    for (size_t index_from_back = input.size(); index_from_back--;)
    {
        EXPECT_EQ(linked_list->get_from_back(index_from_back), input[index_from_back]);
    }
}


TEST_F(SetupDoublyLinkedList, test_push_back_get)
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


TEST_F(SetupDoublyLinkedList, test_push_back_get_from_back)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    for (size_t index_from_back = input.size(); index_from_back--;)
    {
        EXPECT_EQ(linked_list->get_from_back(index_from_back), input[index_from_back]);
    }
}


TEST_F(SetupDoublyLinkedList, test_push_back_pop_back)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    for (size_t index_from_back = input.size(); index_from_back--;)
    {
        EXPECT_EQ(linked_list->pop_back(), input[index_from_back]);
    }
}

TEST_F(SetupDoublyLinkedList, test_push_back_pop_front)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    for (size_t index = 0; index < input.size(); index++)
    {
        EXPECT_EQ(linked_list->pop_front(), input[index]);
    }
}

TEST_F(SetupDoublyLinkedList, test_push_at_front)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    input.insert(input.begin(), 0);
    EXPECT_TRUE(linked_list->push_at(0, 0));
    for (size_t index = 0; index < input.size(); index++)
    {
        EXPECT_EQ(linked_list->pop_front(), input[index]);
    }
}

TEST_F(SetupDoublyLinkedList, test_push_at_front_empty)
{
    auto linked_list_empty = new DoublyLinkedList<int64_t>();
    EXPECT_TRUE(linked_list_empty->push_at(0, 0));
}


TEST_F(SetupDoublyLinkedList, test_push_at_back)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    input.insert(input.begin() + 5, -1);
    EXPECT_TRUE(linked_list->push_at(4, -1));
    EXPECT_EQ(input.size(), linked_list->size());
    for (size_t index = 0; index < input.size(); index++)
    {
        EXPECT_EQ(linked_list->pop_front(), input[index]);
    }
}

TEST_F(SetupDoublyLinkedList, test_push_at_somewhere)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    input.insert(input.begin() + 3, -1);
    EXPECT_TRUE(linked_list->push_at(3, -1));
    input.insert(input.begin() + 3, -2);
    EXPECT_TRUE(linked_list->push_at(3, -2));
    input.insert(input.begin() + 4, -2);
    EXPECT_TRUE(linked_list->push_at(4, -2));

    for (size_t index = 0; index < input.size(); index++)
    {
        auto x1 = linked_list->pop_front();
        auto x2 = input[index];
        EXPECT_EQ(x1, x2);
    }
}

TEST_F(SetupDoublyLinkedList, test_pop_at_front)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    size_t index{};
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    input.erase(input.begin());
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    input.erase(input.begin());
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    input.erase(input.begin());
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    input.erase(input.begin());
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    input.erase(input.begin());
}

TEST_F(SetupDoublyLinkedList, test_pop_at_back)
{
    for (const auto& element : input)
    {
        linked_list->push_back(element);
    }
    size_t index = 4;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    index = 3;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    index = 2;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    index = 1;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
    index = 0;
    EXPECT_EQ(linked_list->pop_at(index), input[index]);
}
