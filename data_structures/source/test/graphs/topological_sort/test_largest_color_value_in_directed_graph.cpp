//
// Created by andreas on 08.12.24.
//

#include "gtest/gtest.h"
#include "graphs/topological_sort/largest_color_value_in_directed_graph.h"

TEST(TestLargestColorValueInDirectedGraph, simple1)
{
    std::string colors{"abaca"};
    std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, largest_color_value_in_directed_graph(colors, edges));
}

TEST(TestLargestColorValueInDirectedGraph, simple2)
{
    std::string colors{"a"};
    std::vector<std::vector<int>> edges{{0, 0}};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, largest_color_value_in_directed_graph(colors, edges));
}


TEST(TestLargestColorValueInDirectedGraph, simple3)
{
    std::string colors{"hhqhuqhqff"};
    std::vector<std::vector<int>> edges{
        {0, 1}, {0, 2}, {2, 3}, {3, 4}, {3, 5}, {5, 6}, {2, 7}, {6, 7}, {7, 8}, {3, 8}, {5, 8}, {8, 9}, {3, 9}, {6, 9}
    };
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, largest_color_value_in_directed_graph(colors, edges));
}


TEST(TestLargestColorValueInDirectedGraph, simple4)
{
    std::string colors{"bwsswpwbpwpsbswbwswbwbbbwpwsbsssw"};
    std::vector<std::vector<int>> edges{
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {3, 5}, {2, 6}, {5, 7}, {6, 8}, {7, 8}, {4, 9}, {8, 9}, {7, 9}, {9, 10},
        {8, 10}, {5, 10}, {9, 11}, {10, 12}, {11, 12}, {9, 12}, {12, 13}, {10, 13}, {11, 13}, {8, 14}, {13, 14},
        {12, 14}, {14, 15}, {13, 15}, {11, 15}, {10, 16}, {13, 17}, {10, 17}, {12, 17}, {15, 17}, {8, 18}, {17, 18},
        {10, 18}, {14, 19}, {10, 19}, {18, 19}, {14, 20}, {18, 20}, {16, 20}, {19, 20}, {20, 21}, {18, 21}, {16, 22},
        {21, 22}, {20, 22}, {14, 23}, {22, 23}, {21, 23}, {20, 23}, {18, 24}, {16, 24}, {22, 24}, {21, 24}, {18, 25},
        {22, 25}, {21, 25}, {24, 25}, {20, 25}, {25, 26}, {25, 27}, {25, 28}, {27, 29}, {22, 29}, {28, 29}, {23, 29},
        {28, 30}, {24, 31}, {28, 31}, {27, 31}, {29, 32}, {28, 32}, {30, 32}
    };
    constexpr int expected_result{8};
    EXPECT_EQ(expected_result, largest_color_value_in_directed_graph(colors, edges));
}
