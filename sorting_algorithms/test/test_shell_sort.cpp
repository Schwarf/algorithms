//
// Created by andreas on 14.01.24.
//
#include "test_setup.h"
#include "shell_sort.h"
#include <algorithm>

TEST_F(SetupSortingTests, ShellSortSimpleSequence1)
{
	auto input = get_N_random_number_vector(0, 1000, 100);
	auto expected_output{input};
	std::sort(expected_output.begin(), expected_output.end());
	shell_sort(input, simple_gaps);
	EXPECT_EQ(input, expected_output);
}

TEST_F(SetupSortingTests, ShellSortSimpleSequence2)
{
	auto input = get_N_random_number_vector(0, 10000, 1000);
	auto expected_output{input};
	std::sort(expected_output.begin(), expected_output.end());
	shell_sort(input, simple_gaps);
	EXPECT_EQ(input, expected_output);
}

TEST_F(SetupSortingTests, ShellSortSimpleSequence3)
{
	auto input = get_N_random_number_vector(-1000, 1000, 523);
	auto expected_output{input};
	std::sort(expected_output.begin(), expected_output.end());
	shell_sort(input, simple_gaps);
	EXPECT_EQ(input, expected_output);
}

TEST_F(SetupSortingTests, ShellSortSimpleSequence4)
{
	auto input = get_N_random_number_vector(-1000, 1000, 5689);
	auto expected_output{input};
	std::sort(expected_output.begin(), expected_output.end());
	shell_sort(input, simple_gaps);
	EXPECT_EQ(input, expected_output);
}

TEST_F(SetupSortingTests, ShellSortSedgewickSequence1)
{
	auto input = get_N_random_number_vector(0, 1000, 100);
	auto expected_output{input};
	std::sort(expected_output.begin(), expected_output.end());
	shell_sort(input, sedgewick_sequence);
	EXPECT_EQ(input, expected_output);
}

TEST_F(SetupSortingTests, ShellSortSedgewickSequence2)
{
	auto input = get_N_random_number_vector(0, 10000, 1000);
	auto expected_output{input};
	std::sort(expected_output.begin(), expected_output.end());
	shell_sort(input, simple_gaps);
	EXPECT_EQ(input, expected_output);
}

TEST_F(SetupSortingTests, ShellSortSedgewickSequence3)
{
	auto input = get_N_random_number_vector(-1000, 1000, 523);
	auto expected_output{input};
	std::sort(expected_output.begin(), expected_output.end());
	shell_sort(input, simple_gaps);
	EXPECT_EQ(input, expected_output);
}

TEST_F(SetupSortingTests, ShellSortSedgewickSequence4)
{
	auto input = get_N_random_number_vector(-1000, 1000, 5689);
	auto expected_output{input};
	std::sort(expected_output.begin(), expected_output.end());
	shell_sort(input, simple_gaps);
	EXPECT_EQ(input, expected_output);
}
