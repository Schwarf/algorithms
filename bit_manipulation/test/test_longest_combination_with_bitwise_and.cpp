//
// Created by andreas on 16.11.24.
//
#include "longest_combination_with_bitwise_and.h"
#include "gtest/gtest.h"

TEST(TestLongetsCombinationWithBitwiseAnd, simple1)
{
    std::vector<int> input{16, 17, 71, 62, 12, 24, 14};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, longest_combination_bitwise_and(input));
}

TEST(TestLongetsCombinationWithBitwiseAnd, simple2)
{
    std::vector<int> input{7, 7};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, longest_combination_bitwise_and(input));
}


TEST(TestLongetsCombinationWithBitwiseAnd, simple3)
{
    std::vector<int> input{12};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, longest_combination_bitwise_and(input));
}

TEST(TestLongetsCombinationWithBitwiseAnd, simple4)
{
    std::vector<int> input{1, 2, 4, 8, 16, 32};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, longest_combination_bitwise_and(input));
}

TEST(TestLongetsCombinationWithBitwiseAnd, medium1)
{
    std::vector<int> input{
        56, 78, 75, 74, 98, 56, 76, 37, 97, 75, 10, 73, 75, 37, 86, 41, 20, 42, 28, 61, 85, 42, 6, 7, 32, 100, 24, 40,
        88, 98, 22, 83, 98, 80, 32, 64, 95, 8, 74, 53, 90, 56, 44, 23, 86, 40, 43, 57, 99, 82, 69, 21
    };
    constexpr int expected_result{27};
    EXPECT_EQ(expected_result, longest_combination_bitwise_and(input));
}


TEST(TestLongetsCombinationWithBitwiseAnd, medium2)
{
    std::vector<int> input{
        523, 316, 466, 52, 883, 256, 251, 435, 590, 139, 814, 905, 340, 334, 199, 579, 487, 72, 117, 455, 988, 719, 937,
        18, 532, 6, 953, 206, 830, 171, 669, 577, 337, 93, 508, 353, 450, 995, 890, 743, 874, 644, 440, 985, 460, 470,
        360, 478, 45, 879, 909, 264, 861, 238, 938, 154, 500, 677, 941, 883, 916, 239, 815, 241, 741, 126, 559, 49, 369,
        327, 959, 660, 362, 158, 568, 26, 703, 967, 208, 45, 146, 538, 474, 518, 59, 585, 438, 975, 632, 190, 85, 868,
        476, 360, 84, 840, 181, 617, 831, 369, 910, 708
    };
    constexpr int expected_result{59};
    EXPECT_EQ(expected_result, longest_combination_bitwise_and(input));
}
