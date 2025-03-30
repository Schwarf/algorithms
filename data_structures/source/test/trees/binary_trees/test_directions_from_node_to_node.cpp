//
// Created by andreas on 16.07.24.
//

#include "trees/binary_trees/directions_from_node_to_node.h"
#include "setup_binary_tree.h"
#include "gtest/gtest.h"

TEST_F(SetupBinaryTree, DirectionsFromNodeToNode_simple1)
{
    auto tuple = SetupBinaryTree::node_to_node_directions1();
    EXPECT_EQ(std::get<3>(tuple), get_directions(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}

TEST_F(SetupBinaryTree, DirectionsFromNodeToNode_simple2)
{
    auto tuple = SetupBinaryTree::node_to_node_directions2();
    EXPECT_EQ(std::get<3>(tuple), get_directions(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}

TEST_F(SetupBinaryTree, DirectionsFromNodeToNode_simple3)
{
    auto tuple = SetupBinaryTree::node_to_node_directions3();
    EXPECT_EQ(std::get<3>(tuple), get_directions(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}

TEST_F(SetupBinaryTree, DirectionsFromNodeToNode_simple4)
{
    auto tuple = SetupBinaryTree::node_to_node_directions4();
    EXPECT_EQ(std::get<3>(tuple), get_directions(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}

TEST_F(SetupBinaryTree, DirectionsFromNodeToNode_simple5)
{
    auto tuple = SetupBinaryTree::node_to_node_directions5();
    EXPECT_EQ(std::get<3>(tuple), get_directions(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}


TEST_F(SetupBinaryTree, DirectionsFromNodeToNodeLCA_simple1)
{
    auto tuple = SetupBinaryTree::node_to_node_directions1();
    EXPECT_EQ(std::get<3>(tuple), get_directions_lca(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}

TEST_F(SetupBinaryTree, DirectionsFromNodeToNodeLCA_simple2)
{
    auto tuple = SetupBinaryTree::node_to_node_directions2();
    EXPECT_EQ(std::get<3>(tuple), get_directions_lca(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}

TEST_F(SetupBinaryTree, DirectionsFromNodeToNodeLCA_simple3)
{
    auto tuple = SetupBinaryTree::node_to_node_directions3();
    EXPECT_EQ(std::get<3>(tuple), get_directions_lca(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}

TEST_F(SetupBinaryTree, DirectionsFromNodeToNodeLCA_simple4)
{
    auto tuple = SetupBinaryTree::node_to_node_directions4();
    EXPECT_EQ(std::get<3>(tuple), get_directions_lca(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}

TEST_F(SetupBinaryTree, DirectionsFromNodeToNodeLCA_simple5)
{
    auto tuple = SetupBinaryTree::node_to_node_directions5();
    EXPECT_EQ(std::get<3>(tuple), get_directions_lca(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}
