//
// Created by andreas on 17.01.22.
//

#include "bubble_sort.h"
void BubbleSort::sort(std::vector<int64_t> &array)
{
	size_t size = array.size()-1;
	bool have_elements_been_swapped{};
	do {
		have_elements_been_swapped =false;
		for(size_t index =0; index < size ; ++index)
		{
			if(array[index + 1] < array[index]) {
				swap(array, index + 1, index);
				have_elements_been_swapped = true;
			}
		}
	} while (have_elements_been_swapped);
}
void BubbleSort::sort(std::shared_ptr<std::vector<int64_t>> &array)
{
	sort((*array));
}
