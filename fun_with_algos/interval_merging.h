//
// Created by andreas on 04.12.22.
//
#include <algorithm>
#include <vector>

#ifndef INTERVAL_MERGING_H
#define INTERVAL_MERGING_H
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

template <typename T>
std::vector<std::vector<T>> merge_intervals(std::vector<std::vector<T>>& intervals)
{
    if (intervals.empty())
        return {};
    auto sorted = [](const std::vector<T>& input1, const std::vector<T>& input2) { return input1[0] < input2[0]; };
    std::sort(intervals.begin(), intervals.end(), sorted);
    std::vector<std::vector<T>> result;
    result.push_back(intervals[0]);
    for (int i{1}; i < intervals.size(); ++i)
    {
        if (result.back()[1] < intervals[i][0])
            result.push_back(intervals[i]);
        else
            result.back()[1] = std::max(intervals[i][1], result.back()[1]);
    }
    return result;
}

template <typename T>
std::vector<std::vector<T>> merge_intervals_optimized(std::vector<std::vector<T>> & intervals) {
    if (intervals.empty())
        return intervals;
    std::sort(intervals.begin(),intervals.end());
    int write = 0;
    for (int read = 1; read < intervals.size(); ++read) {
        if (intervals[read][0] <= intervals[write][1]) {
            intervals[write][1] = std::max(intervals[write][1], intervals[read][1]);
        }
        else {
            ++write;
            intervals[write] = intervals[read];
        }
    }
    intervals.resize(write+1);
    return intervals;
}
#endif // INTERVAL_MERGING_H
