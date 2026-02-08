//
// Created by andreas on 02.02.23.
//

#include <gtest/gtest.h>
#include <vector>
#include <optional>

#include "union_find_disjoint_set/union_find_dense.h"

// Helper: connect all nodes in vec to vec[0]
template <typename UnionFindType, typename T>
static void UniteAll(UnionFindType& union_find, const std::vector<T>& vec)
{
    for (size_t i = 1; i < vec.size(); ++i)
    {
        union_find.union_set(vec[0], vec[i]);
    }
}

TEST(UnionFindDense, InitiallyAllDisconnected)
{
    constexpr int elements{10};
    UnionFindDense<int> union_find(elements);

    for (int i{}; i < elements; ++i)
    {
        for (int j{}; j < elements; ++j)
        {
            if (i==j)
                EXPECT_TRUE(union_find.are_connected(i, j));
            else
                EXPECT_FALSE(union_find.are_connected(i, j));
        }
    }
}

TEST(UnionFindDense, SingleComponentViaStarUnion)
{
    UnionFindDense<int> union_find(10);
    const std::vector<int> set1{0, 2, 4, 6, 8};

    // initially different sets are disconnected
    for (size_t j = 0; j + 1 < set1.size(); ++j)
        for (size_t i = j + 1; i < set1.size(); ++i)
            EXPECT_FALSE(union_find.are_connected(set1[j], set1[i]));

    UniteAll(union_find, set1);
    // all connected
    for (size_t j = 0; j < set1.size(); ++j)
        for (size_t i = 0; i < set1.size(); ++i)
            EXPECT_TRUE(union_find.are_connected(set1[j], set1[i]));
}

TEST(UnionFindDense, TwoComponentsThenMerged)
{
    UnionFindDense<int> union_find(10);
    std::vector<int> set1{0, 2, 4, 6, 8};
    std::vector<int> set2{1, 3, 5, 7, 9};

    UniteAll(union_find, set1);
    UniteAll(union_find, set2);

    // Across components: not connected
    for (int a : set1)
        for (int b : set2)
            EXPECT_FALSE(union_find.are_connected(a, b));

    union_find.union_set(2, 3); // merge the two components

    for (int a : set1)
        for (int b : set2)
            EXPECT_TRUE(union_find.are_connected(a, b));
}

TEST(UnionFindDense, FindRootValidAndInvalid)
{
    UnionFindDense<int> union_find(5);

    for (int i = 0; i < 5; ++i)
    {
        auto r = union_find.find_root(i);
        EXPECT_TRUE(r.has_value());
        EXPECT_EQ(*r, i);
    }

    EXPECT_FALSE(union_find.find_root(-1).has_value());
    EXPECT_FALSE(union_find.find_root(5).has_value());
    EXPECT_FALSE(union_find.find_root(100).has_value());
}

TEST(UnionFindDense, InvalidInputsAreConnectedFalseUnionNoOp)
{
    UnionFindDense<int> union_find(3);

    // are_connected should be false if any input invalid
    EXPECT_FALSE(union_find.are_connected(-1, 0));
    EXPECT_FALSE(union_find.are_connected(0, 3));
    EXPECT_FALSE(union_find.are_connected(-1, 3));

    // union_set should not crash and should not affect valid connectivity
    union_find.union_set(-1, 0);
    union_find.union_set(0, 3);
    union_find.union_set(-1, 3);

    EXPECT_FALSE(union_find.are_connected(0, 1));
    EXPECT_FALSE(union_find.are_connected(1, 2));
}

TEST(UnionFindDense, UnionIsIdempotentAndSelfUnionSafe)
{
    UnionFindDense<int> union_find(4);

    union_find.union_set(1, 2);
    EXPECT_TRUE(union_find.are_connected(1, 2));

    // repeat / reverse should not change correctness
    union_find.union_set(1, 2);
    union_find.union_set(2, 1);
    EXPECT_TRUE(union_find.are_connected(1, 2));

    // self union: should not break anything
    union_find.union_set(2, 2);
    EXPECT_TRUE(union_find.are_connected(1, 2));
    EXPECT_FALSE(union_find.are_connected(0, 1));
}

TEST(UnionFindDense, TransitiveConnectivity)
{
    UnionFindDense<int> union_find(6);

    union_find.union_set(0, 1);
    union_find.union_set(1, 2);
    union_find.union_set(2, 3);

    EXPECT_TRUE(union_find.are_connected(0, 3));
    EXPECT_TRUE(union_find.are_connected(1, 3));
    EXPECT_FALSE(union_find.are_connected(0, 4));
    EXPECT_FALSE(union_find.are_connected(3, 5));
}
