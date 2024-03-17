//
// Created by andreas on 17.03.24.
//

#ifndef INSERT_INTERVAL_H
#define INSERT_INTERVAL_H
// You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i]
// represent the start and the end of the ith interval and intervals is sorted in ascending order by start_i.
// You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i and
// intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
#include <vector>
#include <concepts>
template <typename T>
requires std::three_way_comparable<T>
std::vector<std::vector<T>> insert_new_interval(std::vector<std::vector<T>>& intervals, std::vector<T>& new_interval) {
	int n = intervals.size();
	int index{};
	std::vector<std::vector<T>> result;

	// Compare ending point of intervals to starting point of new_interval and
	// add until new_interval start is lower than endpoint of exiting interval
	while (index < n && intervals[index][1] < new_interval[0]) {
		result.push_back(intervals[index]);
		index++;
	}

	// Merging overlapping intervals
	while (index < n && new_interval[1] >= intervals[index][0]) {
		new_interval[0] = min(new_interval[0], intervals[index][0]);
		new_interval[1] = max(new_interval[1], intervals[index][1]);
		index++;
	}
	result.push_back(new_interval);

	// Add remaining intervals
	while (index < n) {
		result.push_back(intervals[index]);
		index++;
	}
	return result;
}


#endif //INSERT_INTERVAL_H
