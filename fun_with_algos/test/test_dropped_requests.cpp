//
// Created by andreas on 14.03.25.
//
#include "./../dropped_requests.h"
#include "gtest/gtest.h"

TEST(TestDroppedRequests, simple1)
{
    std::vector<int> input_requests{1, 1, 1, 1, 2};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, dropped_requests(input_requests));
}

TEST(TestDroppedRequests, simple2)
{
    std::vector<int> input_requests{1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, dropped_requests(input_requests));
}

TEST(TestDroppedRequests, simple3)
{
    std::vector<int> input_requests{1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 7, 7, 11, 11, 11, 11};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, dropped_requests(input_requests));
}
