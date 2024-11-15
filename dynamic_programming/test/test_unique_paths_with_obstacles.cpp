// Created by andreas on 13.08.23.
//
#include "gtest/gtest.h"
#include "unique_paths_with_obstacles.h"

TEST(UniquePathsWithObstaclesRecursive, simple1)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{2};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple2)
{
    const std::vector<std::vector<int>> matrix{
        {0, 1},
        {0, 0}
    };
    constexpr int expected_paths{1};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple3)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    };
    constexpr int expected_paths{0};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple4)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{6};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple5)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    constexpr int expected_paths{7};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple6)
{
    const std::vector<std::vector<int>> matrix{{0}};
    constexpr int expected_paths{1};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, simple7)
{
    const std::vector<std::vector<int>> matrix{
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{0};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}

TEST(UniquePathsWithObstaclesRecursive, complex1)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
    };
    constexpr int expected_paths{13594824};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_recursive(matrix));
}


TEST(UniquePathsWithObstaclesTopDown, simple1)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{2};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_top_down(matrix));
}

TEST(UniquePathsWithObstaclesTopDown, simple2)
{
    const std::vector<std::vector<int>> matrix{
        {0, 1},
        {0, 0}
    };
    constexpr int expected_paths{1};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_top_down(matrix));
}

TEST(UniquePathsWithObstaclesTopDown, simple3)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    };
    constexpr int expected_paths{0};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_top_down(matrix));
}


TEST(UniquePathsWithObstaclesTopDown, simple4)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{6};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_top_down(matrix));
}

TEST(UniquePathsWithObstaclesTopDown, simple5)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    constexpr int expected_paths{7};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_top_down(matrix));
}

TEST(UniquePathsWithObstaclesTopDown, simple6)
{
    const std::vector<std::vector<int>> matrix{{0}};
    constexpr int expected_paths{1};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_top_down(matrix));
}

TEST(UniquePathsWithObstaclesTopDown, simple7)
{
    const std::vector<std::vector<int>> matrix{
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{0};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_top_down(matrix));
}


TEST(UniquePathsWithObstaclesTopDown, complex1)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
    };
    constexpr int expected_paths{13594824};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_top_down(matrix));
}


TEST(UniquePathsWithObstaclesBottomUp, simple1)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{2};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up(matrix));
}

TEST(UniquePathsWithObstaclesBottomUp, simple2)
{
    const std::vector<std::vector<int>> matrix{
        {0, 1},
        {0, 0}
    };
    constexpr int expected_paths{1};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up(matrix));
}

TEST(UniquePathsWithObstaclesBottomUp, simple3)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    };
    constexpr int expected_paths{0};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up(matrix));
}


TEST(UniquePathsWithObstaclesBottomUp, simple4)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{6};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up(matrix));
}

TEST(UniquePathsWithObstaclesBottomUp, simple5)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    constexpr int expected_paths{7};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up(matrix));
}

TEST(UniquePathsWithObstaclesBottomUp, simple6)
{
    const std::vector<std::vector<int>> matrix{{0}};
    constexpr int expected_paths{1};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up(matrix));
}

TEST(UniquePathsWithObstaclesBottomUp, simple7)
{
    const std::vector<std::vector<int>> matrix{
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{0};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up(matrix));
}


TEST(UniquePathsWithObstaclesBottomUp, complex1)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
    };
    constexpr int expected_paths{13594824};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up(matrix));
}


TEST(UniquePathsWithObstaclesBottomUpOptimized, simple1)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{2};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up_optimized(matrix));
}

TEST(UniquePathsWithObstaclesBottomUpOptimized, simple2)
{
    const std::vector<std::vector<int>> matrix{
        {0, 1},
        {0, 0}
    };
    constexpr int expected_paths{1};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up_optimized(matrix));
}

TEST(UniquePathsWithObstaclesBottomUpOptimized, simple3)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    };
    constexpr int expected_paths{0};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up_optimized(matrix));
}


TEST(UniquePathsWithObstaclesBottomUpOptimized, simple4)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{6};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up_optimized(matrix));
}

TEST(UniquePathsWithObstaclesBottomUpOptimized, simple5)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    constexpr int expected_paths{7};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up_optimized(matrix));
}

TEST(UniquePathsWithObstaclesBottomUpOptimized, simple6)
{
    const std::vector<std::vector<int>> matrix{{0}};
    constexpr int expected_paths{1};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up_optimized(matrix));
}

TEST(UniquePathsWithObstaclesBottomUpOptimized, simple7)
{
    const std::vector<std::vector<int>> matrix{
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    constexpr int expected_paths{0};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up_optimized(matrix));
}


TEST(UniquePathsWithObstaclesBottomUpOptimized, complex1)
{
    const std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
    };
    constexpr int expected_paths{13594824};
    EXPECT_EQ(expected_paths, unique_paths_with_obstacles_bottom_up_optimized(matrix));
}
