//
// Created by andreas on 10.11.24.
//

#ifndef TEST_ARE_STRINGS_EQUAL_UPTO_ROTATION_H
#define TEST_ARE_STRINGS_EQUAL_UPTO_ROTATION_H
#include "gtest/gtest.h"
#include "./../are_strings_equal_upto_rotation.h"


TEST(AreStringsRotateEqualBruteForce, simple1)
{
    std::string input1{"abcdef"};
    std::string target_string{"bcdefg"};
    EXPECT_FALSE(are_strings_equal_brute_force(input1, target_string));
}

TEST(AreStringsRotateEqualBruteForce, simple2)
{
    std::string input1{"a"};
    std::string target_string{"bas"};
    EXPECT_FALSE(are_strings_equal_brute_force(input1, target_string));
}

TEST(AreStringsRotateEqualBruteForce, simple3)
{
    std::string input1{"asb"};
    std::string target_string{"bas"};
    EXPECT_TRUE(are_strings_equal_brute_force(input1, target_string));
}

TEST(AreStringsRotateEqualBruteForce, simple4)
{
    std::string input1{"asb"};
    std::string target_string{"bas"};
    EXPECT_TRUE(are_strings_equal_brute_force(input1, target_string));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(AreStringsRotateEqualDoubleString, simple1)
{
    std::string input1{"abcdef"};
    std::string target_string{"bcdefg"};
    EXPECT_FALSE(are_strings_equal_double_string(input1, target_string));
}

TEST(AreStringsRotateEqualDoubleString, simple2)
{
    std::string input1{"a"};
    std::string target_string{"bas"};
    EXPECT_FALSE(are_strings_equal_double_string(input1, target_string));
}

TEST(AreStringsRotateEqualDoubleString, simple3)
{
    std::string input1{"asb"};
    std::string target_string{"bas"};
    EXPECT_TRUE(are_strings_equal_double_string(input1, target_string));
}

TEST(AreStringsRotateEqualDoubleString, simple4)
{
    std::string input1{"asb"};
    std::string target_string{"bas"};
    EXPECT_TRUE(are_strings_equal_double_string(input1, target_string));
}

#endif //TEST_ARE_STRINGS_EQUAL_UPTO_ROTATION_H
