//
// Created by andreas on 16.07.26.
//
#include "longest_subarray_with_at_most_2_distinct_values.h"
#include "gtest/gtest.h"

TEST(TestLongestSubarrayWithAtMost2DistinctValues, emptyInput)
{
    const std::vector<int> input{};
    constexpr int expected_result{};
    EXPECT_EQ(longest_subarray_with_at_most_2_distinct_values(input), expected_result);
}

TEST(TestLongestSubarrayWithAtMost2DistinctValues, singleValue)
{
    const std::vector<int> input{7};
    constexpr int expected_result{1};
    EXPECT_EQ(longest_subarray_with_at_most_2_distinct_values(input), expected_result);
}

TEST(TestLongestSubarrayWithAtMost2DistinctValues, allValuesSame)
{
    const std::vector<int> input{4, 4, 4, 4, 4};
    constexpr int expected_result{5};
    EXPECT_EQ(longest_subarray_with_at_most_2_distinct_values(input), expected_result);
}

TEST(TestLongestSubarrayWithAtMost2DistinctValues, wholeArrayHasTwoDistinctValues)
{
    const std::vector<int> input{1, 2, 1, 2, 2, 1};
    constexpr int expected_result{6};
    EXPECT_EQ(longest_subarray_with_at_most_2_distinct_values(input), expected_result);
}

TEST(TestLongestSubarrayWithAtMost2DistinctValues, shrinksWhenThirdDistinctValueAppears)
{
    const std::vector<int> input{1, 2, 1, 3, 4, 3, 3};
    constexpr int expected_result{4};
    EXPECT_EQ(longest_subarray_with_at_most_2_distinct_values(input), expected_result);
}

TEST(TestLongestSubarrayWithAtMost2DistinctValues, longestWindowCanBeInTheMiddle)
{
    const std::vector<int> input{0, 1, 2, 2, 2, 1, 1, 3};
    constexpr int expected_result{6};
    EXPECT_EQ(longest_subarray_with_at_most_2_distinct_values(input), expected_result);
}

TEST(TestLongestSubarrayWithAtMost2DistinctValues, supportsNegativeValues)
{
    const std::vector<int> input{-1, -2, -1, -3, -3, -2, -2};
    constexpr int expected_result{4};
    EXPECT_EQ(longest_subarray_with_at_most_2_distinct_values(input), expected_result);
}
