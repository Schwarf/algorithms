//
// Created by andreas on 28.09.23.
//
#include "gtest/gtest.h"
#include "./../longest_common_subsequence.h"

TEST(TestLongesCommonSqubSequence, simple1) {
    const std::string input1{"ABCBDAB"};
    const std::string input2{"BDCAB"};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, longest_common_sub_sequence(input1, input2));
}

TEST(TestLongesCommonSqubSequence, simple2) {
    const std::string input1{"ABC"};
    const std::string input2{"BC"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, longest_common_sub_sequence(input1, input2));
}

TEST(TestLongesCommonSqubSequence, simple3) {
    const std::string input1{"CBA"};
    const std::string input2{"CDA"};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, longest_common_sub_sequence(input1, input2));
}
