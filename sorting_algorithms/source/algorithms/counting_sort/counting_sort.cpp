//
// Created by andreas on 14.02.22.
//

#include "counting_sort.h"
CountingSort::CountingSort(int64_t lower_limit, int64_t upper_limit)
{
	if (lower_limit >= upper_limit)
		throw std::out_of_range("Lower limit is greater-equal upper limit in CountingSort constructor.");
	lower_limit_ = lower_limit;
	upper_limit_ = upper_limit;
	element_counter_ = std::vector<int64_t>((upper_limit - lower_limit + 1), 0);
}

void CountingSort::sort(std::vector<int64_t> &array)
{
	result_ = std::vector<int64_t>(array.size(), 0);
	for (const auto &element: array) {
		element_counter_[element - lower_limit_] = element_counter_[element - lower_limit_] + 1;
	}
	// compute
	for (size_t index = 1; index < element_counter_.size(); ++index) {
		element_counter_[index] += element_counter_[index - 1];
	}

	for (size_t index = result_.size(); index--;) {
		auto i = element_counter_[array[index] - lower_limit_] - 1;
		result_[i] = array[index];
		element_counter_[array[index] - lower_limit_] -= 1;
	}
	array = result_;
}

void CountingSort::sort(std::shared_ptr<std::vector<int64_t>> &array)
{
	sort((*array));
}
