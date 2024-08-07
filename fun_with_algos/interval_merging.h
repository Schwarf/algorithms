//
// Created by andreas on 04.12.22.
//
#include <vector>
#include <algorithm>

#ifndef INTERVAL_MERGING_H
#define INTERVAL_MERGING_H
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
//and return an array of the non-overlapping intervals that cover all the intervals in the input.

template<typename T>
std::vector<std::vector<T>> merge_intervals(std::vector<std::vector<T>> &intervals) {
    if (intervals.empty())
        return {};
    auto sorted = [](const std::vector<T> &input1, const std::vector<T> &input2) {
        return input1[0] < input2[0];
    };
    std::sort(intervals.begin(), intervals.end(), sorted);
    std::vector<std::vector<T>> result;
    result.push_back(intervals[0]);
    for (int i{1}; i < intervals.size(); ++i) {
        if (result.back()[1] < intervals[i][0])
            result.push_back(intervals[i]);
        else
            result.back()[1] = std::max(intervals[i][1], result.back()[1]);
    }
    return result;


}

#endif //INTERVAL_MERGING_H
