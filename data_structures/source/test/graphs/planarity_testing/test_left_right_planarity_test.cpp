//
// Created by andreas on 14.12.24.
//

#include <gtest/gtest.h>

#include "graphs/planarity_testing/left_right_planarity_test.h"

class SetupLeftRightPlanarityTesting : public testing::Test
{
public:
    SetupLeftRightPlanarityTesting() = default;

    static UndirectedGraph<int> path_graph()
    {
        UndirectedGraph<int> graph{{1, 2, 3, 4}, {{1, 2}, {2, 3}, {3, 4}}};
        return graph;
    }

    static UndirectedGraph<int> cycle_graph()
    {
        UndirectedGraph<int> graph{{1, 2, 3, 4, 5, 6}, {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 1}}};
        return graph;
    }

    static UndirectedGraph<int> star_graph()
    {
        UndirectedGraph<int> graph{{1, 2, 3, 4, 5, 6}, {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}}};
        return graph;
    }

    static UndirectedGraph<int> complete_graph_k5()
    {
        UndirectedGraph<int> graph{{1, 2, 3, 4, 5}, {{1, 2}, {1, 3}, {1, 4}, {1, 5},
                                                                {2, 3}, {2, 4}, {2, 5},
                                                                {3, 4}, {3, 5}, {4, 5}}};
        return graph;
    }

};


TEST_F(SetupLeftRightPlanarityTesting, PathGraph)
{
    auto graph = path_graph();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CycleGraph)
{
    auto graph = cycle_graph();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, StarGraph)
{
    auto graph = star_graph();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}


TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK5)
{
    auto graph = complete_graph_k5();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}
