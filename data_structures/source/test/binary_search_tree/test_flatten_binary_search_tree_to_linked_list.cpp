//
// Created by andreas on 11.09.26.
//

#include "../../binary_search_tree/flatten_binary_search_tree_to_linked_list.h"
#include "gtest/gtest.h"

#include <vector>

namespace
{
template <typename T>
std::vector<T> values_forward(TreeNode<T>* head)
{
    std::vector<T> result;
    auto current = head;
    while (current)
    {
        result.push_back(current->value);
        current = current->right;
    }
    return result;
}

template <typename T>
std::vector<T> values_backward(TreeNode<T>* tail)
{
    std::vector<T> result;
    auto current = tail;
    while (current)
    {
        result.push_back(current->value);
        current = current->left;
    }
    return result;
}

template <typename T>
TreeNode<T>* tail_of(TreeNode<T>* head)
{
    auto current = head;
    while (current && current->right)
        current = current->right;
    return current;
}

template <typename T>
void delete_flattened_list(TreeNode<T>* head)
{
    while (head)
    {
        auto next = head->right;
        head->left = nullptr;
        head->right = nullptr;
        delete head;
        head = next;
    }
}
}

TEST(flatten_binary_search_tree_to_linked_list, flattens_tree_in_preorder)
{
    auto root = new TreeNode<int>(25);
    root->left = new TreeNode<int>(15);
    root->right = new TreeNode<int>(50);
    root->left->left = new TreeNode<int>(10);
    root->left->right = new TreeNode<int>(22);
    root->right->left = new TreeNode<int>(35);
    root->right->right = new TreeNode<int>(70);

    flatten_to_linked_list_preorder(root);

    const std::vector<int> expected_forward{25, 15, 10, 22, 50, 35, 70};
    const std::vector<int> expected_backward{70, 35, 50, 22, 10, 15, 25};

    EXPECT_EQ(expected_forward, values_forward(root));
    EXPECT_EQ(expected_backward, values_backward(tail_of(root)));
    EXPECT_EQ(nullptr, root->left);
    EXPECT_EQ(nullptr, tail_of(root)->right);

    delete_flattened_list(root);
}

TEST(flatten_binary_search_tree_to_linked_list, preserves_existing_nodes)
{
    auto root = new TreeNode<int>(1);
    auto left = new TreeNode<int>(2);
    auto right = new TreeNode<int>(5);
    auto left_left = new TreeNode<int>(3);
    auto left_right = new TreeNode<int>(4);
    auto right_right = new TreeNode<int>(6);

    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = left_right;
    right->right = right_right;

    flatten_to_linked_list_preorder(root);

    EXPECT_EQ(left, root->right);
    EXPECT_EQ(root, left->left);
    EXPECT_EQ(left_left, left->right);
    EXPECT_EQ(left, left_left->left);
    EXPECT_EQ(left_right, left_left->right);
    EXPECT_EQ(left_left, left_right->left);
    EXPECT_EQ(right, left_right->right);
    EXPECT_EQ(left_right, right->left);
    EXPECT_EQ(right_right, right->right);
    EXPECT_EQ(right, right_right->left);

    delete_flattened_list(root);
}

TEST(flatten_binary_search_tree_to_linked_list, handles_single_node)
{
    auto root = new TreeNode<int>(42);

    flatten_to_linked_list_preorder(root);

    EXPECT_EQ(42, root->value);
    EXPECT_EQ(nullptr, root->left);
    EXPECT_EQ(nullptr, root->right);

    delete root;
}

TEST(flatten_binary_search_tree_to_linked_list, handles_empty_tree)
{
    TreeNode<int>* root = nullptr;

    EXPECT_NO_THROW(flatten_to_linked_list_preorder(root));
}
