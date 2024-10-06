//
// Created by andreas on 06.10.24.
//
#include "gtest/gtest.h"
#include "./../permutation_included_in_string.h"

TEST(TestPermutationIncludedInString, simple1)
{
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    EXPECT_TRUE(check_if_permutation_included(s1, s2));
}

TEST(TestPermutationIncludedInString, simple2)
{
    std::string s1 = "ab";
    std::string s2 = "eidbhooo";
    EXPECT_FALSE(check_if_permutation_included(s1, s2));
}


TEST(TestPermutationIncludedInString, simple3)
{
    std::string s1 = "logo";
    std::string s2 = "el golo per dato";
    EXPECT_TRUE(check_if_permutation_included(s1, s2));
}

TEST(TestPermutationIncludedInString, simple4)
{
    std::string s1 = "maoam";
    std::string s2 = "maoam";
    EXPECT_TRUE(check_if_permutation_included(s1, s2));
}

TEST(TestPermutationIncludedInString, simple5)
{
    std::string s1 = "hallo";
    std::string s2 = "hall";
    EXPECT_FALSE(check_if_permutation_included(s1, s2));
}
