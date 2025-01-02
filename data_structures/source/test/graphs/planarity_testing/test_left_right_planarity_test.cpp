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

    static UndirectedGraph<int> complete_graph_k3()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3}, {
                {1, 2}, {1, 3}, {2, 3}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> complete_graph_k4()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3, 4}, {
                {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> complete_graph_k5()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3, 4, 5}, {
                {1, 2}, {1, 3}, {1, 4}, {1, 5},
                {2, 3}, {2, 4}, {2, 5},
                {3, 4}, {3, 5}, {4, 5}
            }
        };
        return graph;
    }

    static UndirectedGraph<int> complete_graph_k6()
    {
        UndirectedGraph<int> graph{
            {1, 2, 3, 4, 5, 6}, {
                {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6},
                {2, 3}, {2, 4}, {2, 5},
                {2, 6}, {3, 4}, {3, 5}, {3, 6}, {4, 5}, {4, 6}, {5, 6}
            }
        };
        return graph;
    }

    static UndirectedGraph<short> generalized_petersen_graph_5_1()
    {
        UndirectedGraph<short> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
                {1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 7}, {3, 4},
                {3, 8}, {4, 5}, {4, 9}, {5, 10}, {6, 7}, {6, 10},
                {7, 8}, {8, 9}, {9, 10}
            }
        };
        return graph;
    }

    static UndirectedGraph<short> generalized_petersen_graph_5_2()
    {
        UndirectedGraph<short> graph{
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
                {1, 3}, {1, 4}, {1, 6}, {2, 4}, {2, 5}, {2, 7},
                {3, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 7}, {6, 10},
                {7, 8}, {8, 9}, {9, 10}
            }
        };
        return graph;
    }

    static UndirectedGraph<short> utility_graph()
    {
        UndirectedGraph<short> graph{
                {1, 2, 3, 4, 5, 6}, {
                    {1, 4}, {1, 5}, {1, 6},
                    {2, 4}, {2, 5}, {2, 6},
                    {3, 4}, {3, 5}, {3, 6}}
        };
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

TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK3)
{
    auto graph = complete_graph_k3();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK4)
{
    auto graph = complete_graph_k4();
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

TEST_F(SetupLeftRightPlanarityTesting, CompleteGraphK6)
{
    auto graph = complete_graph_k6();
    PlanarityTest<int> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, PetersenGraph_5_1)
{
    auto graph = generalized_petersen_graph_5_1();
    PlanarityTest<short> test(graph);
    test.run();
    EXPECT_TRUE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, PetersenGraph_5_2)
{
    auto graph = generalized_petersen_graph_5_2();
    PlanarityTest<short> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}

TEST_F(SetupLeftRightPlanarityTesting, UtilityGraph)
{
    auto graph = utility_graph();
    PlanarityTest<short> test(graph);
    test.run();
    EXPECT_FALSE(test.is_graph_planar());
}
