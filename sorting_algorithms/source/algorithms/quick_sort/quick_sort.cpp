//
// Created by andreas on 17.01.22.
//

#include "quick_sort.h"
void QuickSort::sort(std::vector<int64_t> &array)
{
	int start = 0;
	int end = int(array.size()-1);
	quick_sort_(array, start, end);

}

void QuickSort::sort(std::shared_ptr<std::vector<int64_t>> &array)
{
	sort((*array));
}

void QuickSort::quick_sort_(std::vector<int64_t> &array, int start, int end)
{
	if(end <= start)
		return;
	int index = partition_(array, start, end);
	quick_sort_(array, start, index-1);
	quick_sort_(array, index+1, end);
}

int QuickSort::partition_(std::vector<int64_t> &array, int start, int end)
{
	auto index = start;
	int index2 = end + 1;
	while(true)
	{
		while(array[++index] < array[start])
		{
			if(index == end)
				break;
		}
		while(array[start] < array.at(--index2))
		{
			if(index2 == start)
				break;
		}
		if(index >= index2) {
			break;
		}
		swap(array, index, index2);
	}
	swap(array, start, index2);
	return index2;
}
