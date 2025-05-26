//
// Created by andreas on 26.05.25.
//

#include "./../are_two_strings_one_edit_away.h"
#include "gtest/gtest.h"

TEST(TestAreStringsOneEditAway, simple1)
{
    std::string input1 = "pale";
    std::string input2 = "ple";
    EXPECT_TRUE(are_one_edit_away(input1, input2));
}

TEST(TestAreStringsOneEditAway, simple2)
{
    std::string input1 = "pale";
    std::string input2 = "bale";
    EXPECT_TRUE(are_one_edit_away(input1, input2));
}

TEST(TestAreStringsOneEditAway, simple3)
{
    std::string input1 = "pales";
    std::string input2 = "pale";
    EXPECT_TRUE(are_one_edit_away(input1, input2));
}

TEST(TestAreStringsOneEditAway, simple4)
{
    std::string input1 = "ale";
    std::string input2 = "pale";
    EXPECT_TRUE(are_one_edit_away(input1, input2));
}

TEST(TestAreStringsOneEditAway, simple5)
{
    std::string input1 = "bales";
    std::string input2 = "pale";
    EXPECT_FALSE(are_one_edit_away(input1, input2));
}

