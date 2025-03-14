//
// Created by andreas on 14.03.25.
//
#include "./../process_queries_on_cart.h"
#include "gtest/gtest.h"

TEST(testProcessQueriesOnCart, simple1)
{
    std::vector<int> items{1, 2, 3, 4, 5, 6};
    std::vector<int> quries{2, -2, 3, -4, -5, -4};
    std::vector<int> expected_result{1, 3, 6, 2, 3};
    EXPECT_EQ(expected_result, process_queries_on_cart(items, quries));
}

TEST(testProcessQueriesOnCart, simple2)
{
    std::vector<int> items{1, 2, 3, 4, 5, 6};
    std::vector<int> quries{2, 3, 4, 15, 4};
    std::vector<int> expected_result{1, 2, 3, 4, 5, 6, 2, 3, 4, 15, 4};
    EXPECT_EQ(expected_result, process_queries_on_cart(items, quries));
}

TEST(testProcessQueriesOnCart, simple3)
{
    std::vector<int> items{1, 2, 3};
    std::vector<int> quries{-3, -2, -1};
    std::vector<int> expected_result{};
    EXPECT_EQ(expected_result, process_queries_on_cart(items, quries));
}

TEST(testProcessQueriesOnCart, simple4)
{
    std::vector<int> items{1, 2, 3};
    std::vector<int> quries{-3, -2, -1, -3};
    std::vector<int> expected_result{};
    EXPECT_EQ(expected_result, process_queries_on_cart(items, quries));
}
