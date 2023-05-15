//
// Created by andreas on 26.11.22.
//
#include "gtest/gtest.h"
#include "trapping_rain_water.h"

class SetupTrappingRainwater: public testing::Test
{
protected:
	std::vector<int> landscape1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int water1{6};
	std::vector<int> landscape2{4, 2, 0, 3, 2, 5};
	int water2{9};
	std::vector<int> landscape3{0, 1, 2, 0, 3, 2, 5, 2, 1, 3, 1};
	int water3{6};
	std::vector<int> landscape4{3, 0, 1, 0, 1, 2, 0, 2, 4};
	int water4{15};
	std::vector<int> landscape5{3, 0, 1, 0, 8, 2, 0, 2, 4};
	int water5{16};

};

TEST_F(SetupTrappingRainwater, brute_force1)
{
	EXPECT_EQ(rainwater(landscape1), water1);
	std::reverse(landscape1.begin(), landscape1.end());
	EXPECT_EQ(rainwater(landscape1), water1);
}

TEST_F(SetupTrappingRainwater, brute_force2)
{
	EXPECT_EQ(rainwater(landscape2), water2);
	std::reverse(landscape2.begin(), landscape2.end());
	EXPECT_EQ(rainwater(landscape2), water2);

}

TEST_F(SetupTrappingRainwater, brute_force3)
{
	EXPECT_EQ(rainwater(landscape3), water3);
	std::reverse(landscape3.begin(), landscape3.end());
	EXPECT_EQ(rainwater(landscape3), water3);
}

TEST_F(SetupTrappingRainwater, brute_force4)
{
	EXPECT_EQ(rainwater(landscape4), water4);
	std::reverse(landscape4.begin(), landscape4.end());
	EXPECT_EQ(rainwater(landscape4), water4);
}

TEST_F(SetupTrappingRainwater, brute_force5)
{
	EXPECT_EQ(rainwater(landscape5), water5);
	std::reverse(landscape5.begin(), landscape5.end());
	EXPECT_EQ(rainwater(landscape5), water5);
}

TEST_F(SetupTrappingRainwater, dynamic_programming1)
{
	EXPECT_EQ(rainwater_dp(landscape1), water1);
	std::reverse(landscape1.begin(), landscape1.end());
	EXPECT_EQ(rainwater_dp(landscape1), water1);

}

TEST_F(SetupTrappingRainwater, dynamic_programming2)
{
	EXPECT_EQ(rainwater_dp(landscape2), water2);
	std::reverse(landscape2.begin(), landscape2.end());
	EXPECT_EQ(rainwater_dp(landscape2), water2);
}

TEST_F(SetupTrappingRainwater, dynamic_programming3)
{
	EXPECT_EQ(rainwater_dp(landscape3), water3);
	std::reverse(landscape3.begin(), landscape3.end());
	EXPECT_EQ(rainwater_dp(landscape3), water3);
}

TEST_F(SetupTrappingRainwater, dynamic_programming4)
{
	EXPECT_EQ(rainwater_dp(landscape4), water4);
	std::reverse(landscape4.begin(), landscape4.end());
	EXPECT_EQ(rainwater_dp(landscape4), water4);
}

TEST_F(SetupTrappingRainwater, dynamic_programming5)
{
	EXPECT_EQ(rainwater_dp(landscape5), water5);
	std::reverse(landscape5.begin(), landscape5.end());
	EXPECT_EQ(rainwater_dp(landscape5), water5);
}

TEST_F(SetupTrappingRainwater, stack1)
{
	EXPECT_EQ(rainwater_stack(landscape1), water1);
	std::reverse(landscape1.begin(), landscape1.end());
	EXPECT_EQ(rainwater_stack(landscape1), water1);

}

TEST_F(SetupTrappingRainwater, stack2)
{
	EXPECT_EQ(rainwater_stack(landscape2), water2);
	std::reverse(landscape2.begin(), landscape2.end());
	EXPECT_EQ(rainwater_stack(landscape2), water2);
}

TEST_F(SetupTrappingRainwater, stack3)
{
	EXPECT_EQ(rainwater_stack(landscape3), water3);
	std::reverse(landscape3.begin(), landscape3.end());
	EXPECT_EQ(rainwater_stack(landscape3), water3);
}

TEST_F(SetupTrappingRainwater, stack4)
{
	EXPECT_EQ(rainwater_stack(landscape4), water4);
	std::reverse(landscape4.begin(), landscape4.end());
	EXPECT_EQ(rainwater_stack(landscape4), water4);
}

TEST_F(SetupTrappingRainwater, stack5)
{
	EXPECT_EQ(rainwater_stack(landscape5), water5);
	std::reverse(landscape5.begin(), landscape5.end());
	EXPECT_EQ(rainwater_stack(landscape5), water5);
}


TEST_F(SetupTrappingRainwater, two_pointer1)
{
	EXPECT_EQ(rainwater_two_pointer(landscape1), water1);
	std::reverse(landscape1.begin(), landscape1.end());
	EXPECT_EQ(rainwater_two_pointer(landscape1), water1);

}

TEST_F(SetupTrappingRainwater, two_pointer2)
{
	EXPECT_EQ(rainwater_two_pointer(landscape2), water2);
	std::reverse(landscape2.begin(), landscape2.end());
	EXPECT_EQ(rainwater_two_pointer(landscape2), water2);
}

TEST_F(SetupTrappingRainwater, two_pointer3)
{
	EXPECT_EQ(rainwater_two_pointer(landscape3), water3);
	std::reverse(landscape3.begin(), landscape3.end());
	EXPECT_EQ(rainwater_two_pointer(landscape3), water3);
}

TEST_F(SetupTrappingRainwater, two_pointer4)
{
	EXPECT_EQ(rainwater_two_pointer(landscape4), water4);
	std::reverse(landscape4.begin(), landscape4.end());
	EXPECT_EQ(rainwater_two_pointer(landscape4), water4);
}

TEST_F(SetupTrappingRainwater, two_pointer5)
{
	EXPECT_EQ(rainwater_two_pointer(landscape5), water5);
	std::reverse(landscape5.begin(), landscape5.end());
	EXPECT_EQ(rainwater_two_pointer(landscape5), water5);
}



