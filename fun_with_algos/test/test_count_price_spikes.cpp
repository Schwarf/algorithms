//
// Created by andreas on 13.03.25.
//
#include "./../count_price_spikes.h"
#include "gtest/gtest.h"

TEST(TestCountPriceSpike, simple1) {
    std::vector<int> input{1, 2, 8, 5, 3, 4};
    constexpr int k{2};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_spikes(input, k));
}

TEST(TestCountPriceSpike, simple2) {
    std::vector<int> input{1, 2, 8, 5, 3, 4};
    constexpr int k{3};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, count_spikes(input, k));
}

TEST(TestCountPriceSpike, simple3) {
    std::vector<int> input{1, 2, 8, 5, 3, 4};
    constexpr int k{1};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_spikes(input, k));
}

TEST(TestCountPriceSpike, simple4) {
    std::vector<int> input{1, 2, 8, 5, 3, 1};
    constexpr int k{1};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, count_spikes(input, k));
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestCountPriceSpikeOptimized, simple1) {
    std::vector<int> input{1, 2, 8, 5, 3, 4};
    constexpr int k{2};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_spikes_optimized(input, k));
}

TEST(TestCountPriceSpikeOptimized, simple2) {
    std::vector<int> input{1, 2, 8, 5, 3, 4};
    constexpr int k{3};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, count_spikes_optimized(input, k));
}

TEST(TestCountPriceSpikeOptimized, simple3) {
    std::vector<int> input{1, 2, 8, 5, 3, 4};
    constexpr int k{1};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_spikes_optimized(input, k));
}

TEST(TestCountPriceSpikeOptimized, simple4) {
    std::vector<int> input{1, 2, 8, 5, 3, 1};
    constexpr int k{1};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, count_spikes_optimized(input, k));
}
