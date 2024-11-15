//
// Created by andreas on 18.07.22.
//

#include "gtest/gtest.h"
#include "can_reach_last_index.h"
#include <vector>

TEST(CanReachLastIndex, test_scenario1)
{
    const std::vector<int> jump_distance{2, 3, 1, 1, 4};
    EXPECT_TRUE(can_reach_last_index(jump_distance));
}

TEST(CanReachLastIndex, test_scenario2)
{
    const std::vector<int> jump_distance{3, 2, 1, 0, 4};
    EXPECT_FALSE(can_reach_last_index(jump_distance));
}

TEST(CanReachLastIndex, test_scenario3)
{
    const std::vector<int> jump_distance{0, 3, 1, 1, 4};
    EXPECT_FALSE(can_reach_last_index(jump_distance));
}

TEST(CanReachLastIndex, test_scenario4)
{
    const std::vector<int> jump_distance{4, 0, 0, 0, 0};
    EXPECT_TRUE(can_reach_last_index(jump_distance));
}

TEST(CanReachLastIndex, test_scenario5)
{
    const std::vector<int> jump_distance{0};
    EXPECT_TRUE(can_reach_last_index(jump_distance));
}
