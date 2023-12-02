//
// Created by andreas on 02.12.23.
//

#ifndef COUNT_BEAUTIFUL_SUBSTRINGS_H
#define COUNT_BEAUTIFUL_SUBSTRINGS_H
#include <unordered_set>
#include <string>
// You are given a string s and a positive integer k.
// Let vowels and consonants be the number of vowels and consonants in a string.
// A string is beautiful if:
// 1. vowels == consonants.
// 2. (vowels * consonants) % k == 0, in other terms the multiplication of vowels and consonants is divisible by k.
// Return the number of non-empty beautiful substrings in the given string s.
// A substring is a contiguous sequence of characters in a string.
// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
int count_beautiful_substrings(std::string s, int k) {
	int n = s.size();
	std::unordered_set<char> vowels {'a', 'e', 'o', 'u', 'i'};
	int beauties{};
	for(int i{}; i < n; ++i)
	{
		int count_vowels{};
		int count_consonants{};
		for(int j=i; j < n; ++j)
		{
			if(vowels.find(s[j]) != vowels.end())
				count_vowels++;
			else
				count_consonants++;
			if((count_vowels == count_consonants) && (((count_vowels*count_consonants) % k) == 0))
			{
				beauties++;
			}
		}
	}
	return beauties;
}

#endif //COUNT_BEAUTIFUL_SUBSTRINGS_H
