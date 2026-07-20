//
// Created by andreas on 20.07.26.
//

#include "gtest/gtest.h"

#include <vector>

#include "./../search_for_range.h"

TEST(SearchForRange, empty_input_returns_minus_one_range)
{
    const std::vector<int> input{};
    const std::vector<int> expected_result{-1, -1};

    EXPECT_EQ(expected_result, search_for_range(input, 1));
}

TEST(SearchForRange, single_matching_element)
{
    const std::vector<int> input{1};
    const std::vector<int> expected_result{0, 0};

    EXPECT_EQ(expected_result, search_for_range(input, 1));
}

TEST(SearchForRange, single_non_matching_element)
{
    const std::vector<int> input{1};
    const std::vector<int> expected_result{-1, -1};

    EXPECT_EQ(expected_result, search_for_range(input, 2));
}

TEST(SearchForRange, target_occurs_multiple_times_in_middle)
{
    const std::vector<int> input{5, 7, 7, 8, 8, 10};
    const std::vector<int> expected_result{3, 4};

    EXPECT_EQ(expected_result, search_for_range(input, 8));
}

TEST(SearchForRange, target_missing_between_values)
{
    const std::vector<int> input{5, 7, 7, 8, 8, 10};
    const std::vector<int> expected_result{-1, -1};

    EXPECT_EQ(expected_result, search_for_range(input, 6));
}

TEST(SearchForRange, target_missing_less_than_all_values)
{
    const std::vector<int> input{5, 7, 7, 8, 8, 10};
    const std::vector<int> expected_result{-1, -1};

    EXPECT_EQ(expected_result, search_for_range(input, 1));
}

TEST(SearchForRange, target_missing_greater_than_all_values)
{
    const std::vector<int> input{5, 7, 7, 8, 8, 10};
    const std::vector<int> expected_result{-1, -1};

    EXPECT_EQ(expected_result, search_for_range(input, 12));
}

TEST(SearchForRange, target_range_starts_at_first_index)
{
    const std::vector<int> input{2, 2, 2, 3, 4};
    const std::vector<int> expected_result{0, 2};

    EXPECT_EQ(expected_result, search_for_range(input, 2));
}

TEST(SearchForRange, target_range_ends_at_last_index)
{
    const std::vector<int> input{1, 2, 3, 4, 4, 4};
    const std::vector<int> expected_result{3, 5};

    EXPECT_EQ(expected_result, search_for_range(input, 4));
}

TEST(SearchForRange, all_elements_are_target)
{
    const std::vector<int> input{3, 3, 3, 3};
    const std::vector<int> expected_result{0, 3};

    EXPECT_EQ(expected_result, search_for_range(input, 3));
}

TEST(SearchForRange, one_occurrence_in_larger_array)
{
    const std::vector<int> input{1, 2, 3, 4, 5};
    const std::vector<int> expected_result{2, 2};

    EXPECT_EQ(expected_result, search_for_range(input, 3));
}

TEST(SearchForRange, works_with_negative_values)
{
    const std::vector<int> input{-5, -3, -3, -3, 0, 2};
    const std::vector<int> expected_result{1, 3};

    EXPECT_EQ(expected_result, search_for_range(input, -3));
}
