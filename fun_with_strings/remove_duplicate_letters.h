//
// Created by andreas on 26.09.23.
//

#ifndef REMOVE_DUPLICATE_LETTERS_H
#define REMOVE_DUPLICATE_LETTERS_H
#include <string>
#include <vector>
// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
// the smallest in lexicographical order among all possible results.

std::string remove_duplicate_letters(const std::string &s)
{
	std::vector<bool> used(26, false);
	std::vector<int> count(26, 0);
	for (const auto &c: s)
		count[c - 'a']++;

	std::string result;
	for (const auto &c: s) {
		--count[c - 'a'];
		if (used[c - 'a'])
			continue;
		while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
			used[result.back() - 'a'] = false;
			result.pop_back();
		}
		used[c - 'a'] = true;
		result.push_back(c);
	}
	return result;
}
#endif //REMOVE_DUPLICATE_LETTERS_H
