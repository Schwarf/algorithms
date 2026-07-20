//
// Created by andreas on 20.07.26.
//

#ifndef ALGORITHMS_SEARCH_FOR_RANGE_H
#define ALGORITHMS_SEARCH_FOR_RANGE_H
// You are given a sorted array of integers and a target integer.
// Return a two-element array containing:
// [first position of target, last position of target]
// When the target does not occur in the array, return:
// [-1, -1]
#include <vector>
std::vector<int> search_for_range(const std::vector<int>& input, int target)
{
    int n = input.size();
    if (n == 0)
        return {-1, -1};
    int first = -1;
    int last = -1;
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (input[mid] == target && ( mid == 0 || input[mid - 1] != target))
        {
            first = mid;
            break;
        }
        else if (input[mid] >= target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    left = 0;
    right = n-1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (input[mid] == target && (mid == n-1 || input[mid + 1] != target))
        {
            last = mid;
            break;
        }
        else if (input[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return {first, last};
}
#endif // ALGORITHMS_SEARCH_FOR_RANGE_H
