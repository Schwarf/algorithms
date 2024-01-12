//
// Created by andreas on 12.01.24.
//

#ifndef LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#include <string>
#include <unordered_set>
int longest_substring_without_repeating_character(const std::string & s)
{
	if(s.empty())
		return 0;

	std::unordered_set<char> help;
	int left = 0;
	int max_length = 0;

	for (int right = 0; right < s.size(); ++right) {
		// If s[right] is in the set, remove characters from the set until it's removed
		while(help.find(s[right]) != help.end()) {
			help.erase(s[left]);
			left++;
		}
		// Add the current character to the set
		help.insert(s[right]);

		// Update the maximum length
		max_length = std::max(max_length, right - left + 1);
	}

	return max_length;

}
#endif //LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
