//
// Created by andreas on 05.02.22.
//

#include "stacks_and_queues//stack_array_based.h"
#include "setup_stack.h"

TEST_F(SetupStack, test_push_stack_array_based) {
    auto stack = new StackAB<int64_t, 5>();
    EXPECT_TRUE(stack->is_empty());
    for (const auto &element: input) {
        stack->push(element);
    }
    EXPECT_EQ(reference_stack->size(), stack->size());
    EXPECT_EQ(stack->is_empty(), reference_stack->empty());
    EXPECT_FALSE(stack->is_empty());
    EXPECT_EQ(stack->size(), reference_stack->size());
}

TEST_F(SetupStack, test_top_stack_array_based) {
    auto stack = new StackAB<int64_t, 5>();

    for (const auto &element: input) {
        stack->push(element);
    }
    EXPECT_EQ(reference_stack->top(), stack->top());
}


TEST_F(SetupStack, test_pop_stack_array_based) {
    auto stack = new StackAB<int64_t, 5>();

    for (const auto &element: input) {
        stack->push(element);
    }
    EXPECT_EQ(reference_stack->size(), stack->size());
    reference_stack->pop();
    stack->pop();
    EXPECT_EQ(reference_stack->size(), stack->size());
    EXPECT_EQ(reference_stack->top(), stack->top());
}
