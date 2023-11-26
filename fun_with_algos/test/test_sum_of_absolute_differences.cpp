//
// Created by andreas on 26.11.23.
//
#include "gtest/gtest.h"
#include "./../sum_of_absolute_differences.h"

TEST(SumOfAbsluteDifferences, simple1)
{
	const std::vector<int> input{2, 3, 5};
	const std::vector<int> expected_result{4, 3, 5};
	auto result = sum_of_absolute_differences(input);
	EXPECT_EQ(result.size(), expected_result.size());
	for (int i{}; i < expected_result.size(); ++i) {
		EXPECT_EQ(result[i], expected_result[i]);
	}
}

TEST(SumOfAbsluteDifferences, simple2)
{
	const std::vector<int> input{1, 4, 6, 8, 10};
	const std::vector<int> expected_result{24, 15, 13, 15, 21};
	auto result = sum_of_absolute_differences(input);
	EXPECT_EQ(result.size(), expected_result.size());
	for (int i{}; i < expected_result.size(); ++i) {
		EXPECT_EQ(result[i], expected_result[i]);
	}
}


TEST(SumOfAbsluteDifferences, simpl3)
{
	const std::vector<int> input{1, 45, 786, 3190, 9999};
	const std::vector<int> expected_result{14016, 13884, 13143, 15547, 35974};
	auto result = sum_of_absolute_differences(input);
	EXPECT_EQ(result.size(), expected_result.size());
	for (int i{}; i < expected_result.size(); ++i) {
		EXPECT_EQ(result[i], expected_result[i]);
	}
}


TEST(SumOfAbsluteDifferences, simpl4)
{
	const std::vector<int> input{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	const std::vector<int> expected_result{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	auto result = sum_of_absolute_differences(input);
	EXPECT_EQ(result.size(), expected_result.size());
	for (int i{}; i < expected_result.size(); ++i) {
		EXPECT_EQ(result[i], expected_result[i]);
	}
}
