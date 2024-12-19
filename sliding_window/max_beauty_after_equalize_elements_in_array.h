//
// Created by andreas on 19.12.24.
//

#ifndef EQUALIZE_ELEMENTS_IN_ARRAY_H
#define EQUALIZE_ELEMENTS_IN_ARRAY_H
// LC: 2779
// You are given a 0-indexed array input and a non-negative integer k.
// In one operation, you can do the following:
//    Choose an index i that hasn't been chosen before from the range [0, input.length - 1].
//    Replace input[i] with any integer from the range [input[i] - k, input[i] + k].
// The beauty of the array is the length of the longest subsequence consisting of equal elements.
// Return the maximum possible beauty of the array input after applying the operation any number of times.
// Note that you can apply the operation to each index only once.
// A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none)
// without changing the order of the remaining elements.
#include <vector>
#include <algorithm>

int max_beauty(std::vector<int>& input, int k) {
    std::sort(input.begin(), input.end());
    int max_size{};
    int n = input.size();
    int right{};
    for(int left{}; left < n; ++left)
    {
        while(right < n && input[right]-input[left] <= 2*k)
        {
            right++;
        }
        max_size =std::max(max_size, right-left);
    }
    return max_size;
}

#endif //EQUALIZE_ELEMENTS_IN_ARRAY_H
