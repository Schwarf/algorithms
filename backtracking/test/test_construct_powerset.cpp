//
// Created by andreas on 04.06.26.
//
#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

#include "../construct_powerset.h"

std::vector<std::vector<int>> canonicalize(std::vector<std::vector<int>> sets)
{
    for (auto& subset : sets)
    {
        std::sort(subset.begin(), subset.end());
    }

    std::sort(sets.begin(), sets.end());
    return sets;
}

void expect_powerset_no_backtrack_equal(const std::vector<int>& input, const std::vector<std::vector<int>>& expected)
{
    const auto result = powerset_no_backtrack(input);

    EXPECT_EQ(canonicalize(result), canonicalize(expected));
}

void expect_powerset_backtrack_equal(const std::vector<int>& input, const std::vector<std::vector<int>>& expected)
{
    const auto result = powerset_backtrack(input);

    EXPECT_EQ(canonicalize(result), canonicalize(expected));
}


void expect_no_duplicate_subsets(const std::vector<std::vector<int>>& result)
{
    auto canonical = canonicalize(result);

    const auto duplicate = std::adjacent_find(canonical.begin(), canonical.end());

    EXPECT_EQ(duplicate, canonical.end());
}


TEST(PowersetIterative, EmptyInputReturnsOnlyEmptySubset)
{
    const std::vector<int> input{};

    const std::vector<std::vector<int>> expected{{}};

    expect_powerset_no_backtrack_equal(input, expected);
}

TEST(PowersetIterative, SingleElementInputReturnsEmptyAndSingleElementSubset)
{
    const std::vector<int> input{1};

    const std::vector<std::vector<int>> expected{{}, {1}};

    expect_powerset_no_backtrack_equal(input, expected);
}

TEST(PowersetIterative, TwoElementInputReturnsAllSubsets)
{
    const std::vector<int> input{1, 2};

    const std::vector<std::vector<int>> expected{{}, {1}, {2}, {1, 2}};

    expect_powerset_no_backtrack_equal(input, expected);
}

TEST(PowersetIterative, ThreeElementInputReturnsAllSubsets)
{
    const std::vector<int> input{1, 2, 3};

    const std::vector<std::vector<int>> expected{{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}};

    expect_powerset_no_backtrack_equal(input, expected);
}

TEST(PowersetIterative, HandlesZeroAndNegativeNumbers)
{
    const std::vector<int> input{-1, 0, 2};

    const std::vector<std::vector<int>> expected{{}, {-1}, {0}, {2}, {-1, 0}, {-1, 2}, {0, 2}, {-1, 0, 2}};

    expect_powerset_no_backtrack_equal(input, expected);
}

TEST(PowersetIterative, ResultSizeIsTwoPowerN)
{
    const std::vector<int> input{1, 2, 3, 4};

    const auto result = powerset_no_backtrack(input);

    EXPECT_EQ(result.size(), 1ULL << input.size());
}

TEST(PowersetIterative, DoesNotGenerateDuplicateSubsets)
{
    const std::vector<int> input{1, 2, 3, 4};

    const auto result = powerset_no_backtrack(input);

    expect_no_duplicate_subsets(result);
}

TEST(PowersetIterative, ContainsEmptySubsetAndFullSubset)
{
    const std::vector<int> input{1, 2, 3, 4};

    const auto result = canonicalize(powerset_no_backtrack(input));

    const std::vector<int> empty_subset{};
    const std::vector<int> full_subset{1, 2, 3, 4};

    EXPECT_NE(std::find(result.begin(), result.end(), empty_subset), result.end());
    EXPECT_NE(std::find(result.begin(), result.end(), full_subset), result.end());
}
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

TEST(PowersetBacktrack, EmptyInputReturnsOnlyEmptySubset)
{
    const std::vector<int> input{};

    const std::vector<std::vector<int>> expected{{}};

    expect_powerset_backtrack_equal(input, expected);
}

TEST(PowersetBacktrack, SingleElementInputReturnsEmptyAndSingleElementSubset)
{
    const std::vector<int> input{1};

    const std::vector<std::vector<int>> expected{{}, {1}};

    expect_powerset_backtrack_equal(input, expected);
}

TEST(PowersetBacktrack, TwoElementInputReturnsAllSubsets)
{
    const std::vector<int> input{1, 2};

    const std::vector<std::vector<int>> expected{{}, {1}, {2}, {1, 2}};

    expect_powerset_backtrack_equal(input, expected);
}

TEST(PowersetBacktrack, ThreeElementInputReturnsAllSubsets)
{
    const std::vector<int> input{1, 2, 3};

    const std::vector<std::vector<int>> expected{{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}};

    expect_powerset_backtrack_equal(input, expected);
}

TEST(PowersetBacktrack, HandlesZeroAndNegativeNumbers)
{
    const std::vector<int> input{-1, 0, 2};

    const std::vector<std::vector<int>> expected{{}, {-1}, {0}, {2}, {-1, 0}, {-1, 2}, {0, 2}, {-1, 0, 2}};

    expect_powerset_backtrack_equal(input, expected);
}

TEST(PowersetBacktrack, ResultSizeIsTwoPowerN)
{
    const std::vector<int> input{1, 2, 3, 4};

    const auto result = powerset_backtrack(input);

    EXPECT_EQ(result.size(), 1ULL << input.size());
}

TEST(PowersetBacktrack, DoesNotGenerateDuplicateSubsets)
{
    const std::vector<int> input{1, 2, 3, 4};

    const auto result = powerset_backtrack(input);

    expect_no_duplicate_subsets(result);
}

TEST(PowersetBacktrack, ContainsEmptySubsetAndFullSubset)
{
    const std::vector<int> input{1, 2, 3, 4};

    const auto result = canonicalize(powerset_backtrack(input));

    const std::vector<int> empty_subset{};
    const std::vector<int> full_subset{1, 2, 3, 4};

    EXPECT_NE(std::find(result.begin(), result.end(), empty_subset), result.end());
    EXPECT_NE(std::find(result.begin(), result.end(), full_subset), result.end());
}
