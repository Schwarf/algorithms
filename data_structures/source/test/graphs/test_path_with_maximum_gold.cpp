//
// Created by andreas on 20.05.24.
//
#include "gtest/gtest.h"
#include "graphs/path_with_maximum_gold.h"

TEST(TestPathWithMaximumGold, simple1) {
    std::vector<std::vector<float>> input{{0.f, 6.f, 0.f},
                                          {5.f, 8.f, 7.f},
                                          {0.f, 9.f, 0.f}};
    constexpr float expected_result{24.f};
    EXPECT_EQ(path_with_maximum_gold(input), expected_result);
}

TEST(TestPathWithMaximumGold, simple2) {
    std::vector<std::vector<int>> input{{1, 0, 7},
                                        {2, 0, 6},
                                        {3, 4, 5},
                                        {0, 3, 0},
                                        {9, 0, 20}};
    constexpr int expected_result{28};
    EXPECT_EQ(path_with_maximum_gold(input), expected_result);
}

TEST(TestPathWithMaximumGold, simple3) {
    std::vector<std::vector<short>> input{{0, 0, 0,  3, 0, 0,  17, 0,  0, 0,  0,  0},
                                          {0, 0, 0,  0, 0, 0,  0,  0,  0, 0,  0,  0},
                                          {0, 0, 0,  0, 0, 0,  0,  8,  5, 15, 0,  0},
                                          {0, 0, 0,  0, 0, 17, 0,  17, 0, 0,  12, 0},
                                          {0, 0, 0,  4, 0, 0,  20, 0,  0, 0,  0,  0},
                                          {0, 0, 0,  0, 0, 7,  13, 0,  0, 0,  0,  0},
                                          {0, 0, 0,  0, 0, 0,  0,  0,  0, 0,  16, 20},
                                          {2, 0, 0,  4, 0, 0,  0,  16, 0, 4,  0,  0},
                                          {0, 0, 11, 0, 0, 10, 0,  0,  5, 0,  0,  18},
                                          {2, 0, 12, 0, 0, 0,  0,  0,  0, 0,  0,  0},
                                          {0, 0, 0,  0, 0, 0,  0,  0,  0, 0,  3,  0},
                                          {0, 0, 0,  0, 0, 0,  0,  0,  0, 0,  0,  0}};
    constexpr short expected_result{45};
    EXPECT_EQ(path_with_maximum_gold(input), expected_result);
}