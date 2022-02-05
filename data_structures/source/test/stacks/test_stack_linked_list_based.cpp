//
// Created by andreas on 05.02.22.
//

#include <stack>
#include "gtest/gtest.h"
#include "./../../stacks_and_queues/stack_linked_list_based.h"
#include "setup_stack.h"

TEST_F(SetupStack, test_push_stack)
{
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

TEST_F(SetupStack, test_top_stack)
{
	auto stack = new StackLLB<int64_t>();

	for (const auto &element: input) {
		stack->push(element);
	}
	EXPECT_EQ(reference_stack->top(), stack->top());
}


TEST_F(SetupStack, test_pop_stack)
{
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
