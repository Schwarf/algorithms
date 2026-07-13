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
    std::string input{"111000000010000101010010101000010101010100100000111010100001011110110000011111000100011101011110"
                      "110000110000100110010101111010001111110000000010001111101111011111101111011101010011110101111111"
                      "1101101100101010110000011110110100101111000100000001100000"};
    constexpr int expected_result{60};
    EXPECT_EQ(expected_result, minimum_swaps_to_make_alternate_pattern(input));
}
