//
// Created by andreas on 18.04.25.
//

#include "graphs/rotten_oranges.h"
#include "gtest/gtest.h"

TEST(TestRottenOrangesTest, simple1)
{
    std::vector<std::vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    constexpr int expected_result{4};
    EXPECT_EQ(rotten_oranges(grid), expected_result);
}

TEST(TestRottenOrangesTest, simple2)
{
    std::vector<std::vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    constexpr int expected_result{-1};
    EXPECT_EQ(rotten_oranges(grid), expected_result);
}

TEST(TestRottenOrangesTest, simple3)
{
    std::vector<std::vector<int>> grid{{0, 2}};
    constexpr int expected_result{0};
    EXPECT_EQ(rotten_oranges(grid), expected_result);
}

TEST(TestRottenOrangesTest, simple4)
{
    std::vector<std::vector<int>> grid{{0, 2}};
    constexpr int expected_result{0};
    EXPECT_EQ(rotten_oranges(grid), expected_result);
}

TEST(TestRottenOrangesTest, simple5)
{
    std::vector<std::vector<int>> grid{{1, 1}};
    constexpr int expected_result{-1};
    EXPECT_EQ(rotten_oranges(grid), expected_result);
}
