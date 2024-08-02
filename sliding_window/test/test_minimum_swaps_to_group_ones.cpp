//
// Created by andreas on 02.08.24.
//

#include "gtest/gtest.h"
#include "./../minimum_swaps_to_group_ones.h"

TEST(TestMinimumSwaps, simple1) {
    const std::vector<int> input{1, 1, 0, 1, 0, 1, 0, 1, 0};
    constexpr int expected_result{2};
    EXPECT_EQ(sliding_window_analysis(input,1), expected_result);
}

TEST(TestMinimumSwaps, simple2) {
    const std::vector<int> input{1, 1, 0, 1, 0, 1, 0};
    constexpr int expected_result{1};
    EXPECT_EQ(sliding_window_analysis(input,1), expected_result);
}

TEST(TestMinimumSwaps, simple3) {
    const std::vector<int> input{1, 1, 0, 1, 1};
    constexpr int expected_result{1};
    EXPECT_EQ(sliding_window_analysis(input,1), expected_result);
}

TEST(TestMinimumSwaps, medium1) {
    const std::vector<int> input{1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
                                 0, 0, 1, 0, 0};
    constexpr int expected_result{7};
    EXPECT_EQ(sliding_window_analysis(input,1 ), expected_result);
}

TEST(TestMinimumSwaps, medium2) {
    const std::vector<int> input{1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1,
                                 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0,
                                 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
                                 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0,
                                 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1};
    constexpr int expected_result{30};
    EXPECT_EQ(sliding_window_analysis(input, 1), expected_result);
}

TEST(TestMinimumSwapsCircularBoundaryBruteForce, simple1) {
    const std::vector<int> input{1, 1, 0, 1, 0, 1, 0, 1, 0};
    constexpr int expected_result{2};
    EXPECT_EQ(swaps_needed_brute_force_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundaryBruteForce, simple2) {
    const std::vector<int> input{1, 1, 0, 1, 0, 1, 0};
    constexpr int expected_result{1};
    EXPECT_EQ(swaps_needed_brute_force_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundaryBruteForce, simple3) {
    const std::vector<int> input{1, 1, 0, 1, 1};
    constexpr int expected_result{};
    EXPECT_EQ(swaps_needed_brute_force_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundaryBruteForce, medium1) {
    const std::vector<int> input{1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
                                 0, 0, 1, 0, 0};
    constexpr int expected_result{7};
    EXPECT_EQ(swaps_needed_brute_force_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundaryBruteForce, medium2) {
    const std::vector<int> input{1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1,
                                 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0,
                                 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
                                 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0,
                                 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1};
    constexpr int expected_result{28};
    EXPECT_EQ(swaps_needed_brute_force_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundary, simple1) {
    const std::vector<int> input{1, 1, 0, 1, 0, 1, 0, 1, 0};
    constexpr int expected_result{2};
    EXPECT_EQ(swaps_needed_sliding_window_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundary, simple2) {
    const std::vector<int> input{1, 1, 0, 1, 0, 1, 0};
    constexpr int expected_result{1};
    EXPECT_EQ(swaps_needed_sliding_window_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundary, simple3) {
    const std::vector<int> input{1, 1, 0, 1, 1};
    constexpr int expected_result{};
    EXPECT_EQ(swaps_needed_sliding_window_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundary, medium1) {
    const std::vector<int> input{1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
                                 0, 0, 1, 0, 0};
    constexpr int expected_result{7};
    EXPECT_EQ(swaps_needed_sliding_window_circular(input), expected_result);
}

TEST(TestMinimumSwapsCircularBoundary, medium2) {
    const std::vector<int> input{1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1,
                                 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0,
                                 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
                                 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0,
                                 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1};
    constexpr int expected_result{28};
    EXPECT_EQ(swaps_needed_sliding_window_circular(input), expected_result);
}