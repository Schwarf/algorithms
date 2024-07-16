//
// Created by andreas on 04.11.23.
//
#include "gtest/gtest.h"
#include "trees/binary_trees/find_mode_in_binary_tree.h"
#include "setup_binary_tree.h"

TEST_F(SetupBinaryTree, find_mode_dfs_iterative_in_small_tree) {
    const auto tree = small_tree_with_subtree_duplicates();
    EXPECT_EQ(find_mode_dfs_iterative(tree), std::vector<unsigned int>{2});
}

TEST_F(SetupBinaryTree, find_mode_dfs_recursive_in_small_tree) {
    const auto tree = small_tree_with_subtree_duplicates();
    EXPECT_EQ(find_mode_dfs_recursive(tree), std::vector<unsigned int>{2});
}

TEST_F(SetupBinaryTree, find_mode_bfs_in_small_tree) {
    const auto tree = small_tree_with_subtree_duplicates();
    EXPECT_EQ(find_mode_bfs(tree), std::vector<unsigned int>{2});
}


TEST_F(SetupBinaryTree, find_mode_dfs_iterative_in_medium_tree1) {
    const auto tree = medium_tree_with_subtree_duplicates1();
    EXPECT_EQ(find_mode_dfs_iterative(tree), std::vector<unsigned int>{4});
}

TEST_F(SetupBinaryTree, find_mode_dfs_recursive_in_medium_tree1) {
    const auto tree = medium_tree_with_subtree_duplicates1();
    EXPECT_EQ(find_mode_dfs_recursive(tree), std::vector<unsigned int>{4});
}

TEST_F(SetupBinaryTree, find_mode_bfs_in_medium_tree1) {
    const auto tree = medium_tree_with_subtree_duplicates1();
    EXPECT_EQ(find_mode_bfs(tree), std::vector<unsigned int>{4});
}

TEST_F(SetupBinaryTree, find_mode_dfs_iterative_in_medium_tree2) {
    const auto tree = medium_tree_with_subtree_duplicates2();
    const std::vector<unsigned int> expected_result{3, 2};
    EXPECT_EQ(expected_result, find_mode_dfs_iterative(tree));
}

TEST_F(SetupBinaryTree, find_mode_dfs_recursive_in_medium_tree2) {
    const auto tree = medium_tree_with_subtree_duplicates2();
    const std::vector<unsigned int> expected_result{3, 2};
    EXPECT_EQ(expected_result, find_mode_dfs_recursive(tree));
}

TEST_F(SetupBinaryTree, find_mode_bfs_in_medium_tree2) {
    const auto tree = medium_tree_with_subtree_duplicates2();
    const std::vector<unsigned int> expected_result{3, 2};
    EXPECT_EQ(expected_result, find_mode_bfs(tree));
}
