//
// Created by andreas on 22.06.26.
//

#include "./../find_sum_combinations.h"
#include "gtest/gtest.h"

TEST(TestFindAllombinations, simple1)
{
    std::vector<int> input{1, 2, 4};
    constexpr int target{4};
    std::vector<std::vector<int>> expected_output{{1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {4}};
    EXPECT_EQ(find_sum_combinations(input, target), expected_output);
}

TEST(TestFindAllombinations, simple2)
{
    std::vector<int> input{};
    constexpr int target{};
    std::vector<std::vector<int>> expected_output{{}};
    EXPECT_EQ(find_sum_combinations(input, target), expected_output);
}

TEST(TestFindAllombinations, simple3)
{
    std::vector<int> input{2};
    constexpr int target{1};
    std::vector<std::vector<int>> expected_output{};
    EXPECT_EQ(find_sum_combinations(input, target), expected_output);
}

TEST(TestFindAllombinations, simple4)
{
    std::vector<int> input{3, 4, 5};
    constexpr int target{10};
    std::vector<std::vector<int>> expected_output{{3, 3, 4}, {5, 5}};
    EXPECT_EQ(find_sum_combinations(input, target), expected_output);
}
