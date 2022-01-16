//
// Created by andreas on 15.01.22.
//

#include "execution_time_for_sorting.h"
ExecutionTimeForSorting::ExecutionTimeForSorting(std::shared_ptr<ISort> &sorting_algorithm)
	:
	sorting_algorithm_(sorting_algorithm)
{}

void ExecutionTimeForSorting::measure(std::vector<int64_t> &array)
{
	auto start = std::chrono::high_resolution_clock::now();
	sorting_algorithm_->sort(array);
	auto end = std::chrono::high_resolution_clock::now();
	execution_time_ = std::chrono::duration_cast<std::chrono::nanoseconds>(end -start).count();
}

int64_t ExecutionTimeForSorting::execution_time()
{
	return execution_time_;
}
void ExecutionTimeForSorting::set_sorting_algorithm(std::shared_ptr<ISort> algorithm)
{
	sorting_algorithm_ = algorithm;
}
