//
// Created by andreas on 23.02.23.
//
#include <vector>
#include "gtest/gtest.h"
#include "./../../../stacks_and_queues/monotonic_stack/monotonic_stack.h"

TEST(monotonic_stack, simple_increasing1)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6};
	auto increasing_stack = MonotonicStack<int, true>();
	for (const auto &element: input)
		increasing_stack.push(element);

	while (!increasing_stack.empty()) {
		EXPECT_EQ(increasing_stack.top(), input.back());
		input.pop_back();
		increasing_stack.pop();
	}
}

TEST(monotonic_stack, simple_increasing2)
{
	std::vector<int> input{1, 4, 3, 4, 5, 6};
	auto increasing_stack = MonotonicStack<int, true>();
	for (const auto &element: input)
		increasing_stack.push(element);
	std::vector<int> expected_result{1, 3, 4, 5, 6};
	while (!increasing_stack.empty()) {
		EXPECT_EQ(increasing_stack.top(), expected_result.back());
		expected_result.pop_back();
		increasing_stack.pop();
	}
}

TEST(monotonic_stack, simple_increasing3)
{
	std::vector<int> input{5, 4, 3, 4, 7, 6};
	auto increasing_stack = MonotonicStack<int, true>();
	for (const auto &element: input)
		increasing_stack.push(element);
	std::vector<int> expected_result{3, 4, 6};
	while (!increasing_stack.empty()) {
		EXPECT_EQ(increasing_stack.top(), expected_result.back());
		expected_result.pop_back();
		increasing_stack.pop();
	}
}