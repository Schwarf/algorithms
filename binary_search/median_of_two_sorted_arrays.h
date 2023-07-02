//
// Created by andreas on 02.07.23.
//

#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS_H
#define MEDIAN_OF_TWO_SORTED_ARRAYS_H
#include <concepts>
#include <vector>
#include <limits>

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
	return -1;

}

template<typename T>
requires std::is_arithmetic_v<T>
double median_of_sorted_arrays(const std::vector<T> &input1, const std::vector<T> &input2)
{
	int size1 = input1.size() - 1;
	int size2 = input2.size() - 1;

	int size = size1 + size2 + 2;
	if (size == 0)
		return -1.0;
	else if (size & 1)
		return find_median(input1, input2, size / 2, 0, size1, 0, size2);
	else
		return (find_median(input1, input2, size / 2 - 1, 0, size1, 0, size2)
			+ find_median(input1, input2, size / 2, 0, size1, 0, size2)) / 2.0;
}

template<typename T>
requires std::is_arithmetic_v<T>
double median_of_sorted_arrays2(const std::vector<T> &input1, const std::vector<T> &input2)
{
	if (input1.size() > input2.size()) {
		return median_of_sorted_arrays2(input2, input1);
	}

	int m = input1.size(), n = input2.size();
	int left = 0, right = m;

	while (left <= right) {
		int partitionA = (left + right) / 2;
		int partitionB = (m + n + 1) / 2 - partitionA;

		T maxLeftA = (partitionA == 0) ? std::numeric_limits<T>::min() : input1[partitionA - 1];
		T minRightA = (partitionA == m) ? std::numeric_limits<T>::max() : input1[partitionA];
		T maxLeftB = (partitionB == 0) ? std::numeric_limits<T>::min() : input2[partitionB - 1];
		T minRightB = (partitionB == n) ? std::numeric_limits<T>::max() : input2[partitionB];

		if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
			if ((m + n) % 2 == 0) {
				return (std::max(maxLeftA, maxLeftB) + std::min(minRightA, minRightB)) / 2.0;
			}
			else {
				return std::max(maxLeftA, maxLeftB);
			}
		}
		else if (maxLeftA > minRightB) {
			right = partitionA - 1;
		}
		else {
			left = partitionA + 1;
		}
	}

	return 0.0;
}


#endif //MEDIAN_OF_TWO_SORTED_ARRAYS_H


