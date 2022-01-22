#include "gtest/gtest.h"
#include "../../algorithms/merge_sort/merge_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_merge_recursive_sort)
{
	MergeSort merge_sort;
	merge_sort.sort(random_numbers);
	for (size_t index = 0; index < random_numbers.size(); ++index) {
		EXPECT_EQ(random_numbers[index], std_sorted_reference[index]);
	}

}

TEST_F(SetupSorting, test_merge_non_recursive_sort)
{
	MergeSort merge_sort;
	merge_sort.enable_non_recursive_version(true);
	merge_sort.sort(random_numbers);
	for (size_t index = 0; index < random_numbers.size(); ++index) {
		EXPECT_EQ(random_numbers[index], std_sorted_reference[index]);
	}
}


