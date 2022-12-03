//
// Created by andreas on 03.12.22.
//

#ifndef STEPS_TO_MAKE_TWO_EQUAL_SIZED_STRINGS_AN_ANAGRAM_H
#define STEPS_TO_MAKE_TWO_EQUAL_SIZED_STRINGS_AN_ANAGRAM_H
#include <string>
#include <map>
#include <algorithm>
// You are given two strings of the same length s and t. In one step you can choose any character of t
// and replace it with another character.
// Return the minimum number of steps to make t an anagram of s.
// An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

int steps_to_make_anagram1(std::string s, std::string t)
{
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	if(s==t)
		return 0;
	std::map<char, int> s_map;
	std::map<char, int> t_map;
	for(int i{}; i < s.size(); ++i)
	{
		s_map[s[i]]++;
		t_map[t[i]]++;
	}
	int actions{};
	for(const auto & element: s_map)
	{
		if(t_map[element.first] < element.second)
			actions += (element.second - t_map[element.first]);
	}
	return actions;
}
// We only need the difference from s to t, so we count all characters in s positive and all characters in t negative
// Absolute negative can be ignored because we only care bout changes that transform s to t.
int steps_to_make_anagram2(std::string s, std::string t)
{
	std::vector<int> frequencies(26, 0);
	for(int i{}; i < s.size(); ++i)
	{
		frequencies[s[i] -'a']++;
		frequencies[t[i] -'a']--;
	}
	int actions{};
	for(const auto & element: frequencies)
		actions += std::max(element, 0);
	return actions;

}

#endif //STEPS_TO_MAKE_TWO_EQUAL_SIZED_STRINGS_AN_ANAGRAM_H
