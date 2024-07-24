//
// Created by andreas on 12.09.23.
//
#include "gtest/gtest.h"
#include "minimum_deletions_for_unique_character_frequencies.h"

TEST(MinimumDeletions, simple1) {
    std::string input{"aab"};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, minimum_deletions(input));
}

TEST(MinimumDeletions, simple2) {
    std::string input{"abcdefghijklmnopqrstuvwxyz"};
    constexpr int expected_result{25};
    EXPECT_EQ(expected_result, minimum_deletions(input));
}


TEST(MinimumDeletions, simple3) {
    std::string input{"aabbbcccdddd"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, minimum_deletions(input));
}


TEST(MinimumDeletions, simple4) {
    std::string input{""};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, minimum_deletions(input));
}
