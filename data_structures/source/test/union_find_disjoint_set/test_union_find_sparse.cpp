//
// Created by andreas on 08.02.26.
//
#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <optional>

// Include your header (adjust path as needed)
#include "union_find_disjoint_set/union_find_sparse.h"

// --------------------
// Basic behavior tests
// --------------------

TEST(UnionFindSparseInt, AddSetBasicAndDuplicate) {
    UnionFindSparse<int> union_find;

    EXPECT_TRUE(union_find.add_set(1));
    EXPECT_TRUE(union_find.add_set(2));
    EXPECT_FALSE(union_find.add_set(1));  // duplicate

    auto r1 = union_find.get_root(1);
    ASSERT_TRUE(r1.has_value());
    EXPECT_EQ(*r1, 1);

    auto r2 = union_find.get_root(2);
    ASSERT_TRUE(r2.has_value());
    EXPECT_EQ(*r2, 2);
}

TEST(UnionFindSparseInt, GetRootMissingReturnsNullopt) {
    UnionFindSparse<int> union_find;

    EXPECT_FALSE(union_find.get_root(42).has_value());
    EXPECT_FALSE(union_find.get_root(-7).has_value());
}

TEST(UnionFindSparseInt, UnionSetNoOpIfMissing) {
    UnionFindSparse<int> union_find;
    union_find.add_set(1);
    union_find.add_set(2);

    // Missing element -> union does nothing
    union_find.union_set(1, 999);

    EXPECT_FALSE(union_find.are_connected(1, 999));
    EXPECT_FALSE(union_find.get_root(999).has_value());

    // Existing sets should remain unchanged
    EXPECT_EQ(*union_find.get_root(1), 1);
    EXPECT_EQ(*union_find.get_root(2), 2);
    EXPECT_FALSE(union_find.are_connected(1, 2));
}

TEST(UnionFindSparseInt, AreConnectedMissingIsFalseEvenIfBothMissing) {
    UnionFindSparse<int> union_find;

    EXPECT_FALSE(union_find.are_connected(1, 2));   // both missing
    union_find.add_set(1);
    EXPECT_FALSE(union_find.are_connected(1, 2));   // one missing
}

// --------------------
// Union + find behavior
// --------------------

TEST(UnionFindSparseInt, UnionSetConnectsTwoSingletonsDeterministicRootOnTie) {
    UnionFindSparse<int> union_find;
    union_find.add_set(10);
    union_find.add_set(20);

    union_find.union_set(10, 20);

    EXPECT_TRUE(union_find.are_connected(10, 20));

    EXPECT_EQ(*union_find.get_root(10), *union_find.get_root(20));
}

TEST(UnionFindSparseInt, UnionSetTransitiveConnectivity) {
    UnionFindSparse<int> union_find;
    union_find.add_set(1);
    union_find.add_set(2);
    union_find.add_set(3);
    union_find.add_set(4);

    union_find.union_set(1, 2);
    union_find.union_set(2, 3);

    EXPECT_TRUE(union_find.are_connected(1, 3));
    EXPECT_TRUE(union_find.are_connected(2, 3));
    EXPECT_FALSE(union_find.are_connected(1, 4));
    EXPECT_FALSE(union_find.are_connected(2, 4));
    EXPECT_FALSE(union_find.are_connected(3, 4));

    EXPECT_EQ(*union_find.get_root(1), 1);
    EXPECT_EQ(*union_find.get_root(2), 1);
    EXPECT_EQ(*union_find.get_root(3), 1);
}

TEST(UnionFindSparseInt, UnionSetIdempotentAndSelfUnion) {
    UnionFindSparse<int> union_find;
    union_find.add_set(5);
    union_find.add_set(6);

    union_find.union_set(5, 6);
    union_find.union_set(5, 6);  // repeat
    union_find.union_set(6, 5);  // reverse
    union_find.union_set(5, 5);  // self-union

    EXPECT_TRUE(union_find.are_connected(5, 6));
    EXPECT_EQ(*union_find.get_root(5), 5);
    EXPECT_EQ(*union_find.get_root(6), 5);
}

TEST(UnionFindSparseInt, UnionSetMergeTwoComponents) {
    UnionFindSparse<int> union_find;
    for (int x : {1,2,3,4}) union_find.add_set(x);

    union_find.union_set(1, 2);
    union_find.union_set(3, 4);

    EXPECT_TRUE(union_find.are_connected(1, 2));
    EXPECT_TRUE(union_find.are_connected(3, 4));
    EXPECT_FALSE(union_find.are_connected(1, 3));

    union_find.union_set(2, 3);

    EXPECT_TRUE(union_find.are_connected(1, 4));
    EXPECT_TRUE(union_find.are_connected(1, 3));
    EXPECT_EQ(*union_find.get_root(4), *union_find.get_root(1));
}

// --------------------
// Sparse-domain motivation tests
// --------------------

TEST(UnionFindSparseInt, SupportsNegativeAndLargeIds) {
    UnionFindSparse<int> union_find;
    union_find.add_set(-10);
    union_find.add_set(1'000'000);
    union_find.add_set(7);

    EXPECT_EQ(*union_find.get_root(-10), -10);
    EXPECT_EQ(*union_find.get_root(1'000'000), 1'000'000);

    union_find.union_set(-10, 1'000'000);
    EXPECT_TRUE(union_find.are_connected(-10, 1'000'000));
    EXPECT_EQ(*union_find.get_root(1'000'000), -10); // tie -> second attaches to first
    EXPECT_EQ(*union_find.get_root(-10), -10);

    EXPECT_FALSE(union_find.are_connected(7, -10));
}

// --------------------
// Template works for other IdTypes
// --------------------

TEST(UnionFindSparseString, WorksForStringIds) {
    UnionFindSparse<std::string> union_find;

    EXPECT_TRUE(union_find.add_set("alice"));
    EXPECT_TRUE(union_find.add_set("bob"));
    EXPECT_TRUE(union_find.add_set("charlie"));

    union_find.union_set("alice", "bob");

    EXPECT_TRUE(union_find.are_connected("alice", "bob"));
    EXPECT_FALSE(union_find.are_connected("alice", "charlie"));

    EXPECT_EQ(*union_find.get_root("bob"), "alice");
}
