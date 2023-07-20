//
// Created by andreas on 05.02.22.
//

#include "stacks_and_queues/stack_linked_list_based.h"
#include "setup_stack.h"

TEST_F(SetupStack, test_push_stack) {
    auto stack = new StackLLB<int64_t>();
    EXPECT_TRUE(stack->is_empty());
    for (const auto &element: input) {
        stack->push(element);
    }
    EXPECT_EQ(reference_stack->size(), stack->size());
    EXPECT_EQ(stack->is_empty(), reference_stack->empty());
    EXPECT_FALSE(stack->is_empty());
    EXPECT_EQ(stack->size(), reference_stack->size());
}

TEST_F(SetupStack, test_top_stack) {
    auto stack = new StackLLB<int64_t>();

    for (const auto &element: input) {
        stack->push(element);
    }
    EXPECT_EQ(reference_stack->top(), stack->top());
}


TEST_F(SetupStack, test_pop_stack) {
    auto stack = new StackLLB<int64_t>();

    for (const auto &element: input) {
        stack->push(element);
    }
    EXPECT_EQ(reference_stack->size(), stack->size());
    reference_stack->pop();
    stack->pop();
    EXPECT_EQ(reference_stack->size(), stack->size());
    EXPECT_EQ(reference_stack->top(), stack->top());
}


TEST_F(SetupStack, test_pop_empty_stack) {
    auto stack = new StackLLB<int64_t>();
    std::string message = "Can not pop. The stack is empty.";
    try {
        stack->pop();
        FAIL() << "Expected std::out_of_range.";
    }
    catch (std::out_of_range const &err) {
        EXPECT_TRUE(err.what() == message);
    }
}

TEST_F(SetupStack, test_top_empty_stack) {
    auto stack = new StackLLB<int64_t>();
    std::string message = "Can not top. The stack is empty.";
    try {
        stack->top();
        FAIL() << "Expected std::out_of_range.";
    }
    catch (std::out_of_range const &err) {
        EXPECT_TRUE(err.what() == message);
    }
}
