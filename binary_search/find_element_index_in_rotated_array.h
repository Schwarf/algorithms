//
// Created by andreas on 10.08.23.
//

#ifndef FIND_ELEMENT_INDEX_IN_ROTATED_ARRAY_H
#define FIND_ELEMENT_INDEX_IN_ROTATED_ARRAY_H
#include <concepts>
#include <vector>
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k(1 <= k < nums.length)
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.
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

template<typename T>
requires std::is_arithmetic_v<T>
int find_element_index_in_rotated_array_optimized(const std::vector<T> &input, T target)
{
	int n = input.size();
	int left{};
	int right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		// Case 1: find target
		if (input[mid] == target) {
			return mid;
		}

			// Case 2: subarray on mid's left is sorted
		else if (input[mid] >= input[left]) {
			if (target >= input[left] && target < input[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

			// Case 3: subarray on mid's right is sorted
		else {
			if (target <= input[right] && target > input[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}

	return -1;
}

#endif //FIND_ELEMENT_INDEX_IN_ROTATED_ARRAY_H
