#include <iostream>
#include "selection_sort/selection_sort.h"
#include "insertion_sort/insertion_sort.h"
#include "shell_sort/shell_sort.h"
#include "merge_sort/merge_sort.h"
#include "performance_measurement/execution_time_for_sorting.h"
#include "performance_measurement/data_accumulator.h"
#include "performance_measurement/test_template.h"

int main()
{
	TestTemplate test_template;
	std::shared_ptr<ISort>  merge_sort = std::make_shared<MergeSort>();
	test_template.execute_all_with(merge_sort);
	auto execution_times = test_template.get_execution_time_dictionary()[merge_sort];
	for(const auto & execution_time : (*execution_times))
	{
		std::cout << "execution time = " << execution_time << " in nanoseconds." << std::endl;
	}


	DataAccumulator<int64_t> data;
	std::vector<int64_t> test{17, 10, 1, 2, 25, 6, 62, 3, 3, 4, 4, 5, 5};
	std::shared_ptr<std::vector<int64_t>> test_ptr = std::make_shared<std::vector<int64_t>>(test);
	data.add_data_vector(test_ptr);
	SelectionSort selection_sort;
	//selection_sort.enable_non_recursive_version(true);
	std::shared_ptr<ISort>  selection_sort_ptr = std::make_shared<SelectionSort>(selection_sort);
	auto sample = data.get_data_vector(0);
	selection_sort.sort(sample);
	//ExecutionTimeForSorting time(merge_sort);
//	time.measure(test);
	for (const auto &element: *sample) {
		std::cout << element << std::endl;
	}
	//std::cout << "Time in nanoseconds: " << time.execution_time() << std::endl;
	return 0;
}
