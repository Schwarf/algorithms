//
// Created by andreas on 19.04.25.
//

#include "./../minimum_swaps_to_make_alternating_pattern.h"
#include "gtest/gtest.h"

TEST(TestMinimumSwapsToMakeAlternatingPattern, simple1)
{
    std::string input{"111000"};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, minimum_swaps_to_make_alternate_pattern(input));
}

TEST(TestMinimumSwapsToMakeAlternatingPattern, simple2)
{
    std::string input{"010"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, minimum_swaps_to_make_alternate_pattern(input));
}

TEST(TestMinimumSwapsToMakeAlternatingPattern, simple3)
{
    std::string input{"1"};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, minimum_swaps_to_make_alternate_pattern(input));
}

TEST(TestMinimumSwapsToMakeAlternatingPattern, simple4)
{
    std::string input{"11"};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, minimum_swaps_to_make_alternate_pattern(input));
}


TEST(TestMinimumSwapsToMakeAlternatingPattern, simple5)
{
    std::string input{"1101"};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, minimum_swaps_to_make_alternate_pattern(input));
}

TEST(TestMinimumSwapsToMakeAlternatingPattern, complex1)
{
    std::string input{
        "1110000000100001010100101010000101010101001000001110101000010111101100000111110001000111010111101100001100001001100101011110100011111100000000100011111011110111111011110111010100111101011111111101101100101010110000011110110100101111000100000001100000"
    };
    constexpr int expected_result{60};
    EXPECT_EQ(expected_result, minimum_swaps_to_make_alternate_pattern(input));
}
