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