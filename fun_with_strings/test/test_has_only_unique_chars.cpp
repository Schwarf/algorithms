//
// Created by andreas on 25.05.25.
//
#include "./../has_only_unique_characters.h"
#include "gtest/gtest.h"

TEST(TestHasOnlyUniqueChars, simple1)
{
    std::string input{"1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./"};
    EXPECT_TRUE(has_unique_chars(input));
}

TEST(TestHasOnlyUniqueChars, simple2)
{
    std::string input{"12345678901"};
    EXPECT_FALSE(has_unique_chars(input));
}

TEST(TestHasOnlyUniqueChars, simple3)
{
    std::string input{""};
    EXPECT_TRUE(has_unique_chars(input));
}

TEST(TestHasOnlyUniqueChars, simple4)
{
    std::string input{"AabB"};
    EXPECT_TRUE(has_unique_chars(input));
}

TEST(TestHasOnlyUniqueChars, simple5)
{
    std::string input{"!1"};
    EXPECT_TRUE(has_unique_chars(input));
}

//////////////////////////////////////////////////////////

TEST(TestHasOnlyUniqueCharsNoAdditionalMemory, simple1)
{
    std::string input{"1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./"};
    EXPECT_TRUE(has_unique_chars_no_additional_memory(input));
}

TEST(TestHasOnlyUniqueCharsNoAdditionalMemory, simple2)
{
    std::string input{"12345678901"};
    EXPECT_FALSE(has_unique_chars_no_additional_memory(input));
}

TEST(TestHasOnlyUniqueCharsNoAdditionalMemory, simple3)
{
    std::string input{""};
    EXPECT_TRUE(has_unique_chars_no_additional_memory(input));
}

TEST(TestHasOnlyUniqueCharsNoAdditionalMemory, simple4)
{
    std::string input{"AabB"};
    EXPECT_TRUE(has_unique_chars_no_additional_memory(input));
}

TEST(TestHasOnlyUniqueCharsNoAdditionalMemory, simple5)
{
    std::string input{"!1"};
    EXPECT_TRUE(has_unique_chars_no_additional_memory(input));
}
