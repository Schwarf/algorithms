//
// Created by andreas on 23.07.24.
//
#include "gtest/gtest.h"
#include "sort_array_by_increasing_frequency.h"

TEST(SortArrayByFrequency, simple1) {
    std::vector<int> input{1, 1, 2, 2, 2, 3};
    std::vector<int> expected_result{3, 1, 1, 2, 2, 2};
    sort_by_increasing_frequency(input);
    EXPECT_EQ(expected_result, input);
}

TEST(SortArrayByFrequency, simple2) {
    std::vector<int> input{2, 3, 1, 3, 2};
    std::vector<int> expected_result{1, 3, 3, 2, 2};
    sort_by_increasing_frequency(input);
    EXPECT_EQ(expected_result, input);
}

TEST(SortArrayByFrequency, simple3) {
    std::vector<int> input{-1, 1, -6, 4, 5, -6, 1, 4, 1};
    std::vector<int> expected_result{5, -1, 4, 4, -6, -6, 1, 1, 1};
    sort_by_increasing_frequency(input);
    EXPECT_EQ(expected_result, input);
}

TEST(SortArrayByFrequency, simple4) {
    std::vector<int> input{-36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36,
                           -36, -36};
    std::vector<int> expected_result{-36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36, -36,
                                     -36, -36, -36, -36};
    sort_by_increasing_frequency(input);
    EXPECT_EQ(expected_result, input);
}

TEST(SortArrayByFrequency, medium1) {
    std::vector<int> input{14, 32, 24, 27, 1, 32, -16, 29, 46, 40, 21, 9, -18, 29, 40, 7, -16, -43, 9, 19, 24, -32, 32,
                           -35};
    std::vector<int> expected_result{46, 27, 21, 19, 14, 7, 1, -18, -32, -35, -43, 40, 40, 29, 29, 24, 24, 9, 9, -16,
                                     -16, 32, 32, 32};
    sort_by_increasing_frequency(input);
    EXPECT_EQ(expected_result, input);
}