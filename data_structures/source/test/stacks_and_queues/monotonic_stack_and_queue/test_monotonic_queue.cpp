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
    for (const auto& element : input)
        increasing_queue.push(element);

    while (!increasing_queue.empty())
    {
        EXPECT_EQ(increasing_queue.front(), input.back());
        input.pop_back();
        increasing_queue.pop();
    }
}

TEST(monotonic_queue, simple_increasing2)
{
    std::vector<int> input{1, 4, 3, 4, 5, 6};
    auto increasing_queue = MonotonicQueue<int, true>();
    for (const auto& element : input)
        increasing_queue.push(element);
    std::vector<int> expected_result{1, 3, 4, 5, 6};
    while (!increasing_queue.empty())
    {
        EXPECT_EQ(increasing_queue.front(), expected_result.back());
        expected_result.pop_back();
        increasing_queue.pop();
    }
}

TEST(monotonic_queue, simple_increasing3)
{
    std::vector<int> input{5, 4, 3, 4, 7, 6};
    auto increasing_queue = MonotonicQueue<int, true>();
    for (const auto& element : input)
        increasing_queue.push(element);
    std::vector<int> expected_result{6, 7};
    while (!increasing_queue.empty())
    {
        EXPECT_EQ(increasing_queue.front(), expected_result.back());
        expected_result.pop_back();
        increasing_queue.pop();
    }
    EXPECT_TRUE(increasing_queue.empty());
}


TEST(monotonic_queue, simple_decreasing1)
{
    std::vector<int> input{6, 5, 4, 3, 2, 1};
    auto decreasing_queue = MonotonicQueue<int, false>();
    for (const auto& element : input)
        decreasing_queue.push(element);

    while (!decreasing_queue.empty())
    {
        EXPECT_EQ(decreasing_queue.front(), input.back());
        input.pop_back();
        decreasing_queue.pop();
    }
}

TEST(monotonic_queue, simple_decreasing2)
{
    std::vector<int> input{1, 4, 3, 4, 5, 6};
    auto decreasing_queue = MonotonicQueue<int, false>();
    for (const auto& element : input)
        decreasing_queue.push(element);
    std::vector<int> expected_result{6, 5, 4, 3, 1};
    while (!decreasing_queue.empty())
    {
        EXPECT_EQ(decreasing_queue.front(), expected_result.back());
        expected_result.pop_back();
        decreasing_queue.pop();
    }
}

TEST(monotonic_queue, simple_decreasing3)
{
    std::vector<int> input{5, 4, 3, 4, 3, 2};
    auto decreasing_queue = MonotonicQueue<int, false>();
    for (const auto& element : input)
        decreasing_queue.push(element);
    std::vector<int> expected_result{5, 4, 4, 3, 2};
    while (!decreasing_queue.empty())
    {
        EXPECT_EQ(decreasing_queue.front(), expected_result.back());
        expected_result.pop_back();
        decreasing_queue.pop();
    }
}
