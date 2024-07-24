//
// Created by andreas on 17.03.24.
//
#include "gtest/gtest.h"
#include "insert_interval.h"

TEST(TestInsertIntervals, simple1) {
    const std::vector<std::vector<int>> input{{1, 3},
                                              {6, 9}};
    std::vector<int> new_interval{2, 5};
    const std::vector<std::vector<int>> expected_result{{1, 5},
                                                        {6, 9}};
    EXPECT_EQ(insert_new_interval(input, new_interval), expected_result);
}

TEST(TestInsertIntervals, simple2) {
    const std::vector<std::vector<int>> input{{1,  2},
                                              {3,  5},
                                              {6,  7},
                                              {8,  10},
                                              {12, 16}};
    std::vector<int> new_interval{4, 8};
    const std::vector<std::vector<int>> expected_result{{1,  2},
                                                        {3,  10},
                                                        {12, 16}};
    EXPECT_EQ(insert_new_interval(input, new_interval), expected_result);
}

TEST(TestInsertIntervals, simple3) {
    const std::vector<std::vector<int>> input
            {{8,  11},
             {12, 12},
             {15, 15},
             {19, 19},
             {20, 23},
             {24, 24},
             {25, 29},
             {32, 32},
             {35, 38},
             {41, 41},
             {42, 45}};
    std::vector<int> new_interval{6, 11};
    const std::vector<std::vector<int>> expected_result
            {{6,  11},
             {12, 12},
             {15, 15},
             {19, 19},
             {20, 23},
             {24, 24},
             {25, 29},
             {32, 32},
             {35, 38},
             {41, 41},
             {42, 45}};
    EXPECT_EQ(insert_new_interval(input, new_interval), expected_result);
}

TEST(TestInsertIntervals, simple4) {
    const std::vector<std::vector<int>> input
            {{8,  11},
             {12, 12},
             {15, 15},
             {19, 19},
             {20, 23},
             {24, 24},
             {25, 29},
             {32, 32},
             {35, 38},
             {41, 41},
             {42, 45}};
    std::vector<int> new_interval{12, 12};
    const std::vector<std::vector<int>> expected_result
            {{8,  11},
             {12, 12},
             {15, 15},
             {19, 19},
             {20, 23},
             {24, 24},
             {25, 29},
             {32, 32},
             {35, 38},
             {41, 41},
             {42, 45}};
    EXPECT_EQ(insert_new_interval(input, new_interval), expected_result);
}

TEST(TestInsertIntervals, simple5) {
    const std::vector<std::vector<int>> input
            {{8,  11},
             {12, 12},
             {15, 15},
             {19, 19},
             {20, 23},
             {24, 24},
             {25, 29},
             {32, 32},
             {35, 38},
             {41, 41},
             {42, 45}};
    std::vector<int> new_interval{12, 16};
    const std::vector<std::vector<int>> expected_result
            {{8,  11},
             {12, 16},
             {19, 19},
             {20, 23},
             {24, 24},
             {25, 29},
             {32, 32},
             {35, 38},
             {41, 41},
             {42, 45}};
    EXPECT_EQ(insert_new_interval(input, new_interval), expected_result);
}
