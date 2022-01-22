//
// Created by andreas on 14.01.22.
//

#include "insertion_sort.h"
void InsertionSort::sort(std::vector<int64_t> &array)
{
	auto size = array.size();
	for (size_t index1 = 0; index1 < size; ++index1) {
		for (size_t index2 = index1; index2 > 0; --index2) {
			if (array[index2] < array[index2 - 1]) {
				swap(array, index2, index2 - 1);
			}
		}
	}
}
void InsertionSort::sort(std::shared_ptr<std::vector<int64_t>> &array)
{
	sort((*array));
}
