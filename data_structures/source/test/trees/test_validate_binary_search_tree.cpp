//
// Created by andreas on 28.06.25.
//
#include "trees/binary_trees/validate_binary_search_tree.h"

#include "gtest/gtest.h"

template <typename T>
static TreeNode<T>* newNode(T val, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr)
{
    TreeNode<T>* node = new TreeNode(val);
    node->left = left;
    node->right = right;
    return node;
}

// Corner case: empty tree
TEST(is_valid_BSTTest, EmptyTree)
{
    EXPECT_TRUE(is_valid_BST<int>(nullptr));
}

// Single-node tree should always be valid
TEST(is_valid_BSTTest, SingleNode)
{
    EXPECT_TRUE(is_valid_BST(new TreeNode(42)));
}

TEST(is_valid_BSTTest, SimpleThreeNodeValid)
{
    auto root = newNode(2, newNode(1), newNode(3));
    EXPECT_TRUE(is_valid_BST(root));
}

/* Simple invalid BST: immediate child violation
      1
       \
        1
*/
TEST(is_valid_BSTTest, DuplicateImmediateChild)
{
    auto root = newNode<int>(1, nullptr, newNode(1));
    EXPECT_FALSE(is_valid_BST(root));
}

/* Invalid BST: deeper violation in right subtree
       10
      /  \
     5    15
         /  \
        6    20
*/
TEST(is_valid_BSTTest, RightSubtreeDeepViolation)
{
    auto root = newNode(10,
                        newNode(5),
                        newNode(15, newNode(6), newNode(20)));
    EXPECT_FALSE(is_valid_BST(root));
}

/* Invalid BST: deeper violation in left subtree
       10
      /  \
     5    15
      \
       11
*/
TEST(is_valid_BSTTest, LeftSubtreeDeepViolation)
{
    auto root = newNode<int>(10,
                        newNode<int>(5, nullptr, newNode(11)),
                        newNode<int>(15));
    EXPECT_FALSE(is_valid_BST(root));
}

// Valid BST including INT_MIN and INT_MAX
TEST(is_valid_BSTTest, IntMinMaxValues)
{
    auto root = newNode(0,
                        newNode(std::numeric_limits<int>::min()),
                        newNode(std::numeric_limits<int>::max()));
    EXPECT_TRUE(is_valid_BST(root));
}

/* Complex valid BST
         8
       /   \
      3     10
     / \      \
    1   6      14
       / \     /
//
      4   7   13
*/
TEST(is_valid_BSTTest, ComplexValidTree)
{
    auto root = newNode(8,
                        newNode(3,
                                newNode(1),
                                newNode(6, newNode(4), newNode(7))
                        ),
                        newNode<int>(10,
                                nullptr,
                                newNode<int>(14, newNode(13), nullptr)
                        )
    );
    EXPECT_TRUE(is_valid_BST(root));
}
