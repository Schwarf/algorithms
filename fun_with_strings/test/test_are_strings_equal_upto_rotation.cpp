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
    std::string input2{"bcdefg"};
    EXPECT_FALSE(are_strings_equal_brute_force(input1, input2));
}

TEST(AreStringsRotateEqualBruteForce, simple2)
{
    std::string input1{"a"};
    std::string input2{"bas"};
    EXPECT_FALSE(are_strings_equal_brute_force(input1, input2));
}

TEST(AreStringsRotateEqualBruteForce, simple3)
{
    std::string input1{"asb"};
    std::string input2{"bas"};
    EXPECT_TRUE(are_strings_equal_brute_force(input1, input2));
}

TEST(AreStringsRotateEqualBruteForce, simple4)
{
    std::string input1{"asb"};
    std::string input2{"bas"};
    EXPECT_TRUE(are_strings_equal_brute_force(input1, input2));
}

#endif //TEST_ARE_STRINGS_EQUAL_UPTO_ROTATION_H
