//
// Created by andreas on 26.11.22.
//

#ifndef SUM_SUBARRAY_MINIMUMS_H
#define SUM_SUBARRAY_MINIMUMS_H
#include <vector>
#include <stack>
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
// Since the answer may be large, return the answer modulo 109 + 7.
// https://leetcode.com/problems/sum-of-subarray-minimums/solution/
int sum_of_subarray_minimums(std::vector<int> &arr)
{
	constexpr int kMod = 1e9 + 7;
	const int n = arr.size();
	long ans = 0;
	std::vector<int> prev(n, -1);
	std::vector<int> next(n, n);
	std::stack<int> monotonic_stack;

	for (int i = 0; i < n; ++i) {
		while (!monotonic_stack.empty() && arr[monotonic_stack.top()] > arr[i]) {
			const int index = monotonic_stack.top();
			monotonic_stack.pop();
			next[index] = i;
		}
		if (!monotonic_stack.empty())
			prev[i] = monotonic_stack.top();
		monotonic_stack.push(i);
	}

	for (int i = 0; i < n; ++i) {
		ans += static_cast<long>(arr[i]) * (i - prev[i]) * (next[i] - i);
		ans %= kMod;
	}

	return ans;
}


#endif //SUM_SUBARRAY_MINIMUMS_H
