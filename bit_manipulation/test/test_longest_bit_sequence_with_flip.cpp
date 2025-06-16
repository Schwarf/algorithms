//
// Created by andreas on 16.06.25.
//
#include "gtest/gtest.h"
#include "./../longest_bit_sequence_with_flip.h"

TEST(TestLongestBitSequenceWithFlip, simple1)
{
    constexpr int input{1775};
    constexpr int expected_result{8};
    EXPECT_EQ(expected_result, longest_bit_sequence_with_flip(input));
}

TEST(TestLongestBitSequenceWithFlip, simple2)
{
    constexpr int input{0b1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, longest_bit_sequence_with_flip(input));
}

TEST(TestLongestBitSequenceWithFlip, simple3)
{
    constexpr int input{0b101};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, longest_bit_sequence_with_flip(input));
}

TEST(TestLongestBitSequenceWithFlip, simple4)
{
    constexpr int input{0b1001};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, longest_bit_sequence_with_flip(input));
}

TEST(TestLongestBitSequenceWithFlip, simple5)
{
    constexpr int input{0b1111};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, longest_bit_sequence_with_flip(input));
}

TEST(TestLongestBitSequenceWithFlip, simple6)
{
    constexpr int input{0};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, longest_bit_sequence_with_flip(input));
}
