//
// Created by andreas on 06.11.23.
//
#include "gtest/gtest.h"
#include "find_original_array_from_doubled_array.h"

TEST(FindArrayFromDoubledArray, simple1) {
    std::vector<int> input{1, 2};
    std::vector<int> expected_result{1};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}

TEST(FindArrayFromDoubledArray, simple2) {
    std::vector<int> input{0, 1};
    std::vector<int> expected_result{};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}


TEST(FindArrayFromDoubledArray, simple3) {
    std::vector<int> input{2, 1};
    std::vector<int> expected_result{1};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}


TEST(FindArrayFromDoubledArray, simple4) {
    std::vector<int> input{0, 0};
    std::vector<int> expected_result{0};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}


TEST(FindArrayFromDoubledArray, simple5) {
    std::vector<int> input{1, 2, 8, 4};
    std::vector<int> expected_result{1, 4};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}

TEST(FindArrayFromDoubledArray, simple6) {
    std::vector<int> input{2, 2, 2, 4, 4, 4, 4, 8};
    std::vector<int> expected_result{2, 2, 2, 4};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}

TEST(FindArrayFromDoubledArray, simple7) {
    std::vector<int> input{2};
    std::vector<int> expected_result{};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}

TEST(FindArrayFromDoubledArray, simple8) {
    std::vector<int> input{2, 1, 3};
    std::vector<int> expected_result{};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}

TEST(FindArrayFromDoubledArray, medium1) {
    std::vector<int> input
            {40, 7, 78, 12, 40, 28, 33, 27, 35, 90, 56, 44, 42, 38, 36, 3, 12, 68, 86, 14, 27, 80, 33, 40, 12, 74, 20,
             50,
             15, 54, 76, 13, 40, 3, 43, 88, 14, 54, 20, 0, 100, 10, 23, 30, 27, 50, 84, 24, 15, 45, 94, 66, 6, 22, 20,
             34,
             25, 100, 28, 6, 37, 10, 18, 82, 96, 0, 76, 40, 32, 33, 48, 70, 24, 80, 20, 40, 50, 4, 19, 25, 66, 38, 46,
             44,
             98, 47, 26, 54, 38, 39, 41, 20, 49, 8, 16, 6, 50, 30, 20, 66};
    std::vector<int> expected_result
            {0, 3, 3, 4, 6, 7, 10, 10, 12, 12, 13, 14, 15, 15, 16, 18, 19, 20, 20, 20, 20, 22, 23, 25, 25, 27, 27, 27,
             28,
             33, 33, 33, 34, 35, 37, 38, 38, 39, 40, 40, 41, 42, 43, 44, 45, 47, 48, 49, 50, 50};
    EXPECT_EQ(find_array_from_doubled_arrays(input), expected_result);
}
