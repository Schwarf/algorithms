//
// Created by andreas on 14.01.22.
//

#include "merge_sort.h"
void MergeSort::sort(std::vector<int64_t> &array)
{

	std::vector<int64_t> help(array.size(), 0);
	size_t start = 0;
	size_t end = array.size() - 1;
	if(non_recursive_version_is_enabled_)
		sort_non_recursive_(array);
	else
		sort_recursive_(array, help, start, end);
}

void MergeSort::sort_recursive_(std::vector<int64_t> &array, std::vector<int64_t> &help, size_t start, size_t end)
{
	if(end <= start)
	{
		return;
	}
	size_t middle = start + (end-start)/2;
	sort_recursive_(array, help, start, middle);
	sort_recursive_(array, help, middle+1, end);
	merge_(array, help, start, middle, end);
}

void MergeSort::sort_non_recursive_(std::vector<int64_t> &array)
{

}
void MergeSort::enable_non_recursive_version(bool enable = true)
{
	non_recursive_version_is_enabled_ = enable;
}


void MergeSort::merge_(std::vector<int64_t> &array, std::vector<int64_t> &help, size_t start, size_t middle, size_t end){
	for(size_t index =start; index <= end; ++index )
	{
		help[index] = array[index];
	}

	size_t first_half_index = start;
	size_t second_half_index = middle + 1;
	for(size_t index = start; index <= end; ++index)
	{
		if(first_half_index > middle)
		{
			array[index] = help[second_half_index++];
		}
		else if(second_half_index > end)
		{
			array[index] = help[first_half_index++];
		}
		else if( help[second_half_index] < help[first_half_index])
		{
			array[index] = help[second_half_index++];
		}
		else
		{
			array[index] = help[first_half_index++];
		}
	}

}
