//
// Created by andreas on 03.08.22.
//
#include "gtest/gtest.h"
#include "trees/binary_trees/binary_search_tree_from_sorted_array.h"

template<typename T>
bool is_valid_binary_search_tree(TreeNode<T> *root, TreeNode<T> *min = nullptr, TreeNode<T> *max = nullptr) {
    if (!root)
        return true;
    if (min != nullptr && root->value <= min->value) return false;
    if (max != nullptr && root->value >= max->value) return false;
    return is_valid_binary_search_tree(root->left, min, root) && is_valid_binary_search_tree(root->right, root, max);
}

TEST(binary_search_tree_from_sorted_array, simple_array) {
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto root = binary_search_tree_from_sorted_array<int>(input);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
}

TEST(binary_search_tree_from_sorted_array, long_array) {
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 18, 20, 26, 31, 56, 78, 89, 109, 1010, 12091, 188888};
    auto root = binary_search_tree_from_sorted_array<int>(input);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
}