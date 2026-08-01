//
// Created by andreas on 01.08.26.
//

#ifndef ALGORITHMS_LONGEST_SUBARRAY_WITH_ABSOLUTE_DIFF_LIMIT_H
#define ALGORITHMS_LONGEST_SUBARRAY_WITH_ABSOLUTE_DIFF_LIMIT_H
// Given an array of integers "input",
// return the length of the longest contiguous subarray such that the
// absolute difference between any two elements in the subarray is less than or equal to limit.
// If no such subarray exists, return 0.

#include <deque>
#include <vector>

int longest_subarray_with_absolute_diff_limit(const std::vector<int>& input, int limit)
{
    const int n = input.size();

    if (n == 0)
        return 0;
    int left = 0;

    std::deque<int> max_deque(input[0]);
    std::deque<int> min_deque(input[0]);

    int max_length = 1;

    for (int right = 1; right < n; ++right)
    {
        while (!min_deque.empty() && input[right] < min_deque.back())
            min_deque.pop_back();
        while (!max_deque.empty() && input[right] > max_deque.back())
            max_deque.pop_back();

        min_deque.push_back(input[right]);
        max_deque.push_back(input[right]);

        while (max_deque.front() - min_deque.front() > limit)
        {
            if (min_deque.front() == input[left])
                min_deque.pop_front();
            if (max_deque.front() == input[left])
                max_deque.pop_front();
            ++left;
        }
        max_length = std::max(max_length, right - left + 1);
    }
    return max_length;
}


#endif // ALGORITHMS_LONGEST_SUBARRAY_WITH_ABSOLUTE_DIFF_LIMIT_H
