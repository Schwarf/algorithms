//
// Created by andreas on 14.07.22.
//

#include "setup_binary_tree.h"
#include "trees/binary_trees/construct_binary_tree_from_preorder_and_inorder.h"
#include "trees/binary_trees/post_order_traversal.h"
#include "trees/binary_trees/in_order_traversal.h"

template <typename T>
static bool is_same_tree(TreeNode<T>* a, TreeNode<T>* b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    if (a->value != b->value)
        return false;
    return is_same_tree(a->left, b->left) && is_same_tree(a->right, b->right);
}


TEST_F(SetupBinaryTree, Empty)
{
    std::vector<int> preorder;
    std::vector<int> inorder;
    EXPECT_EQ(construct_from_preorder_and_inorder(preorder, inorder), nullptr);
}

TEST_F(SetupBinaryTree, SingleNode)
{
    std::vector<int> preorder{42};
    std::vector<int> inorder{42};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    auto const expected = new TreeNode<int>(42);
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, LeftSkewed)
{
    std::vector<int> preorder{3, 2, 1};
    std::vector<int> inorder{1, 2, 3};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    const auto expected = new TreeNode<int>(3, new TreeNode<int>(2, new TreeNode(1), nullptr), nullptr);
    EXPECT_TRUE(is_same_tree(root, expected));
}


TEST_F(SetupBinaryTree, RightSkewed)
{
    std::vector<int> preorder{1, 2, 3};
    std::vector<int> inorder{1, 2, 3};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    const auto expected = new TreeNode<int>(1, nullptr, new TreeNode<int>(2, nullptr, new TreeNode<int>(3)));
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, test_construct_binary_tree_from_preorder_and_inorder)
{
    auto constructed_root = construct_from_preorder_and_inorder(preorder, inorder);
    auto result_constructed = post_order_traversal_recursive(constructed_root);
    auto result_constructed2 = in_order_traversal(constructed_root);
    for (size_t index = 0; index < postorder.size(); ++index)
    {
        EXPECT_EQ(result_constructed.at(index), postorder.at(index));
        EXPECT_EQ(result_constructed2.at(index), inorder.at(index));
    }
}
