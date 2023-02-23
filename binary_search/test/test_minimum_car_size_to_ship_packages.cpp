//
// Created by andreas on 23.02.23.
//

#include "gtest/gtest.h"
#include <vector>
#include "./../minimum_car_size_to_ship_packages.h"

TEST(MinimumCarSize, case1)
{
	std::vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int days{5};
	int expected_result{15};
	EXPECT_EQ(get_car_size_to_ship_in_days(weights, days), expected_result);
}

TEST(MinimumCarSize, case2)
{
	std::vector<int> weights{3,2,2,4,1,4};
	int days{3};
	int expected_result{6};
	EXPECT_EQ(get_car_size_to_ship_in_days(weights, days), expected_result);
}

TEST(MinimumCarSize, case3)
{
	std::vector<int> weights{1,2,3,1,1};
	int days{4};
	int expected_result{3};
	EXPECT_EQ(get_car_size_to_ship_in_days(weights, days), expected_result);
}
