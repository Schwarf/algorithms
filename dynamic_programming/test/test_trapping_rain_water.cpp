//
// Created by andreas on 26.11.22.
//
#include "gtest/gtest.h"
#include "./../trapping_rain_water.h"

class SetupTrappingRainwater: public testing::Test
{
protected:
	std::vector<int> landscape1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int water1{6};
	std::vector<int> landscape2{4, 2, 0, 3, 2, 5};
	int water2{9};
};

TEST_F(SetupTrappingRainwater, brute_force1)
{
	EXPECT_EQ(rainwater(landscape1), water1);
}

TEST_F(SetupTrappingRainwater, brute_force2)
{
	EXPECT_EQ(rainwater(landscape2), water2);
}

TEST_F(SetupTrappingRainwater, dynamic_programming1)
{
	EXPECT_EQ(rainwater_dp(landscape1), water1);
}

TEST_F(SetupTrappingRainwater, dynamic_programming2)
{
	EXPECT_EQ(rainwater_dp(landscape2), water2);
}

TEST_F(SetupTrappingRainwater, stack1)
{
	EXPECT_EQ(rainwater_stack(landscape1), water1);
}

TEST_F(SetupTrappingRainwater, stack2)
{
	EXPECT_EQ(rainwater_stack(landscape2), water2);
}
