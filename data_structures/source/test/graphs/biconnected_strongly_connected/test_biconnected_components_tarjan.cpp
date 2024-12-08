//
// Created by andreas on 04.11.24.
//

#include "graphs/biconnected_strongly_connected/biconnected_components_tarjan.h"
#include "gtest/gtest.h"

TEST(TestTarjanAlgoBi, simple1)
{
    auto graph = UndirectedGraph<int>{
        {1, 2, 3, 4, 5, 6, 7}, {{1, 2}, {2, 5}, {3, 4}, {3, 5}, {3, 6}, {3, 7}, {4, 6}, {4, 7}, {5, 6}}
    };

    auto result = biconnected_components_tarjan(graph);
    std::set<std::set<int>> expected_result{{4, 7, 6, 3, 5}, {1, 2}, {2, 5}};
    EXPECT_EQ(result, expected_result);
}


TEST(TestTarjanAlgoBi, simple2)
{
    auto graph = UndirectedGraph<int>{{1, 2, 3}, {{1, 2}, {2, 3}, {1, 3}}};

    auto result = biconnected_components_tarjan(graph);
    std::set<std::set<int>> expected_result{{1, 2, 3}};
    EXPECT_EQ(result, expected_result);
}

TEST(TestTarjanAlgoBi, simple3)
{
    auto graph = UndirectedGraph<int>{{1, 2, 3}, {{1, 2}, {2, 3}}};

    auto result = biconnected_components_tarjan(graph);
    std::set<std::set<int>> expected_result{{1, 2}, {2, 3}};
    EXPECT_EQ(result, expected_result);
}


TEST(TestTarjanAlgoBi, simple4)
{
    auto graph = UndirectedGraph<int>{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
            {1, 2}, {1, 5}, {2, 3}, {2, 4}, {2, 7}, {2, 10}, {3, 4}, {3, 9}, {
                4, 5
            },
            {4, 6}, {4, 8}, {4, 10}, {5, 6}, {5, 7}, {5, 10}, {6, 7}, {
                6, 8
            },
            {7, 9}, {9, 10}
        }
    };

    auto result = biconnected_components_tarjan(graph);
    std::set<std::set<int>> expected_result{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    EXPECT_EQ(result, expected_result);
}
