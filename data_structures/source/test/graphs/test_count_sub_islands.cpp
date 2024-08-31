//
// Created by andreas on 31.08.24.
//
#include "gtest/gtest.h"
#include "graphs/count_sub_islands.h"

TEST(TestCountSubIslandsBFS, simple1) {
    std::vector<std::vector<int>> grid1{{1, 1, 1, 0, 0},
                                        {0, 1, 1, 1, 1},
                                        {0, 0, 0, 0, 0},
                                        {1, 0, 0, 0, 0},
                                        {1, 1, 0, 1, 1}};
    std::vector<std::vector<int>> grid2{{1, 1, 1, 0, 0},
                                        {0, 0, 1, 1, 1},
                                        {0, 1, 0, 0, 0},
                                        {1, 0, 1, 1, 0},
                                        {0, 1, 0, 1, 0}};

    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, count_sub_islands_bfs(grid1, grid2));
}


TEST(TestCountSubIslandsBFS, simple2) {
    std::vector<std::vector<int>> grid1{{1, 0, 1, 0, 1},
                                        {1, 1, 1, 1, 1},
                                        {0, 0, 0, 0, 0},
                                        {1, 1, 1, 1, 1},
                                        {1, 0, 1, 0, 1}};
    std::vector<std::vector<int>> grid2{{0, 0, 0, 0, 0},
                                        {1, 1, 1, 1, 1},
                                        {0, 1, 0, 1, 0},
                                        {0, 1, 0, 1, 0},
                                        {1, 0, 0, 0, 1}};

    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_sub_islands_bfs(grid1, grid2));
}

TEST(TestCountSubIslandsBFS, simple3) {
    std::vector<std::vector<int>> grid1{{1, 0, 1, 0, 1},
                                        {1, 1, 1, 1, 1},
                                        {0, 0, 0, 0, 0},
                                        {1, 1, 1, 1, 1},
                                        {1, 0, 1, 0, 1}};
    std::vector<std::vector<int>> grid2{{0, 0, 0, 0, 0},
                                        {1, 1, 1, 1, 1},
                                        {0, 1, 0, 1, 0},
                                        {0, 1, 0, 1, 0},
                                        {0, 0, 0, 0, 0}};

    constexpr int expected_result{};
    EXPECT_EQ(expected_result, count_sub_islands_bfs(grid1, grid2));
}

TEST(TestCountSubIslandsBFS, simple4) {
    std::vector<std::vector<int>> grid1{{0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                                        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
                                        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
                                        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
                                        {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
                                        {1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
                                        {1, 1, 0, 1, 1, 0, 0, 1, 1, 0},
                                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 0, 0, 1, 1, 0, 1, 1, 1, 1}};
    std::vector<std::vector<int>> grid2{{0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 0, 0, 1, 1, 1, 0, 0, 1, 0},
                                        {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
                                        {1, 0, 0, 1, 0, 0, 1, 0, 1, 1},
                                        {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
                                        {1, 1, 1, 0, 0, 0, 1, 0, 1, 0},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                        {1, 1, 1, 0, 0, 0, 1, 0, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0}};

    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_sub_islands_bfs(grid1, grid2));
}

