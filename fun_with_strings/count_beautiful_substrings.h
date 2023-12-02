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

int count_beautiful_substrings_optimized(const std::string &s, int k) {
	int n = s.length();
	std::unordered_set<char> vowels {'a', 'e', 'o', 'u', 'i'};
	std::vector<int> vowel_count(n + 1, 0), consonant_count(n + 1, 0);
	int count{};

	for (int i = 0; i < n; ++i) {
		if(vowels.find(s[i]) != vowels.end()) {
			vowel_count[i + 1] = vowel_count[i] + 1;
			consonant_count[i+1] = consonant_count[i];
		}
		else {
			consonant_count[i + 1] = consonant_count[i] + 1;
			vowel_count[i+1] = vowel_count[i];
		}
	}

	for (int start = 1; start <= n; ++start) {
		for (int end = start; end <= n; ++end) {
			int current_vowels = vowel_count[end] - vowel_count[start-1];
			int current_consonants = consonant_count[end] - consonant_count[start-1];

			if (current_vowels == current_consonants && (current_vowels * current_consonants) % k == 0) {
				count++;
			}
		}
	}

	return count;
}
#endif //COUNT_BEAUTIFUL_SUBSTRINGS_H
