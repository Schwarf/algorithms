//
// Created by andreas on 27.12.24.
//
#include "maximize_index_value_pair.h"
#include "gtest/gtest.h"

TEST(TestMaxValuePair, simple1)
{
    std::vector<int> input{8, 1, 5, 2, 6};
    constexpr int expected_result{11};
    EXPECT_EQ(expected_result, max_index_value_pair(input));
}

TEST(TestMaxValuePair, simple2)
{
    std::vector<int> input{2, 1};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, max_index_value_pair(input));
}

TEST(TestMaxValuePair, simple3)
{
    std::vector<int> input{1, 2};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, max_index_value_pair(input));
}

TEST(TestMaxValuePair, medium1)
{
    std::vector<int> input{
        79, 27, 14, 31, 4, 36, 2, 61, 30, 74, 35, 65, 31, 43, 92, 15, 11, 22, 76, 81, 55, 72, 92, 10, 86, 25, 64, 28,
        12, 43
    };
    constexpr int expected_result{176};
    EXPECT_EQ(expected_result, max_index_value_pair(input));
}

TEST(TestMaxValuePair, complex1)
{
    std::vector<int> input{
        30, 13, 28, 32, 16, 8, 11, 78, 83, 5, 22, 93, 61, 60, 100, 8, 6, 48, 87, 43, 41, 86, 93, 5, 19, 29, 59, 31, 7,
        51, 99, 47, 40, 24, 20, 98, 41, 42, 81, 92, 55, 85, 51, 92, 84, 21, 84, 92, 1, 73, 93, 51, 44, 27, 23, 54, 32,
        57, 60, 9, 69, 14, 28, 86, 15, 92, 47, 63, 12, 99, 54, 6, 16, 52, 28, 86, 38, 73, 16, 52, 37, 30, 84, 81, 46,
        97, 84, 17, 21, 14, 52, 19, 74, 20, 20, 56, 89, 7, 34, 21
    };
    constexpr int expected_result{192};
    EXPECT_EQ(expected_result, max_index_value_pair(input));
}
