//
// Created by andreas on 15.05.25.
//
#include "./../sum_longest_subarray_with_unique_elements.h"
#include "gtest/gtest.h"

TEST(TestSumLongestSubarrayWithUniqueElements, simple1)
{
    std::vector<int> input{4, 2, 4, 5, 6};
    constexpr int expected_result{17};
    EXPECT_EQ(sum_longest_subarray_with_unique_elements(input), expected_result);
}

TEST(TestSumLongestSubarrayWithUniqueElements, simple2)
{
    std::vector<int> input{5, 2, 1, 2, 5, 2, 1, 2, 5};
    constexpr int expected_result{8};
    EXPECT_EQ(sum_longest_subarray_with_unique_elements(input), expected_result);
}

TEST(TestSumLongestSubarrayWithUniqueElements, simple3)
{
    std::vector<int> input{558, 508, 782, 32, 187, 103, 370, 607, 619, 267, 984, 10};
    constexpr int expected_result{5027};
    EXPECT_EQ(sum_longest_subarray_with_unique_elements(input), expected_result);
}

TEST(TestSumLongestSubarrayWithUniqueElements, simple4)
{
    std::vector<int> input{558, 508, 782, 32, 187, 103, 370, 607, 619, 267, 984, 10};
    constexpr int expected_result{5027};
    EXPECT_EQ(sum_longest_subarray_with_unique_elements(input), expected_result);
}

TEST(TestSumLongestSubarrayWithUniqueElements, simple5)
{
    std::vector<int> input{
        187, 470, 25, 436, 538, 809, 441, 167, 477, 110, 275, 133, 666, 345, 411, 459, 490, 266, 987, 965, 429, 166,
        809, 340, 467, 318, 125, 165, 809, 610, 31, 585, 970, 306, 42, 189, 169, 743, 78, 810, 70, 382, 367, 490, 787,
        670, 476, 278, 775, 673, 299, 19, 893, 817, 971, 458, 409, 886, 434
    };
    constexpr int expected_result{16911};
    EXPECT_EQ(sum_longest_subarray_with_unique_elements(input), expected_result);
}
