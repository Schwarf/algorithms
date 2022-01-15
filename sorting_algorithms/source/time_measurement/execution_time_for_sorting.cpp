//
// Created by andreas on 15.01.22.
//

#include "execution_time_for_sorting.h"
ExecutionTimeForSorting::ExecutionTimeForSorting(std::shared_ptr<ISort> &sorting_object)
	:
	sorting_object_(sorting_object)
{

}

void ExecutionTimeForSorting::measure(std::vector<int64_t> &array)
{
	auto start = std::chrono::high_resolution_clock::now();
	sorting_object_->sort(array);
	auto end = std::chrono::high_resolution_clock::now();
	execution_time_ = std::chrono::duration_cast<std::chrono::nanoseconds>(end -start).count();
}

int64_t ExecutionTimeForSorting::execution_time()
{
	return execution_time_;
}
