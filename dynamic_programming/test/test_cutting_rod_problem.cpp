//
// Created by andreas on 23.06.24.
//

#include "gtest/gtest.h"
#include "./../cutting_rod_problem.h"

TEST(TestCuttingRodProblem, simple1) {
    std::vector<int> prices{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    constexpr int length{8};
    constexpr int expected_result{22};
    EXPECT_EQ(expected_result, rod_cutting(prices, length));
}

TEST(TestCuttingRodProblem, simple2) {
    std::vector<int> prices{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    constexpr int length{10};
    constexpr int expected_result{30};
    EXPECT_EQ(expected_result, rod_cutting(prices, length));
}

TEST(TestCuttingRodProblem, simple3) {
    std::vector<int> prices{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    constexpr int length{9};
    constexpr int expected_result{25};
    EXPECT_EQ(expected_result, rod_cutting(prices, length));
}

TEST(TestCuttingRodProblem, simple4) {
    std::vector<int> prices{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    constexpr int length{15};
    constexpr int expected_result{43};
    EXPECT_EQ(expected_result, rod_cutting(prices, length));
}
