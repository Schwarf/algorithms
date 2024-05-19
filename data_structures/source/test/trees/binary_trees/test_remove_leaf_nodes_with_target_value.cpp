//
// Created by andreas on 19.05.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/pre_order_traversal.h"
#include "trees/binary_trees/remove_leafe_nodes_with_target_value.h"

TEST_F(SetupBinaryTree, RemoveLeafNodesSimple1) {
    auto input = medium_tree_with_subtree_duplicates3();
    constexpr unsigned int target{2U};
    auto result_tree = remove_leaf_nodes(input, target);
    auto expected_result_tree = new TreeNode<unsigned int>(2);
    expected_result_tree->left = new TreeNode<unsigned int>(1);
    expected_result_tree->right = new TreeNode<unsigned int>(1);
    expected_result_tree->left->left = new TreeNode<unsigned int>(2);
    expected_result_tree->left->right = new TreeNode<unsigned int>(3);
    expected_result_tree->right->left = new TreeNode<unsigned int>(4);
    expected_result_tree->right->right = new TreeNode<unsigned int>(5);
    auto result = pre_order_traversal(result_tree);
    auto expected_result = pre_order_traversal(expected_result_tree);
    EXPECT_EQ(result, expected_result);
}