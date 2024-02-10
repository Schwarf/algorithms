//
// Created by andreas on 10.02.24.
//

#ifndef SORT_CHARACTERS_BY_FREQUENCY_H
#define SORT_CHARACTERS_BY_FREQUENCY_H
#include <string>
#include <queue>
#include <map>


std::string sort_by_frequencies(std::string input)
{
	std::map<char, int> map;
	for (const auto c: input) {
		map[c]++;
	}
	auto comparator = [](const std::pair<int, char> &p1, const std::pair<int, char> &p2) -> bool
	{
		if (p1.first == p2.first) {
			return p1.second > p2.second;
		}
		return p1.first < p2.first;
	};
	std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, decltype(comparator)> q(comparator);
	for (const auto [c, frequency]: map) {
		q.emplace(frequency, c);
	}
	std::string result{};
	while (!q.empty()) {
		auto [frequency, character] = q.top();
		q.pop();
		result += std::string(frequency, character);
	}
	return result;
}
#endif //SORT_CHARACTERS_BY_FREQUENCY_H
