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
	std::priority_queue<std::pair<int, char>> q;
	for (const auto [c, frequency]: map) {
		q.push({frequency, c});
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
