//
// Created by andreas on 14.07.22.
//

#include "setup_binary_tree.h"
#include "trees/binary_trees/construct_binary_tree_from_inorder_and_postorder.h"
#include "trees/binary_trees/pre_order_traversal.h"

// Empty tree
TEST_F(SetupBinaryTree, EmptyInorderPostorder) {
    std::vector<int> inorder;
    std::vector<int> postorder;
    EXPECT_EQ(construct_from_inorder_and_postorder(inorder, postorder), nullptr);
}
// Single-node tree
TEST_F(SetupBinaryTree, SingleNodeInorderPostorder) {
    std::vector<int> inorder{42};
    std::vector<int> postorder{42};
    TreeNode<int>* root = construct_from_inorder_and_postorder(inorder, postorder);
    TreeNode<int>* expected = new TreeNode<int>(42);
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, LeftSkewedInorderPostorder) {
    std::vector<int> inorder{1, 2, 3};
    std::vector<int> postorder{1, 2, 3};
    TreeNode<int>* root = construct_from_inorder_and_postorder(inorder, postorder);
    TreeNode<int>* expected = new TreeNode<int>(3, new TreeNode<int>(2, new TreeNode<int>(1), nullptr), nullptr);
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, RightSkewedInorderPostorder) {
    std::vector<int> inorder{1, 2, 3};
    std::vector<int> postorder{3, 2, 1};
    TreeNode<int>* root = construct_from_inorder_and_postorder(inorder, postorder);
    TreeNode<int>* expected = new TreeNode<int>(1, nullptr, new TreeNode<int>(2, nullptr, new TreeNode<int>(3)));
    EXPECT_TRUE(is_same_tree(root, expected));
}

TEST_F(SetupBinaryTree, FullSevenNodeInorderPostorder) {
    std::vector<int> inorder{1,2,3,4,5,6,7};
    std::vector<int> postorder{1,3,2,5,7,6,4};
    TreeNode<int>* root = construct_from_inorder_and_postorder(inorder, postorder);
    TreeNode<int>* expected = new TreeNode<int>(4,
        new TreeNode<int>(2, new TreeNode<int>(1), new TreeNode<int>(3)),
        new TreeNode<int>(6, new TreeNode<int>(5), new TreeNode<int>(7))
    );
    EXPECT_TRUE(is_same_tree(root, expected));
}
TEST_F(SetupBinaryTree, test_construct_binary_tree_from_inorder_and_postorder)
{
    auto constructed_root = construct_from_inorder_and_postorder(postorder, inorder);
    auto result_constructed = pre_order_traversal_recursive(constructed_root);
    for (size_t index = 0; index < preorder.size(); ++index)
    {
        EXPECT_EQ(result_constructed.at(index), preorder.at(index));
    }
}
