//
// Created by andreas on 17.01.22.
//
#include "gtest/gtest.h"
#include "./../algorithms/quick_sort/quick_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_quick_sort_modern)
{
	QuickSort quick_sort;
	quick_sort.sort(random_numbers);
	for (size_t index = 0; index < random_numbers.size(); ++index) {
		EXPECT_EQ(random_numbers[index], std_sorted_reference[index]);
	}
}

TEST_F(SetupSorting, test_quick_sort_classic)
{
	QuickSort quick_sort;
	quick_sort.set_classic_variant(true);
	quick_sort.sort(random_numbers);
	for (size_t index = 0; index < random_numbers.size(); ++index) {
		EXPECT_EQ(random_numbers[index], std_sorted_reference[index]);
	}
}

