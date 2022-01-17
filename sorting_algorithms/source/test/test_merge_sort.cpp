#include "gtest/gtest.h"
#include <algorithm>
#include "./../algorithms/merge_sort/merge_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_merge_recursive_sort)
{
	MergeSort merge_sort;
	merge_sort.sort(random_numbers);
	std::sort(random_numbers2.begin(), random_numbers2.end());
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], random_numbers2[index]);
	}

}

TEST_F(SetupSorting, test_merge_non_recursive_sort)
{
	MergeSort merge_sort;
	merge_sort.enable_non_recursive_version(true);
	merge_sort.sort(random_numbers);
	std::sort(random_numbers2.begin(), random_numbers2.end());
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], random_numbers2[index]);
	}

}


