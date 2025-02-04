//
// Created by andreas on 03.02.25.
//
#include "./../decode_string.h"
#include "gtest/gtest.h"

TEST(TestDecodeString, simple1)
{
    const std::string input{"3[a]2[bc]"};
    const std::string expected_result{"aaabcbc"};
    EXPECT_EQ(expected_result, decode_string(input));
}

TEST(TestDecodeString, simple2)
{
    const std::string input{"3[a2[c]]"};
    const std::string expected_result{"accaccacc"};
    EXPECT_EQ(expected_result, decode_string(input));
}

TEST(TestDecodeString, simple3)
{
    const std::string input{"2[abc]3[cd]ef"};
    const std::string expected_result{"abcabccdcdcdef"};
    EXPECT_EQ(expected_result, decode_string(input));
}
