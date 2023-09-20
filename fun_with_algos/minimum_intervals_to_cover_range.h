//
// Created by andreas on 31.08.23.
//

#ifndef MINIMUM_INTERVALS_TO_COVER_RANGE_H
#define MINIMUM_INTERVALS_TO_COVER_RANGE_H
#include <concepts>
#include <vector>
// There is a one-dimensional area A on the x-axis. The range starts at the point 0 and ends at the point n.
// There are n + 1 points [0, 1, ..., n] in the area A.
// Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed)
// means the i-th tap can cover the area [i - ranges[i], i + ranges[i]].
// Return the minimum number of ranges that should be used to cover the whole area A.
// Note the intervals also need to cover the area between the points [0, 1, ..., n].  If this is not possible return -1.

// #GREEDY
template<typename T>
requires std::signed_integral<T>
int minimum_intervals_to_cover_range(int area_size, const std::vector<T> & ranges)
{
	std::vector<std::pair<T, T>> intervals;
	for (int i{}; i <= area_size; ++i)
		intervals.push_back({i - ranges.at(i), i + ranges.at(i)});
	std::sort(intervals.begin(), intervals.end());

	int number_of_intervals_needed{};
	int index{};
	int currently_covered{};
	while (currently_covered < area_size) {
		int farthest = currently_covered;
		while (index <= area_size && intervals[index].first <= currently_covered) {
			farthest = std::max(farthest, intervals[index].second);
			index++;
		}
		if (farthest == currently_covered)
			return -1;
		number_of_intervals_needed++;
		currently_covered = farthest;
	}
	return number_of_intervals_needed;
}

#endif //MINIMUM_INTERVALS_TO_COVER_RANGE_H
