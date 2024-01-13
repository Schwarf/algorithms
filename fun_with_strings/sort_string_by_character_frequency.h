//
// Created by andreas on 03.12.22.
//
#include <string>
#include <map>
#include <queue>

#ifndef SORT_STRING_BY_CHARACTER_FREQUENCY_H
#define SORT_STRING_BY_CHARACTER_FREQUENCY_H
// Given a string s, sort it in decreasing order based on the frequency of the characters.
// The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

std::string sorted_by_character_frequency(const std::string & s )
{
	std::map<char, int> char_counter;
	for (const auto &c: s)
		char_counter[c]++;
	std::priority_queue<std::pair<int, char>> queue;
	// Note by default std::pair is sorted by 1st element
	for (const auto &char_count: char_counter)
		queue.emplace(char_count.second, char_count.first);
	std::string result;
	while (!queue.empty()) {
		auto frequency = queue.top().first;
		auto character = queue.top().second;
		result += std::string(frequency, character);
		queue.pop();
	}

	return result;
}

#endif //SORT_STRING_BY_CHARACTER_FREQUENCY_H
