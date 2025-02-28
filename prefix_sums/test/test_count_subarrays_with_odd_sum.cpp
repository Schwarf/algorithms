//
// Created by andreas on 25.02.25.
//

#include "./../count_subarrays_with_odd_sum.h"
#include "gtest/gtest.h"

TEST(TestCountSubarraysWithOddSumBruteForce, simple1)
{
    std::vector<int> input{1, 3, 5};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, count_odd_subarray_sums_brute_force(input));
}


TEST(TestCountSubarraysWithOddSumBruteForce, simple2)
{
    std::vector<int> input{2, 4, 6};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, count_odd_subarray_sums_brute_force(input));
}

TEST(TestCountSubarraysWithOddSumBruteForce, simple3)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7};
    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, count_odd_subarray_sums_brute_force(input));
}

TEST(TestCountSubarraysWithOddSumBruteForce, complex1)
{
    std::vector<int> input{
        11, 75, 93, 70, 47, 99, 49, 12, 15, 88, 81, 61, 31, 61, 65, 61, 5, 90, 6, 65, 55, 82, 38, 64, 31, 42, 81, 91, 7,
        30, 33, 87, 43, 54, 62, 41, 67, 46, 94, 64, 45, 45, 67, 46, 13, 50, 19, 52, 28, 80, 35, 97, 72, 38, 96, 61, 31,
        42, 80, 36, 96, 25, 22, 69, 31, 98, 33, 98, 100, 62, 34, 37, 45, 42, 29, 79, 78, 50, 18, 2, 52, 56, 58, 45, 96,
        78, 8, 54, 29, 39, 45, 58, 70, 33, 20, 59, 92, 1, 43, 25, 1, 35, 93, 3, 48, 58, 34, 6
    };
    constexpr int expected_result{2928};
    EXPECT_EQ(expected_result, count_odd_subarray_sums_brute_force(input));
}


TEST(TestCountSubarraysWithOddSumBruteForce, complex2)
{
    std::vector<int> input{
        81, 22, 84, 15, 82, 17, 45, 47, 95, 52, 92, 40, 69, 9, 76, 75, 79, 80, 24, 45, 27, 56, 18, 6, 13, 85, 52, 14,
        58, 42, 69, 4, 56, 64, 13, 72, 75, 74, 8, 46, 71, 73, 57, 23, 49, 75, 94, 5, 48, 67, 83, 66, 22, 81, 96, 41, 64,
        32, 12, 73, 21, 74, 12, 75, 100, 29, 30, 29, 65, 37, 69, 58, 48, 12, 12, 49, 41, 91, 42, 47, 20, 86, 48, 100,
        62, 64, 91, 33, 9, 45, 16, 90, 48, 65, 46, 66, 75, 95, 37, 75, 85, 56, 66, 73, 12, 75, 42, 85, 89, 85, 10, 19,
        50, 76, 16, 43, 35, 39, 17, 57, 35, 42, 19, 82, 12, 4, 43, 73, 22, 70, 35, 2, 67, 86, 13, 67, 62, 57, 87, 35,
        83, 7, 78, 62, 35, 21, 20, 66, 43, 58, 13, 41, 52, 83, 73, 4, 10, 71, 86, 90, 90, 88, 83, 31, 49, 19, 91, 38,
        40, 85, 44, 43, 27, 11, 7, 44, 85, 95, 82, 18, 12, 78, 99, 34, 42, 15, 65, 84, 43, 80, 38, 88, 11, 96, 43, 3, 5,
        96, 34, 36, 61, 40, 81, 20, 13, 40, 58, 97, 79, 81, 94, 96, 28, 25, 46, 23, 75, 33, 78, 89, 80, 1, 65, 48, 64,
        96, 28, 4, 30, 60, 88, 35, 78, 65, 7, 78, 10, 73, 74, 44, 72, 84, 10, 41, 3, 41, 65, 11, 82, 57, 78, 88, 27, 29,
        55, 64, 47, 38, 69, 25, 98, 16, 76, 83, 49, 44, 2, 31, 12, 47, 20, 72, 77, 25, 55, 30, 58, 48, 77, 53, 83, 77,
        35, 65, 10, 50, 13, 4, 87, 62, 51, 27, 38, 54, 69, 16, 86, 86, 1, 74, 93, 65, 1, 98, 68, 92, 85, 98, 44, 62, 73,
        38, 57, 1, 49, 71, 76, 30, 61, 18, 4, 45, 28, 11, 58, 68, 28, 25, 28, 92, 12, 27, 51, 74, 12, 88, 91, 83, 55,
        80, 13, 50, 50, 89, 60, 64, 35, 77, 23, 95, 38, 60, 1, 6, 78, 76, 11, 22, 91, 50, 46, 85, 20, 93, 11, 53, 94,
        45, 72, 47, 87, 37, 24, 2, 16, 9, 19, 79, 87, 99, 2, 5, 39, 86, 60, 42, 34, 11, 29, 95, 30, 26, 11, 49, 85, 88,
        46, 25, 54, 59, 12, 22, 19, 39, 3, 5, 45, 13, 96, 97, 85, 41, 34, 24, 63, 100, 3, 29, 49, 19, 93, 54, 38, 64,
        55, 72, 59, 21, 8, 16, 44, 15, 55, 96, 46, 41, 88, 82, 20, 46, 65, 78, 34, 15, 69, 11, 67, 29, 34, 98, 67, 11,
        47, 73, 57, 32, 18, 32, 41, 40, 60, 9, 65, 29, 94, 74, 34, 78, 68, 92, 84, 5, 27, 86, 17, 12, 85, 36, 91, 34,
        37, 21, 87, 76, 40, 67, 88, 96, 16, 42, 99, 8, 44, 79, 4, 87, 80, 80, 84, 8, 46, 14, 27, 83, 60, 54, 91, 63, 39,
        33, 100, 75, 26, 66, 26, 8, 47, 60, 63, 42, 66, 8, 25, 58, 71, 21, 51, 4, 90, 79, 93, 89, 21, 42, 100, 77, 82,
        41, 66, 55, 71, 66, 79, 39, 93, 80, 54, 1, 27, 11, 59, 43, 9, 18, 53, 75, 34, 16, 41, 36, 100, 24, 24, 4, 37,
        32, 49, 13, 65, 60, 57, 34, 95, 20, 21, 42, 30, 74, 80, 91, 92, 10, 21, 48, 58, 7, 48, 47, 99, 37, 27, 8, 5, 88,
        1, 18, 56, 38, 33, 86, 53, 28, 70, 27, 22, 12, 94, 88, 97, 7, 63, 87, 11, 82, 80, 93, 64, 26, 46, 25, 50, 68,
        98, 82, 62, 23, 34, 100, 17, 88, 37, 24, 73, 33, 99, 16, 39, 91, 33, 35, 38, 51, 85, 12, 79, 88, 76, 82, 73, 53,
        56, 2, 79, 65, 48, 78, 54, 7, 72, 85, 4, 83, 63, 57, 45, 75, 63, 54, 18, 88, 54, 56, 75, 4, 83, 87, 74, 70, 30,
        74, 83, 79, 17, 4, 43, 50, 86, 95, 91, 24, 46, 38, 37, 6, 52, 84, 98, 66, 33, 19, 87, 68, 48, 22, 54, 93, 13,
        85, 59, 41, 71, 51, 78, 30, 22, 25, 85, 100, 83, 81, 78, 14, 96, 11, 91, 13, 42, 50, 39, 54, 87, 66, 6, 42, 96,
        32, 9, 5, 81, 91, 11, 5, 53, 19, 8, 25, 29, 19, 57, 54, 98, 80, 44, 63, 58, 92, 27, 91, 70, 29, 2, 91, 3, 92,
        16, 45, 3, 61, 43, 2, 12, 79, 94, 48, 55, 67, 23, 11, 38, 11, 50, 53, 92, 80, 77, 93, 77, 6, 11, 41, 49, 60, 26,
        45, 82, 86, 70, 70, 20, 4, 80, 82, 80, 5, 25, 12, 66, 77, 9, 92, 40, 87, 84, 72, 96, 77, 97, 32, 88, 22, 50, 18,
        91, 29, 72, 54, 24, 49, 8, 61, 77, 18, 21, 39, 6, 63, 56, 99, 32, 80, 39, 2, 9, 3, 3, 2, 20, 71, 80, 73, 57, 13,
        76, 74, 10, 78, 78, 37, 27, 85, 37, 86, 82, 37, 78, 39, 17, 76, 40, 84, 11, 96, 37, 22, 58, 20, 42, 10, 93, 7,
        12, 75, 24, 10, 50, 54, 35, 2, 27, 16, 41, 46, 19, 99, 26, 30, 24, 33, 70, 93, 1, 89, 20, 98, 98, 71, 39, 91,
        50, 74, 19, 86, 25, 8, 94, 50, 99, 98, 63, 54, 57, 94, 21, 84, 30, 54, 53, 90, 69, 43, 86, 39, 26, 22, 39, 87,
        76, 98, 28, 49, 91, 59, 65, 93, 55, 4, 99, 50, 96, 78, 53, 85, 12, 75, 97, 92, 55, 9, 59, 95, 89, 20, 28, 45,
        69, 51, 97, 100, 24, 86, 36, 37, 39, 97, 84, 45, 95, 21, 36, 13, 45, 45, 86, 50, 93, 24, 31, 8, 56, 83, 92, 43,
        93, 10, 85, 15, 6, 24, 46, 54, 85
    };
    constexpr int expected_result{250976};
    EXPECT_EQ(expected_result, count_odd_subarray_sums_brute_force(input));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(TestCountSubarraysWithOddSum, simple1)
{
    std::vector<int> input{1, 3, 5};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, count_odd_subarray_sums(input));
}


TEST(TestCountSubarraysWithOddSum, simple2)
{
    std::vector<int> input{2, 4, 6};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, count_odd_subarray_sums(input));
}

TEST(TestCountSubarraysWithOddSum, simple3)
{
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7};
    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, count_odd_subarray_sums(input));
}

TEST(TestCountSubarraysWithOddSum, complex1)
{
    std::vector<int> input{
        11, 75, 93, 70, 47, 99, 49, 12, 15, 88, 81, 61, 31, 61, 65, 61, 5, 90, 6, 65, 55, 82, 38, 64, 31, 42, 81, 91, 7,
        30, 33, 87, 43, 54, 62, 41, 67, 46, 94, 64, 45, 45, 67, 46, 13, 50, 19, 52, 28, 80, 35, 97, 72, 38, 96, 61, 31,
        42, 80, 36, 96, 25, 22, 69, 31, 98, 33, 98, 100, 62, 34, 37, 45, 42, 29, 79, 78, 50, 18, 2, 52, 56, 58, 45, 96,
        78, 8, 54, 29, 39, 45, 58, 70, 33, 20, 59, 92, 1, 43, 25, 1, 35, 93, 3, 48, 58, 34, 6
    };
    constexpr int expected_result{2928};
    EXPECT_EQ(expected_result, count_odd_subarray_sums(input));
}


TEST(TestCountSubarraysWithOddSum, complex2)
{
    std::vector<int> input{
        81, 22, 84, 15, 82, 17, 45, 47, 95, 52, 92, 40, 69, 9, 76, 75, 79, 80, 24, 45, 27, 56, 18, 6, 13, 85, 52, 14,
        58, 42, 69, 4, 56, 64, 13, 72, 75, 74, 8, 46, 71, 73, 57, 23, 49, 75, 94, 5, 48, 67, 83, 66, 22, 81, 96, 41, 64,
        32, 12, 73, 21, 74, 12, 75, 100, 29, 30, 29, 65, 37, 69, 58, 48, 12, 12, 49, 41, 91, 42, 47, 20, 86, 48, 100,
        62, 64, 91, 33, 9, 45, 16, 90, 48, 65, 46, 66, 75, 95, 37, 75, 85, 56, 66, 73, 12, 75, 42, 85, 89, 85, 10, 19,
        50, 76, 16, 43, 35, 39, 17, 57, 35, 42, 19, 82, 12, 4, 43, 73, 22, 70, 35, 2, 67, 86, 13, 67, 62, 57, 87, 35,
        83, 7, 78, 62, 35, 21, 20, 66, 43, 58, 13, 41, 52, 83, 73, 4, 10, 71, 86, 90, 90, 88, 83, 31, 49, 19, 91, 38,
        40, 85, 44, 43, 27, 11, 7, 44, 85, 95, 82, 18, 12, 78, 99, 34, 42, 15, 65, 84, 43, 80, 38, 88, 11, 96, 43, 3, 5,
        96, 34, 36, 61, 40, 81, 20, 13, 40, 58, 97, 79, 81, 94, 96, 28, 25, 46, 23, 75, 33, 78, 89, 80, 1, 65, 48, 64,
        96, 28, 4, 30, 60, 88, 35, 78, 65, 7, 78, 10, 73, 74, 44, 72, 84, 10, 41, 3, 41, 65, 11, 82, 57, 78, 88, 27, 29,
        55, 64, 47, 38, 69, 25, 98, 16, 76, 83, 49, 44, 2, 31, 12, 47, 20, 72, 77, 25, 55, 30, 58, 48, 77, 53, 83, 77,
        35, 65, 10, 50, 13, 4, 87, 62, 51, 27, 38, 54, 69, 16, 86, 86, 1, 74, 93, 65, 1, 98, 68, 92, 85, 98, 44, 62, 73,
        38, 57, 1, 49, 71, 76, 30, 61, 18, 4, 45, 28, 11, 58, 68, 28, 25, 28, 92, 12, 27, 51, 74, 12, 88, 91, 83, 55,
        80, 13, 50, 50, 89, 60, 64, 35, 77, 23, 95, 38, 60, 1, 6, 78, 76, 11, 22, 91, 50, 46, 85, 20, 93, 11, 53, 94,
        45, 72, 47, 87, 37, 24, 2, 16, 9, 19, 79, 87, 99, 2, 5, 39, 86, 60, 42, 34, 11, 29, 95, 30, 26, 11, 49, 85, 88,
        46, 25, 54, 59, 12, 22, 19, 39, 3, 5, 45, 13, 96, 97, 85, 41, 34, 24, 63, 100, 3, 29, 49, 19, 93, 54, 38, 64,
        55, 72, 59, 21, 8, 16, 44, 15, 55, 96, 46, 41, 88, 82, 20, 46, 65, 78, 34, 15, 69, 11, 67, 29, 34, 98, 67, 11,
        47, 73, 57, 32, 18, 32, 41, 40, 60, 9, 65, 29, 94, 74, 34, 78, 68, 92, 84, 5, 27, 86, 17, 12, 85, 36, 91, 34,
        37, 21, 87, 76, 40, 67, 88, 96, 16, 42, 99, 8, 44, 79, 4, 87, 80, 80, 84, 8, 46, 14, 27, 83, 60, 54, 91, 63, 39,
        33, 100, 75, 26, 66, 26, 8, 47, 60, 63, 42, 66, 8, 25, 58, 71, 21, 51, 4, 90, 79, 93, 89, 21, 42, 100, 77, 82,
        41, 66, 55, 71, 66, 79, 39, 93, 80, 54, 1, 27, 11, 59, 43, 9, 18, 53, 75, 34, 16, 41, 36, 100, 24, 24, 4, 37,
        32, 49, 13, 65, 60, 57, 34, 95, 20, 21, 42, 30, 74, 80, 91, 92, 10, 21, 48, 58, 7, 48, 47, 99, 37, 27, 8, 5, 88,
        1, 18, 56, 38, 33, 86, 53, 28, 70, 27, 22, 12, 94, 88, 97, 7, 63, 87, 11, 82, 80, 93, 64, 26, 46, 25, 50, 68,
        98, 82, 62, 23, 34, 100, 17, 88, 37, 24, 73, 33, 99, 16, 39, 91, 33, 35, 38, 51, 85, 12, 79, 88, 76, 82, 73, 53,
        56, 2, 79, 65, 48, 78, 54, 7, 72, 85, 4, 83, 63, 57, 45, 75, 63, 54, 18, 88, 54, 56, 75, 4, 83, 87, 74, 70, 30,
        74, 83, 79, 17, 4, 43, 50, 86, 95, 91, 24, 46, 38, 37, 6, 52, 84, 98, 66, 33, 19, 87, 68, 48, 22, 54, 93, 13,
        85, 59, 41, 71, 51, 78, 30, 22, 25, 85, 100, 83, 81, 78, 14, 96, 11, 91, 13, 42, 50, 39, 54, 87, 66, 6, 42, 96,
        32, 9, 5, 81, 91, 11, 5, 53, 19, 8, 25, 29, 19, 57, 54, 98, 80, 44, 63, 58, 92, 27, 91, 70, 29, 2, 91, 3, 92,
        16, 45, 3, 61, 43, 2, 12, 79, 94, 48, 55, 67, 23, 11, 38, 11, 50, 53, 92, 80, 77, 93, 77, 6, 11, 41, 49, 60, 26,
        45, 82, 86, 70, 70, 20, 4, 80, 82, 80, 5, 25, 12, 66, 77, 9, 92, 40, 87, 84, 72, 96, 77, 97, 32, 88, 22, 50, 18,
        91, 29, 72, 54, 24, 49, 8, 61, 77, 18, 21, 39, 6, 63, 56, 99, 32, 80, 39, 2, 9, 3, 3, 2, 20, 71, 80, 73, 57, 13,
        76, 74, 10, 78, 78, 37, 27, 85, 37, 86, 82, 37, 78, 39, 17, 76, 40, 84, 11, 96, 37, 22, 58, 20, 42, 10, 93, 7,
        12, 75, 24, 10, 50, 54, 35, 2, 27, 16, 41, 46, 19, 99, 26, 30, 24, 33, 70, 93, 1, 89, 20, 98, 98, 71, 39, 91,
        50, 74, 19, 86, 25, 8, 94, 50, 99, 98, 63, 54, 57, 94, 21, 84, 30, 54, 53, 90, 69, 43, 86, 39, 26, 22, 39, 87,
        76, 98, 28, 49, 91, 59, 65, 93, 55, 4, 99, 50, 96, 78, 53, 85, 12, 75, 97, 92, 55, 9, 59, 95, 89, 20, 28, 45,
        69, 51, 97, 100, 24, 86, 36, 37, 39, 97, 84, 45, 95, 21, 36, 13, 45, 45, 86, 50, 93, 24, 31, 8, 56, 83, 92, 43,
        93, 10, 85, 15, 6, 24, 46, 54, 85
    };
    constexpr int expected_result{250976};
    EXPECT_EQ(expected_result, count_odd_subarray_sums(input));
}
