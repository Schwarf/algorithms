//
// Created by andreas on 14.12.24.
//

#include <gtest/gtest.h>

#include "graphs/planarity_testing/left_right_planarity_test.h"

class SetupLeftRightPlanarityTesting : public testing::Test
{
public:
    SetupLeftRightPlanarityTesting() = default;

    UndirectedGraph<int> path_graph()
    {
        UndirectedGraph<int> graph{{1,2,3,4}, {{1, 2}, {2, 3}, {3,4}}};
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