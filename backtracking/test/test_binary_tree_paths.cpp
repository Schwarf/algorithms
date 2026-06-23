//
// Created by andreas on 23.06.26.
//
#include <algorithm>
#include <string>
#include <vector>

#include <gtest/gtest.h>

// Include the header that defines TreeNode<int> and binary_tree_paths().
#include "../binary_tree_paths.h"

namespace
{

void expect_paths_equal(
    std::vector<std::string> actual,
    std::vector<std::string> expected)
{
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(actual, expected);
}

} // namespace

TEST(BinaryTreePathsTest, ReturnsEmptyVectorForEmptyTree)
{
    const auto result = binary_tree_paths(nullptr);

    EXPECT_TRUE(result.empty());
}

TEST(BinaryTreePathsTest, ReturnsSinglePathForSingleNodeTree)
{
    TreeNode<int> root{42};

    const auto result = binary_tree_paths(&root);

    expect_paths_equal(result, {"42"});
}

TEST(BinaryTreePathsTest, ReturnsPathsForExampleTree)
{
    //     1
    //    / \
    //   2   3
    //    \
    //     5
    TreeNode<int> root{1};
    TreeNode<int> left{2};
    TreeNode<int> right{3};
    TreeNode<int> left_right{5};

    root.left = &left;
    root.right = &right;
    left.right = &left_right;

    const auto result = binary_tree_paths(&root);

    expect_paths_equal(result, {"1->2->5", "1->3"});
}

TEST(BinaryTreePathsTest, HandlesLeftSkewedTree)
{
    //     1
    //    /
    //   2
    //  /
    // 3
    TreeNode<int> root{1};
    TreeNode<int> second{2};
    TreeNode<int> third{3};

    root.left = &second;
    second.left = &third;

    const auto result = binary_tree_paths(&root);

    expect_paths_equal(result, {"1->2->3"});
}

TEST(BinaryTreePathsTest, HandlesRightSkewedTree)
{
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode<int> root{1};
    TreeNode<int> second{2};
    TreeNode<int> third{3};

    root.right = &second;
    second.right = &third;

    const auto result = binary_tree_paths(&root);

    expect_paths_equal(result, {"1->2->3"});
}

TEST(BinaryTreePathsTest, HandlesTreeWithSeveralLeaves)
{
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6
    TreeNode<int> root{1};
    TreeNode<int> left{2};
    TreeNode<int> right{3};
    TreeNode<int> left_left{4};
    TreeNode<int> left_right{5};
    TreeNode<int> right_right{6};

    root.left = &left;
    root.right = &right;
    left.left = &left_left;
    left.right = &left_right;
    right.right = &right_right;

    const auto result = binary_tree_paths(&root);

    expect_paths_equal(
        result,
        {
            "1->2->4",
            "1->2->5",
            "1->3->6",
        });
}

TEST(BinaryTreePathsTest, HandlesNegativeAndMultiDigitValues)
{
    //      -10
    //      / \
    //     25  7
    TreeNode<int> root{-10};
    TreeNode<int> left{25};
    TreeNode<int> right{7};

    root.left = &left;
    root.right = &right;

    const auto result = binary_tree_paths(&root);

    expect_paths_equal(result, {"-10->25", "-10->7"});
}

TEST(BinaryTreePathsTest, RestoresCurrentPathAfterBacktracking)
{
    //     1
    //    / \
    //   2   3
    TreeNode<int> root{1};
    TreeNode<int> left{2};
    TreeNode<int> right{3};

    root.left = &left;
    root.right = &right;

    std::vector<std::string> result;
    std::string current{"prefix"};

    backtrack(result, current, &root);

    // Verifies that current.resize(old_size) restores the caller's state.
    EXPECT_EQ(current, "prefix");

    expect_paths_equal(
        result,
        {
            "prefix->1->2",
            "prefix->1->3",
        });
}