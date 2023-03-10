//
// Created by andreas on 01.03.23.
//
#include "test_setup.h"
#include "heap_sort.h"
#include <algorithm>

TEST_F(SetupSortingTests, heap_sort_int_vector)
{
	auto result = get_N_random_number_vector(-1000, 1000, 1000);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);

	EXPECT_NE(result, expected_result);
	heap_sort(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, heap_sort_int_array)
{
	auto result = get_N_random_number_array<100>(-1000, 1000);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_NE(result, expected_result);
	heap_sort(result);
	EXPECT_EQ(result, expected_result);
}


TEST_F(SetupSortingTests, heap_sort_string)
{
	auto result = generate_random_string(128);
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_NE(result, expected_result);
	heap_sort(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, heap_sort_empty_vector)
{
	auto result = std::vector<int>{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	heap_sort(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, heap_sort_empty_array)
{
	auto result = std::array<int, 0>{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	heap_sort(result);
	EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, heap_sort_empty_string)
{
	auto result = std::string{};
	auto expected_result = result;
	EXPECT_EQ(result, expected_result);
	std::ranges::sort(expected_result);
	EXPECT_EQ(result, expected_result);
	heap_sort(result);
	EXPECT_EQ(result, expected_result);
}


TEST_F(SetupSortingTests, heap_sort_int_vector_of_pointers)
{
	auto result = get_N_random_number_vector_of_pointers(-1000, 1000, 1000);
	heap_sort(result);
	int before {-1001};
	for(int i{}; i < result.size(); ++i) {
		EXPECT_TRUE(before <= *result[i]);
		before = *result[i];
	}

}
