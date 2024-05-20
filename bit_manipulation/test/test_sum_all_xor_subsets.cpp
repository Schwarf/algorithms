//
// Created by andreas on 20.05.24.
//
#include "gtest/gtest.h"
#include "./../sum_all_xor_subsets.h"

TEST(TestSumAllXorSubsets, simple1) {
    const std::vector<int> input{1, 3};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, compute_xor_sums(input));
}

TEST(TestSumAllXorSubsets, simple2) {
    const std::vector<int> input{5, 1, 6};
    constexpr int expected_result{28};
    EXPECT_EQ(expected_result, compute_xor_sums(input));
}

TEST(TestSumAllXorSubsets, simple3) {
    const std::vector<int> input{3, 4, 5, 6, 7, 8};
    constexpr int expected_result{480};
    EXPECT_EQ(expected_result, compute_xor_sums(input));
}

TEST(TestSumAllXorSubsets, simple4) {
    const std::vector<int> input{10, 5, 8, 3, 6, 12, 2, 4, 11, 7, 1, 9};
    constexpr int expected_result{30720};
    EXPECT_EQ(expected_result, compute_xor_sums(input));
}

TEST(TestSumAllXorSubsetsOptimal, simple1) {
    const std::vector<int> input{1, 3};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, compute_xor_sums_optimal(input));
}

TEST(TestSumAllXorSubsetsOptimal, simple2) {
    const std::vector<int> input{5, 1, 6};
    constexpr int expected_result{28};
    EXPECT_EQ(expected_result, compute_xor_sums_optimal(input));
}

TEST(TestSumAllXorSubsetsOptimal, simple3) {
    const std::vector<int> input{3, 4, 5, 6, 7, 8};
    constexpr int expected_result{480};
    EXPECT_EQ(expected_result, compute_xor_sums_optimal(input));
}

TEST(TestSumAllXorSubsetsOptimal, simple4) {
    const std::vector<int> input{10, 5, 8, 3, 6, 12, 2, 4, 11, 7, 1, 9};
    constexpr int expected_result{30720};
    EXPECT_EQ(expected_result, compute_xor_sums_optimal(input));
}
