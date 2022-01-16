//
// Created by andreas on 12.01.22.
//

#include "selection_sort.h"
void SelectionSort::sort(std::vector<int64_t> &array)
{
	auto size = array.size();
	for(size_t index =0; index < size; ++index)
	{
		auto minimum_index = index;
		for(size_t index2 = index+1; index2< size; ++index2)
		{
			if(array[index2] < array[minimum_index]){
				minimum_index = index2;
			}
		}
		swap(array, index, minimum_index);
	}
}
void SelectionSort::sort(std::shared_ptr<std::vector<int64_t>> &array)
{
	sort((*array));
}
