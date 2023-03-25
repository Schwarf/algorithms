//
// Created by andreas on 25.03.23.
//

//
// Created by andreas on 22.03.23.
//
#include "test_setup.h"
#include "bitonic_sort.h"
#include <algorithm>

TEST_F(SetupSortingTests, bitonic_sort_int_vector)
{
	auto result = get_N_random_number_vector(-1000, 1000, two_to_the_power_of_10);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_NE(result, expected_result);
	bitonic_sort<std::vector<int>, two_to_the_power_of_10>(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, bitonic_sort_int_array)
{
	auto result = get_N_random_number_array<two_to_the_power_of_11>(-1000, 1000);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_NE(result, expected_result);
	bitonic_sort<std::array<int, two_to_the_power_of_11>, two_to_the_power_of_11>(result);
	EXPECT_EQ(result, expected_result);
}


TEST_F(SetupSortingTests, bitonic_sort_string)
{
	auto result = generate_random_string(two_to_the_power_of_7);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_NE(result, expected_result);
	bitonic_sort<std::string, two_to_the_power_of_7>(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, bitonic_sort_empty_vector)
{
	auto result = std::vector<int>{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	bitonic_sort<std::vector<int>, 0>(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, bitonic_sort_empty_array)
{
	auto result = std::array<int, 0>{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	bitonic_sort<std::array<int,0>, 0>(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, bitonic_sort_empty_string)
{
	auto result = std::string{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	bitonic_sort<std::string, 0>(result);
	EXPECT_EQ(result, expected_result);
}
