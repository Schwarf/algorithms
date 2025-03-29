//
// Created by andreas on 29.03.25.
//
#include "gtest/gtest.h"
#include "graphs/shortest_path_in_grid_with_obstacles.h"

TEST(TestShortestPathINGridWithObstacles, simple1)
{
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    std::pair<int, int> source = {0, 0};
    std::pair<int, int> target = {2, 4};
    constexpr int expected_result{10};
    EXPECT_EQ(expected_result, shortest_path_in_grid_with_obstacles(grid, source, target));
}
/*
TEST(TestShortestPathINGridWithObstacles, simple2)
{
    std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 1}, {1, 0, 0}};
    constexpr int k{1};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, shortest_path_with_k_obstactles_removed(grid, k));
}

TEST(TestShortestPathINGridWithObstacles, simple3)
{
    std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 1}, {1, 0, 0}};
    constexpr int k{2};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, shortest_path_with_k_obstactles_removed(grid, k));
}

TEST(TestShortestPathINGridWithObstacles, simple4)
{
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };
    constexpr int k{1};
    constexpr int expected_result{20};
    EXPECT_EQ(expected_result, shortest_path_with_k_obstactles_removed(grid, k));
}

TEST(TestShortestPathINGridWithObstacles, simple5)
{
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };
    constexpr int k{5};
    constexpr int expected_result{20};
    EXPECT_EQ(expected_result, shortest_path_with_k_obstactles_removed(grid, k));
}
*/