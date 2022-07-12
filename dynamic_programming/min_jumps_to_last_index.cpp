// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.

#include <iostream>
#include <vector>

int min_jumps_to_last_index(std::vector<int> &max_jump_lengths)
{
	int current_reach = 0;
	int current_max = 0;
	int jumps = 0;
	for(int i = 0;i<max_jump_lengths.size()-1;i++){
		// update the maximum to reach from the current index
		if(i+max_jump_lengths[i] > current_max){
			current_max = i +max_jump_lengths[i];
		}
		// when the index reaches the current-reach we update the current-reach to the seen maximum
		if(i==current_reach){
			jumps++;
			current_reach = current_max;
		}
	}
	return jumps;
}


int main()
{
	auto test1 = std::pair<std::vector<int>, int>{std::vector<int>{2,3,1,1,4}, 2};
	auto test2 = std::pair<std::vector<int>, int>{std::vector<int>{1,2,3,4,5,6,7,8,9,10}, 4};
	auto test3 =
	std::pair<std::vector<int>, int>{std::vector<int>{1,3,5,3,3,3,6,1,1,1,1,1,1}, 4};
	std::cout << min_jumps_to_last_index(test1.first) << ", " << test1.second << std::endl;
	std::cout << min_jumps_to_last_index(test2.first) << ", " << test2.second << std::endl;
	std::cout << min_jumps_to_last_index(test3.first) << ", " << test3.second << std::endl;

}