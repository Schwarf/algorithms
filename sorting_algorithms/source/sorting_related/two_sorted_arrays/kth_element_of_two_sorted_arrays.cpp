//
// Created by andreas on 22.01.22.
//

#include "kth_element_of_two_sorted_arrays.h"

int KthElementOfTwoSortedArrays::merging(const int *array1,
										 const int *array2,
										 const size_t size1,
										 const size_t size2,
										 size_t k)
{
	if (k > size1 + size2)
		return -1;
	if (k == 1)
		return std::min(array1[0], array2[0]);

	int merged[size1 + size2];
	size_t index1 = 0;
	size_t index2 = 0;
	size_t merged_index = 0;
	while ((index1 < size1) && (index2 < size2)) {
		if (array1[index1] < array2[index2])
			merged[merged_index++] = array1[index1++];
		else
			merged[merged_index++] = array2[index2++];
	}
	while (index1 < size1)
		merged[merged_index++] = array1[index1++];
	while (index2 < size2)
		merged[merged_index++] = array2[index2++];

	return merged[k - 1];
}
int KthElementOfTwoSortedArrays::merging_with_no_extra_space(const int *array1,
															 const int *array2,
															 size_t size1,
															 size_t size2,
															 size_t k)
{
	if (k > size1 + size2)
		return -1;
	if (k == 1)
		return std::min(array1[0], array2[0]);
	size_t index1 = 0;
	size_t index2 = 0;
	size_t k_index = 0;
	while ((index1 < size1) && (index2 < size2)) {
		if (array1[index1] < array2[index2]) {
			k_index++;
			if (k_index == k)
				return array1[index1];
			index1++;
		}
		else {
			k_index++;
			if (k_index == k)
				return array2[index2];
			index2++;
		}
	}
	while (index1 < size1) {
		k_index++;
		if (k_index == k)
			return array1[index1];

	}
	while (index2 < size2) {
		k_index++;
		if (k_index == k)
			return array2[index2];
	}
}
int KthElementOfTwoSortedArrays::divide_and_conquer(const int *array1,
													const int *array2,
													size_t size1,
													size_t size2,
													size_t k)
{

}
