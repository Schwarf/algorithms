//
// Created by andreas on 20.04.24.
//
#include "gtest/gtest.h"
#include "./../island_perimeter.h"

TEST(TestIslandPerimeter, simple1) {
    const std::vector<std::vector<int>> input{{0, 1, 0, 0},
                                              {1, 1, 1, 0},
                                              {0, 1, 0, 0},
                                              {1, 1, 0, 0}};

    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, island_perimeter(input));
}

TEST(TestIslandPerimeter, simple2) {
    const std::vector<std::vector<int>> input{{1}};

    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, island_perimeter(input));
}

TEST(TestIslandPerimeter, simple3) {
    const std::vector<std::vector<int>> input{{1,1,1}};

    constexpr int expected_result{8};
    EXPECT_EQ(expected_result, island_perimeter(input));
}

TEST(TestIslandPerimeter, simple4) {
    const std::vector<std::vector<int>> input{{1,1,1},
                                              {0,1,0},
                                              {1,1,1}};

    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, island_perimeter(input));
}

/// Test for multiple islands
TEST(TestIslandPerimeter, simple_multiple_islands1) {
    const std::vector<std::vector<int>> input{{1,1,1},
                                              {0,0,0},
                                              {1,1,1}};

    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, island_perimeter(input));
}

TEST(TestIslandPerimeter, simple_multiple_islands2) {
    const std::vector<std::vector<int>> input{{0, 1, 0, 0},
                                              {1, 0, 1, 0},
                                              {0, 1, 0, 0},
                                              {1, 1, 0, 0}};

    constexpr int expected_result{20};
    EXPECT_EQ(expected_result, island_perimeter(input));
}
