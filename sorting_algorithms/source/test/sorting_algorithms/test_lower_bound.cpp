//
// Created by andreas on 16.08.22.
//
//
// Created by andreas on 16.08.22.
//
#include "gtest/gtest.h"
#include "./../../algorithms/upper_lower_bounds/lower_bound.h"

class SetupLowerbound: public testing::Test
{
protected:
	std::vector<int64_t> sorted{-100, -18, -9, 0, 1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10};
};


TEST_F(SetupLowerbound, test_lower_bound1)
{
	auto value{7};
	auto bound = my_lower_bound(sorted.begin(), sorted.end(), value);
	auto expected_bound = std::lower_bound(sorted.begin(), sorted.end(), value);
	EXPECT_EQ(*bound, *expected_bound);

}
TEST_F(SetupLowerbound, test_lower_bound2)
{
	auto value{-18};
	auto bound = my_lower_bound(sorted.begin(), sorted.end(), value);
	auto expected_bound = std::lower_bound(sorted.begin(), sorted.end(), value);
	EXPECT_EQ(*bound, *expected_bound);

}
