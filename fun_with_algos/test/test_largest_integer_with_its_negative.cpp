//
// Created by andreas on 04.05.24.
//

#include "gtest/gtest.h"
#include "./../largest_integer_with_its_negative.h"

TEST(TestLargestIntegerAndItsNegative, simple1) {
    std::vector<int> input{-1, 2, -3, 3};
    constexpr int expected_result{3};
    EXPECT_EQ(largest_integer_with_its_negative(input), expected_result);
}

TEST(TestLargestIntegerAndItsNegative, simple2) {
    std::vector<int> input{-1, 10, 6, 7, -7, 1};
    constexpr int expected_result{7};
    EXPECT_EQ(largest_integer_with_its_negative(input), expected_result);
}

TEST(TestLargestIntegerAndItsNegative, simple3) {
    std::vector<int> input{-10, 8, 6, 7, -2, -3};
    constexpr int expected_result{-1};
    EXPECT_EQ(largest_integer_with_its_negative(input), expected_result);
}

TEST(TestLargestIntegerAndItsNegative, medium1) {
    std::vector<int> input{-977, -652, -793, 376, -70, 251, 891, 356, -843, 790, -64, -594, 768, 606, 231, -855, 363,
                           -823, -297, 460, -389, -249, -30, 869, -858, -684, -228, -807, -867, 620, 748, -278, 150,
                           -230, 528, 284, -446, 211, -922, 214, 501, 349, -636, -568, -337, 917, -417, 875, -609, 516,
                           28, 334, -938, 641, 475, -506, -378, -631, 306, 901, -672, 633, -7, 272, -344, -853, -335,
                           -193, 380, -77, -961, 267, -350, -197, -518};
    constexpr int expected_result{-1};
    EXPECT_EQ(largest_integer_with_its_negative(input), expected_result);
}


TEST(TestLargestIntegerAndItsNegative, medium2) {
    std::vector<int> input{33, -12, -24, 22, 22, 25, -3, -21, -27, -49, 23, -14, 24, -30, 33, -16, 14, -39, 23, -21, 44,
                           -5, -28, 30, -16, 2, 13, 25, -5, 3, 13, 43, 39, 44, -3, 26, 50, 1, 23, 33, -4, 38, 2, -33,
                           -22, -20, 1, -39, 38, 37, -41, -33, -7, -23, 6, -23, -10, -26, 38, -31, -48, -20, -23, 8, 1,
                           -50, 47, 22, 33, -40, 49, 49, 24, 8, 25, -49, -25, -2};
    constexpr int expected_result{50};
    EXPECT_EQ(largest_integer_with_its_negative(input), expected_result);
}

TEST(TestLargestIntegerAndItsNegativeHashset, simple1) {
    std::vector<int> input{-1, 2, -3, 3};
    constexpr int expected_result{3};
    EXPECT_EQ(largest_integer_with_its_negative_hashset(input), expected_result);
}

TEST(TestLargestIntegerAndItsNegativeHashset, simple2) {
    std::vector<int> input{-1, 10, 6, 7, -7, 1};
    constexpr int expected_result{7};
    EXPECT_EQ(largest_integer_with_its_negative_hashset(input), expected_result);
}

TEST(TestLargestIntegerAndItsNegativeHashset, simple3) {
    std::vector<int> input{-10, 8, 6, 7, -2, -3};
    constexpr int expected_result{-1};
    EXPECT_EQ(largest_integer_with_its_negative_hashset(input), expected_result);
}

TEST(TestLargestIntegerAndItsNegativeHashset, medium1) {
    std::vector<int> input{-977, -652, -793, 376, -70, 251, 891, 356, -843, 790, -64, -594, 768, 606, 231, -855, 363,
                           -823, -297, 460, -389, -249, -30, 869, -858, -684, -228, -807, -867, 620, 748, -278, 150,
                           -230, 528, 284, -446, 211, -922, 214, 501, 349, -636, -568, -337, 917, -417, 875, -609, 516,
                           28, 334, -938, 641, 475, -506, -378, -631, 306, 901, -672, 633, -7, 272, -344, -853, -335,
                           -193, 380, -77, -961, 267, -350, -197, -518};
    constexpr int expected_result{-1};
    EXPECT_EQ(largest_integer_with_its_negative_hashset(input), expected_result);
}


TEST(TestLargestIntegerAndItsNegativeHashset, medium2) {
    std::vector<int> input{33, -12, -24, 22, 22, 25, -3, -21, -27, -49, 23, -14, 24, -30, 33, -16, 14, -39, 23, -21, 44,
                           -5, -28, 30, -16, 2, 13, 25, -5, 3, 13, 43, 39, 44, -3, 26, 50, 1, 23, 33, -4, 38, 2, -33,
                           -22, -20, 1, -39, 38, 37, -41, -33, -7, -23, 6, -23, -10, -26, 38, -31, -48, -20, -23, 8, 1,
                           -50, 47, 22, 33, -40, 49, 49, 24, 8, 25, -49, -25, -2};
    constexpr int expected_result{50};
    EXPECT_EQ(largest_integer_with_its_negative_hashset(input), expected_result);
}
