//
// Created by andreas on 12.03.23.
//
//
// Created by andreas on 11.03.23.
//

#include "test_setup.h"
#include "selection_sort.h"
#include <algorithm>

TEST_F(SetupSortingTests, selection_sort_int_vector)
{
	auto result = get_N_random_number_vector(-1000, 1000, 1000);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_NE(result, expected_result);
	selection_sort(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, selection_sort_int_array)
{
	auto result = get_N_random_number_array<100>(-1000, 1000);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_NE(result, expected_result);
	selection_sort(result);
	EXPECT_EQ(result, expected_result);
}


TEST_F(SetupSortingTests, selection_sort_string)
{
	auto result = generate_random_string(128);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_NE(result, expected_result);
	selection_sort(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, selection_sort_empty_vector)
{
	auto result = std::vector<int>{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	selection_sort(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, selection_sort_empty_array)
{
	auto result = std::array<int, 0>{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	selection_sort(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, selection_sort_empty_string)
{
	auto result = std::string{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	selection_sort(result);
	EXPECT_EQ(result, expected_result);
}
