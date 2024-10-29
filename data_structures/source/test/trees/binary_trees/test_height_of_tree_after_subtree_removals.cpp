//
// Created by andreas on 29.10.24.
//
#include "trees/binary_trees/height_of_tree_after_subtree_removals.h"
#include "setup_binary_tree.h"

TEST_F(SetupBinaryTree, RemoveSubtreesViaQueriesSimple1) {
    auto tuple = trees_and_heights_after_removing_subtrees1();
    EXPECT_EQ(height_of_trees(std::get<0>(tuple), std::get<1>(tuple)), std::get<2>(tuple));
}

TEST_F(SetupBinaryTree, RemoveSubtreesViaQueriesSimple2) {
    auto tuple = trees_and_heights_after_removing_subtrees2();
    EXPECT_EQ(height_of_trees(std::get<0>(tuple), std::get<1>(tuple)), std::get<2>(tuple));
}
