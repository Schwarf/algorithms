//
// Created by andreas on 15.02.25.
//
#include "gtest/gtest.h"
#include "./../construct_lexicographically_largest_sequence.h"


TEST(TestConstructLexicographicallyLargestSequence, simple1)
{
    constexpr int n{2};
    const std::vector<int> expected_result{2, 1, 2};
    EXPECT_EQ(expected_result, construct_distanced_sequence(n));
}

TEST(TestConstructLexicographicallyLargestSequence, simple2)
{
    constexpr int n{3};
    const std::vector<int> expected_result{3, 1, 2, 3, 2};
    EXPECT_EQ(expected_result, construct_distanced_sequence(n));
}

TEST(TestConstructLexicographicallyLargestSequence, simple3)
{
    constexpr int n{5};
    const std::vector<int> expected_result{5, 3, 1, 4, 3, 5, 2, 4, 2};
    EXPECT_EQ(expected_result, construct_distanced_sequence(n));
}

TEST(TestConstructLexicographicallyLargestSequence, simple4)
{
    constexpr int n{10};
    const std::vector<int> expected_result{10, 8, 6, 9, 3, 1, 7, 3, 6, 8, 10, 5, 9, 7, 4, 2, 5, 2, 4};
    EXPECT_EQ(expected_result, construct_distanced_sequence(n));
}
