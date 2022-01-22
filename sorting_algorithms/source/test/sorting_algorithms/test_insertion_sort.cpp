#include "gtest/gtest.h"
#include "../../algorithms/insertion_sort/insertion_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_insertion_sort)
{
	InsertionSort insertion_sort;
	insertion_sort.sort(random_numbers);
	for (size_t index = 0; index < random_numbers.size(); ++index) {
		EXPECT_EQ(random_numbers[index], std_sorted_reference[index]);
	}

}


