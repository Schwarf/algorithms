//
// Created by andreas on 17.08.24.
//
#include "gtest/gtest.h"
#include "./../maximum_number_of_points_with_costs.h"

TEST(TestMaximumNumberWithCostsBruteForce, simple1) {
    std::vector<std::vector<int>> input{{1, 2, 3},
                                        {1, 5, 1},
                                        {3, 1, 1}};
    constexpr long long expected_result{9};
    EXPECT_EQ(expected_result, get_maximum_cost_dp_brute_force(input));

}


TEST(TestMaximumNumberWithCostsBruteForce, simple2) {
    std::vector<std::vector<int>> input{{1, 5},
                                        {2, 3},
                                        {4, 2}
    };
    constexpr long long expected_result{11};
    EXPECT_EQ(expected_result, get_maximum_cost_dp_brute_force(input));
}

TEST(TestMaximumNumberWithCostsBruteForce, simple3) {
    std::vector<std::vector<int>> input{{8, 2, 4, 4,  9, 3, 5,  3, 10, 10},
                                        {4, 8, 7, 4,  0, 1, 10, 6, 4,  0},
                                        {0, 5, 2, 10, 4, 2, 7,  8, 6,  8},
                                        {0, 1, 1, 2,  8, 0, 5,  9, 8,  2},
                                        {6, 2, 0, 4,  5, 0, 5,  3, 10, 3}};
    constexpr long long expected_result{43};
    EXPECT_EQ(expected_result, get_maximum_cost_dp_brute_force(input));
}

TEST(TestMaximumNumberWithCostsBruteForce, simple4) {
    std::vector<std::vector<int>> input{{5,  8, 6,  9,  2},
                                        {3,  2, 2,  6,  0},
                                        {2,  5, 6,  10, 3},
                                        {4,  2, 1,  6,  0},
                                        {7,  3, 3,  7,  5},
                                        {4,  3, 3,  0,  10},
                                        {3,  6, 5,  4,  1},
                                        {4,  5, 10, 8,  6},
                                        {10, 8, 5,  0,  1},
                                        {4,  2, 9,  4,  0}};
    constexpr long long expected_result{75};
    EXPECT_EQ(expected_result, get_maximum_cost_dp_brute_force(input));
}
