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
}

TEST(BinarySearchTree, TestRemovingMissingValueDoesNothing) {
    auto bst = makeBST<int>(10, {5, 15, 2, 7, 12, 20});
    bst.remove(999);

    expectContains(bst, {10, 5, 15, 2, 7, 12, 20});
    EXPECT_FALSE(bst.contains(999));
}
