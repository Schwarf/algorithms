//
// Created by andreas on 16.09.23.
//
#include "gtest/gtest.h"
#include "graphs/path_with_minimum_effort.h"

TEST(PathWithMinimumEffort, bfs1)
{
    std::vector<std::vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    constexpr int expected_result{2};
    std::function<bool(const std::vector<std::vector<int>>&, int)>
        graph_function = bfs_algo_reaches_right_lower_end<int>;
    EXPECT_EQ(path_with_minimum_effort(heights, graph_function), expected_result);
}

TEST(PathWithMinimumEffort, dfs1)
{
    std::vector<std::vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    constexpr int expected_result{2};
    std::function<bool(const std::vector<std::vector<int>>&, int)>
        graph_function = dfs_algo_reaches_right_lower_end<int>;
    EXPECT_EQ(path_with_minimum_effort(heights, graph_function), expected_result);
}

TEST(PathWithMinimumEffort, bfs2)
{
    std::vector<std::vector<int>> heights{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    constexpr int expected_result{1};
    std::function<bool(const std::vector<std::vector<int>>&, int)>
        graph_function = bfs_algo_reaches_right_lower_end<int>;
    EXPECT_EQ(path_with_minimum_effort(heights, graph_function), expected_result);
}

TEST(PathWithMinimumEffort, dfs2)
{
    std::vector<std::vector<int>> heights{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    constexpr int expected_result{1};
    std::function<bool(const std::vector<std::vector<int>>&, int)>
        graph_function = dfs_algo_reaches_right_lower_end<int>;
    EXPECT_EQ(path_with_minimum_effort(heights, graph_function), expected_result);
}


TEST(PathWithMinimumEffort, bfs3)
{
    std::vector<std::vector<int>>
        heights{{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    constexpr int expected_result{0};
    std::function<bool(const std::vector<std::vector<int>>&, int)>
        graph_function = bfs_algo_reaches_right_lower_end<int>;
    EXPECT_EQ(path_with_minimum_effort(heights, graph_function), expected_result);
}

TEST(PathWithMinimumEffort, dfs3)
{
    std::vector<std::vector<int>>
        heights{{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    constexpr int expected_result{0};
    std::function<bool(const std::vector<std::vector<int>>&, int)>
        graph_function = dfs_algo_reaches_right_lower_end<int>;
    EXPECT_EQ(path_with_minimum_effort(heights, graph_function), expected_result);
}

TEST(PathWithMinimumEffort, djikstra1)
{
    std::vector<std::vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    constexpr int expected_result{2};
    EXPECT_EQ(path_with_minimum_effort2(heights), expected_result);
}

TEST(PathWithMinimumEffort, djikstra2)
{
    std::vector<std::vector<int>> heights{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    constexpr int expected_result{1};
    EXPECT_EQ(path_with_minimum_effort2(heights), expected_result);
}

TEST(PathWithMinimumEffort, djikstra3)
{
    std::vector<std::vector<int>>
        heights{{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    constexpr int expected_result{0};
    EXPECT_EQ(path_with_minimum_effort2(heights), expected_result);
}
