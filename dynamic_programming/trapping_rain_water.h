//
// Created by andreas on 26.11.22.
//

#ifndef TRAPPING_RAIN_WATER_H
#define TRAPPING_RAIN_WATER_H
#include<vector>
#include<stack>

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


// dynamic-programming approach
int rainwater_dp(const std::vector<int> & landscape)
{
	if(landscape.empty())
		return 0;
	int result{};
	int size = landscape.size();
	std::vector<int>  left_max, right_max;
	for(int i=1; i < size; ++i)
		left_max[i] = std::max(landscape[i], left_max[i-1]);
	for(int i=size-2; i > -1; --i)
		right_max[i] = std::max(landscape[i], right_max[i+1]);
	for(int i =1; i <=size -1; ++i)
		result += std::min(left_max[i], right_max[i]) - landscape[i];
	return result;
}


#endif //TRAPPING_RAIN_WATER_H
