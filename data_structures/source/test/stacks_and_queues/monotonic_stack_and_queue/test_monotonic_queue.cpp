//
// Created by andreas on 19.08.23.
//
#include <vector>
#include "gtest/gtest.h"
#include "stacks_and_queues/monotonic_stack_and_queue/monotonic_queue.h"

TEST(monotonic_queue, simple_increasing1)
{
	std::vector<int> input{1, 2, 3, 4, 5, 6};
	auto increasing_queue = MonotonicQueue<int, true>();
	for (const auto &element: input)
		increasing_queue.push(element);

	while (!increasing_queue.empty()) {
		EXPECT_EQ(increasing_queue.front(), input.back());
		input.pop_back();
		increasing_queue.pop();
	}
}


