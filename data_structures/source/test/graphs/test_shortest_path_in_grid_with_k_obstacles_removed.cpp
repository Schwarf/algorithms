//
// Created by andreas on 10.01.25.
//
#include "gtest/gtest.h"
#include "graphs/shortest_path_in_grid_with_k_obstacles_removed.h"

TEST(TestShortestPathINGridWithKObstaclesRemoved, simple1)
{
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    constexpr int k{1};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, shortest_path_with_k_obstactles_removed(grid, k));
}

TEST(TestShortestPathINGridWithKObstaclesRemoved, simple2)
{
    std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 1}, {1, 0, 0}};
    constexpr int k{1};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, shortest_path_with_k_obstactles_removed(grid, k));
}

TEST(TestShortestPathINGridWithKObstaclesRemoved, simple3)
{
    std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 1}, {1, 0, 0}};
    constexpr int k{2};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, shortest_path_with_k_obstactles_removed(grid, k));
}

TEST(TestShortestPathINGridWithKObstaclesRemoved, simple4)
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

TEST(TestShortestPathINGridWithKObstaclesRemoved, simple5)
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
