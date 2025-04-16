//
// Created by andreas on 12.03.25.
//
#include "./../minimum_swaps.h"
#include "gtest/gtest.h"

TEST(TestMinimumSwaps, simple1)
{
    std::vector<int> input = {9, 10, 1, 3, 2};
    constexpr int expected_result{4};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

TEST(TestMinimumSwaps, simple2)
{
    std::vector<int> input = {9, 1, 10, 3, 2};
    constexpr int expected_result{3};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

TEST(TestMinimumSwaps, simple3)
{
    std::vector<int> input = {5, 3, 1};
    constexpr int expected_result{3};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

TEST(TestMinimumSwaps, simple4)
{
    std::vector<int> input = {3, 4, 5, 5, 3, 1};
    constexpr int expected_result{6};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

TEST(TestMinimumSwaps, simple5)
{
    std::vector<int> input = {9};
    constexpr int expected_result{0};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

TEST(TestMinimumSwaps, simple6)
{
    std::vector<int> input = {3, 4, 5, 5, 1, 3, 1};
    constexpr int expected_result{6};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

TEST(TestMinimumSwapsConcise, simple1)
{
    std::vector<int> input = {9, 10, 1, 3, 2};
    constexpr int expected_result{4};
    EXPECT_EQ(minimum_swaps(input), expected_result);
}

TEST(TestMinimumSwapsConcise, simple2)
{
    std::vector<int> input = {9, 1, 10, 3, 2};
    constexpr int expected_result{3};
    EXPECT_EQ(minimum_swaps_concise(input), expected_result);
}

TEST(TestMinimumSwapsConcise, simple3)
{
    std::vector<int> input = {5, 3, 1};
    constexpr int expected_result{3};
    EXPECT_EQ(minimum_swaps_concise(input), expected_result);
}

TEST(TestMinimumSwapsConcise, simple4)
{
    std::vector<int> input = {3, 4, 5, 5, 3, 1};
    constexpr int expected_result{6};
    EXPECT_EQ(minimum_swaps_concise(input), expected_result);
}

TEST(TestMinimumSwapsConcise, simple5)
{
    std::vector<int> input = {9};
    constexpr int expected_result{0};
    EXPECT_EQ(minimum_swaps_concise(input), expected_result);
}

TEST(TestMinimumSwapsConcise, simple6)
{
    std::vector<int> input = {3, 4, 5, 5, 1, 3, 1};
    constexpr int expected_result{6};
    EXPECT_EQ(minimum_swaps_concise(input), expected_result);
}
