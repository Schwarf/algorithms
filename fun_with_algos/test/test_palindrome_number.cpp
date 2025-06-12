//
// Created by andreas on 12.06.25.
//
#include "gtest/gtest.h"
#include "./../palindrome_number.h"

TEST(TestPalindromNumber, simple1)
{
    constexpr int input{1};
    EXPECT_TRUE(is_palindrome_number(input));
}

TEST(TestPalindromNumber, simple2)
{
    constexpr int input{121};
    EXPECT_TRUE(is_palindrome_number(input));
}

TEST(TestPalindromNumber, simple3)
{
    constexpr int input{1991};
    EXPECT_TRUE(is_palindrome_number(input));
}

TEST(TestPalindromNumber, simple4)
{
    constexpr int input{19};
    EXPECT_FALSE(is_palindrome_number(input));
}

TEST(TestPalindromNumber, simple5)
{
    constexpr int input{-19};
    EXPECT_FALSE(is_palindrome_number(input));
}