#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "stacks_and_queues/monotonic_stack_and_queue/free_building_views.h"

namespace
{
void expect_free_views(const std::vector<int>& buildings, const std::string& direction, const std::vector<int>& expected)
{
    EXPECT_EQ(expected, free_views(buildings, direction));
    EXPECT_EQ(expected, free_views_monotonic_stack(buildings, direction));
}
}

TEST(FreeBuildingViews, EmptyInputHasNoViewsFromEast)
{
    expect_free_views({}, "EAST", {});
}

TEST(FreeBuildingViews, EmptyInputHasNoViewsFromWest)
{
    expect_free_views({}, "WEST", {});
}

TEST(FreeBuildingViews, SingleBuildingSeesBothHorizons)
{
    expect_free_views({10}, "EAST", {0});
    expect_free_views({10}, "WEST", {0});
}

TEST(FreeBuildingViews, ExampleMixedHeightsFromEast)
{
    expect_free_views({3, 5, 4, 4, 3, 1, 3, 2}, "EAST", {1, 3, 6, 7});
}

TEST(FreeBuildingViews, ExampleMixedHeightsFromWest)
{
    expect_free_views({3, 5, 4, 4, 3, 1, 3, 2}, "WEST", {0, 1});
}

TEST(FreeBuildingViews, StrictlyIncreasingHeights)
{
    expect_free_views({1, 2, 3, 4}, "EAST", {3});
    expect_free_views({1, 2, 3, 4}, "WEST", {0, 1, 2, 3});
}

TEST(FreeBuildingViews, StrictlyDecreasingHeights)
{
    expect_free_views({4, 3, 2, 1}, "EAST", {0, 1, 2, 3});
    expect_free_views({4, 3, 2, 1}, "WEST", {0});
}

TEST(FreeBuildingViews, EqualHeightBuildingsBlockEachOther)
{
    expect_free_views({5, 5, 5, 5}, "EAST", {3});
    expect_free_views({5, 5, 5, 5}, "WEST", {0});
}

TEST(FreeBuildingViews, EqualMaximaOnlyNearestHorizonHasView)
{
    expect_free_views({2, 7, 3, 7, 4}, "EAST", {3, 4});
    expect_free_views({2, 7, 3, 7, 4}, "WEST", {0, 1});
}

TEST(FreeBuildingViews, AlternatingPeaks)
{
    expect_free_views({1, 3, 2, 4, 3, 5, 4}, "EAST", {5, 6});
    expect_free_views({1, 3, 2, 4, 3, 5, 4}, "WEST", {0, 1, 3, 5});
}

TEST(FreeBuildingViews, UnknownDirectionUsesWestBehavior)
{
    expect_free_views({3, 1, 4, 2}, "NORTH", {0, 2});
}
