//
// Created by andreas on 04.11.23.
//
#include "gtest/gtest.h"
#include "setup_binary_tree.h"
#include "trees/binary_trees/maximum_path_sum.h"


TEST_F(SetupBinaryTree, all) {
    auto cases = trees_maximum_path_sum();
    for (const auto &[root, result]: cases) {
        EXPECT_EQ(max_path_sum(root), result);
    }
}

