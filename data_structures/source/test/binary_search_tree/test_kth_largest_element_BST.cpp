//
// Created by andreas on 18.12.25.
//
#include "binary_search_tree/kth_largest_element_BST.h"
#include "gtest/gtest.h"

// ---------------- helpers ----------------

// Insert with BST rule: left < node, right >= node (duplicates go right)
static TreeNode<int>* insert(TreeNode<int>* root, int v) {
    if (!root) return new TreeNode<int>(v);
    auto* cur = root;
    while (true) {
        if (v < cur->value) {
            if (cur->left) cur = cur->left;
            else { cur->left = new TreeNode<int>(v); break; }
        } else {
            if (cur->right) cur = cur->right;
            else { cur->right = new TreeNode<int>(v); break; }
        }
    }
    return root;
}

static TreeNode<int>* buildBst(std::initializer_list<int> values) {
    TreeNode<int>* root = nullptr;
    for (int v : values) root = insert(root, v);
    return root;
}

// Post-order delete. This will trigger your TreeNode dtor (and thus TestTracker logging).
static void destroy(TreeNode<int>* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}


TEST(KthLargestInBST, SingleNodeK1) {
    auto* root = buildBst({42});
    EXPECT_EQ(find_Kth_largest_value(root, 1), 42);
    destroy(root);
}

TEST(KthLargestInBST, BalancedUniqueValues_AllKs) {
    auto* root = buildBst({4, 2, 6, 1, 3, 5, 7});
    // Desc: 7,6,5,4,3,2,1
    EXPECT_EQ(find_Kth_largest_value(root, 1), 7);
    EXPECT_EQ(find_Kth_largest_value(root, 2), 6);
    EXPECT_EQ(find_Kth_largest_value(root, 3), 5);
    EXPECT_EQ(find_Kth_largest_value(root, 4), 4);
    EXPECT_EQ(find_Kth_largest_value(root, 5), 3);
    EXPECT_EQ(find_Kth_largest_value(root, 6), 2);
    EXPECT_EQ(find_Kth_largest_value(root, 7), 1);
    destroy(root);
}

TEST(KthLargestInBST, RightSkewedTree) {
    auto* root = buildBst({1, 2, 3, 4, 5}); // right chain
    // Desc: 5,4,3,2,1
    EXPECT_EQ(find_Kth_largest_value(root, 1), 5);
    EXPECT_EQ(find_Kth_largest_value(root, 2), 4);
    EXPECT_EQ(find_Kth_largest_value(root, 5), 1);
    destroy(root);
}

TEST(KthLargestInBST, LeftSkewedTree) {
    auto* root = buildBst({5, 4, 3, 2, 1}); // left chain
    EXPECT_EQ(find_Kth_largest_value(root, 1), 5);
    EXPECT_EQ(find_Kth_largest_value(root, 3), 3);
    EXPECT_EQ(find_Kth_largest_value(root, 5), 1);
    destroy(root);
}

TEST(KthLargestInBST, HandlesDuplicates_DuplicatesGoRight) {
    auto* root = buildBst({5, 3, 7, 5, 5, 7, 1});
    // Sorted asc: 1,3,5,5,5,7,7
    // Desc:       7,7,5,5,5,3,1
    EXPECT_EQ(find_Kth_largest_value(root, 1), 7);
    EXPECT_EQ(find_Kth_largest_value(root, 2), 7);
    EXPECT_EQ(find_Kth_largest_value(root, 3), 5);
    EXPECT_EQ(find_Kth_largest_value(root, 5), 5);
    EXPECT_EQ(find_Kth_largest_value(root, 6), 3);
    EXPECT_EQ(find_Kth_largest_value(root, 7), 1);
    destroy(root);
}

TEST(KthLargestInBST, HandlesNegativeAndMixedValues) {
    auto* root = buildBst({-10, -3, -20, 0, 5, -3, 2});
    // Sorted asc: -20, -10, -3, -3, 0, 2, 5
    // Desc:        5,   2,  0, -3, -3, -10, -20
    EXPECT_EQ(find_Kth_largest_value(root, 1), 5);
    EXPECT_EQ(find_Kth_largest_value(root, 2), 2);
    EXPECT_EQ(find_Kth_largest_value(root, 3), 0);
    EXPECT_EQ(find_Kth_largest_value(root, 4), -3);
    EXPECT_EQ(find_Kth_largest_value(root, 6), -10);
    EXPECT_EQ(find_Kth_largest_value(root, 7), -20);
    destroy(root);
}

TEST(KthLargestInBST, LargerTree_SanityChecks) {
    auto* root = buildBst({15, 5, 20, 2, 5, 17, 22, 1, 3, 18});
    // Asc: 1,2,3,5,5,15,17,18,20,22
    // Desc:22,20,18,17,15,5,5,3,2,1
    EXPECT_EQ(find_Kth_largest_value(root, 1), 22);
    EXPECT_EQ(find_Kth_largest_value(root, 2), 20);
    EXPECT_EQ(find_Kth_largest_value(root, 5), 15);
    EXPECT_EQ(find_Kth_largest_value(root, 6), 5);
    EXPECT_EQ(find_Kth_largest_value(root, 10), 1);
    destroy(root);
}
