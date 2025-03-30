//
// Created by andreas on 09.05.22.
//

#include "setup_binary_tree.h"
#include "trees/binary_trees/post_order_traversal.h"

template <typename T>
TreeNode<T>* insert_level_order(std::vector<T>& input, TreeNode<T>* root, int index, int number_of_nodes)
{
    if (index < number_of_nodes)
    {
        auto temp = new TreeNode<T>(input[index]);
        root = temp;

        root->left = insert_level_order(input, root->left, 2 * index + 1, number_of_nodes);
        root->right = insert_level_order(input, root->right, 2 * index + 2, number_of_nodes);
    }
    return root;
}

TEST_F(SetupBinaryTree, test_postorder_traversal)
{
    auto root = SetupBinaryTree::binary_tree_root();
    auto result = post_order_traversal_iterative(root);
    for (size_t index = 0; index < postorder.size(); ++index)
    {
        EXPECT_EQ(result.at(index), postorder.at(index));
    }
}

TEST_F(SetupBinaryTree, test_postorder_traversal_recursive)
{
    auto root = SetupBinaryTree::binary_tree_root();
    auto result = post_order_traversal_recursive(root);
    for (size_t index = 0; index < postorder.size(); ++index)
    {
        EXPECT_EQ(result.at(index), postorder.at(index));
    }
}

TEST_F(SetupBinaryTree, test_postorder_traversal_morris1)
{
    auto root = SetupBinaryTree::binary_tree_root();
    auto result = post_order_traversal_morris(root);
    for (size_t index = 0; index < postorder.size(); ++index)
    {
        EXPECT_EQ(result.at(index), postorder.at(index));
    }
}

TEST_F(SetupBinaryTree, test_postorder_traversal_morris2)
{
    auto root = new TreeNode<short>(1);
    root->right = new TreeNode<short>(2);
    root->right->left = new TreeNode<short>(3);
    std::vector<short> expected_result{3, 2, 1};
    auto result = post_order_traversal_morris(root);
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupBinaryTree, test_postorder_traversal_morris3)
{
    auto result = post_order_traversal_morris<double>(nullptr);
    EXPECT_EQ(result, std::vector<double>{});
}

TEST_F(SetupBinaryTree, test_postorder_traversal_morris4)
{
    std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    TreeNode<int>* root = nullptr;
    auto tree = insert_level_order(values, root, 0, values.size());
    std::vector<int> expected_result{16, 17, 8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1};
    EXPECT_EQ(expected_result, post_order_traversal_morris(tree));
}
