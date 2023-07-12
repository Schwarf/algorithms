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
    std::vector<unsigned int> distances{2,1};
    constexpr int expected_result{1};
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
    std::vector<unsigned int> distances{2,1};
    constexpr int expected_result{1};
    EXPECT_EQ(minimal_jumps_to_last_index_top_down(distances), expected_result);
}
