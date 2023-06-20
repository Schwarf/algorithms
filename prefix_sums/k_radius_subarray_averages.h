//
// Created by andreas on 20.06.23.
//

#ifndef K_RADIUS_SUBARRAY_AVERAGES_H
#define K_RADIUS_SUBARRAY_AVERAGES_H
#include <vector>
// You are given a 0-indexed array nums of n numbers, and an integer k.

// The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all
// elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or
// after the index i, then the k-radius average is -1.
// Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

template <typename T>
std::vector<double> get_averages_prefix_sum(std::vector<T> & nums, int k)
{
	int n = nums.size();
	if( k == 0)
		return nums;
	std::vector<double> prefix_sum(n+1, 0.0);
	prefix_sum[0] = nums[0];
	std::vector<double> result(n, -1.0);
	for(int i{}; i < n; ++i)
		prefix_sum[i+1] = prefix_sum[i] + nums[i];
	const double div{2.0*k + 1.0};
	for(int i{k}; i < n-k; ++i)
		result[i] = (prefix_sum[i+k+1] - prefix_sum[i-k])/div;
	return result;
};


template <typename T>
std::vector<double> get_averages_sliding_window(std::vector<T> & nums, int k)
{
	int n = nums.size();
	if( k == 0)
		return nums;
	std::vector<double> result(n, -1.0);
	if(2*k+1 > n)
		return result;
	double sum{};
	const double div{2.0*k + 1.0};
	for(int i{}; i < 2*k+1; ++i)
		sum += nums[i];
	result[k] = sum/div;
	for(int i{2*k+1} ; i < n; ++i)
	{
		sum += -nums[i-2*k-1] + nums[i];
		result[i-k] = sum/div;
	}
	return result;

};



#endif //K_RADIUS_SUBARRAY_AVERAGES_H
