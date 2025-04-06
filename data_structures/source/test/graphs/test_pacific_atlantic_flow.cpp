//
// Created by andreas on 06.04.25.
//
#include "graphs/pacific_atlantic_flow.h"
#include "gtest/gtest.h"

TEST(TestPacificAtlanticFlow, simple1)
{
    std::vector<std::vector<int>> input{
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}
    };
    std::vector<std::vector<int>> expected_output{{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};
    EXPECT_EQ(expected_output, pacific_atlanctic_flow(input));
}

TEST(TestPacificAtlanticFlow, simple2)
{
    std::vector<std::vector<int>> input{{1}};
    std::vector<std::vector<int>> expected_output{{0, 0}};
    EXPECT_EQ(expected_output, pacific_atlanctic_flow(input));
}
