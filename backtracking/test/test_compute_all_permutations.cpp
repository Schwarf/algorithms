//
// Created by andreas on 02.08.23.
//

#include "compute_all_permutations.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <string>
#include <vector>

template <typename T>
std::vector<std::vector<T>> sorted_permutations(std::vector<std::vector<T>> permutations)
{
    std::sort(permutations.begin(), permutations.end());
    return permutations;
}

TEST(ComputeAllPermutations, simple1)
{
    const std::vector<int> input{1, 2, 3};

    const std::vector<std::vector<int>> expected_result{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                                        {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

    EXPECT_EQ(sorted_permutations(expected_result), sorted_permutations(compute_all_permutations(input)));
}

TEST(ComputeAllPermutations, simple2)
{
    const std::vector<char> input{0, 1};

    const std::vector<std::vector<char>> expected_result{{0, 1}, {1, 0}};

    EXPECT_EQ(sorted_permutations(expected_result), sorted_permutations(compute_all_permutations(input)));
}

TEST(ComputeAllPermutations, simple3)
{
    const std::vector<std::string> input{"s"};

    const std::vector<std::vector<std::string>> expected_result{{"s"}};

    EXPECT_EQ(sorted_permutations(expected_result), sorted_permutations(compute_all_permutations(input)));
}

TEST(ComputeAllPermutations, medium1)
{
    const std::vector<int> input{5, 4, 6, 2};

    const std::vector<std::vector<int>> expected_result{
        {5, 4, 6, 2}, {5, 4, 2, 6}, {5, 6, 4, 2}, {5, 6, 2, 4}, {5, 2, 4, 6}, {5, 2, 6, 4}, {4, 5, 6, 2}, {4, 5, 2, 6},
        {4, 6, 5, 2}, {4, 6, 2, 5}, {4, 2, 5, 6}, {4, 2, 6, 5}, {6, 5, 4, 2}, {6, 5, 2, 4}, {6, 4, 5, 2}, {6, 4, 2, 5},
        {6, 2, 5, 4}, {6, 2, 4, 5}, {2, 5, 4, 6}, {2, 5, 6, 4}, {2, 4, 5, 6}, {2, 4, 6, 5}, {2, 6, 5, 4}, {2, 6, 4, 5}};

    EXPECT_EQ(sorted_permutations(expected_result), sorted_permutations(compute_all_permutations(input)));
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

TEST(ComputeAllPermutations2, simple1)
{
    std::vector<int> input{1, 2, 3};

    const std::vector<std::vector<int>> expected_result{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                                        {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

    EXPECT_EQ(sorted_permutations(expected_result), sorted_permutations(compute_all_permutations2(input)));
}

TEST(ComputeAllPermutations2, simple2)
{
    std::vector<char> input{0, 1};

    const std::vector<std::vector<char>> expected_result{{0, 1}, {1, 0}};

    EXPECT_EQ(sorted_permutations(expected_result), sorted_permutations(compute_all_permutations2(input)));
}

TEST(ComputeAllPermutations2, simple3)
{
    std::vector<std::string> input{"s"};

    const std::vector<std::vector<std::string>> expected_result{{"s"}};

    EXPECT_EQ(sorted_permutations(expected_result), sorted_permutations(compute_all_permutations2(input)));
}

TEST(ComputeAllPermutations2, medium1)
{
    std::vector<int> input{5, 4, 6, 2};

    const std::vector<std::vector<int>> expected_result{
        {5, 4, 6, 2}, {5, 4, 2, 6}, {5, 6, 4, 2}, {5, 6, 2, 4}, {5, 2, 4, 6}, {5, 2, 6, 4}, {4, 5, 6, 2}, {4, 5, 2, 6},
        {4, 6, 5, 2}, {4, 6, 2, 5}, {4, 2, 5, 6}, {4, 2, 6, 5}, {6, 5, 4, 2}, {6, 5, 2, 4}, {6, 4, 5, 2}, {6, 4, 2, 5},
        {6, 2, 5, 4}, {6, 2, 4, 5}, {2, 5, 4, 6}, {2, 5, 6, 4}, {2, 4, 5, 6}, {2, 4, 6, 5}, {2, 6, 5, 4}, {2, 6, 4, 5}};

    EXPECT_EQ(sorted_permutations(expected_result), sorted_permutations(compute_all_permutations2(input)));
}
