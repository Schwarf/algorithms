//
// Created by andreas on 15.04.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/compute_sum_root_to_all_leafs.h"


TEST_F(SetupBinaryTree, TestComputeSumRootToAllLeafsBasic) {
    auto tree = new TreeNode<double>(2.56);
    constexpr double expected_result{2.56};
    EXPECT_EQ(expected_result, sum_of_root_to_leafs(tree));
}

TEST_F(SetupBinaryTree, TestComputeSumRootToAllLeafsSimple) {
    auto tree = small_tree_with_subtree_duplicates();
    constexpr unsigned int expected_result{24};
    EXPECT_EQ(expected_result, sum_of_root_to_leafs(tree));
}

TEST_F(SetupBinaryTree, TestComputeSumRootToAllLeafsMedium) {
    auto tree = medium_tree_with_subtree_duplicates2();
    constexpr unsigned int expected_result{246};
    EXPECT_EQ(expected_result, sum_of_root_to_leafs(tree));
}


TEST_F(SetupBinaryTree, TestComputeSumRootToAllLeafsComplex) {
    auto [tree, _] = k_distance_tree2();
    constexpr unsigned int expected_result{8035};
    EXPECT_EQ(expected_result, sum_of_root_to_leafs(tree));
}


