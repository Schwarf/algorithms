//
// Created by andreas on 19.05.25.
//
#include "gtest/gtest.h"
#include "./../../knapsack/multiple_knapsack.h"
class TestMultipleKnapsack : public ::testing::Test
{
protected:
    std::vector<ItemCounted<int, int>> items1{
        ItemCounted<int, int>(6, 1, 3),
        ItemCounted<int, int>(10, 2, 2),
        ItemCounted<int, int>(12, 3, 1)
    };
    int knapsack_capacity1 = 5;

    std::vector<ItemCounted<int, int>> items2{
        ItemCounted<int, int>(6, 1, 1),
        ItemCounted<int, int>(10, 2, 1),
        ItemCounted<int, int>(12, 3, 1)
    };
    int knapsack_capacity2 = 4;

    std::vector<ItemCounted<int, int>> items3{
        ItemCounted<int, int>(7, 2, 3),
        ItemCounted<int, int>(10, 3, 2),
        ItemCounted<int, int>(12, 4, 1)
    };
    int knapsack_capacity3 = 6;
};

TEST_F(TestMultipleKnapsack, simple1)
{
    const auto result = multiple_knapsack_bottom_up(items1, knapsack_capacity1);
    constexpr int expected_result = 28;
    EXPECT_EQ(result, expected_result);
}

TEST_F(TestMultipleKnapsack, simple2)
{
    const auto result = multiple_knapsack_bottom_up(items2, knapsack_capacity2);
    constexpr int expected_result = 18;
    EXPECT_EQ(result, expected_result);
}

TEST_F(TestMultipleKnapsack, simple3)
{
    const auto result = multiple_knapsack_bottom_up(items3, knapsack_capacity3);
    constexpr int expected_result = 21;
    EXPECT_EQ(result, expected_result);
}

TEST_F(TestMultipleKnapsack, simple4)
{
    // no items
    std::vector<ItemCounted<int, int>> empty_items;
    int knapsack_capacity = 5;
    const auto result = multiple_knapsack_bottom_up(empty_items, knapsack_capacity);
    constexpr int expected_result = 0;
    EXPECT_EQ(result, expected_result);
}

TEST_F(TestMultipleKnapsack, simple5)
{
    // space for one item
    const auto result = multiple_knapsack_bottom_up(items1, 1);
    constexpr int expected_result = 6;
    EXPECT_EQ(result, expected_result);
}


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(TestMultipleKnapsack, simple_optimized1)
{
    const auto result = multiple_knapsack_bottom_up_optimized(items1, knapsack_capacity1);
    constexpr int expected_result = 28;
    EXPECT_EQ(result, expected_result);
}

TEST_F(TestMultipleKnapsack, simple_optimized2)
{
    const auto result = multiple_knapsack_bottom_up_optimized(items2, knapsack_capacity2);
    constexpr int expected_result = 18;
    EXPECT_EQ(result, expected_result);
}

TEST_F(TestMultipleKnapsack, simple_optimized3)
{
    const auto result = multiple_knapsack_bottom_up_optimized(items3, knapsack_capacity3);
    constexpr int expected_result = 21;
    EXPECT_EQ(result, expected_result);
}

TEST_F(TestMultipleKnapsack, simple_optimized4)
{
    // no items
    std::vector<ItemCounted<int, int>> empty_items;
    int knapsack_capacity = 5;
    const auto result = multiple_knapsack_bottom_up_optimized(empty_items, knapsack_capacity);
    constexpr int expected_result = 0;
    EXPECT_EQ(result, expected_result);
}

TEST_F(TestMultipleKnapsack, simple_optimized5)
{
    // space for one item
    const auto result = multiple_knapsack_bottom_up_optimized(items1, 1);
    constexpr int expected_result = 6;
    EXPECT_EQ(result, expected_result);
}
