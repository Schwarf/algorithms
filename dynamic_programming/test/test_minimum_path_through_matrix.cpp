//
// Created by andreas on 13.12.22.
//
#include "gtest/gtest.h"
#include <vector>
#include "./../minimum_path_through_matrix.h"
class SetupMinimumPathThroughMatrix: public testing::Test
{
protected:
	std::vector<std::vector<int>> input1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int result1{12};
	std::vector<std::vector<int>> input2{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	int result2{15};
	std::vector<std::vector<int>> input3{{0, 1, 0}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1}, {-1, 0, 1}, {1, 0, 1}};
	int result3{};

};

TEST_F(SetupMinimumPathThroughMatrix, test_scenario1)
{
	auto minimum = minimal_downward_path_through_matrix(input1);
	EXPECT_EQ(minimum, result1);
}

TEST_F(SetupMinimumPathThroughMatrix, test_scenario2)
{
	auto minimum = minimal_downward_path_through_matrix(input2);
	EXPECT_EQ(minimum, result2);
}

TEST_F(SetupMinimumPathThroughMatrix, test_scenario3)
{
	auto minimum = minimal_downward_path_through_matrix(input3);
	EXPECT_EQ(minimum, result3);
}


TEST_F(SetupMinimumPathThroughMatrix, test_scenario1_constant_input)
{
	auto minimum = minimal_downward_path_through_matrix2(input1);
	EXPECT_EQ(minimum, result1);
}

TEST_F(SetupMinimumPathThroughMatrix, test_scenario2_constant_input)
{
	auto minimum = minimal_downward_path_through_matrix2(input2);
	EXPECT_EQ(minimum, result2);
}

TEST_F(SetupMinimumPathThroughMatrix, test_scenario3_constant_input)
{
	auto minimum = minimal_downward_path_through_matrix2(input3);
	EXPECT_EQ(minimum, result3);
}