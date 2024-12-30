//
// Created by andreas on 28.12.24.
//
#include "graphs/topological_sort/kahns_algorithm.h"
#include "gtest/gtest.h"


class SetupTopologicalSortTesting : public testing::Test
{
public:
    SetupTopologicalSortTesting() = default;

protected:
    template <typename NodeType>
    void verify_topological_order(const DirectedGraph<NodeType>& graph, std::vector<NodeType>& order)
    {
        std::unordered_map<NodeType, int> position;
        for (int i{}; i < order.size(); ++i)
        {
            position[order[i]] = i;
        }

        EXPECT_EQ(order.size(), graph.get_all_nodes().size());
        auto nodes = graph.get_all_nodes();
        for (const auto node : nodes)
        {
            for (const auto neighbor : graph.get_neighbors(node))
            {
                EXPECT_TRUE(position[node] < position[neighbor]);
            }
        }
    }
};


TEST_F(SetupTopologicalSortTesting, simple1)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {
            {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7},
            {1, 8}, {1, 9}, {1, 10}, {2, 3}, {2, 4},
            {2, 9}, {2, 10}, {3, 4}, {3, 6}, {3, 8},
            {3, 9}, {3, 10}, {4, 5}, {4, 6}, {4, 7},
            {4, 8}, {4, 9}, {5, 6}, {5, 7}, {5, 8},
            {5, 9}, {6, 7}, {6, 8}, {6, 9}, {6, 10},
            {7, 8}, {7, 10}, {8, 9}
        }
    };
    std::vector<int> expected_result{1, 2, 3, 4, 5, 6, 7, 10, 8, 9};
    auto computed_order = kahns_algorithm(digraph);
    EXPECT_EQ(kahns_algorithm(digraph), expected_result);
    verify_topological_order(digraph, computed_order);
}

TEST_F(SetupTopologicalSortTesting, simple2)
{
    DirectedGraph<int> digraph{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, {
            {1, 3}, {1, 5}, {1, 7}, {1, 9}, {1, 11}, {1, 15}, {1, 18}, {2, 3}, {
                2, 6
            },
            {2, 7}, {2, 9}, {2, 11}, {2, 12}, {2, 13}, {2, 14}, {2, 17}, {
                2, 20
            },
            {3, 5}, {3, 8}, {3, 9}, {3, 17}, {3, 19}, {4, 5}, {4, 9}, {
                4, 10
            },
            {4, 11}, {4, 16}, {4, 20}, {5, 7}, {5, 10}, {5, 11}, {
                5, 16
            },
            {6, 8}, {6, 12}, {7, 8}, {7, 9}, {7, 13}, {7, 14}, {7, 15}, {
                7, 16
            },
            {7, 17}, {8, 9}, {8, 10}, {8, 14}, {8, 15}, {8, 20}, {
                9, 10
            },
            {9, 12}, {9, 18}, {11, 12}, {11, 13}, {11, 14}, {11, 16}, {
                11, 17
            },
            {11, 19}, {11, 20}, {12, 13}, {12, 15}, {12, 16}, {12, 17}, {
                12, 19
            },
            {13, 16}, {13, 20}, {14, 20}, {15, 18}, {16, 19}
        }
    };
    auto computed_order = kahns_algorithm(digraph);
    verify_topological_order(digraph, computed_order);
}
