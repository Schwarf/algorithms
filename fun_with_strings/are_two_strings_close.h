//
// Created by andreas on 14.01.24.
//

#ifndef ARE_TWO_STRINGS_CLOSE_H
#define ARE_TWO_STRINGS_CLOSE_H
// Two strings are considered close if you can attain one from the other using the following operations:
// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
//You can use the operations on either string as many times as necessary.
//Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
#include <string>
#include <vector>
#include <set>
#include <algorithm>

bool are_strings_close(const std::string & input1, const std::string & input2)
{
	if (input1.length() != input2.length())
		return false;
	std::vector<int> count1(26, 0);
	std::vector<int> count2(26, 0);
	std::set<char> chars1;
	std::set<char> chars2;
	int n = input1.size();
	for (int i{}; i < n; ++i)
	{
		count1[input1[i]-'a']++;
		count2[input2[i]-'a']++;
		chars1.insert(input1[i]);
		chars2.insert(input2[i]);
	}
	if(chars1 != chars2)
		return false;
	std::sort(count1.begin(), count1.end());
	std::sort(count2.begin(), count2.end());
	return count1 == count2;
}

#endif //ARE_TW	O_STRINGS_CLOSE_H
