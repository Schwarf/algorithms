//
// Created by andreas on 23.04.24.
//
#include "graphs/minimum_height_trees.h"
#include "gtest/gtest.h"

TEST(TestMinimumHeightTrees, simple1) {
    std::vector<std::vector<unsigned int>> edges{{1U, 0U},
                                                 {1U, 2U},
                                                 {1U, 3U}};
    constexpr int n{4};
    std::vector<unsigned int> expected_result{1U};
    EXPECT_EQ(expected_result, find_minimum_height_trees(edges, n));
}

TEST(TestMinimumHeightTrees, simple2) {
    std::vector<std::vector<unsigned int>> edges{{3, 0},
                                                 {3, 1},
                                                 {3, 2},
                                                 {3, 4},
                                                 {5, 4}};
    constexpr int n{6};
    std::vector<unsigned int> expected_result{3, 4};
    auto result = find_minimum_height_trees(edges, n);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expected_result, result);
}

TEST(TestMinimumHeightTrees, simple3) {
    std::vector<std::vector<unsigned int>> edges{{0, 1},
                                                 {0, 2},
                                                 {2, 3},
                                                 {0, 4},
                                                 {2, 5},
                                                 {5, 6},
                                                 {3, 7},
                                                 {6, 8},
                                                 {8, 9},
                                                 {9, 10}};
    constexpr int n{11};
    std::vector<unsigned int> expected_result{5, 6};
    auto result = find_minimum_height_trees(edges, n);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expected_result, result);
}


TEST(TestMinimumHeightTrees, medium1) {
    std::vector<std::vector<unsigned int>> edges{{0,  1},
                                                 {1,  2},
                                                 {0,  3},
                                                 {1,  4},
                                                 {1,  5},
                                                 {0,  6},
                                                 {2,  7},
                                                 {3,  8},
                                                 {2,  9},
                                                 {7,  10},
                                                 {6,  11},
                                                 {11, 12},
                                                 {2,  13},
                                                 {0,  14},
                                                 {8,  15},
                                                 {6,  16},
                                                 {8,  17},
                                                 {4,  18},
                                                 {18, 19},
                                                 {17, 20}};
    constexpr int n{21};
    std::vector<unsigned int> expected_result{0};
    EXPECT_EQ(expected_result, find_minimum_height_trees(edges, n));
}


TEST(TestMinimumHeightTreesAlternative, simple1) {
    std::vector<std::vector<unsigned int>> edges{{1U, 0U},
                                                 {1U, 2U},
                                                 {1U, 3U}};
    constexpr int n{4};
    std::vector<unsigned int> expected_result{1U};
    EXPECT_EQ(expected_result, find_minimum_height_trees_alternative(edges, n));
}

TEST(TestMinimumHeightTreesAlternative, simple2) {
    std::vector<std::vector<unsigned int>> edges{{3, 0},
                                                 {3, 1},
                                                 {3, 2},
                                                 {3, 4},
                                                 {5, 4}};
    constexpr int n{6};
    std::vector<unsigned int> expected_result{3, 4};
    auto result = find_minimum_height_trees_alternative(edges, n);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expected_result, result);

}

TEST(TestMinimumHeightTreesAlternative, simple3) {
    std::vector<std::vector<unsigned int>> edges{{0, 1},
                                                 {0, 2},
                                                 {2, 3},
                                                 {0, 4},
                                                 {2, 5},
                                                 {5, 6},
                                                 {3, 7},
                                                 {6, 8},
                                                 {8, 9},
                                                 {9, 10}};
    constexpr int n{11};
    std::vector<unsigned int> expected_result{5, 6};
    auto result = find_minimum_height_trees_alternative(edges, n);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expected_result, result);

}


TEST(TestMinimumHeightTreesAlternative, medium1) {
    std::vector<std::vector<unsigned int>> edges{{0,  1},
                                                 {1,  2},
                                                 {0,  3},
                                                 {1,  4},
                                                 {1,  5},
                                                 {0,  6},
                                                 {2,  7},
                                                 {3,  8},
                                                 {2,  9},
                                                 {7,  10},
                                                 {6,  11},
                                                 {11, 12},
                                                 {2,  13},
                                                 {0,  14},
                                                 {8,  15},
                                                 {6,  16},
                                                 {8,  17},
                                                 {4,  18},
                                                 {18, 19},
                                                 {17, 20}};
    constexpr int n{21};
    std::vector<unsigned int> expected_result{0};
    EXPECT_EQ(expected_result, find_minimum_height_trees_alternative(edges, n));
}

