//
// Created by andreas on 17.01.22.
//
#include "gtest/gtest.h"
#include <algorithm>
#include "./../algorithms/quick_sort/quick_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_quick_sort)
{
	QuickSort quick_sort;
	quick_sort.sort(random_numbers);
	std::sort(random_numbers2.begin(), random_numbers2.end());
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], random_numbers2[index]);
	}

}


