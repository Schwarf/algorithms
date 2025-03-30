//
// Created by andreas on 02.02.23.
//
#include "union_find_disjoint_set/optimized_disjoint_set.h"
#include "setup_disjoint_sets.h"

TEST_F(SetupDisjointSets, single_set_optimized)
{
    auto quick_find = OptimizedDisjointSet(10);
    for (int j{}; j < set1.size() - 1; ++j)
        for (int i{j + 1}; i < set1.size(); ++i)
            EXPECT_FALSE(quick_find.are_connected(set1[j], set1[i]));

    for (int i{1}; i < set1.size(); ++i)
        quick_find.union_set(set1[0], set1[i]);
    for (int j{}; j < set1.size() - 1; ++j)
        for (int i{j + 1}; i < set1.size(); ++i)
            EXPECT_TRUE(quick_find.are_connected(set1[j], set1[i]));
}

TEST_F(SetupDisjointSets, two_sets_optimized)
{
    auto quick_find = OptimizedDisjointSet(10);
    for (int i{1}; i < set1.size(); ++i)
        quick_find.union_set(set1[0], set1[i]);
    for (int i{1}; i < set2.size(); ++i)
        quick_find.union_set(set2[0], set2[i]);

    for (int i{}, j{}; i < set1.size() && j < set2.size(); ++i, ++j)
    {
        EXPECT_FALSE(quick_find.are_connected(set1[i], set2[j]));
    }
    quick_find.union_set(set1[2], set2[3]);
    for (int i{}, j{}; i < set1.size() && j < set2.size(); ++i, ++j)
    {
        EXPECT_TRUE(quick_find.are_connected(set1[i], set2[j]));
    }
}
