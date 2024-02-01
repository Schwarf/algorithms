//
// Created by andreas on 01.02.24.
//

#ifndef STACK_TEMPERATURES_H
#define STACK_TEMPERATURES_H
// Given an array of integers temperatures represents the daily temperatures, return an array answer such that
// answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
// If there is no future day for which this is possible, keep answer[i] == 0 instead.
#include <vector>
#include <stack>

std::vector<int> daily_temperatures(const std::vector<int> &temperatures)
{
	std::stack<int> help;
	std::vector<int> result(temperatures.size(), 0);
	for (int i{}; i < temperatures.size(); ++i) {
		while (!help.empty() && temperatures[help.top()] < temperatures[i]) {
			result[help.top()] = i - help.top();
			help.pop();
		}
		help.push(i);
	}
	return result;
}


#endif //STACK_TEMPERATURES_H
