//
// Created by andreas on 06.04.26.
//
#include "stacks_and_queues/max_stack.h"

#include <gtest/gtest.h>
#include <stdexcept>


class MaxStackTest : public ::testing::Test {
protected:
    MaxStack<int> stack;
};

TEST_F(MaxStackTest, default_constructed_stack_is_empty) {
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST_F(MaxStackTest, pop_on_empty_throws) {
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST_F(MaxStackTest, top_on_empty_throws) {
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    EXPECT_THROW(stack.top(), std::out_of_range);
}

TEST_F(MaxStackTest, peekMax_on_empty_throws) {
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    EXPECT_THROW(stack.peekMax(), std::out_of_range);
}

TEST_F(MaxStackTest, popMax_on_empty_throws) {
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    EXPECT_THROW(stack.popMax(), std::out_of_range);
}

TEST_F(MaxStackTest, push_one_element_updates_empty_size_top_and_max) {
    stack.push(42);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.peekMax(), 42);
}

TEST_F(MaxStackTest, push_multiple_elements_updates_size) {
    stack.push(1);
    EXPECT_EQ(stack.size(), 1);

    stack.push(2);
    EXPECT_EQ(stack.size(), 2);

    stack.push(3);
    EXPECT_EQ(stack.size(), 3);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.peekMax(), 3);
}

TEST_F(MaxStackTest, pop_returns_last_pushed_element_and_decreases_size) {
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.size(), 3);

    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.peekMax(), 2);
}

TEST_F(MaxStackTest, top_does_not_modify_stack) {
    stack.push(10);
    stack.push(20);

    EXPECT_EQ(stack.size(), 2);

    EXPECT_EQ(stack.top(), 20);
    EXPECT_EQ(stack.top(), 20);

    EXPECT_EQ(stack.size(), 2);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.peekMax(), 20);
}

TEST_F(MaxStackTest, peekMax_does_not_modify_stack) {
    stack.push(5);
    stack.push(1);
    stack.push(7);
    stack.push(3);

    EXPECT_EQ(stack.size(), 4);

    EXPECT_EQ(stack.peekMax(), 7);
    EXPECT_EQ(stack.peekMax(), 7);

    EXPECT_EQ(stack.size(), 4);
    EXPECT_EQ(stack.top(), 3);
}

TEST_F(MaxStackTest, popMax_removes_largest_value_and_decreases_size) {
    stack.push(5);
    stack.push(1);
    stack.push(7);
    stack.push(3);

    EXPECT_EQ(stack.size(), 4);

    EXPECT_EQ(stack.popMax(), 7);
    EXPECT_EQ(stack.size(), 3);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.peekMax(), 5);
    EXPECT_EQ(stack.top(), 3);
}

TEST_F(MaxStackTest, popMax_removes_most_recent_of_duplicate_maximums) {
    stack.push(5);
    stack.push(1);
    stack.push(5);

    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.top(), 5);
    EXPECT_EQ(stack.peekMax(), 5);

    EXPECT_EQ(stack.popMax(), 5);

    EXPECT_EQ(stack.size(), 2);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.peekMax(), 5);
}

TEST_F(MaxStackTest, pop_after_popMax_keeps_structure_consistent) {
    stack.push(5);
    stack.push(1);
    stack.push(5);

    EXPECT_EQ(stack.popMax(), 5);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_EQ(stack.size(), 1);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.top(), 5);
    EXPECT_EQ(stack.peekMax(), 5);
}

TEST_F(MaxStackTest, popMax_when_top_is_not_max_preserves_top) {
    stack.push(1);
    stack.push(3);
    stack.push(2);

    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.peekMax(), 3);

    EXPECT_EQ(stack.popMax(), 3);

    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.peekMax(), 2);
}

TEST_F(MaxStackTest, repeated_popMax_removes_all_elements) {
    stack.push(4);
    stack.push(2);
    stack.push(4);
    stack.push(1);
    stack.push(3);

    EXPECT_EQ(stack.size(), 5);

    EXPECT_EQ(stack.popMax(), 4);
    EXPECT_EQ(stack.size(), 4);
    EXPECT_EQ(stack.peekMax(), 4);

    EXPECT_EQ(stack.popMax(), 4);
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.peekMax(), 3);

    EXPECT_EQ(stack.popMax(), 3);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.peekMax(), 2);

    EXPECT_EQ(stack.popMax(), 2);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.peekMax(), 1);

    EXPECT_EQ(stack.popMax(), 1);
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST_F(MaxStackTest, alternating_operations_work_correctly) {
    stack.push(2);
    stack.push(7);
    stack.push(1);
    stack.push(7);
    stack.push(3);

    EXPECT_EQ(stack.size(), 5);
    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.peekMax(), 7);

    EXPECT_EQ(stack.popMax(), 7);
    EXPECT_EQ(stack.size(), 4);
    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.peekMax(), 7);

    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.peekMax(), 7);

    EXPECT_EQ(stack.popMax(), 7);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.peekMax(), 2);

    EXPECT_EQ(stack.pop(), 1);
    EXPECT_EQ(stack.size(), 1);

    EXPECT_EQ(stack.pop(), 2);
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST_F(MaxStackTest, single_element_pop_leaves_stack_empty) {
    stack.push(77);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);

    EXPECT_EQ(stack.pop(), 77);

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST_F(MaxStackTest, single_element_popMax_leaves_stack_empty) {
    stack.push(99);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);

    EXPECT_EQ(stack.popMax(), 99);

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}