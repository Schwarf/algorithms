//
// Created by andreas on 05.11.24.
//
#include "graphs/tarjan_algorithm_directed_graph.h"
#include "gtest/gtest.h"

TEST(TestTarjanAlgoSSC, simple1)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8}, {
            {1, 2}, {2, 3}, {2, 8}, {3, 4}, {3, 7}, {4, 5}, {5, 3}, {5, 6}, {7, 4}, {7, 6}, {8, 1}, {8, 7}
        }
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
    DirectedGraph<int> digraph{{1, 2, 3, 4, 5, 6}, {{2, 1}, {2, 3}, {3, 4}, {3, 5}, {4, 2}, {4, 5}, {6, 4}}};
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


TEST(TestTarjanAlgoSSC, simple_chain)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6}, {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}}
    };

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{6};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    std::set<std::set<int>> expected_sscs{{1}, {2}, {3}, {4}, {5}, {6}};
    EXPECT_EQ(ssc_sets, expected_sscs);
}

TEST(TestTarjanAlgoSSC, binary_tree)
{
    DirectedGraph<int> digraph{{1, 2, 3, 4, 5, 6, 7}, {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}}};

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{7};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    std::set<std::set<int>> expected_sscs{{1}, {2}, {3}, {4}, {5}, {6}, {7}};
    EXPECT_EQ(ssc_sets, expected_sscs);
}


TEST(TestTarjanAlgoSSC, disconnected_nodes)
{
    DirectedGraph<int> digraph{{1, 2, 3, 4}, {}};

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{4};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    std::set<std::set<int>> expected_sscs{{1}, {2}, {3}, {4}};
    EXPECT_EQ(ssc_sets, expected_sscs);
}

/// MISSING CASES:
/// - Self loops
/// - Combinations of the above

TEST(TestTarjanAlgoSSC, empty_graph)
{
    DirectedGraph<int> digraph{{}, {}};

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{0};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    std::set<std::set<int>> expected_sscs{};
    EXPECT_EQ(ssc_sets, expected_sscs);
}

TEST(TestTarjanAlgoSSC, single_self_loop)
{
    DirectedGraph<int> digraph{{1}, {{1, 1}}};

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{1};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    std::set<std::set<int>> expected_sscs{{1}};
    EXPECT_EQ(ssc_sets, expected_sscs);
}

TEST(TestTarjanAlgoSSC, multiple_self_loop_weakly_connected)
{
    DirectedGraph<int> digraph{{1, 2, 3}, {{1, 1}, {1, 2}, {2, 2}, {2, 3}, {3, 3}}};

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{3};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    std::set<std::set<int>> expected_sscs{{1}, {2}, {3}};
    EXPECT_EQ(ssc_sets, expected_sscs);
}


TEST(TestTarjanAlgoSSC, medium_complexity1)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
        {
            {1, 11}, {1, 15}, {3, 10}, {4, 1}, {4, 15}, {5, 14}, {6, 8},
            {7, 3}, {8, 4}, {8, 7}, {9, 2}, {9, 8}, {9, 11}, {11, 12},
            {12, 4}, {12, 10}, {13, 9}, {13, 11}, {14, 2}, {15, 5}
        }
    };

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{12};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    const std::set<int> first_SSC{1, 4, 1, 112};
    const std::set<int> second_SSC{2, 4};
    const std::set<int> third_SSC{3};
    const std::set<int> fourth_SSC{5};
    const std::set<int> fifth_SSC{6};
    std::set<std::set<int>> expected_sscs{{2}, {14}, {5}, {15}, {10}, {1, 4, 11, 12}, {3}, {7}, {8}, {6}, {9}, {13}};
    EXPECT_EQ(ssc_sets, expected_sscs);
}


TEST(TestTarjanAlgoSSC, medium_complexity2)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {
            {1, 18}, {2, 9}, {2, 10}, {3, 9},
            {4, 9}, {4, 18}, {5, 1}, {5, 13}, {6, 1}, {6, 2},
            {6, 3}, {6, 8}, {6, 13}, {7, 4}, {7, 9}, {7, 15},
            {8, 16}, {8, 19}, {9, 5}, {9, 11}, {10, 12}, {11, 7},
            {12, 11}, {12, 20}, {13, 15}, {15, 11}, {17, 1}, {17, 3},
            {17, 18}, {18, 17}
        }
    };

    auto ssc_sets = strongly_connected_components_tarjan(digraph);
    constexpr int expected_number_of_strongly_connected_components{10};
    EXPECT_EQ(ssc_sets.size(), expected_number_of_strongly_connected_components);
    const std::set<int> first_SSC{1, 4, 1, 112};
    const std::set<int> second_SSC{2, 4};
    const std::set<int> third_SSC{3};
    const std::set<int> fourth_SSC{5};
    const std::set<int> fifth_SSC{6};
    std::set<std::set<int>> expected_sscs{
        {1, 3, 4, 5, 7, 9, 11, 13, 15, 17, 18},
        {20}, {12}, {10}, {2}, {16}, {19}, {8}, {6}, {14}
    };
    EXPECT_EQ(ssc_sets, expected_sscs);
}
