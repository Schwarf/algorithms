//
// Created by andreas on 12.03.25.
//
#include "./../hiring_candidates.h"
#include "gtest/gtest.h"

TEST(TestHiringCandidates, simple1)
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    constexpr int min_cost{3};
    constexpr int max_cost{8};
    constexpr int expected_result{9};
    EXPECT_EQ(expected_result, number_of_candidate_pairs(input, min_cost, max_cost));
}


TEST(TestHiringCandidates, simple2)
{
    std::vector<int> input = {1, 2};
    constexpr int min_cost{4};
    constexpr int max_cost{8};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, number_of_candidate_pairs(input, min_cost, max_cost));
}

TEST(TestHiringCandidates, simple3)
{
    std::vector<int> input = {1, 2, 4, 4};
    constexpr int min_cost{8};
    constexpr int max_cost{8};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_candidate_pairs(input, min_cost, max_cost));
}

TEST(TestHiringCandidates, simple4)
{
    std::vector<int> input = {1, 2, 4, 4};
    constexpr int min_cost{8};
    constexpr int max_cost{8};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, number_of_candidate_pairs(input, min_cost, max_cost));
}
