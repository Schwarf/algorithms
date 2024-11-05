//
// Created by andreas on 05.11.24.
//
#include "graphs/tarjan_algorithm_directed_graph.h"
#include "gtest/gtest.h"

TEST(TestTarjanAlgoSSC, simple1)
{
    DirectedGraph<int> digraph{{1, 2}, {2, 3}, {2, 8}, {3, 4}, {3, 7}, {4, 5}, {5, 3}, {5, 6}, {7, 4}, {7, 6}, {8, 1}, {8,7}};
    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{3};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    const std::set<int> first_SSC{1, 2, 8};
    const std::set<int> second_SSC{3, 4, 5, 7};
    const std::set<int> third_SSC{6};
    std::set<std::set<int>> expected_sscs{first_SSC, second_SSC, third_SSC};
    EXPECT_EQ(ssc_sets, expected_sscs);
}
