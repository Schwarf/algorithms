//
// Created by andreas on 15.06.25.
//
#include "gtest/gtest.h"
#include "./../maximize_difference_by_replacing_digits.h"

TEST(TestMaximizeDifferenceByReplacingDigits, simple1)
{
    constexpr int input{555};
    constexpr int expected_result{888};
    EXPECT_EQ(expected_result, max_difference_by_replacing_digits(input));
}

TEST(TestMaximizeDifferenceByReplacingDigits, simple2)
{
    constexpr int input{4};
    constexpr int expected_result{8};
    EXPECT_EQ(expected_result, max_difference_by_replacing_digits(input));
}

TEST(TestMaximizeDifferenceByReplacingDigits, simple3)
{
    constexpr int input{190};
    constexpr int expected_result{890};
    EXPECT_EQ(expected_result, max_difference_by_replacing_digits(input));
}

TEST(TestMaximizeDifferenceByReplacingDigits, simple4)
{
    constexpr int input{9288};
    constexpr int expected_result{8700};
    EXPECT_EQ(expected_result, max_difference_by_replacing_digits(input));
}

TEST(TestMaximizeDifferenceByReplacingDigits, simple5)
{
    constexpr int input{1101057};
    constexpr int expected_result{8808050};
    EXPECT_EQ(expected_result, max_difference_by_replacing_digits(input));
}