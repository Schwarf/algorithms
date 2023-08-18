//
// Created by andreas on 23.02.23.
//
#include <vector>
#include "gtest/gtest.h"
#include "stacks_and_queues/monotonic_stack_and_queue/monotonic_stack.h"

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


TEST(monotonic_stack, simple_decreasing1)
{
	std::vector<int> input{6, 5, 4, 3, 2, 1};
	auto decreasing_stack = MonotonicStack<int, false>();
	for (const auto &element: input)
		decreasing_stack.push(element);

	while (!decreasing_stack.empty()) {
		EXPECT_EQ(decreasing_stack.top(), input.back());
		input.pop_back();
		decreasing_stack.pop();
	}
}

TEST(monotonic_stack, simple_decreasing2)
{
	std::vector<int> input{1, 4, 3, 4, 5, 6};
	auto decreasing_stack = MonotonicStack<int, false>();
	for (const auto &element: input)
		decreasing_stack.push(element);
	std::vector<int> expected_result{6};
	while (!decreasing_stack.empty()) {
		EXPECT_EQ(decreasing_stack.top(), expected_result.back());
		expected_result.pop_back();
		decreasing_stack.pop();
	}
}

TEST(monotonic_stack, simple_decreasing3)
{
	std::vector<int> input{5, 4, 3, 4, 3, 2};
	auto decreasing_stack = MonotonicStack<int, false>();
	for (const auto &element: input)
		decreasing_stack.push(element);
	std::vector<int> expected_result{5, 4, 4, 3, 2};
	while (!decreasing_stack.empty()) {
		EXPECT_EQ(decreasing_stack.top(), expected_result.back());
		expected_result.pop_back();
		decreasing_stack.pop();
	}
}