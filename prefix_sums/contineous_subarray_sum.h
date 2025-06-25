//
// Created by andreas on 25.06.25.
//

#ifndef CONTINEOUS_SUBARRAY_SUM_H
#define CONTINEOUS_SUBARRAY_SUM_H
// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
//
// A good subarray is a subarray where:
//
//    its length is at least two, and
//    the sum of the elements of the subarray is a multiple of k.
//
// Note that:
//
//    A subarray is a contiguous part of the array.
//    An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

#include <utility>
#include <unordered_map>
#include <vector>

bool has_valid_subarray_sum(const std::vector<int>& nums, int k) {
    int n = nums.size();
    // Special‐case: if k==0, only subarrays summing exactly to 0
    // count—but per the examples we still exclude zero‐sum subarrays,
    // so there's nothing to find.
    if (k == 0)
      return false;

    // Map from residue -> pair{ earliest index, prefixSum at that index }
    std::unordered_map<int, std::pair<int,long long>> seen;
    // We treat prefix sum 0 at index -1
    seen[0] = std::make_pair(-1, 0LL);

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        // normalize mod in [0..|k|-1]
        int residue = ((sum % k) + k) % k;

        auto it = seen.find(residue);
        if (it != seen.end()) {
            int prevIdx = it->second.first;
            long long prevSum = it->second.second;
            // check length >= 2 and actual subarray sum != 0
            if (i - prevIdx >= 2 && (sum - prevSum) != 0) {
                return true;
            }
        } else {
            // first time we see this residue
            seen[residue] = std::make_pair(i, sum);
        }
    }
    return false;
}

#endif //CONTINEOUS_SUBARRAY_SUM_H
