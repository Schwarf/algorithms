//
// Created by andreas on 22.01.22.
//

#include "quick_select.h"
int64_t QuickSelect::select(std::vector<int64_t> &array, size_t kth_element)
{
	if(kth_element > array.size())
	{
		const std::string message = "In QuickSelect the kth_element is greater than the array-size";
		throw std::out_of_range(message);
	}
	size_t start = 0;
	size_t end = array.size() - 1;
	while(end > start)
	{
		size_t index = partition_(array, start, end);
		if( index < kth_element) start = ++index;
		else if(index > kth_element) end = --index;
		else return array[kth_element];
	}
	return array[kth_element];
}

size_t QuickSelect::partition_(std::vector<int64_t> &array, size_t start, size_t end)
{
	auto index = start;
	size_t index2 = end + 1;
	int64_t help;
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
		help = array[index];
		array[index] = array[index2];
		array[index2] = help;
	}
	help = array[start];
	array[start] = array[index2];
	array[index2] = help;

	return index2;
}
