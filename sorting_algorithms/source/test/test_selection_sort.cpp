#include "gtest/gtest.h"
#include "./../algorithms/selection_sort/selection_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_selection_sort)
{
	SelectionSort selection_sort;
	selection_sort.sort(random_numbers);
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], std_sorted_reference[index]);
	}

}


