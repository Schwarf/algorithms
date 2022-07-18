//
// Created by andreas on 18.07.22.
//
#include "gtest/gtest.h"
#include "./../count_ways_2D_grid.h"

class SetupCountWaysIn2DGrid : public testing::Test
{
protected:
	int number_of_rows1{1};
	int number_of_columns1{1};
	int ways1{1};

	int number_of_rows2{2};
	int number_of_columns2{3};
	int ways2{3};


	int number_of_rows3{3};
	int number_of_columns3{2};
	int ways3{3};

	int number_of_rows4{3};
	int number_of_columns4{3};
	int ways4{6};

};


TEST_F(SetupCountWaysIn2DGrid, test_scenario1)
{
	auto result1 = count_ways_down_and_right_in_2D_grid(number_of_rows1, number_of_columns1);
	EXPECT_EQ(result1, ways1);
}

TEST_F(SetupCountWaysIn2DGrid, test_scenario2)
{
	auto result2 = count_ways_down_and_right_in_2D_grid(number_of_rows2, number_of_columns2);
	EXPECT_EQ(result2, ways2);
}

TEST_F(SetupCountWaysIn2DGrid, test_scenario3)
{
	auto result3 = count_ways_down_and_right_in_2D_grid(number_of_rows3, number_of_columns3);
	EXPECT_EQ(result3, ways3);
}

TEST_F(SetupCountWaysIn2DGrid, test_scenario4)
{
	auto result4 = count_ways_down_and_right_in_2D_grid(number_of_rows4, number_of_columns4);
	EXPECT_EQ(result4, ways4);
}