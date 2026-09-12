//
// Created by andreas on 12.09.26.
//

#include "../../binary_search_tree/sorted_linked_list_to_bst.h"
#include "gtest/gtest.h"
#include "test_helper.h"

#include <algorithm>
#include <cstdlib>
#include <vector>

namespace
{
std::vector<ListNode<int>> make_linked_list(const std::vector<int>& values)
{
    std::vector<ListNode<int>> nodes;
    nodes.reserve(values.size());
    for (const auto value : values)
        nodes.push_back({value, nullptr});

    for (size_t index = 1; index < nodes.size(); ++index)
        nodes[index - 1].next = &nodes[index];

    return nodes;
}

ListNode<int>* head_of(std::vector<ListNode<int>>& nodes)
{
    if (nodes.empty())
        return nullptr;
    return &nodes.front();
}

std::vector<int> in_order_values(TreeNode<int>* root)
{
    if (!root)
        return {};

    auto result = in_order_values(root->left);
    result.push_back(root->value);
    auto right_values = in_order_values(root->right);
    result.insert(result.end(), right_values.begin(), right_values.end());
    return result;
}

int height(TreeNode<int>* root)
{
    if (!root)
        return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

bool is_height_balanced(TreeNode<int>* root)
{
    if (!root)
        return true;

    return std::abs(height(root->left) - height(root->right)) <= 1 && is_height_balanced(root->left) &&
        is_height_balanced(root->right);
}

void expect_balanced_bst_with_values(TreeNode<int>* root, const std::vector<int>& values)
{
    EXPECT_EQ(values, in_order_values(root));
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    EXPECT_TRUE(is_height_balanced(root));
}
}

TEST(sorted_linked_list_to_bst, handles_empty_list)
{
    EXPECT_EQ(nullptr, build_tree<int>(nullptr));
}

TEST(sorted_linked_list_to_bst, handles_single_node)
{
    const std::vector<int> values{42};
    auto list = make_linked_list(values);

    auto root = build_tree(head_of(list));

    ASSERT_NE(nullptr, root);
    EXPECT_EQ(42, root->value);
    EXPECT_EQ(nullptr, root->left);
    EXPECT_EQ(nullptr, root->right);
    expect_balanced_bst_with_values(root, values);

    delete_tree(root);
}

TEST(sorted_linked_list_to_bst, handles_two_nodes)
{
    const std::vector<int> values{1, 2};
    auto list = make_linked_list(values);

    auto root = build_tree(head_of(list));

    expect_balanced_bst_with_values(root, values);

    delete_tree(root);
}

TEST(sorted_linked_list_to_bst, builds_balanced_tree_from_odd_number_of_nodes)
{
    const std::vector<int> values{-10, -3, 0, 5, 9};
    auto list = make_linked_list(values);

    auto root = build_tree(head_of(list));

    expect_balanced_bst_with_values(root, values);

    delete_tree(root);
}

TEST(sorted_linked_list_to_bst, builds_balanced_tree_from_even_number_of_nodes)
{
    const std::vector<int> values{-20, -10, -3, 0, 5, 9};
    auto list = make_linked_list(values);

    auto root = build_tree(head_of(list));

    expect_balanced_bst_with_values(root, values);

    delete_tree(root);
}

TEST(sorted_linked_list_to_bst, preserves_sorted_order_for_larger_input)
{
    const std::vector<int> values{-50, -25, -11, -4, 0, 3, 8, 13, 21, 34, 55, 89, 144};
    auto list = make_linked_list(values);

    auto root = build_tree(head_of(list));

    expect_balanced_bst_with_values(root, values);

    delete_tree(root);
}
