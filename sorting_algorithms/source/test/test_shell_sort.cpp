//
// Created by andreas on 16.01.22.
//

#include "gtest/gtest.h"
#include "./../algorithms/shell_sort/shell_sort.h"
#include "sorting_setup.h"


TEST_F(SetupSorting, test_shell_sort_classic)
{
	ShellSort shell_sort;
	shell_sort.sort(random_numbers);
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], random_numbers2[index]);
	}

}

TEST_F(SetupSorting, test_shell_sort_sedgewick)
{
	ShellSort shell_sort;
	shell_sort.set_variant(ShellSortVariant::sedgewick);
	shell_sort.sort(random_numbers);
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], random_numbers2[index]);
	}
}

TEST_F(SetupSorting, test_shell_sort_tokuda)
{
	ShellSort shell_sort;
	shell_sort.set_variant(ShellSortVariant::tokuda);
	shell_sort.sort(random_numbers);
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], random_numbers2[index]);
	}
}


TEST_F(SetupSorting, test_shell_sort_ciura)
{
	ShellSort shell_sort;
	shell_sort.set_variant(ShellSortVariant::ciura);
	shell_sort.sort(random_numbers);
	for(size_t index =0; index < random_numbers.size(); ++index)
	{
		EXPECT_EQ(random_numbers[index], random_numbers2[index]);
	}
}

