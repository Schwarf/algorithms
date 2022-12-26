//
// Created by andreas on 18.07.22.
//

#include "gtest/gtest.h"
#include "./../jumps.h"
#include <vector>

TEST(CanReachLastIndex, test_scenario1)
{
	std::vector<int> jump_distance{2, 3, 1, 1, 4};
	EXPECT_TRUE(can_reach_last_index(jump_distance));
}

TEST(CanReachLastIndex, test_scenario2)
{
	std::vector<int> jump_distance{3, 2, 1, 0, 4};
	EXPECT_FALSE(can_reach_last_index(jump_distance));
}

TEST(CanReachLastIndex, test_scenario3)
{
	std::vector<int> jump_distance{0, 3, 1, 1, 4};
	EXPECT_FALSE(can_reach_last_index(jump_distance));
}

TEST(CanReachLastIndex, test_scenario4)
{
	std::vector<int> jump_distance{4, 0, 0, 0, 0};
	EXPECT_TRUE(can_reach_last_index(jump_distance));
}


TEST(MinimalNumberOfJumps, test_scenario1)
{
	std::vector<int> max_jump_distance1{2, 3, 1, 1, 4};
	int minimal_number_of_jumps1{2};
	auto min_jumps = min_jumps_to_last_index(max_jump_distance1);
	EXPECT_EQ(minimal_number_of_jumps1, min_jumps);
}

TEST(MinimalNumberOfJumps, test_scenario2)
{
	std::vector<int> max_jump_distance2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int minimal_number_of_jumps2{4};
	auto min_jumps = min_jumps_to_last_index(max_jump_distance2);
	EXPECT_EQ(minimal_number_of_jumps2, min_jumps);
}

TEST(MinimalNumberOfJumps, test_scenario3)
{
	std::vector<int> max_jump_distance3{1, 3, 5, 3, 3, 3, 6, 1, 1, 1, 1, 1, 1};
	int minimal_number_of_jumps3{4};
	auto min_jumps = min_jumps_to_last_index(max_jump_distance3);
	EXPECT_EQ(minimal_number_of_jumps3, min_jumps);
}

