#include <iostream>
#include "selection_sort/selection_sort.h"
#include "insertion_sort/insertion_sort.h"
#include "shell_sort/shell_sort.h"
#include "merge_sort/merge_sort.h"
#include "time_measurement/execution_time_for_sorting.h"

int main()
{
	std::vector<int64_t> test{17, 10, 1, 2, 25, 6, 62, 3, 3, 4, 4, 5, 5};
	MergeSort selection_sort;
	//selection_sort.enable_non_recursive_version(true);
	std::shared_ptr<ISort>  merge_sort = std::make_shared<MergeSort>(selection_sort);


	ExecutionTimeForSorting time(merge_sort);
	size_t i = 0;
	size_t j = 0;
	time.measure(test);
	for (const auto &element: test) {
		std::cout << element << std::endl;
	}
	std::cout << "Time in nanoseconds: " << time.execution_time() << std::endl;
	return 0;
}
