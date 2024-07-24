//
// Created by andreas on 26.03.24.
//
#include "gtest/gtest.h"
#include "./../find_first_missing_positive.h"

TEST(TestFindFirstMissingPositive, simple1) {
    const std::vector<int> input{1, 2, 0};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, find_first_missing_positive(input));
}

TEST(TestFindFirstMissingPositive, simple2) {
    const std::vector<int> input{1, 2, -2, -3};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, find_first_missing_positive(input));
}

TEST(TestFindFirstMissingPositive, simple3) {
    const std::vector<int> input{0, -1, -2,};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, find_first_missing_positive(input));
}

TEST(TestFindFirstMissingPositive, simple4) {
    const std::vector<int> input{1, 2, 3, 4, 5};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, find_first_missing_positive(input));
}

TEST(TestFindFirstMissingPositive, simple5) {
    const std::vector<int> input{0, 0, 0, 0, 0};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, find_first_missing_positive(input));
}


TEST(TestFindFirstMissingPositive, simple6) {
    const std::vector<int> input{5, 6, 7, 8};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, find_first_missing_positive(input));
}

TEST(TestFindFirstMissingPositive, simple7) {
    const std::vector<int> input{1, 1, 1};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, find_first_missing_positive(input));
}


TEST(TestFindFirstMissingPositiveOptimized, simple1) {
    std::vector<int> input{1, 2, 0};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, find_first_missing_positive_optimized(input));
}

TEST(TestFindFirstMissingPositiveOptimized, simple2) {
    std::vector<int> input{1, 2, -2, -3};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, find_first_missing_positive_optimized(input));
}

TEST(TestFindFirstMissingPositiveOptimized, simple3) {
    std::vector<int> input{0, -1, -2,};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, find_first_missing_positive_optimized(input));
}

TEST(TestFindFirstMissingPositiveOptimized, simple4) {
    std::vector<int> input{1, 2, 3, 4, 5};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, find_first_missing_positive_optimized(input));
}

TEST(TestFindFirstMissingPositiveOptimized, simple5) {
    std::vector<int> input{0, 0, 0, 0, 0};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, find_first_missing_positive_optimized(input));
}


TEST(TestFindFirstMissingPositiveOptimized, simple6) {
    std::vector<int> input{5, 6, 7, 8};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, find_first_missing_positive_optimized(input));
}

TEST(TestFindFirstMissingPositiveOptimized, simple7) {
    std::vector<int> input{1, 1, 1};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, find_first_missing_positive_optimized(input));
}
