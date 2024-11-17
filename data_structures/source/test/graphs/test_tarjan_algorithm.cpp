//
// Created by andreas on 04.11.24.
//

#include "graphs/tarjan_algorithm.h"
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
    std::set<std::set<int>> expected_result{{1,2,3}};
    EXPECT_EQ(result, expected_result);
}
