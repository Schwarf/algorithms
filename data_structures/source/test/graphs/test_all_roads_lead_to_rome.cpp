//
// Created by andreas on 27.03.23.
//
#include "gtest/gtest.h"
#include "graphs/all_roads_lead_to_rome.h"

TEST(AllRoadsLeadToRome, simple1)
{
	std::vector<std::vector<unsigned int>> input{{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
	int expected_result{3};
	unsigned int number_of_cities{6};
	EXPECT_EQ(all_roads_lead_to_rome(number_of_cities, input), expected_result);
}


TEST(AllRoadsLeadToRome, simple2)
{
	std::vector<std::vector<unsigned int>> input{{1, 0}, {1, 2}, {3, 2}, {3, 4}};
	int expected_result{2};
	unsigned int number_of_cities{5};
	EXPECT_EQ(all_roads_lead_to_rome(number_of_cities, input), expected_result);
}


TEST(AllRoadsLeadToRome, simple_zero)
{
	std::vector<std::vector<unsigned int>> input{{1, 0}, {2, 0}};
	int expected_result{0};
	unsigned int number_of_cities{3};
	EXPECT_EQ(all_roads_lead_to_rome(number_of_cities, input), expected_result);
}
