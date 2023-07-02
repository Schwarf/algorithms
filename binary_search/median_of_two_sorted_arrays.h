//
// Created by andreas on 02.07.23.
//

#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS_H
#define MEDIAN_OF_TWO_SORTED_ARRAYS_H
#include <concepts>
#include <vector>


template<typename T>
int find_median(const std::vector<T> &input1,
				const std::vector<T> &input2,
				int median_index,
				int left1,
				int right1,
				int left2,
				int right2)
{
	// If the segment of on array is empty, it means we have passed all
	// its element, just return the corresponding element in the other array.
	if (right1 < left1)
		return input2[median_index - left1];
	if (right2 < left2)
		return input1[median_index - left2];

	int mid1 = (left1 + right1) / 2;
	int mid2 = (left2 + right2) / 2;
	// If median_index is in the right half of input1 + input2, remove the smaller left half.
	if (mid1 + mid2 < median_index) {
		// if true input2[left2:mid2] is the smaller half
		if (input1[mid1] > input2[mid2])
			return find_median(input1, input2, median_index, left1, right1, mid2 + 1, right2);
		else
			return find_median(input1, input2, median_index, mid1 + 1, right1, left2, right2);
	}
		// else remove the larger right half.
	else {
		if (input1[mid1] > input2[mid2])
			return find_median(input1, input2, median_index, left1, mid1 - 1, left2, right2);
		else
			return find_median(input1, input2, median_index, left1, right1, left2, mid2 - 1);
	}

}

template<typename T>
requires std::is_arithmetic_v<T>
double median_of_sorted_arrays(const std::vector<T> &input1, const std::vector<T> &input2)
{
	int size1 = input1.size() - 1;
	int size2 = input2.size() - 1;

	int size = size1 + size2 + 2;
	if (size & 1)
		return find_median(input1, input2, size / 2, 0, size1, 0, size2);
	else
		return (find_median(input1, input2, size / 2 - 1, 0, size1, 0, size2)
			+ find_median(input1, input2, size / 2, 0, size1, 0, size2)) / 2.0;
}

#endif //MEDIAN_OF_TWO_SORTED_ARRAYS_H

