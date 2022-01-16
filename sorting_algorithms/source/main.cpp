#include <iostream>
#include "selection_sort/selection_sort.h"
#include "insertion_sort/insertion_sort.h"
#include "shell_sort/shell_sort.h"
#include "merge_sort/merge_sort.h"
#include "performance_measurement/execution_time_for_sorting.h"
#include "performance_measurement/data_accumulator.h"

int main()
{
	DataAccumulator<int64_t> data;
	std::vector<int64_t> test{17, 10, 1, 2, 25, 6, 62, 3, 3, 4, 4, 5, 5};
	std::shared_ptr<std::vector<int64_t>> test_ptr = std::make_shared<std::vector<int64_t>>(test);
	data.add_data_vector(test_ptr);
	SelectionSort selection_sort;
	//selection_sort.enable_non_recursive_version(true);
	std::shared_ptr<ISort>  merge_sort = std::make_shared<SelectionSort>(selection_sort);

	selection_sort.sort(test_ptr);
	//ExecutionTimeForSorting time(merge_sort);
	size_t i = 0;
	size_t j = 0;
//	time.measure(test);
	for (const auto &element: *test_ptr) {
		std::cout << element << std::endl;
	}
	//std::cout << "Time in nanoseconds: " << time.execution_time() << std::endl;
	return 0;
}
