//
// Created by andreas on 14.06.25.
//
#include "./../is_rotated_string.h"
#include "gtest/gtest.h"


TEST(TestIsRotatedString, simple1)
{
    EXPECT_TRUE(is_rotated_string("waterbottle", "erbottlewat"));
    EXPECT_TRUE(is_rotated_string("abcdef", "defabc"));
    EXPECT_TRUE(is_rotated_string("a", "a"));
}

TEST(TestIsRotatedString, simple2)
{
    EXPECT_FALSE(is_rotated_string("waterbottle", "bottlewaterx")); // wrong string
    EXPECT_FALSE(is_rotated_string("abcdef", "feabcd")); // not a rotation
    EXPECT_FALSE(is_rotated_string("a", "b"));
}

TEST(TestIsRotatedString, simpl3)
{
    EXPECT_FALSE(is_rotated_string("abc", "abcd"));
    EXPECT_FALSE(is_rotated_string("", "a"));
    EXPECT_FALSE(is_rotated_string("a", ""));
}

TEST(TestIsRotatedString, simpl4)
{
    EXPECT_FALSE(is_rotated_string("", ""));
}
