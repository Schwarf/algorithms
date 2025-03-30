//
// Created by andreas on 30.03.25.
//
#include "spatial_data_structures/k_d_tree.h"
#include "gtest/gtest.h"


TEST(KDTreeTest, EmptyTree)
{
    std::vector<std::array<double, 3>> emptyPoints;
    KDTree<double, 3> tree(emptyPoints);
    std::array<double, 3> target = {0.0, 0.0, 0.0};
    auto result = tree.nearest_neighbor(target);
    // Assuming default-constructed array returns zeros:
    EXPECT_EQ(result, (std::array<double, 3>{}));
}

TEST(KDTreeTest, SinglePoint)
{
    std::vector<std::array<double, 3>> points = {{1.0, 2.0, 3.0}};
    KDTree<double, 3> tree(points);
    std::array<double, 3> target = {5.0, 5.0, 5.0};
    auto result = tree.nearest_neighbor(target);
    EXPECT_EQ(result, points[0]);
}

TEST(KDTreeTest, ExactMatch)
{
    std::vector<std::array<double, 2>> points = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0}
    };
    KDTree<double, 2> tree(points);
    std::array<double, 2> target = {3.0, 4.0};
    auto result = tree.nearest_neighbor(target);
    EXPECT_EQ(result, target);
}

TEST(KDTreeTest, BoundaryCaseTieGivesLexicographicalOrder)
{
    std::vector<std::array<double, 2>> points = {
        {1.0, 1.0},
        {2.0, 2.0},
        {3.0, 3.0},
        {4.0, 4.0}
    };
    KDTree<double, 2> tree(points);
    // Target is exactly halfway between (2.0,2.0) and (3.0,3.0)
    std::array<double, 2> target = {2.5, 2.5};
    auto result = tree.nearest_neighbor(target);
    // Both (2.0, 2.0) and (3.0, 3.0) are equally distant;
    // Your implementation might consistently choose one based on traversal order.
    // Test that the result is one of them.
    EXPECT_DOUBLE_EQ(result[0], 2.0);
    EXPECT_DOUBLE_EQ(result[1], 2.0);
}

TEST(KDTreeTest, NearestNeighbor3D)
{
    std::vector<std::array<double, 3>> points = {
        {2.1, 3.2, 4.5},
        {5.4, 2.3, 3.1},
        {4.2, 7.3, 1.5},
        {9.1, 6.2, 8.7},
        {7.4, 3.5, 2.6}
    };

    // Build the tree from points
    KDTree<double, 3> tree(points);

    // Define a target point
    std::array<double, 3> target = {5.0, 3.0, 4.0};

    // Retrieve the nearest neighbor from the KDTree
    auto nearest = tree.nearest_neighbor(target);

    // (2.1, 3.2, 4.5): squared distance ≈ 8.70
    // (5.4, 2.3, 3.1): squared distance ≈ 1.46
    // (4.2, 7.3, 1.5): squared distance ≈ 25.38
    // (9.1, 6.2, 8.7): squared distance ≈ 49.14
    // (7.4, 3.5, 2.6): squared distance ≈ 8.97
    // So, the expected nearest neighbor is (5.4, 2.3, 3.1)
    EXPECT_DOUBLE_EQ(nearest[0], 5.4);
    EXPECT_DOUBLE_EQ(nearest[1], 2.3);
    EXPECT_DOUBLE_EQ(nearest[2], 3.1);
}

// Test the 2-dimensional KDTree nearest neighbor functionality
TEST(KDTreeTest, NearestNeighbor2D)
{
    std::vector<std::array<double, 2>> points = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 1.0},
        {2.0, 3.0},
        {4.0, 0.0}
    };

    KDTree<double, 2> tree(points);
    std::array<double, 2> target = {3.1, 3.9};
    auto nearest = tree.nearest_neighbor(target);

    // (1.0, 2.0): squared distance ≈ 8.02
    // (3.0, 4.0): squared distance ≈ 0.02
    // (5.0, 1.0): squared distance ≈ 12.02
    // (2.0, 3.0): squared distance ≈ 2.02
    // (4.0, 0.0): squared distance ≈ 16.02
    // The expected nearest neighbor is (3.0, 4.0)
    EXPECT_DOUBLE_EQ(nearest[0], 3.0);
    EXPECT_DOUBLE_EQ(nearest[1], 4.0);
}
