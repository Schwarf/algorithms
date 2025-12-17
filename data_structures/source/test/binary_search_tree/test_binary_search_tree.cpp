//
// Created by andreas on 17.12.25.
//
#include "./../../binary_search_tree/binary_search_tree.h"
#include "gtest/gtest.h"

template <typename T>
BinarySearchTree<T> makeBST(const T& root, std::initializer_list<T> vals) {
    BinarySearchTree<T> bst(root);
    for (const auto& v : vals) bst.insert(v);
    return bst; // relies on move / NRVO (copy must be disabled or deep)
}

template <typename T>
void expectContains(BinarySearchTree<T>& bst, std::initializer_list<T> present) {
    for (const auto& v : present) {
        EXPECT_TRUE(bst.contains(v)) << "Expected contains(" << v << ") == true";
    }
}

template <typename T>
void expectNotContains(BinarySearchTree<T>& bst, std::initializer_list<T> absent) {
    for (const auto& v : absent) {
        EXPECT_FALSE(bst.contains(v)) << "Expected contains(" << v << ") == false";
    }
}

template <typename T>
bool is_valid_binary_search_tree(BinarySearchTree<T>* root, long long min = std::numeric_limits<long long>::min(), long long max =
std::numeric_limits<long long>::max()) {
    if(!root)
        return true;

    if(root->value <= min || root->value >= max)
        return false;

    return is_valid_binary_search_tree(root->left, min, root->value) && is_valid_binary_search_tree(root->right, root->value, max);
}

TEST(BinarySearchTree, TestSingleNodeContainsRoot) {
    BinarySearchTree<int> bst(10);
    EXPECT_TRUE(bst.contains(10));
    EXPECT_FALSE(bst.contains(9));
    EXPECT_FALSE(bst.contains(11));
}

TEST(BinarySearchTree, TestContainsRootAndInsertedValues) {
    auto bst = makeBST<int>(10, {5, 15, 2, 7, 12, 20});

    expectContains(bst, {10, 5, 15, 2, 7, 12, 20});
    expectNotContains(bst, {-1, 0, 1, 3, 6, 8, 9, 11, 13, 14, 16, 999});

}

TEST(BinarySearchTree, TestInsertsGoLeftAndRight) {
    BinarySearchTree<int> bst(10);
    bst.insert(5).insert(15).insert(2).insert(7).insert(12).insert(20);

    expectContains(bst, {10, 5, 15, 2, 7, 12, 20});
    expectNotContains(bst, {0, 1, 3, 6, 8, 11, 13, 100});
    EXPECT_TRUE(is_valid_binary_search_tree(&bst));
}

TEST(BinarySearchTree, TestRemovingMissingValueDoesNothing) {
    auto bst = makeBST<int>(10, {5, 15, 2, 7, 12, 20});
    bst.remove(999);

    expectContains(bst, {10, 5, 15, 2, 7, 12, 20});
    EXPECT_FALSE(bst.contains(999));
    EXPECT_TRUE(is_valid_binary_search_tree(&bst));
}

TEST(BinarySearchTree, TestRemoveLeaf) {
    // leaf: 2
    auto bst = makeBST<int>(10, {5, 15, 2, 7});

    EXPECT_TRUE(bst.contains(2));
    bst.remove(2);
    EXPECT_FALSE(bst.contains(2));

    expectContains(bst, {10, 5, 15, 7});
    EXPECT_TRUE(is_valid_binary_search_tree(&bst));
}

TEST(BinarySearchTree, TestRemoveNodeWithOneChildLeft) {
    // Remove 5 which has only left child 2:
    //     10
    //    /
    //   5
    //  /
    // 2
    auto bst = makeBST<int>(10, {5, 2});

    EXPECT_TRUE(bst.contains(5));
    bst.remove(5);
    EXPECT_FALSE(bst.contains(5));

    expectContains(bst, {10, 2});
    EXPECT_TRUE(is_valid_binary_search_tree(&bst));
}

TEST(BinarySearchTree, TestRemoveNodeWithOneChildRight) {
    // Remove 15 which has only right child 20:
    // 10
    //   \
    //   15
    //     \
    //     20
    auto bst = makeBST<int>(10, {15, 20});

    EXPECT_TRUE(bst.contains(15));
    bst.remove(15);
    EXPECT_FALSE(bst.contains(15));

    expectContains(bst, {10, 20});
    EXPECT_TRUE(is_valid_binary_search_tree(&bst));
}

TEST(BinarySearchTree, TestRemoveNodeWithTwoChildren) {
    // Remove 15 (two children: 12 and 20; and 12 has left 11):
    //          10
    //        /    \
    //       5      15
    //            /   \
    //           12    20
    //          /
    //         11
    auto bst = makeBST<int>(10, {5, 15, 12, 20, 11});

    EXPECT_TRUE(bst.contains(15));
    bst.remove(15);
    EXPECT_FALSE(bst.contains(15));

    expectContains(bst, {10, 5, 12, 20, 11});
    EXPECT_TRUE(is_valid_binary_search_tree(&bst));
}

TEST(BinarySearchTree, TestRemoveRootTwoChildren)
{
    auto bst = makeBST<int>(10, {5, 15, 2, 7, 12, 20});
    bst.remove(10);

    expectContains(bst, {5, 15, 2, 7, 12, 20});
    EXPECT_TRUE(is_valid_binary_search_tree(&bst));
}