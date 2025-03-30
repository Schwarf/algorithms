//
// Created by andreas on 10.07.23.
//

#include "setup_binary_tree.h"
#include "trees/binary_trees/minimum_depth_of_binary_tree.h"

TEST_F(SetupBinaryTree, four_level_tree)
{
    auto tree = binary_tree_root();
    constexpr int expected_result{4};
    EXPECT_EQ(minimum_depth_binary_tree_dfs(tree), expected_result);
}

TEST_F(SetupBinaryTree, empty_tree)
{
    TreeNode<double>* tree = nullptr;
    constexpr int expected_result{0};
    EXPECT_EQ(minimum_depth_binary_tree_dfs(tree), expected_result);
}

TEST_F(SetupBinaryTree, small_tree)
{
    auto tree = small_binary_tree_root();
    constexpr int expected_result{2};
    EXPECT_EQ(minimum_depth_binary_tree_dfs(tree), expected_result);
}

TEST_F(SetupBinaryTree, imbalanced_right_tree)
{
    auto tree = imbalanced_right_tree();
    constexpr int expected_result{3};
    EXPECT_EQ(minimum_depth_binary_tree_dfs(tree), expected_result);
}

TEST_F(SetupBinaryTree, four_level_tree_bfs)
{
    auto tree = binary_tree_root();
    constexpr int expected_result{4};
    EXPECT_EQ(minimum_depth_binary_tree_bfs(tree), expected_result);
}

TEST_F(SetupBinaryTree, empty_tree_bfs)
{
    TreeNode<double>* tree = nullptr;
    constexpr int expected_result{0};
    EXPECT_EQ(minimum_depth_binary_tree_bfs(tree), expected_result);
}

TEST_F(SetupBinaryTree, small_tree_bfs)
{
    auto tree = small_binary_tree_root();
    constexpr int expected_result{2};
    EXPECT_EQ(minimum_depth_binary_tree_bfs(tree), expected_result);
}

TEST_F(SetupBinaryTree, imbalanced_right_tree_bfs)
{
    auto tree = imbalanced_right_tree();
    constexpr int expected_result{3};
    EXPECT_EQ(minimum_depth_binary_tree_bfs(tree), expected_result);
}
