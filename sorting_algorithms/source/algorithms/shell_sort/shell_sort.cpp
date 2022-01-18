//
// Created by andreas on 15.01.22.
//

#include "shell_sort.h"

size_t ShellSort::sedgewick_sequence_[20] =
	{1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001, 36289, 64769, 146305, 260609, 587521, 1045505,
	 2354689, 4188161};

size_t ShellSort::tokuda_sequence_[20] =
	{1, 4, 9, 20, 46, 103, 233, 525, 1182, 2660, 5985, 13467, 30301, 68178, 153401, 345152, 776591, 1747331,
	 3931496, 8845866};

size_t ShellSort::ciura_sequence_[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};

size_t ShellSort::fuchs_sequence_[20] = {};
ShellSort::ShellSort()
{
	fuchs_sequence_[0] = 1;
	fuchs_sequence_[1] = 4;
	for(size_t index =2; index < 20; ++index)
	{
		fuchs_sequence_[index] = 3*fuchs_sequence_[index-1] + fuchs_sequence_[index-2];
	};
}

void ShellSort::sort(std::vector<int64_t> &array)
{

	if (variant_ == ShellSortVariant::classic)
		sort_3_N_plus_1_(array);
	if (variant_ == ShellSortVariant::sedgewick) {
		auto sequence = sedgewick_sequence_;
		size_t last_sequence_element = 19;
		hard_coded_sequence_sort(array, sequence, last_sequence_element);
	}
	if (variant_ == ShellSortVariant::tokuda) {
		auto sequence = tokuda_sequence_;
		size_t last_sequence_element = 19;
		hard_coded_sequence_sort(array, sequence, last_sequence_element);
	}
	if (variant_ == ShellSortVariant::ciura) {
		auto sequence = ciura_sequence_;
		size_t last_sequence_element = 8;
		hard_coded_sequence_sort(array, sequence, last_sequence_element);
	}
	if (variant_ == ShellSortVariant::fuchs) {
		auto sequence = fuchs_sequence_;
		size_t last_sequence_element = 19;
		hard_coded_sequence_sort(array, sequence, last_sequence_element);
	}

}

void ShellSort::hard_coded_sequence_sort(std::vector<int64_t> &array, size_t sequence[], size_t last_sequence_element)
{
	size_t size = array.size();

	for(size_t sequence_index = last_sequence_element; sequence_index--;)
	{

		size_t distance = sequence[sequence_index];
		for(size_t index = distance; index < size; ++index)
		{
			int64_t help = array[index];
			size_t index2 = index;
			while((index2 >= distance) && (array[index2-distance] > help))
			{
				array[index2] = array[index2 - distance];
				index2 -= distance;
			}
			array[index2] = help;
		}
	}
}



void ShellSort::sort_3_N_plus_1_(std::vector<int64_t> &array)
{
	size_t size = array.size();
	size_t distance = 1;
	while (distance < size / 3) {
		distance = 3 * distance + 1;
	}
	while (distance > 0) {
		for (size_t index = distance; index < size; ++index) {
			for (size_t index2 = index; index2 >= distance && (array[index2] < array[index2 - distance]);
				 index2 -= distance) {
				swap(array, index2, index2 - distance);
			}

		}
		distance /= 3;
	}

}

void ShellSort::set_variant(ShellSortVariant variant)
{
	variant_ = variant;
}
void ShellSort::sort(std::shared_ptr<std::vector<int64_t>> & array)
{
	sort((*array));
}
