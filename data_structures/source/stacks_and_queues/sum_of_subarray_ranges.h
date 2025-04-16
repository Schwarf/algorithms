//
// Created by andreas on 16.04.25.
//

#ifndef SUM_OF_SUBARRAY_RANGES_H
#define SUM_OF_SUBARRAY_RANGES_H
// You are given an integer array nums. The range of a subarray of nums is the difference
// between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.
#include <vector>
long long sum_of_subarray_ranges_brute_force(const std::vector<int> &input)
{
  int n = input.size();
  long long result{};
  for(int left{}; left < n-1; ++left)
  {
    int min = input[left];
    int max = input[left];
    for(int right{left+1}; right < n; ++right)
    {
      max = std::max(max, input[right]);
      min = std::min(min, input[right]);
      result += max - min;
    }
  }
  return result;
}
#endif //SUM_OF_SUBARRAY_RANGES_H
