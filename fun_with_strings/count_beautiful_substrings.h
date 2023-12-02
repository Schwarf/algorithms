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
int getRoot(int k) {
	for (int i = 1; i <= k; ++i)
		if (i * i % k == 0)
			return i;
	throw;
}

struct PairHash {
	size_t operator()(const std::pair<int, int>& p) const
	{
		return p.first ^ p.second;
	}
};

// O(N)
int count_beautiful_substrings_optimized(const std::string &s, int k)
{
	const int root = getRoot(k);
	std::unordered_set<char> vowels{'a', 'e', 'o', 'u', 'i'};
	int count{};
	int vowels_count{};
	int vowelsMinusConsonants{};
	// {(vowels_count, vowelsMinusConsonants): count}
	std::unordered_map<std::pair<int, int>, int, PairHash> prefix_count{{{0, 0}, 1}};

	for (const char c: s) {
		if (vowels.find(c) != vowels.end()) {
			vowels_count = (vowels_count + 1) % root;
			++vowelsMinusConsonants;
		}
		else {
			--vowelsMinusConsonants;
		}
		const std::pair<int, int> prefix{vowels_count, vowelsMinusConsonants};
		count += prefix_count[prefix]++;
	}	

	return count;
}


#endif //COUNT_BEAUTIFUL_SUBSTRINGS_H
