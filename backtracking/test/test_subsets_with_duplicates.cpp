//
// Created by andreas on 24.06.26.
//
#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include "../subsets_with_duplicates.h"

namespace
{
    using Subsets = std::vector<std::vector<int>>;

    void expect_subsets_equal(Subsets actual, Subsets expected)
    {
        std::sort(actual.begin(), actual.end());
        std::sort(expected.begin(), expected.end());

        EXPECT_EQ(actual, expected);
    }
} // namespace

TEST(SubsetsWithDuplicatesTest, ReturnsOnlyEmptySubsetForEmptyInput)
{
    std::vector<int> nums;

    const auto result = subsets_with_duplicates(nums);

    expect_subsets_equal(
        result,
        {
            {},
        });
}

TEST(SubsetsWithDuplicatesTest, HandlesSingleElement)
{
    std::vector<int> nums{0};

    const auto result = subsets_with_duplicates(nums);

    expect_subsets_equal(
        result,
        {
            {},
            {0},
        });
}

TEST(SubsetsWithDuplicatesTest, HandlesGivenExampleOne)
{
    std::vector<int> nums{1, 2, 2};

    const auto result = subsets_with_duplicates(nums);

    expect_subsets_equal(
        result,
        {
            {},
            {1},
            {2},
            {1, 2},
            {2, 2},
            {1, 2, 2},
        });
}

TEST(SubsetsWithDuplicatesTest, HandlesGivenExampleWithManyDuplicates)
{
    std::vector<int> nums{4, 4, 4, 1, 4};

    const auto result = subsets_with_duplicates(nums);

    expect_subsets_equal(
        result,
        {
            {},
            {1},
            {4},
            {1, 4},
            {4, 4},
            {1, 4, 4},
            {4, 4, 4},
            {1, 4, 4, 4},
            {4, 4, 4, 4},
            {1, 4, 4, 4, 4},
        });
}

TEST(SubsetsWithDuplicatesTest, HandlesOnlyDuplicateValues)
{
    std::vector<int> nums{7, 7, 7};

    const auto result = subsets_with_duplicates(nums);

    expect_subsets_equal(
        result,
        {
            {},
            {7},
            {7, 7},
            {7, 7, 7},
        });
}

TEST(SubsetsWithDuplicatesTest, HandlesAllDistinctValues)
{
    std::vector<int> nums{1, 2, 3};

    const auto result = subsets_with_duplicates(nums);

    expect_subsets_equal(
        result,
        {
            {},
            {1},
            {2},
            {3},
            {1, 2},
            {1, 3},
            {2, 3},
            {1, 2, 3},
        });
}

TEST(SubsetsWithDuplicatesTest, HandlesUnsortedInput)
{
    std::vector<int> nums{2, 1, 2};

    const auto result = subsets_with_duplicates(nums);

    expect_subsets_equal(
        result,
        {
            {},
            {1},
            {2},
            {1, 2},
            {2, 2},
            {1, 2, 2},
        });
}

TEST(SubsetsWithDuplicatesTest, HandlesNegativeValuesAndZero)
{
    std::vector<int> nums{-1, 0, -1};

    const auto result = subsets_with_duplicates(nums);

    expect_subsets_equal(
        result,
        {
            {},
            {-1},
            {0},
            {-1, -1},
            {-1, 0},
            {-1, -1, 0},
        });
}

TEST(SubsetsWithDuplicatesTest, DoesNotGenerateDuplicateSubsets)
{
    std::vector<int> nums{2, 2, 2, 2};

    const auto result = subsets_with_duplicates(nums);

    ASSERT_EQ(result.size(), 5U);

    expect_subsets_equal(
        result,
        {
            {},
            {2},
            {2, 2},
            {2, 2, 2},
            {2, 2, 2, 2},
        });
}

TEST(SubsetsWithDuplicatesTest, SortsInputInPlace)
{
    std::vector<int> nums{4, 1, 4, 2};

    static_cast<void>(subsets_with_duplicates(nums));

    EXPECT_EQ(nums, (std::vector<int>{1, 2, 4, 4}));
}
