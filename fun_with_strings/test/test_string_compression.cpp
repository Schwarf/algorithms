//
// Created by andreas on 26.05.25.
//
#include "./../string_compression.h"
#include "gtest/gtest.h"

TEST(TestStringCompression, simple1)
{
     std::string input{"aaabbcc"};
     std::string expected_result{"3a2b2c"};
     EXPECT_EQ(compression(input), expected_result);
}

TEST(TestStringCompression, simple2)
{
     std::string input{"abc"};
     std::string expected_result{"abc"};
     EXPECT_EQ(compression(input), expected_result);
}

TEST(TestStringCompression, simple3)
{
     std::string input{"aabbcc"};
     std::string expected_result{"aabbcc"};
     EXPECT_EQ(compression(input), expected_result);
}

TEST(TestStringCompression, simple4)
{
     std::string input{""};
     std::string expected_result{""};
     EXPECT_EQ(compression(input), expected_result);
}
