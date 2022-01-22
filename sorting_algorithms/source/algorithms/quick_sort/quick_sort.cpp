//
// Created by andreas on 17.01.22.
//

#include "quick_sort.h"
void QuickSort::sort(std::vector<int64_t> &array)
{
	int start = 0;
	int end = int(array.size() - 1);
	if (use_classic_variant_)
		quick_sort_(array, start, end);
	else
		modern_quick_sort_(array, start, end);

}

void QuickSort::sort(std::shared_ptr<std::vector<int64_t>> &array)
{
	sort((*array));
}

void QuickSort::quick_sort_(std::vector<int64_t> &array, int start, int end)
{
	if (end <= start)
		return;
	int index = classic_partition_(array, start, end);
	quick_sort_(array, start, index - 1);
	quick_sort_(array, index + 1, end);
}

int QuickSort::classic_partition_(std::vector<int64_t> &array, int start, int end)
{
	auto index = start;
	int index2 = end + 1;
	while (true) {
		while (array[++index] < array[start]) {
			if (index == end)
				break;
		}
		while (array[start] < array.at(--index2)) {
			if (index2 == start)
				break;
		}
		if (index >= index2) {
			break;
		}
		swap(array, index, index2);
	}
	swap(array, start, index2);
	return index2;
}
void QuickSort::set_classic_variant(bool use_classic_variant)
{
	use_classic_variant_ = use_classic_variant;
}
void QuickSort::modern_quick_sort_(std::vector<int64_t> &array, int start, int end)
{
	if (end <= start)
		return;
	int less_than = start;
	int greater_than = end;
	auto pivot_element = array[start];
	int index = start;
	while (index <= greater_than) {
		if (array[index] < pivot_element)
			swap(array, less_than++, index++);
		else if (array[index] > pivot_element)
			swap(array, index, greater_than--);
		else
			index++;
	}
	modern_quick_sort_(array, start, less_than-1);
	modern_quick_sort_(array, greater_than+1, end);
}
