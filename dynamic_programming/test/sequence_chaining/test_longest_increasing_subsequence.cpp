//
// Created by andreas on 20.09.26.
//

#include <algorithm>
#include <vector>

#include "../../sequence_chaining/longest_increasing_subsequence.h"
#include "gtest/gtest.h"

namespace
{
    void ExpectValidLongestIncreasingSubsequence(const std::vector<int>& input, const std::vector<int>& output,
                                                 int expected_length)
    {
        EXPECT_EQ(expected_length, output.size());

        EXPECT_TRUE(std::is_sorted(output.begin(), output.end(), std::less<int>()));
        EXPECT_EQ(output.end(), std::adjacent_find(output.begin(), output.end()));

        auto input_it = input.begin();
        for (int value : output)
        {
            input_it = std::find(input_it, input.end(), value);
            ASSERT_NE(input.end(), input_it);
            ++input_it;
        }
    }

    void ExpectSameSubsequences(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual)
    {
        std::sort(expected.begin(), expected.end());
        std::sort(actual.begin(), actual.end());

        EXPECT_EQ(expected, actual);
    }
} // namespace

TEST(LongestIncreasingSubsequence, empty_input)
{
    const std::vector<int> input{};

    EXPECT_TRUE(longest_increasing_subsequence(input).empty());
}

TEST(LongestIncreasingSubsequence, single_element)
{
    const std::vector<int> input{7};
    const std::vector<int> expected_result{7};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(LongestIncreasingSubsequence, strictly_increasing_input_uses_all_elements)
{
    const std::vector<int> input{1, 2, 3, 4, 5};
    const std::vector<int> expected_result{1, 2, 3, 4, 5};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(LongestIncreasingSubsequence, strictly_decreasing_input_returns_single_element)
{
    const std::vector<int> input{5, 4, 3, 2, 1};

    ExpectValidLongestIncreasingSubsequence(input, longest_increasing_subsequence(input), 1);
}

TEST(LongestIncreasingSubsequence, duplicate_values_are_not_chained)
{
    const std::vector<int> input{1, 2, 2, 3};
    const std::vector<int> expected_result{1, 2, 3};

    EXPECT_EQ(expected_result, longest_increasing_subsequence(input));
}

TEST(LongestIncreasingSubsequence, all_equal_values_return_one_element)
{
    const std::vector<int> input{4, 4, 4, 4};

    ExpectValidLongestIncreasingSubsequence(input, longest_increasing_subsequence(input), 1);
}

TEST(LongestIncreasingSubsequence, handles_negative_zero_and_positive_values)
{
    const std::vector<int> input{-3, -1, -2, 0, 2, -1, 3};

    ExpectValidLongestIncreasingSubsequence(input, longest_increasing_subsequence(input), 5);
}

TEST(LongestIncreasingSubsequence, classic_example)
{
    const std::vector<int> input{10, 9, 2, 5, 3, 7, 101, 18};

    ExpectValidLongestIncreasingSubsequence(input, longest_increasing_subsequence(input), 4);
}

TEST(LongestIncreasingSubsequence, allows_multiple_longest_subsequences)
{
    const std::vector<int> input{1, 3, 2, 4};

    ExpectValidLongestIncreasingSubsequence(input, longest_increasing_subsequence(input), 3);
}

TEST(LongestIncreasingSubsequence, allows_multiple_longest_subsequences_with_repeated_lengths)
{
    const std::vector<int> input{2, 1, 3, 2, 4, 3};

    ExpectValidLongestIncreasingSubsequence(input, longest_increasing_subsequence(input), 3);
}

TEST(MultipleLongestIncreasingSubsequence, empty_input)
{
    const std::vector<int> input{};

    EXPECT_TRUE(multiple_longest_increasing_subsequence(input).empty());
}

TEST(MultipleLongestIncreasingSubsequence, single_element)
{
    const std::vector<int> input{7};
    const std::vector<std::vector<int>> expected_result{{7}};

    EXPECT_EQ(expected_result, multiple_longest_increasing_subsequence(input));
}

TEST(MultipleLongestIncreasingSubsequence, strictly_increasing_input_has_one_result)
{
    const std::vector<int> input{1, 2, 3, 4, 5};
    const std::vector<std::vector<int>> expected_result{{1, 2, 3, 4, 5}};

    EXPECT_EQ(expected_result, multiple_longest_increasing_subsequence(input));
}

TEST(MultipleLongestIncreasingSubsequence, strictly_decreasing_input_returns_each_element)
{
    const std::vector<int> input{5, 4, 3, 2, 1};
    const std::vector<std::vector<int>> expected_result{{5}, {4}, {3}, {2}, {1}};

    EXPECT_EQ(expected_result, multiple_longest_increasing_subsequence(input));
}

TEST(MultipleLongestIncreasingSubsequence, returns_multiple_subsequences_with_different_endpoints)
{
    const std::vector<int> input{2, 1, 3, 2, 4, 3};
    const std::vector<std::vector<int>> expected_result{{2, 3, 4}, {1, 3, 4}, {1, 2, 4}, {1, 2, 3}};

    ExpectSameSubsequences(expected_result, multiple_longest_increasing_subsequence(input));
}

TEST(MultipleLongestIncreasingSubsequence, returns_multiple_subsequences_with_same_endpoint)
{
    const std::vector<int> input{1, 2, 4, 3, 5};
    const std::vector<std::vector<int>> expected_result{{1, 2, 4, 5}, {1, 2, 3, 5}};

    ExpectSameSubsequences(expected_result, multiple_longest_increasing_subsequence(input));
}

TEST(MultipleLongestIncreasingSubsequence, handles_negative_zero_and_positive_values)
{
    const std::vector<int> input{-3, -1, -2, 0, 2, -1, 3};
    const std::vector<std::vector<int>> expected_result{{-3, -1, 0, 2, 3}, {-3, -2, 0, 2, 3}};

    ExpectSameSubsequences(expected_result, multiple_longest_increasing_subsequence(input));
}

TEST(MultipleLongestIncreasingSubsequence, returns_index_distinct_results_for_duplicate_values)
{
    const std::vector<int> input{1, 2, 2, 3};
    const std::vector<std::vector<int>> expected_result{{1, 2, 3}, {1, 2, 3}};

    ExpectSameSubsequences(expected_result, multiple_longest_increasing_subsequence(input));
}


TEST(MultipleLongestIncreasingSubsequence, returns_index_distinct_results_for_duplicate_values_and_duplicate_sequences)
{
    const std::vector<int> input{1, 2, 10, 10, 10, 1, 2, 10};
    const std::vector<std::vector<int>> expected_result{{1, 2, 10}, {1, 2, 10}, {1, 2, 10},
                                                        {1, 2, 10}, {1, 2, 10}, {1, 2, 10}};

    ExpectSameSubsequences(expected_result, multiple_longest_increasing_subsequence(input));
}
