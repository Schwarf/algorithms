//
// Created by andreas on 15.01.22.
//

#include "shell_sort.h"

void ShellSort::sort(std::vector<int64_t> &array)
{
	sort_3_N_plus_1_(array);
}
void ShellSort::sort_ciura_sequence_(std::vector<int64_t> &array)
{}

void ShellSort::sort_tokuda_sequence_(std::vector<int64_t> &array)
{}

void ShellSort::sort_sedgewick_sequence_(std::vector<int64_t> &array)
{

}
void ShellSort::sort_3_N_plus_1_(std::vector<int64_t> &array)
{
	size_t size = array.size();
	size_t distance = 1;
	while(distance < size/3)
	{
		distance = 3*distance + 1;
	}
	while(distance > 0)
	{
		for(size_t index = distance; index < size; ++index)
		{
			for (size_t index2 = index; index >= distance && (array[index2] < array[index - distance]); index2 -= distance)
			{
				swap(array, index2, index2-distance);
			}

		}
		distance /=3;
	}

}
