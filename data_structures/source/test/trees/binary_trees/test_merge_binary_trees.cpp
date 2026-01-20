//
// Created by andreas on 20.01.26.
//
#include "setup_binary_tree.h"          // your fixture + is_same_tree
#include "trees/binary_trees/merge_binary_trees.h"

// Build expected tree for merging your "small" + "inverted_small" trees.
TreeNode<unsigned int>* expected_merge_small_and_inverted_small() {
    // small:            inverted_small:
    //        3                 3
    //      /   \             /   \
    //     9     20          20    9
    //          /  \        / \
    //         15   7      7  15
    //
    // merge (sum): root=6
    // left: 9+20=29, right: 20+9=29
    // right->left: 15+0=15, right->right: 7+0=7
    // left->left: 0+7=7, left->right: 0+15=15
    auto* root = new TreeNode<unsigned int>(6);
    root->left  = new TreeNode<unsigned int>(29);
    root->right = new TreeNode<unsigned int>(29);

    root->left->left  = new TreeNode<unsigned int>(7);
    root->left->right = new TreeNode<unsigned int>(15);

    root->right->left  = new TreeNode<unsigned int>(15);
    root->right->right = new TreeNode<unsigned int>(7);
    return root;
}

// Collect all node addresses in a tree (to ensure "new" tree is deep-copied).
template<typename T>
void collect_ptrs(TreeNode<T>* root, std::unordered_set<const void*>& out) {
    if (!root) return;
    out.insert(static_cast<const void*>(root));
    collect_ptrs(root->left, out);
    collect_ptrs(root->right, out);
}

// -------------------------
// tests
// -------------------------

TEST_F(SetupBinaryTree, MergeBothNullReturnsNull) {
    TreeNode<unsigned int>* root1 = nullptr;
    TreeNode<unsigned int>* root2 = nullptr;

    auto* merged = merge_binary_trees(root1, root2);
    EXPECT_EQ(merged, nullptr);
}

TEST_F(SetupBinaryTree, MergeNullAndTreeReturnsDeepCopyOfTree) {
    auto* root = small_binary_tree_root();

    auto* merged = merge_binary_trees<unsigned int>(nullptr, root);

    // Same shape + values
    EXPECT_TRUE(is_same_tree(merged, root));

    // But should not reuse any nodes (deep copy)
    std::unordered_set<const void*> orig_ptrs;
    collect_ptrs(root, orig_ptrs);
    std::unordered_set<const void*> merged_ptrs;
    collect_ptrs(merged, merged_ptrs);

    for (const void* p : merged_ptrs) {
        EXPECT_TRUE(orig_ptrs.find(p) == orig_ptrs.end());
    }

}

TEST_F(SetupBinaryTree, MergeTreeAndNullReturnsDeepCopyOfTree) {
    auto* root = inverted_small_binary_tree_root();

    auto* merged = merge_binary_trees<unsigned int>(root, nullptr);

    EXPECT_TRUE(is_same_tree(merged, root));

    std::unordered_set<const void*> orig_ptrs;
    collect_ptrs(root, orig_ptrs);
    std::unordered_set<const void*> merged_ptrs;
    collect_ptrs(merged, merged_ptrs);

    for (const void* p : merged_ptrs) {
        EXPECT_TRUE(orig_ptrs.find(p) == orig_ptrs.end());
    }
}

TEST_F(SetupBinaryTree, MergeSmallTreeWithInvertedSmallTreeProducesExpectedSumsAndStructure) {
    auto* a = small_binary_tree_root();
    auto* b = inverted_small_binary_tree_root();

    auto* merged = merge_binary_trees<unsigned int>(a, b);

    auto* expected = expected_merge_small_and_inverted_small();
    EXPECT_TRUE(is_same_tree(merged, expected));

}

TEST_F(SetupBinaryTree, MergeWithDifferentShapesPreservesAllNodes) {
    // root1 has both children, root2 has only left subtree in places.
    auto* root1 = new TreeNode<unsigned int>(10);
    root1->left  = new TreeNode<unsigned int>(5);
    root1->right = new TreeNode<unsigned int>(3);
    root1->right->right = new TreeNode<unsigned int>(7);

    auto* root2 = new TreeNode<unsigned int>(1);
    root2->left = new TreeNode<unsigned int>(2);
    root2->left->left = new TreeNode<unsigned int>(4);

    auto* merged = merge_binary_trees<unsigned int>(root1, root2);

    // expected:
    //        11
    //      /    \
    //     7      3
    //    /        \
    //   4          7
    auto* expected = new TreeNode<unsigned int>(11);
    expected->left = new TreeNode<unsigned int>(7);
    expected->right = new TreeNode<unsigned int>(3);
    expected->left->left = new TreeNode<unsigned int>(4);
    expected->right->right = new TreeNode<unsigned int>(7);

    EXPECT_TRUE(is_same_tree(merged, expected));
}

TEST_F(SetupBinaryTree, MergeDoesNotMutateInputs) {
    auto* a = binary_tree_root();
    auto* b = inverted_tree();

    // snapshot copies (structure+values) by cloning via merge with nullptr
    auto* a_before = merge_binary_trees<unsigned int>(a, nullptr);
    auto* b_before = merge_binary_trees<unsigned int>(nullptr, b);

    auto* merged = merge_binary_trees<unsigned int>(a, b);

    EXPECT_TRUE(is_same_tree(a, a_before));
    EXPECT_TRUE(is_same_tree(b, b_before));
    EXPECT_NE(merged, nullptr);
}

