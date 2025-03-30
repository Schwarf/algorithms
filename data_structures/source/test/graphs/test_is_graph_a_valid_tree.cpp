//
// Created by andreas on 24.11.23.
//

#include "gtest/gtest.h"
#include "graphs/is_graph_valid_tree.h"

TEST(IsGraphAValidTree, simple1)
{
    const std::vector<std::vector<unsigned int>> edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    constexpr int number_of_nodes{5};
    EXPECT_TRUE(is_graph_valid_tree(number_of_nodes, edges));
}

TEST(IsGraphAValidTree, simple2)
{
    const std::vector<std::vector<unsigned int>> edges{{0, 1}, {2, 0}, {3, 0}, {1, 4}};
    constexpr int number_of_nodes{5};
    EXPECT_TRUE(is_graph_valid_tree(number_of_nodes, edges));
}

TEST(IsGraphAValidTree, simple3)
{
    const std::vector<std::vector<unsigned int>> edges{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    constexpr int number_of_nodes{5};
    EXPECT_FALSE(is_graph_valid_tree(number_of_nodes, edges));
}

TEST(IsGraphAValidTree, medium1)
{
    const std::vector<std::vector<unsigned int>>
        edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {3, 7}, {5, 8}, {5, 9}, {6, 10}};
    constexpr int number_of_nodes{11};
    EXPECT_TRUE(is_graph_valid_tree(number_of_nodes, edges));
}

TEST(IsGraphAValidTree, medium2)
{
    const std::vector<std::vector<unsigned int>>
        edges{{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 0}};
    constexpr int number_of_nodes{11};
    EXPECT_FALSE(is_graph_valid_tree(number_of_nodes, edges));
}

TEST(IsGraphAValidTree, simple4)
{
    const std::vector<std::vector<unsigned int>>
        edges{{}};
    constexpr int number_of_nodes{0};
    EXPECT_FALSE(is_graph_valid_tree(number_of_nodes, edges));
}

TEST(IsGraphAValidTree, simple5)
{
    const std::vector<std::vector<unsigned int>>
        edges{{0, 1}, {1, 0}};
    constexpr int number_of_nodes{2};
    EXPECT_FALSE(is_graph_valid_tree(number_of_nodes, edges));
}

TEST(IsGraphAValidTreeSet, simple1)
{
    const std::vector<std::vector<unsigned int>> edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    constexpr int number_of_nodes{5};
    EXPECT_TRUE(is_graph_valid_tree_with_set(number_of_nodes, edges));
}

TEST(IsGraphAValidTreeSet, simple2)
{
    const std::vector<std::vector<unsigned int>> edges{{0, 1}, {2, 0}, {3, 0}, {1, 4}};
    constexpr int number_of_nodes{5};
    EXPECT_TRUE(is_graph_valid_tree_with_set(number_of_nodes, edges));
}

TEST(IsGraphAValidTreeSet, simple3)
{
    const std::vector<std::vector<unsigned int>> edges{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    constexpr int number_of_nodes{5};
    EXPECT_FALSE(is_graph_valid_tree_with_set(number_of_nodes, edges));
}

TEST(IsGraphAValidTreeSet, medium1)
{
    const std::vector<std::vector<unsigned int>>
        edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {3, 7}, {5, 8}, {5, 9}, {6, 10}};
    constexpr int number_of_nodes{11};
    EXPECT_TRUE(is_graph_valid_tree_with_set(number_of_nodes, edges));
}

TEST(IsGraphAValidTreeSet, medium2)
{
    const std::vector<std::vector<unsigned int>>
        edges{{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 0}};
    constexpr int number_of_nodes{11};
    EXPECT_FALSE(is_graph_valid_tree_with_set(number_of_nodes, edges));
}

TEST(IsGraphAValidTreeSet, simple4)
{
    const std::vector<std::vector<unsigned int>>
        edges{{}};
    constexpr int number_of_nodes{0};
    EXPECT_FALSE(is_graph_valid_tree_with_set(number_of_nodes, edges));
}

TEST(IsGraphAValidTreeSet, simple5)
{
    const std::vector<std::vector<unsigned int>>
        edges{{0, 1}, {1, 0}};
    constexpr int number_of_nodes{2};
    EXPECT_FALSE(is_graph_valid_tree_with_set(number_of_nodes, edges));
}
