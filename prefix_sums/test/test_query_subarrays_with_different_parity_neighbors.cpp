//
// Created by andreas on 09.12.24.
//
#include "./../query_subarrays_with_different_parity_neighbors.h"
#include "gtest/gtest.h"

TEST(TestQuerySubarraysWithDifferentParityNeighbors, simple1)
{
    std::vector<int> input{3, 4, 1, 2, 6};
    std::vector<std::vector<int>> queries{{0, 4}};
    std::vector<bool> expected_result{false};
    EXPECT_EQ(expected_result, get_query_results(input, queries));
}

TEST(TestQuerySubarraysWithDifferentParityNeighbors, simple2)
{
    std::vector<int> input{4, 3, 1, 6};
    std::vector<std::vector<int>> queries{{0, 2}, {2, 3}};
    std::vector<bool> expected_result{false, true};
    EXPECT_EQ(expected_result, get_query_results(input, queries));
}


TEST(TestQuerySubarraysWithDifferentParityNeighbors, simple3)
{
    std::vector<int> input{1, 3, 6, 10, 8, 9, 5, 1, 10, 8, 5};
    std::vector<std::vector<int>> queries{{0, 7}};
    std::vector<bool> expected_result{false};
    EXPECT_EQ(expected_result, get_query_results(input, queries));
}

TEST(TestQuerySubarraysWithDifferentParityNeighbors, complex1)
{
    std::vector<int> input{
        13, 90, 16, 40, 56, 7, 65, 70, 50, 22, 48, 12, 39, 36, 49, 45, 15, 14, 31, 53, 23, 6, 26, 1, 24
    };
    std::vector<std::vector<int>> queries{
        {19, 24}, {9, 17}, {19, 22}, {4, 5}, {5, 23}, {8, 23}, {10, 19}, {1, 1}, {8, 8}, {10, 20}, {21, 22}, {7, 12},
        {4, 4}, {10, 20}, {0, 22}, {5, 14}, {13, 15}, {9, 20}, {9, 15}, {5, 17}, {0, 4}, {10, 12}, {9, 12}, {16, 19},
        {4, 22}, {13, 18}, {10, 23}, {1, 17}, {0, 6}, {17, 24}, {4, 9}, {11, 13}, {2, 4}, {16, 16}, {7, 15}, {7, 19},
        {7, 24}, {6, 14}, {11, 19}, {4, 5}, {4, 16}, {6, 11}, {2, 3}, {10, 20}, {2, 5}, {4, 10}, {8, 10}, {4, 11},
        {18, 20}, {13, 19}, {15, 21}, {0, 10}, {12, 13}, {14, 20}, {5, 21}, {5, 19}, {10, 22}, {3, 11}, {13, 16},
        {3, 18}, {13, 22}
    };
    std::vector<bool> expected_result{
        false, false, false, true, false, false, false, true, true, false, false, false, true, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
        false, true, false, false, false, false, false, true, false, false, false, false, false, false, false, false,
        false, false, false, false, true, false, false, false, false, false, false, false, false
    };
    EXPECT_EQ(expected_result, get_query_results(input, queries));
}
