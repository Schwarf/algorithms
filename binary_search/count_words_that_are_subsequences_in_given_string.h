//
// Created by andreas on 20.07.22.
//

#ifndef COUNT_WORDS_THAT_ARE_SUBSEQUENCES_IN_GIVEN_STRING_H
#define COUNT_WORDS_THAT_ARE_SUBSEQUENCES_IN_GIVEN_STRING_H
#include <vector>
#include <string>
#include <algorithm>

// Consider only lower case english characters
// Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

int count_words_that_are_subsequences_in_given_string(std::string s, std::vector<std::string> &words)
{
	// Use character position on alphabet and record appearance (indices in s) of each character in separate vector.
	std::vector<std::vector<int>> indices_for_characters(26);

	auto n = s.length();

	// Normalize char (lower-case letters mapped to range 0-25)
	auto normalize_char = 'a';
	for (int i = 0; i < n; i++) {
		indices_for_characters[s[i] - normalize_char].push_back(i);
	}

	int ans = words.size();

	for (const auto &word: words) {
		// Initialize last character index in string s
		int last_index = -1;

		for (const auto &c: word) {
			auto &character_indices = indices_for_characters[c - normalize_char];
			auto it = std::upper_bound(character_indices.begin(), character_indices.end(), last_index);
			if (it == character_indices.end()) {
				ans--;
				break;
			}
			else {
				last_index = *it;
			}
		}
	}

	return ans;
}


#endif //COUNT_WORDS_THAT_ARE_SUBSEQUENCES_IN_GIVEN_STRING_H
