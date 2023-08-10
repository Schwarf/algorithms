//
// Created by andreas on 10.08.23.
//

#ifndef FIND_ELEMENT_INDEX_IN_ROTATED_ARRAY_H
#define FIND_ELEMENT_INDEX_IN_ROTATED_ARRAY_H
#include <concepts>
#include <vector>

template<typename T>
requires std::is_arithmetic_v<T>
int find_index_with_binary_search(const std::vector<T> &input, int left_boundary, int right_boundary, T target)
{
	int left{left_boundary};
	int right{right_boundary};
	while (left <= right) {
		int mid = (left + right) / 2;
		if (input[mid] == target)
			return mid;
		else if (input[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}


template<typename T>
requires std::is_arithmetic_v<T>
int find_element_index_in_rotated_array(const std::vector<T> & input, T target)
{
	int n = input.size();
	int left{};
	int right = n -1;
	while(left <= right)
	{
		int mid =(left +right)/2;
		if(input[mid] > input[n-1])
			left = mid +1;
		else
			right = mid -1;
	}
	int result = find_index_with_binary_search(input, 0, left-1, target);
	if(result != -1)
		return result;
	return find_index_with_binary_search(input, left, n-1, target);
}

#endif //FIND_ELEMENT_INDEX_IN_ROTATED_ARRAY_H
