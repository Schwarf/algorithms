//
// Created by andreas on 22.01.22.
//

#ifndef KTH_ELEMENT_OF_TWO_SORTED_ARRAYS_H
#define KTH_ELEMENT_OF_TWO_SORTED_ARRAYS_H
#include <cstddef>
#include <algorithm>

class KthElementOfTwoSortedArrays
{
public:
	int merging(const int * array1, const int * array2, size_t size1, size_t size2, size_t k); // O(m+n) time complexity, O(m+n) space complexity
	int merging_with_no_extra_space(const int * array1, const int * array2, size_t size1, size_t size2, size_t k); // O(m+n) time complexity
	int divide_and_conquer(const int * array1, const int * array2, size_t size1, size_t size2, size_t k);
};


#endif //KTH_ELEMENT_OF_TWO_SORTED_ARRAYS_H
