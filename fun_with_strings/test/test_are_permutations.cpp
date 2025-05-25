//
// Created by andreas on 25.05.25.
//
#include "./../are_permutations.h"
#include "gtest/gtest.h"

TEST(TestCeckPermutations, simple1)
{
    std::string input1{"12345678"};
    std::string input2{"12875634"};
    EXPECT_TRUE(are_permutations(input1, input2));
}

TEST(TestCeckPermutations, simple2)
{
    std::string input1{"12"};
    std::string input2{"1"};
    EXPECT_FALSE(are_permutations(input1, input2));
}

TEST(TestCeckPermutations, simple3)
{
    std::string input1{"aba"};
    std::string input2{"aab"};
    EXPECT_TRUE(are_permutations(input1, input2));
}

TEST(TestCeckPermutations, simple4)
{
    std::string input1{"aabbccdd"};
    std::string input2{"aaccbbee"};
    EXPECT_FALSE(are_permutations(input1, input2));
}

TEST(TestCeckPermutations, simple5)
{
    std::string input1{""};
    std::string input2{""};
    EXPECT_TRUE(are_permutations(input1, input2));
}

TEST(TestCeckPermutations, simple6)
{
    std::string input1{"h"};
    std::string input2{""};
    EXPECT_FALSE(are_permutations(input1, input2));
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

TEST(TestCeckPermutationsFasterButMemory, simple1)
{
    std::string input1{"12345678"};
    std::string input2{"12875634"};
    EXPECT_TRUE(are_permutations_faster_but_memory(input1, input2));
}

TEST(TestCeckPermutationsFasterButMemory, simple2)
{
    std::string input1{"12"};
    std::string input2{"1"};
    EXPECT_FALSE(are_permutations_faster_but_memory(input1, input2));
}

TEST(TestCeckPermutationsFasterButMemory, simple3)
{
    std::string input1{"aba"};
    std::string input2{"aab"};
    EXPECT_TRUE(are_permutations_faster_but_memory(input1, input2));
}

TEST(TestCeckPermutationsFasterButMemory, simple4)
{
    std::string input1{"aabbccdd"};
    std::string input2{"aaccbbee"};
    EXPECT_FALSE(are_permutations_faster_but_memory(input1, input2));
}

TEST(TestCeckPermutationsFasterButMemory, simple5)
{
    std::string input1{""};
    std::string input2{""};
    EXPECT_TRUE(are_permutations_faster_but_memory(input1, input2));
}

TEST(TestCeckPermutationsFasterButMemory, simple6)
{
    std::string input1{"h"};
    std::string input2{""};
    EXPECT_FALSE(are_permutations_faster_but_memory(input1, input2));
}
