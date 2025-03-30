//
// Created by andreas on 29.03.25.
//
#include "gtest/gtest.h"
#include "graphs/shortest_path_in_grid_with_obstacles.h"

TEST(TestShortestPathINGridWithObstacles, simple1)
{
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    std::pair<int, int> source = {0, 0};
    std::pair<int, int> target = {4, 2};
    constexpr int expected_result{10};
    EXPECT_EQ(expected_result, shortest_path_in_grid_with_obstacles(grid, source, target));
}

TEST(TestShortestPathINGridWithObstacles, simple2)
{
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 0, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    std::pair<int, int> source = {0, 0};
    std::pair<int, int> target = {4, 2};
    constexpr int expected_result{8};
    EXPECT_EQ(expected_result, shortest_path_in_grid_with_obstacles(grid, source, target));
}


TEST(TestShortestPathINGridWithObstacles, simple3)
{
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 1}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    std::pair<int, int> source = {0, 0};
    std::pair<int, int> target = {4, 2};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, shortest_path_in_grid_with_obstacles(grid, source, target));
}


TEST(TestShortestPathINGridWithObstacles, simple4)
{
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    std::pair<int, int> source = {1, 2};
    std::pair<int, int> target = {4, 0};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, shortest_path_in_grid_with_obstacles(grid, source, target));
}


TEST(TestShortestPathINGridWithObstacles, simple5)
{
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };
    std::pair<int, int> source = {0, 0};
    std::pair<int, int> target = {11, 9};

    constexpr int expected_result{26};
    EXPECT_EQ(expected_result, shortest_path_in_grid_with_obstacles(grid, source, target));
}

TEST(TestShortestPathINGridWithObstacles, simple6)
{
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    std::pair<int, int> source = {0, 0};
    std::pair<int, int> target = {11, 9};

    constexpr int expected_result{20};
    EXPECT_EQ(expected_result, shortest_path_in_grid_with_obstacles(grid, source, target));
}
