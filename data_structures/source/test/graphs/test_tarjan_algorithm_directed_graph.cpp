//
// Created by andreas on 05.11.24.
//
#include "graphs/tarjan_algorithm_directed_graph.h"
#include "gtest/gtest.h"

TEST(TestTarjanAlgoSSC, simple1)
{
    DirectedGraph<int> digraph{
        {1, 2}, {2, 3}, {2, 8}, {3, 4}, {3, 7}, {4, 5}, {5, 3}, {5, 6}, {7, 4}, {7, 6}, {8, 1}, {8, 7}
    };
    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{3};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    const std::set<int> first_SSC{1, 2, 8};
    const std::set<int> second_SSC{3, 4, 5, 7};
    const std::set<int> third_SSC{6};
    std::set<std::set<int>> expected_sscs{first_SSC, second_SSC, third_SSC};
    EXPECT_EQ(ssc_sets, expected_sscs);
}

TEST(TestTarjanAlgoSSC, simple2)
{
    DirectedGraph<int> digraph{{2 ,  1}, { 2 ,  3}, { 3 ,  4}, { 3 ,  5}, { 4 ,  2}, { 4 ,  5}, { 6 ,  4}};
    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{4};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    const std::set<int> first_SSC{1};
    const std::set<int> second_SSC{2, 3, 4};
    const std::set<int> third_SSC{5};
    const std::set<int> fourth_SSC{6};
    std::set<std::set<int>> expected_sscs{first_SSC, second_SSC, third_SSC, fourth_SSC};
    EXPECT_EQ(ssc_sets, expected_sscs);
}

TEST(TestTarjanAlgoSSC, simple3)
{
    DirectedGraph<int> digraph{
            {1, 2, 3, 4, 5, 6}, {{2, 1}, {2, 4}, {3, 1}, {3, 4}, {3, 6}, {4, 1}, {4, 2}}
    };

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{5};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    const std::set<int> first_SSC{1};
    const std::set<int> second_SSC{2, 4};
    const std::set<int> third_SSC{3};
    const std::set<int> fourth_SSC{5};
    const std::set<int> fifth_SSC{6};
    std::set<std::set<int>> expected_sscs{first_SSC, second_SSC, third_SSC, fourth_SSC, fifth_SSC};
    EXPECT_EQ(ssc_sets, expected_sscs);
}
