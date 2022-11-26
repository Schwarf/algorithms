//
// Created by andreas on 26.11.22.
//

#ifndef TRAPPING_RAIN_WATER_H
#define TRAPPING_RAIN_WATER_H
#include<vector>
#include<stack>

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// dynamic-programming approach
int rainwater_dp(const std::vector<int> &landscape)
{
	constexpr int init = 0;
	if (landscape.empty())
		return init;
	int result{};
	int size = landscape.size();
	std::vector<int> left_max, right_max;
	for (int i = 1; i < size; ++i)
		left_max[i] = std::max(landscape[i], left_max[i - 1]);
	for (int i = size - 2; i > -1; --i)
		right_max[i] = std::max(landscape[i], right_max[i + 1]);
	for (int i = 1; i <= size - 1; ++i)
		result += std::min(left_max[i], right_max[i]) - landscape[i];
	return result;
}

int rainwater_stack(const std::vector<int> &landscape)
{
	if (landscape.empty())
		return 0;
	int result{};
	int current_index{};
	int size = landscape.size();
	std::stack<int> decreasing_heights_index;
	while (current_index < size) {
		while (!decreasing_heights_index.empty()
			&& landscape[current_index] > landscape[decreasing_heights_index.top()]) {
			int top_index = decreasing_heights_index.top();
			decreasing_heights_index.pop();
			if (decreasing_heights_index.empty())
				break;
			int distance = current_index - decreasing_heights_index.top() - 1;
			int bounded_height =
				std::min(landscape[current_index], landscape[decreasing_heights_index.top()]) - landscape[top_index];
			result += distance * bounded_height;
		}
		decreasing_heights_index.push(current_index++);
	}
	return result;
}

// stack approach



#endif //TRAPPING_RAIN_WATER_H
