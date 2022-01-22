#include <iostream>
#include "selection_sort/selection_sort.h"
#include "insertion_sort/insertion_sort.h"
#include "shell_sort/shell_sort.h"
#include "merge_sort/merge_sort.h"
#include "quick_sort/quick_sort.h"
#include "performance_measurement/execution_time_for_sorting.h"
#include "performance_measurement/data_accumulator.h"
#include "performance_measurement/test_template.h"
#include "sorting_related/quick_select/quick_select.h"
int main()
{
	std::vector<int64_t> test_select{1, 2, 3, 4, 6, 7, 8, 9, 10};
	QuickSelect select;
	std::cout << select.select(test_select, 5) << std::endl;

	/*
	 TestTemplate test_template;
	QuickSort quick;
	quick.set_classic_variant(true);
	std::shared_ptr<ISort>  quick_sort = std::make_shared<QuickSort>(quick);

	test_template.execute_all_with(quick_sort, "Quicksort");
	auto execution_times = test_template.get_execution_time_map()[quick_sort];
	for(const auto & execution_time : (*execution_times))
	{
		std::cout << test_template.get_algorithm_name_map()[quick_sort] + " execution time = " << execution_time << " in nanoseconds." << std::endl;
	}
	*/
	return 0;
}
