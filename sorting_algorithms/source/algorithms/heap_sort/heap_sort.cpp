//
// Created by andreas on 12.02.22.
//

#include "heap_sort.h"
void HeapSort::sort(std::vector<int64_t> &array)
{
	for (size_t index = 0; index < array.size(); index++) {
		insert_(index, array);
	}

}
void HeapSort::sort(std::shared_ptr<std::vector<int64_t>> &array)
{
	sort((*array));
}
void HeapSort::insert_(size_t element, std::vector<int64_t> &array)
{
	if (heap_size_ == 0) {
		heap_size_ = 1;
		return;
	}
	heap_size_++;
	auto index = heap_size_ - 1;
	promote_(index, array);
}
void HeapSort::promote_(size_t index, std::vector<int64_t> &array)
{
	while (index != 0 && array[(index - 1) / 2] < array[index]) {
		swap(array, index, (index - 1) / 2);
		index = (index - 1)/2;
	}
}
