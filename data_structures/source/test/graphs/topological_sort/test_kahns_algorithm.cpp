//
// Created by andreas on 28.12.24.
//
#include "graphs/topological_sort/kahns_algorithm.h"
#include "gtest/gtest.h"

TEST(TestKahnsAlgorithm, simple1)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
            {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7},
            {1, 8}, {1, 9}, {1, 10}, {2, 3},{2, 4},
            {2, 9}, {2, 10},{3, 4}, {3, 6}, {3, 8},
            {3, 9}, {3, 10},{4, 5}, {4, 6}, {4, 7},
            {4, 8}, {4, 9}, {5, 6}, {5, 7}, {5, 8},
            {5, 9}, {6, 7}, {6, 8}, {6, 9}, {6, 10},
            {7, 8}, {7, 10}, {8, 9}
        }
    };
    std::vector<int> expected_result{1, 2, 3, 4, 5, 6, 7, 10, 8, 9};
    EXPECT_EQ(kahns_algorithm(digraph), expected_result);
}
