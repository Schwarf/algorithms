//
// Created by andreas on 20.07.26.
//

#include <vector>

#include "../../sequence_chaining/maximum_sum_increasing_subsequence_with_elements.h"
#include "gtest/gtest.h"

TEST(MaximumSumIncreasingSubsequenceWithElements, empty_input)
{
    const std::vector<int> input{};
    const std::vector<std::vector<int>> expected_result{{0}, {}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, single_positive_element)
{
    const std::vector<int> input{7};
    const std::vector<std::vector<int>> expected_result{{7}, {7}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, single_negative_element)
{
    const std::vector<int> input{-7};
    const std::vector<std::vector<int>> expected_result{{-7}, {-7}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, strictly_increasing_input_uses_all_elements)
{
    const std::vector<int> input{1, 2, 3, 4, 5};
    const std::vector<std::vector<int>> expected_result{{15}, {1, 2, 3, 4, 5}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, strictly_decreasing_input_uses_largest_single_element)
{
    const std::vector<int> input{9, 7, 5, 3, 1};
    const std::vector<std::vector<int>> expected_result{{9}, {9}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, duplicate_values_are_not_chained)
{
    const std::vector<int> input{1, 2, 2, 3};
    const std::vector<std::vector<int>> expected_result{{6}, {1, 2, 3}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, classic_example)
{
    const std::vector<int> input{1, 101, 2, 3, 100, 4, 5};
    const std::vector<std::vector<int>> expected_result{{106}, {1, 2, 3, 100}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, maximum_sum_can_be_shorter_than_longest_subsequence)
{
    const std::vector<int> input{4, 6, 1, 3, 8, 4, 6};
    const std::vector<std::vector<int>> expected_result{{18}, {4, 6, 8}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, all_negative_values_use_least_negative_single_element)
{
    const std::vector<int> input{-5, -1, -3, -2};
    const std::vector<std::vector<int>> expected_result{{-1}, {-1}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(MaximumSumIncreasingSubsequenceWithElements, mixed_negative_zero_and_positive_values)
{
    const std::vector<int> input{-1, 0, 1, -2, 2};
    const std::vector<std::vector<int>> expected_result{{3}, {1, 2}};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}
