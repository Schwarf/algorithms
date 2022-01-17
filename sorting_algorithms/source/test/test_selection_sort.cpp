#include "gtest/gtest.h"
#include <algorithm>
#include "./../algorithms/selection_sort/selection_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_selection_sort)
{
	SelectionSort selection_sort;
	selection_sort.sort(random_numbers);
	std::sort(random_numbers2.begin(), random_numbers2.end());
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], random_numbers2[index]);
	}

}


