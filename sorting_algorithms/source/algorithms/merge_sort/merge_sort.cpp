//
// Created by andreas on 14.01.22.
//

#include "merge_sort.h"
void MergeSort::sort(std::vector<int64_t> &array)
{

	help_ = std::vector<int64_t>(array.size(), 0);
	size_t start = 0;
	size_t end = array.size() - 1;
	if (non_recursive_version_is_enabled_)
		sort_non_recursive_(array);
	else
		sort_recursive_(array, start, end);
}

void MergeSort::sort_recursive_(std::vector<int64_t> &array, size_t start, size_t end)
{
	if (end <= start) {
		return;
	}
	size_t middle = start + (end - start) / 2;
	sort_recursive_(array, start, middle);
	sort_recursive_(array, middle + 1, end);
	merge_(array, start, middle, end);
}

void MergeSort::sort_non_recursive_(std::vector<int64_t> &array)
{
	size_t size = array.size();
	for (size_t index = 1; index < size; index *= 2)
		for (size_t index2 = 0; index2 < size - index; index2 += 2 * index)
			merge_(array, index2, index2 + index - 1, std::min(index2 + index + index - 1, size - 1));
}

void MergeSort::enable_non_recursive_version(bool enable = true)
{
	non_recursive_version_is_enabled_ = enable;
}

void MergeSort::merge_(std::vector<int64_t> &array, size_t start, size_t middle, size_t end)
{
	help_ = array;

	size_t first_half_index = start;
	size_t second_half_index = middle + 1;
	for (size_t index = start; index <= end; ++index) {
		if (first_half_index > middle)
			array[index] = help_[second_half_index++];
		else if (second_half_index > end)
			array[index] = help_[first_half_index++];
		else if (help_[second_half_index] < help_[first_half_index])
			array[index] = help_[second_half_index++];
		else
			array[index] = help_[first_half_index++];
	}

}
void MergeSort::sort(std::shared_ptr<std::vector<int64_t>> &array)
{
	sort((*array));
}
