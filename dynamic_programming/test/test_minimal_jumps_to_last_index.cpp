//
// Created by andreas on 13.07.23.
//

#include "gtest/gtest.h"
#include "minimal_jumps_to_last_index.h"

TEST(MinimalJumpsToLastIndex, simple1_recursive) {
    std::vector<unsigned int> distances{2, 3, 1, 1, 4};
    constexpr int expected_result{2};
    EXPECT_EQ(minimal_jumps_to_last_index_recursive(distances), expected_result);
}

TEST(MinimalJumpsToLastIndex, simple2_recursive) {
    std::vector<unsigned int> distances{2, 3, 1, 1, 4, 1, 2, 3, 6};
    constexpr int expected_result{3};
    EXPECT_EQ(minimal_jumps_to_last_index_recursive(distances), expected_result);
}

TEST(MinimalJumpsToLastIndex, simple3_recursive) {
    std::vector<unsigned int> distances{2, 1};
    constexpr int expected_result{1};
    EXPECT_EQ(minimal_jumps_to_last_index_recursive(distances), expected_result);
}

TEST(MinimalJumpsToLastIndex, simple4_recursive) {
    std::vector<unsigned int> distances{2, 3, 0, 1, 4};
    constexpr int expected_result{2};
    EXPECT_EQ(minimal_jumps_to_last_index_recursive(distances), expected_result);
}


TEST(MinimalJumpsToLastIndex, simple1_top_down) {
    std::vector<unsigned int> distances{2, 3, 1, 1, 4};
    constexpr int expected_result{2};
    EXPECT_EQ(minimal_jumps_to_last_index_top_down(distances), expected_result);
}

TEST(MinimalJumpsToLastIndex, simple2_top_down) {
    std::vector<unsigned int> distances{2, 3, 1, 1, 4, 1, 2, 3, 6};
    constexpr int expected_result{3};
    EXPECT_EQ(minimal_jumps_to_last_index_top_down(distances), expected_result);
}

TEST(MinimalJumpsToLastIndex, simple3_top_down) {
    std::vector<unsigned int> distances{2, 1};
    constexpr int expected_result{1};
    EXPECT_EQ(minimal_jumps_to_last_index_top_down(distances), expected_result);
}

TEST(MinimalJumpsToLastIndex, simple4_top_down) {
    std::vector<unsigned int> distances{2, 3, 0, 1, 4};
    constexpr int expected_result{2};
    EXPECT_EQ(minimal_jumps_to_last_index_top_down(distances), expected_result);
}


TEST(MinimalJumpsToLastIndex, medium1_top_down) {
    std::vector<unsigned int> distances{5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9,
                                        4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5};
    constexpr int expected_result{5};
    EXPECT_EQ(minimal_jumps_to_last_index_top_down(distances), expected_result);
}

TEST(MinimalJumpsToLastIndex, complex1_top_down) {
    std::vector<unsigned int> distances{1, 2, 1, 1, 1, 4, 4, 1, 5, 2, 3, 4, 1, 4, 2, 5, 2, 6, 4, 4, 2, 2, 5, 6, 2, 3, 4,
                                        5, 4, 4, 2, 3, 1, 4, 1, 6, 2, 3, 5, 3, 6, 6, 1, 2, 5, 3, 3, 4, 6, 1, 1, 5, 3, 3,
                                        4, 5, 1, 4, 2, 6, 6, 4, 1, 4, 1, 2, 1, 4, 4, 2, 1, 2, 2, 5, 6, 5, 4, 4, 3, 6, 5,
                                        2, 5, 6, 1, 4, 3, 4, 3, 3, 1, 2, 6, 5, 3, 6, 1, 2, 6, 4, 2, 3, 3, 4, 6, 3, 5, 3,
                                        2, 3, 3, 1, 3, 2, 4, 1, 3, 5, 1, 1, 5, 2, 4, 2, 2, 5, 3, 4, 2, 1, 3, 3, 1, 2, 4,
                                        5, 4, 6, 2, 5, 6, 4, 6, 5, 2, 2, 1, 4, 6, 4, 2, 4, 1, 6, 3, 3, 6, 1, 4, 5, 4, 5,
                                        1, 2, 3, 6, 1, 4, 3, 2, 5, 1, 5, 2, 5, 1, 2, 3, 3, 6, 6, 3, 5, 2, 6, 1, 6, 4, 3,
                                        4, 1, 2, 5, 1, 5, 6, 5, 3, 1, 5, 6, 3, 6, 3, 5, 6, 2, 2, 6, 3, 4, 1, 4, 1, 1, 3,
                                        4, 1, 5, 6, 5, 4, 2, 5, 3, 6, 4, 1, 2, 3, 5, 6, 5, 2, 3, 6, 1, 3, 4, 6, 3, 2, 5,
                                        5, 1, 6, 6, 6, 2, 3, 5, 5, 4, 5, 2, 1, 6, 6, 2, 5, 1, 3, 2, 5, 1, 2, 3, 4, 1, 1,
                                        5, 1, 4, 1, 2, 2, 6, 1, 4, 3, 2, 1, 6, 5, 1, 6, 2, 3, 5, 3, 6, 6, 5, 2, 1, 4, 4,
                                        5, 3, 5, 5, 1, 3, 2, 6, 1, 6, 6, 4, 6, 5, 3, 3, 1, 6, 2, 6, 4, 2, 4, 1, 2, 2, 2,
                                        2, 1, 5, 4, 3, 6, 3, 2, 5, 5, 4, 6, 4, 1, 5, 2, 4, 6, 2, 4, 5, 5, 3, 4, 6, 6, 1,
                                        6, 6, 5, 3, 1, 4, 6, 5, 3, 5, 3, 5, 2, 3, 4, 6, 2, 5, 6, 6, 2, 5, 6, 1, 1, 5, 4,
                                        5, 6, 6, 5, 5, 3, 3, 4, 4, 5, 2, 6, 5, 1, 3, 2, 3, 1, 3, 1, 2, 3, 5, 2, 5, 3, 2,
                                        2, 3, 4, 4, 2, 6, 5, 1, 3, 4, 6, 1, 6, 4, 4, 2, 4, 5, 2, 5, 6, 6, 1, 3, 1, 1, 4,
                                        6, 5, 6, 4, 1, 3, 1, 1, 6, 2, 6, 4, 5, 5, 3, 5, 3, 6, 6, 2, 1, 3, 2, 5, 5, 3, 5,
                                        3, 3, 5, 3, 2, 1, 2, 2, 6, 1, 6, 4, 2, 2, 2, 6, 2, 4, 2, 5, 5, 2, 3, 1, 1, 5, 6,
                                        6, 3, 4, 6, 2, 1, 2, 1, 4, 2, 5, 6, 5, 5, 3, 2, 1, 5, 1, 3, 2, 2, 5, 1, 6, 1, 6,
                                        5, 6, 2, 6, 3, 6, 5, 1, 4, 6, 3, 3, 6, 6, 4, 1, 4, 6, 3, 4, 1, 4, 2, 5, 5, 5, 4,
                                        2, 5, 6, 6, 3, 1, 5, 4, 2, 3, 6, 1, 6, 4, 1, 5, 5, 6, 4, 5, 4, 4, 6, 5, 2, 5, 1,
                                        4, 3, 2, 6, 1, 5, 2, 6, 2, 6, 1, 2, 3, 5, 5, 4, 4, 5, 4, 2, 1, 4, 1, 4, 6, 1, 1,
                                        2, 6, 2, 3, 6, 4, 4, 5, 6, 6, 4, 1, 6, 3, 2, 4, 1, 4, 5, 5, 2, 6, 6, 4, 2, 5, 4,
                                        6, 6, 5, 2, 4, 1, 1, 4, 1, 1, 4, 6, 1, 5, 2, 4, 6, 5, 1, 6, 6, 6, 2, 1, 6, 1, 5,
                                        5, 4, 5, 2, 3, 2, 2, 2, 6, 4, 6, 2, 4, 6, 4, 5, 1, 3, 2, 4, 2, 6, 6, 4, 3, 3, 1,
                                        1, 4, 4, 5, 5, 4, 1, 6, 5, 1, 3, 3, 6, 5, 5, 3, 6, 3, 5, 2, 4, 3, 4, 6, 5, 2, 6,
                                        6, 1, 2, 3, 4, 6, 1, 5, 6, 4, 6, 6, 1, 1, 2, 4, 6, 4, 1, 1, 6, 6, 2, 1, 1, 2, 3,
                                        6, 5, 3, 1, 6, 1, 3, 6, 2, 4, 5, 3, 2, 5, 3, 5, 5, 2, 1, 3, 4, 4, 6, 2, 4, 3, 3,
                                        1, 5, 3, 3, 1, 2, 5, 2, 5, 2, 2, 4, 2, 2, 4, 6, 3, 1, 4, 2, 3, 4, 2, 2, 6, 3, 2,
                                        6, 3, 3, 5, 5, 5, 2, 3, 1, 6, 5, 4, 5, 2, 6, 5, 2, 1, 2, 2, 2, 2, 2, 3, 2, 6, 3,
                                        1, 5, 6, 1, 4, 6, 5, 3, 3, 5, 5, 6, 5, 1, 4, 3, 5, 5, 3, 4, 6, 4, 6, 3, 2, 1, 1,
                                        6, 2, 2, 5, 5, 3, 1, 3, 5, 6, 3, 6, 2, 5, 6, 2, 1, 4, 4, 2, 2, 6, 2, 1, 5, 6, 1,
                                        1, 3, 3, 5, 5, 3, 2, 5, 2, 1, 3, 2, 4, 3, 5, 2, 5, 5, 4, 1, 1, 3, 4, 3, 1, 3, 5,
                                        5, 4, 5, 5, 1, 3, 5, 4, 6, 5, 4, 2, 1, 2, 6, 6, 4, 4, 5, 6, 6, 6, 3, 4, 3, 5, 2,
                                        5, 6, 5, 2, 1, 4, 5, 3, 1, 6, 4, 1, 5, 4, 5, 2, 5, 1, 4, 2, 6, 3, 3, 5, 1, 3, 4,
                                        3, 3, 6, 6, 5, 5, 5, 4, 5, 3, 6, 6, 6, 4, 2, 4, 4, 1, 2, 2, 2, 3, 2, 2, 5, 6, 5,
                                        6, 3, 3, 1, 1, 4, 1, 6, 6, 5, 3, 2, 6, 5, 2, 1, 6, 1, 4, 6, 4, 1, 2, 1, 2, 5, 1,
                                        1, 6, 3, 2, 5, 4, 5, 2, 6, 5, 6, 2, 2, 1, 5, 5, 1, 6, 2, 1, 3, 4, 5, 4, 3, 1, 5,
                                        6, 5, 4, 1, 2, 3, 4, 2, 2, 6, 2, 4, 3, 2, 5, 3, 2, 2, 5, 6, 3, 3, 2, 1, 4, 5, 2,
                                        3, 2, 5, 3, 1, 3, 6, 3, 6, 4, 2, 5, 3, 6, 1, 6, 5, 2, 1, 5, 2, 1, 1, 4, 3, 3, 1,
                                        1, 2, 2, 1, 1, 4, 1, 6, 5, 5, 6, 4, 6, 6, 2, 2, 2, 6, 1, 1, 1, 1, 5, 2, 2, 1, 6,
                                        5, 6, 1, 3, 1, 6, 4, 1, 2, 1, 5, 1, 1, 3, 6, 4, 5, 4, 2, 3, 4, 1, 5, 2, 2, 1, 6,
                                        2, 3, 2, 3, 3, 1, 1, 4, 5, 5, 3, 5, 3, 6, 4, 5, 4, 4, 4, 2, 2, 1, 4, 6, 0, 0, 0,
                                        0, 0};
    constexpr int expected_result{274};
    EXPECT_EQ(minimal_jumps_to_last_index_top_down(distances), expected_result);
}
