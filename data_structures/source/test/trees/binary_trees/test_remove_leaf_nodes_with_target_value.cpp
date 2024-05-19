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
    expected_result_tree->left->right = new TreeNode<unsigned int>(3);
    expected_result_tree->right->left = new TreeNode<unsigned int>(4);
    expected_result_tree->right->right = new TreeNode<unsigned int>(5);
    auto result = pre_order_traversal(result_tree);
    auto expected_result = pre_order_traversal(expected_result_tree);
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupBinaryTree, RemoveLeafNodesSimple2) {
    auto input = medium_tree_with_subtree_duplicates2();
    constexpr unsigned int target{3U};
    auto result_tree = remove_leaf_nodes(input, target);
    auto expected_result_tree = new TreeNode<unsigned int>(1);
    expected_result_tree->left = new TreeNode<unsigned int>(2);
    expected_result_tree->right = new TreeNode<unsigned int>(2);
    auto result = pre_order_traversal(result_tree);
    auto expected_result = pre_order_traversal(expected_result_tree);
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupBinaryTree, RemoveLeafNodesSimple3) {
    auto input = medium_tree_with_subtree_duplicates1();
    constexpr unsigned int target{4U};
    auto result_tree = remove_leaf_nodes(input, target);
    auto expected_result_tree = new TreeNode<unsigned int>(1);
    expected_result_tree->left = new TreeNode<unsigned int>(2);
    expected_result_tree->right = new TreeNode<unsigned int>(3);
    expected_result_tree->right->left = new TreeNode<unsigned int>(2);
    auto result = pre_order_traversal(result_tree);
    auto expected_result = pre_order_traversal(expected_result_tree);
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupBinaryTree, RemoveLeafNodesSimple4) {
    auto input = medium_tree_with_subtree_duplicates1();
    input->left->left = new TreeNode(4U);
    constexpr unsigned int target{4U};
    auto result_tree = remove_leaf_nodes(input, target);
    auto expected_result_tree = new TreeNode<unsigned int>(1);
    expected_result_tree->left = new TreeNode<unsigned int>(2);
    expected_result_tree->right = new TreeNode<unsigned int>(3);
    expected_result_tree->right->left = new TreeNode<unsigned int>(2);
    auto result = pre_order_traversal(result_tree);
    auto expected_result = pre_order_traversal(expected_result_tree);
    EXPECT_EQ(result, expected_result);
}


TEST_F(SetupBinaryTree, RemoveLeafNodesSimple5) {
    auto input = small_tree_with_subtree_duplicates();
    input->value = 2U;
    constexpr unsigned int target{2U};
    auto result_tree = remove_leaf_nodes(input, target);
    EXPECT_EQ(result_tree, nullptr);
}
