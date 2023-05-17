//
// Created by andreas on 17.05.23.
//

#include "gtest/gtest.h"
#include "setup_singly_linked_lists.h"
#include "linked_lists/maximum_twin_sum.h"

TEST_F(SetupSinglyLinkedLists, maximum_twin_sum_double_simple)
{
	std::vector<double> input{1.0, 2.0, 5.0, 10.0};
	double expected_result{11.0};
	auto head = get_single_list_from_vector(input);
	EXPECT_EQ(maximum_twin_sum_with_vector(head), expected_result);
}

TEST_F(SetupSinglyLinkedLists, maximum_twin_sum_integer_simple)
{
	std::vector<int> input{1, 2};
	int expected_result{3};
	auto head = get_single_list_from_vector(input);
	EXPECT_EQ(maximum_twin_sum_with_vector(head), expected_result);
}


TEST_F(SetupSinglyLinkedLists, maximum_twin_sum_integer_simple2)
{
	std::vector<int> input{1, 2, 3, 4, 4, 5, 6, 7, 8, 90, 2, 3, 4, 56};
	int expected_result{94};
	auto head = get_single_list_from_vector(input);
	EXPECT_EQ(maximum_twin_sum_with_vector(head), expected_result);
}

TEST_F(SetupSinglyLinkedLists, maximum_twin_sum_with_stack_double_simple)
{
	std::vector<double> input{1.0, 2.0, 5.0, 10.0};
	double expected_result{11.0};
	auto head = get_single_list_from_vector(input);
	EXPECT_EQ(maximum_twin_sum_with_stack(head), expected_result);
}

TEST_F(SetupSinglyLinkedLists, maximum_twin_sum_with_stack_integer_simple)
{
	std::vector<int> input{1, 2};
	int expected_result{3};
	auto head = get_single_list_from_vector(input);
	EXPECT_EQ(maximum_twin_sum_with_stack(head), expected_result);
}


TEST_F(SetupSinglyLinkedLists, maximum_twin_sum_with_stack_integer_simple2)
{
	std::vector<int> input{1, 2, 3, 4, 4, 5, 6, 7, 8, 90, 2, 3, 4, 56};
	int expected_result{94};
	auto head = get_single_list_from_vector(input);
	EXPECT_EQ(maximum_twin_sum_with_stack(head), expected_result);
}
