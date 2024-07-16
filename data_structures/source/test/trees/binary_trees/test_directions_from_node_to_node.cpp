//
// Created by andreas on 16.07.24.
//

#include "trees/binary_trees/directions_from_node_to_node.h"
#include "setup_binary_tree.h"
#include "gtest/gtest.h"

TEST_F(SetupBinaryTree, DirectionsFromNodeToNode_simple1) {
    auto tuple = SetupBinaryTree::node_to_node_directions1();
    EXPECT_EQ(std::get<3>(tuple), get_directions(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
}