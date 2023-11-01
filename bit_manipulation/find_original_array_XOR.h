//
// Created by andreas on 01.11.23.
//

#ifndef FIND_ORIGINAL_ARRAY_XOR_H
#define FIND_ORIGINAL_ARRAY_XOR_H
#include <vector>
// Given an integer array pref of size n. Find and return the array arr of size n that satisfies:
// pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
// Input: pref = [5,2,0,3,1]
// Output: [5,7,2,3,2]

// Searching arr given perf with above relations.
// We realize that:
// pref[i] = arr[i] ^ pref[i-1]
// apply ^perf[i-1] on both sides:
// perf[i] ^ perf[i-1] = arr[i]
template <typename T>
requires std::is_integral_v<T>
std::vector<T> find_original_array(const std::vector<T> & perf)
{
	int n = perf.size();
	std::vector<T> arr(n);
	arr[0] = perf[0];
	for(int i{1}; i < n; ++i)
	{
		arr[i] = perf[i] ^ perf[i-1];
	}
	return arr;
}
#endif //FIND_ORIGINAL_ARRAY_XOR_H
