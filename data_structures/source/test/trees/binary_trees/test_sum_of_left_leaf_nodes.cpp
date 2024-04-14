//
// Created by andreas on 14.04.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/sum_of_left_leaf_nodes.h"

TEST_F(SetupBinaryTree, TestSumOfLeftLeafNodeSimple1) {
    auto tree = small_binary_tree_root();
    constexpr int expected_result{24};
    EXPECT_EQ(sum_of_left_leafs(tree), expected_result);
}

TEST_F(SetupBinaryTree, TestSumOfLeftLeafNodeSimple2) {
    auto tree = small_tree_with_subtree_duplicates();
    constexpr int expected_result{2};
    EXPECT_EQ(sum_of_left_leafs(tree), expected_result);
}

TEST_F(SetupBinaryTree, TestSumOfLeftLeafNodeSimple3) {
    auto tree = new TreeNode<float>(2.6f);
    constexpr float expected_result{};
    EXPECT_EQ(sum_of_left_leafs(tree), expected_result);
}

TEST_F(SetupBinaryTree, TestSumOfLeftLeafNodeSimple4) {
    auto tree = imbalanced_right_tree();
    constexpr unsigned int expected_result{4};
    EXPECT_EQ(sum_of_left_leafs(tree), expected_result);
}

TEST_F(SetupBinaryTree, TestSumOfLeftLeafNodeSimple5) {
    auto tree = infected_tree1();
    constexpr int expected_result{19};
    EXPECT_EQ(sum_of_left_leafs(tree), expected_result);
}

TEST_F(SetupBinaryTree, TestSumOfLeftLeafNodeSimple6) {
    auto tree = even_odd_tree2();
    constexpr int expected_result{4};
    EXPECT_EQ(sum_of_left_leafs(tree), expected_result);
}
