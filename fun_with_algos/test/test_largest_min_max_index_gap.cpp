//
// Created by andreas on 13.10.24.
//
#include "gtest/gtest.h"
#include "./../largest_min_max_index_gap .h"

TEST(TestLargestMinMaxGapSort, simple1) {
    std::vector<float> input{6.F, 0.F, 8.F, 2.F, 1.F, 5.F};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, largest_min_max_index_gap_sort(input));
}

TEST(TestLargestMinMaxGapSort, simple2) {
    std::vector<double> input{1.0};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, largest_min_max_index_gap_sort(input));
}

TEST(TestLargestMinMaxGapSort, simple3) {
    std::vector<int> input{9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    constexpr int expected_result{7};
    EXPECT_EQ(expected_result, largest_min_max_index_gap_sort(input));
}

TEST(TestLargestMinMaxGapSort, simple4) {
    std::vector<int> input{24, 27, 16, 25, 15, 27, 25, 6, 25, 27, 0, 21, 27, 15, 13, 8, 6, 15, 9, 17, 17, 2, 20, 4, 8,
                           25, 4, 27, 14, 18};
    constexpr int expected_result{27};
    EXPECT_EQ(expected_result, largest_min_max_index_gap_sort(input));
}

TEST(TestLargestMinMaxGapSort, simple5) {
    std::vector<int> input{34, 48, 46, 45, 95, 42, 75, 37, 37, 50, 85, 4, 18, 29, 72, 65, 1, 54, 22, 31, 12, 85, 99, 94,
                           23, 16, 39, 13, 94, 43, 87, 46, 85, 90, 73, 72, 51, 28, 55, 88, 60, 93, 78, 86, 39, 88, 57,
                           47, 12, 61, 72, 44, 14, 5, 11, 78, 71, 17, 54, 34, 26, 95, 31, 48, 16, 6, 59, 82, 64, 92, 98,
                           48, 83, 77, 4, 23, 85, 29, 41, 78, 4, 45, 42, 36, 77, 21, 21, 14, 95, 22, 67, 40, 64, 75, 84,
                           19, 93, 19, 99, 75};
    constexpr int expected_result{99};
    EXPECT_EQ(expected_result, largest_min_max_index_gap_sort(input));
}