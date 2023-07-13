// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.

#include <iostream>
#include <vector>

bool can_reach_last_index(const std::vector<int> &jump_distances)
{
	int back = jump_distances.size() - 1;
	if (back == 0)
		return true;
	if (jump_distances[0] == back)
		return true;
	if (jump_distances[0] == 0)
		return false;
	int current_position = back;
	for (int i{current_position - 1}; i > -1; --i) {
		if (i + jump_distances[i] >= current_position)
			current_position = i;
	}
	return current_position == 0;
}


