//
// Created by andreas on 11.07.26.
//

#include <vector>

#include "../../sequence_chaining/maximum_sum_increasing_subsequence.h"
#include "gtest/gtest.h"

TEST(MaximumSumIncreasingSubsequence, empty_input)
{
    const std::vector<int> input{};
    constexpr int expected_result{};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, single_positive_element)
{
    const std::vector<int> input{7};
    constexpr int expected_result{7};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, single_negative_element)
{
    const std::vector<int> input{-7};
    constexpr int expected_result{-7};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, strictly_increasing_input_uses_all_elements)
{
    const std::vector<int> input{1, 2, 3, 4, 5};
    constexpr int expected_result{15};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, strictly_decreasing_input_uses_largest_single_element)
{
    const std::vector<int> input{9, 7, 5, 3, 1};
    constexpr int expected_result{9};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, duplicate_values_are_not_chained)
{
    const std::vector<int> input{1, 2, 2, 3};
    constexpr int expected_result{6};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, all_equal_values_use_one_element)
{
    const std::vector<int> input{4, 4, 4, 4};
    constexpr int expected_result{4};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, classic_example)
{
    const std::vector<int> input{1, 101, 2, 3, 100, 4, 5};
    constexpr int expected_result{106};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, maximum_sum_can_be_shorter_than_longest_subsequence)
{
    const std::vector<int> input{4, 6, 1, 3, 8, 4, 6};
    constexpr int expected_result{18};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, all_negative_values_use_least_negative_single_element)
{
    const std::vector<int> input{-5, -1, -3, -2};
    constexpr int expected_result{-1};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequence, mixed_negative_zero_and_positive_values)
{
    const std::vector<int> input{-1, 0, 1, -2, 2};
    constexpr int expected_result{3};

    EXPECT_EQ(expected_result, maximum_sum_increasing_subsequence(input));
}
