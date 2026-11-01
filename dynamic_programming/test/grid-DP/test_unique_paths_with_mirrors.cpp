//
// Created by andreas on 01.11.26.
//
#include "../../grid-DP/unique_paths_with_mirrors.h"
#include "gtest/gtest.h"

TEST(UniquePathsWithMirrors, CountsTheStartingCellAsAPath)
{
    std::vector<std::vector<int>> grid{{0}};

    EXPECT_EQ(unique_paths_with_mirrors(grid), 1);
}

TEST(UniquePathsWithMirrors, CountsPathsWithoutMirrors)
{
    std::vector<std::vector<int>> grid{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    EXPECT_EQ(unique_paths_with_mirrors(grid), 6);
}

TEST(UniquePathsWithMirrors, ReflectsRightwardMovementDown)
{
    std::vector<std::vector<int>> grid{{0, 1}, {0, 0}};

    EXPECT_EQ(unique_paths_with_mirrors(grid), 2);
}

TEST(UniquePathsWithMirrors, ReflectsDownwardMovementRight)
{
    std::vector<std::vector<int>> grid{{0, 0}, {1, 0}};

    EXPECT_EQ(unique_paths_with_mirrors(grid), 2);
}

TEST(UniquePathsWithMirrors, RejectsReflectionOutsideTheGrid)
{
    std::vector<std::vector<int>> grid{{0, 1, 0}};

    EXPECT_EQ(unique_paths_with_mirrors(grid), 0);
}

TEST(UniquePathsWithMirrors, DoesNotCountPathsEndingOnAMirror)
{
    std::vector<std::vector<int>> grid{{0, 0}, {0, 1}};

    EXPECT_EQ(unique_paths_with_mirrors(grid), 0);
}

TEST(UniquePathsWithMirrors, CountsValidPathsAroundABoundaryMirror)
{
    std::vector<std::vector<int>> grid{{0, 0, 0}, {0, 0, 1}, {0, 0, 0}};

    EXPECT_EQ(unique_paths_with_mirrors(grid), 5);
}

TEST(UniquePathsWithMirrors, ReturnsTheResultModuloOneBillionAndSeven)
{
    std::vector<std::vector<int>> grid(20, std::vector<int>(20));

    EXPECT_EQ(unique_paths_with_mirrors(grid), 345'263'555);
}
