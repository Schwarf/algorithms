// You are given an integer array cost where cost[i] is the cost of ith step. Once you pay the cost, you can either
// take one or two steps. You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the end of the array.
// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

#include <iostream>
#include <vector>
#include <algorithm>
template<typename T>
int min_cost_to_reach_end(std::vector<T> &cost)
{
	T previous{};
	T before_previous{};
	if (cost.size() == 2)
		return std::min(cost[0], cost[1]);
	for (int i = 2; i <= cost.size(); ++i) {
		auto one_step = previous + cost[i - 1];
		auto two_step = before_previous + cost[i - 2];
		before_previous = previous;
		previous = std::min(one_step, two_step);
	}
	return previous;
}
/*
int main()
{
	auto test1 = std::pair<std::vector<int>, int>{std::vector<int>{10, 15, 20}, 15};
	auto test2 = std::pair<std::vector<int>, int>{std::vector<int>{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6};
	auto test3 =
		std::pair<std::vector<int>, int>{std::vector<int>{1, 12, 419, 181, 17, 19, 0, 71, 26, 1, 2, 3, 4, 5, 6, 7},
										 248};
	std::cout << min_cost_to_reach_end(test1.first) << ", " << test1.second << std::endl;
	std::cout << min_cost_to_reach_end(test2.first) << ", " << test2.second << std::endl;
	std::cout << min_cost_to_reach_end(test3.first) << ", " << test3.second << std::endl;
}
 */