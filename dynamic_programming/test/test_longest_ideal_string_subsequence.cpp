//
// Created by andreas on 26.04.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_TEST_LONGEST_IDEAL_STRING_SUBSEQUENCE_CPP
#define DYNAMIC_PROGRAMMING_SAMPLES_TEST_LONGEST_IDEAL_STRING_SUBSEQUENCE_CPP

#include "gtest/gtest.h"
#include "./../longest_ideal_string_subsequence.h"

TEST(TestLongestIdealStringSubsequence, simple1_top_down) {
    std::string input{"acfgbd"};
    constexpr int k{2};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, longest_ideal_string_top_down(input, k));
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_TEST_LONGEST_IDEAL_STRING_SUBSEQUENCE_CPP
