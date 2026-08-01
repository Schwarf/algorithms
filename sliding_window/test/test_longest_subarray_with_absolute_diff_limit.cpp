//
// Created by andreas on 01.08.26.
//
#include "longest_subarray_with_absolute_diff_limit.h"
#include "gtest/gtest.h"

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, emptyInput)
{
    const std::vector<int> input{};
    constexpr int limit{4};
    constexpr int expected_result{};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, singleValue)
{
    const std::vector<int> input{7};
    constexpr int limit{};
    constexpr int expected_result{1};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, leetcodeExample1)
{
    const std::vector<int> input{8, 2, 4, 7};
    constexpr int limit{4};
    constexpr int expected_result{2};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, leetcodeExample2)
{
    const std::vector<int> input{10, 1, 2, 4, 7, 2};
    constexpr int limit{5};
    constexpr int expected_result{4};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, leetcodeExample3)
{
    const std::vector<int> input{4, 2, 2, 2, 4, 4, 2, 2};
    constexpr int limit{};
    constexpr int expected_result{3};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, allValuesSame)
{
    const std::vector<int> input{5, 5, 5, 5};
    constexpr int limit{};
    constexpr int expected_result{4};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, wholeArrayWithinLimit)
{
    const std::vector<int> input{1, 3, 6, 7};
    constexpr int limit{6};
    constexpr int expected_result{4};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, longestWindowCanBeAtTheEnd)
{
    const std::vector<int> input{9, 1, 2, 3, 4};
    constexpr int limit{3};
    constexpr int expected_result{4};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}

TEST(TestLongestSubarrayWithAbsoluteDiffLimit, strictlyIncreasingWithTightLimit)
{
    const std::vector<int> input{1, 2, 3, 4, 5};
    constexpr int limit{1};
    constexpr int expected_result{2};
    EXPECT_EQ(longest_subarray_with_absolute_diff_limit(input, limit), expected_result);
}
