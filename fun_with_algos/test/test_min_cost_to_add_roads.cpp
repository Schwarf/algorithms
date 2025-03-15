//
// Created by andreas on 15.03.25.
//
#include <gtest/gtest.h>
#include "./../min_cost_to_add_roads.h"

TEST(TestMinCostToAddRoads, simple1)
{
    std::vector<std::vector<int>> connections = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    constexpr int N{3};
    constexpr int expected_result{6};
    EXPECT_EQ(min_cost_to_add_roads(N, connections), expected_result);
}

TEST(TestMinCostToAddRoads, simple2)
{
    std::vector<std::vector<int>> connections = {{1, 2, 3}, {3, 4, 4}};
    constexpr int N{4};
    constexpr int expected_result{-1};
    EXPECT_EQ(min_cost_to_add_roads(N, connections), expected_result);
}
