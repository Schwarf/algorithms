//
// Created by andreas on 09.03.23.
//

#include "gtest/gtest.h"
#include <vector>
#include "./../minimum_speed_to_eat_bananas_in_n_hours.h"

TEST(MinimumSpeedToEatBananas, case1)
{
	std::vector<unsigned int> weights{3,6,7,11};
	int time{8};
	int expected_result{4};
	EXPECT_EQ(minimum_speed_to_eat_bananas_in_n_hours(weights, time), expected_result);
}

TEST(MinimumSpeedToEatBananas, case2)
{
	std::vector<unsigned int> weights{30,11,23,4,20};
	int time{5};
	int expected_result{30};
	EXPECT_EQ(minimum_speed_to_eat_bananas_in_n_hours(weights, time), expected_result);
}

TEST(MinimumSpeedToEatBananas, case3)
{
	std::vector<unsigned int> weights{30,11,23,4,20};
	int time{6};
	int expected_result{23};
	EXPECT_EQ(minimum_speed_to_eat_bananas_in_n_hours(weights, time), expected_result);
}
