//
// Created by andreas on 12.09.23.
//

#ifndef MINIMUM_DELETIONS_FOR_UNIQUE_CHARACTER_FREQUENCIES_H
#define MINIMUM_DELETIONS_FOR_UNIQUE_CHARACTER_FREQUENCIES_H
// A string s is called good if there are no two different characters in s that have the same frequency.
// Given a string s, return the minimum number of characters you need to delete to make s good.
// The frequency of a character in a string is the number of times it appears in the string.
// For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
// Only lowercase english characters are in the string.
// #GREEDY
#include <string>
#include <vector>
#include <unordered_set>
int minimum_deletions(const std::string & input)
{
	std::vector<int> frequencies(26, 0);
	for(const auto & c: input)
		frequencies[c-'a']++;
	std::unordered_set<int> frequency_count;
	int deletions{};
	for(auto & frequency : frequencies)
	{
		if(frequency > 0)
		{
			while(frequency >0 && frequency_count.find(frequency) != frequency_count.end())
			{
				deletions++;
				frequency--;
			}
			if(frequency > 0)
				frequency_count.insert(frequency);
		}
	}
	return deletions;
}
#endif //MINIMUM_DELETIONS_FOR_UNIQUE_CHARACTER_FREQUENCIES_H
