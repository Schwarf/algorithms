//
// Created by andreas on 14.02.22.
//

#include "gtest/gtest.h"
#include "../../algorithms/counting_sort/counting_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_counting_sort)
{
	CountingSort counting_sort(lower_limit_, upper_limit_);
	counting_sort.sort(random_numbers_in_range);
	for (size_t index = 0; index < random_numbers_in_range.size(); ++index) {
		EXPECT_EQ(random_numbers_in_range[index], std_sorted_numbers_in_range[index]);
	}

}
