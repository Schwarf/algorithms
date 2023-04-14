//
// Created by andreas on 20.09.22.
//

#ifndef MAXIMUM_LENGTH_OF_SAME_SUBARRAY_IN_TWO_ARRAYS_H
#define MAXIMUM_LENGTH_OF_SAME_SUBARRAY_IN_TWO_ARRAYS_H
#include <vector>
// Given two std::vectors we want to find out the maximum length of the subarrays that appear in both arrays
template<typename T>
int maximum_length(std::vector<T> &array1, std::vector<T> &array2)
{
	int n1 = array1.size();
	int n2 = array2.size();
	auto help = std::vector<std::vector<int>>(n1, std::vector<int>(n2, 0));
	int result{};
	for (int i1{}; i1 < n1; ++i1) {
		for (int i2{}; i2 < n2; ++i2) {
			if (array1[i1] == array2[i2]) {
				if (i1 == 0 || i2 == 0)
					help[i1][i2] = 1;
				else
					help[i1][i2] = 1 + help[i1 - 1][i2 - 1];
				result = std::max(result, help[i1][i2]);
			}
		}
	}
	return result;
}


#endif //MAXIMUM_LENGTH_OF_SAME_SUBARRAY_IN_TWO_ARRAYS_H
