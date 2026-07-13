//
// Created by andreas on 14.07.22.
//

#include <string>
#include "setup_binary_tree.h"
#include "trees/binary_trees/construct_binary_tree_from_preorder_and_inorder.h"
#include "trees/binary_trees/in_order_traversal.h"
#include "trees/binary_trees/post_order_traversal.h"

TEST_F(SetupBinaryTree, EmptyPreorderInorder)
{
    std::vector<int> preorder;
    std::vector<int> inorder;
    EXPECT_EQ(construct_from_preorder_and_inorder(preorder, inorder), nullptr);
}

TEST_F(SetupBinaryTree, MismatchedTraversalSizesPreorderInorder)
{
    std::vector<int> preorder{1, 2};
    std::vector<int> inorder{2};
    EXPECT_EQ(construct_from_preorder_and_inorder(preorder, inorder), nullptr);
}

TEST_F(SetupBinaryTree, SingleNodePreorderInorder)
{
    std::vector<int> preorder{42};
    std::vector<int> inorder{42};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    auto const expected = new TreeNode<int>(42);
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, LeftSkewedPreorderInorder)
{
    std::vector<int> preorder{3, 2, 1};
    std::vector<int> inorder{1, 2, 3};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    const auto expected = new TreeNode<int>(3, new TreeNode<int>(2, new TreeNode(1), nullptr), nullptr);
    EXPECT_TRUE(is_same_tree(root, expected));
}


TEST_F(SetupBinaryTree, RightSkewedPreorderInorder)
{
    std::vector<int> preorder{1, 2, 3};
    std::vector<int> inorder{1, 2, 3};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    const auto expected = new TreeNode<int>(1, nullptr, new TreeNode<int>(2, nullptr, new TreeNode<int>(3)));
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, FullSevenNodePreorderInorder)
{
    std::vector<int> preorder{4, 2, 1, 3, 6, 5, 7};
    std::vector<int> inorder{1, 2, 3, 4, 5, 6, 7};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    auto expected = new TreeNode<int>(4, new TreeNode<int>(2, new TreeNode<int>(1), new TreeNode<int>(3)),
                                      new TreeNode<int>(6, new TreeNode<int>(5), new TreeNode<int>(7)));
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, AsymmetricTreePreorderInorder)
{
    std::vector<int> preorder{3, 9, 20, 15, 7};
    std::vector<int> inorder{9, 3, 15, 20, 7};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    auto expected =
        new TreeNode<int>(3, new TreeNode<int>(9), new TreeNode<int>(20, new TreeNode<int>(15), new TreeNode<int>(7)));
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, NegativeValuesPreorderInorder)
{
    std::vector<int> preorder{-1, -2, -4, -5, -3};
    std::vector<int> inorder{-4, -2, -5, -1, -3};
    TreeNode<int>* root = construct_from_preorder_and_inorder(preorder, inorder);
    auto expected = new TreeNode<int>(-1, new TreeNode<int>(-2, new TreeNode<int>(-4), new TreeNode<int>(-5)),
                                      new TreeNode<int>(-3));
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, StringValuesPreorderInorder)
{
    std::vector<std::string> preorder{"root", "left", "right"};
    std::vector<std::string> inorder{"left", "root", "right"};
    TreeNode<std::string>* root = construct_from_preorder_and_inorder(preorder, inorder);
    auto expected =
        new TreeNode<std::string>("root", new TreeNode<std::string>("left"), new TreeNode<std::string>("right"));
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, ConstructsProvidedTreeFromPreorderInorder)
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
