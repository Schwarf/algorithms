//
// Created by andreas on 14.06.22.
//

#ifndef LONGEST_COMMON_SUBSTRING_H
#define LONGEST_COMMON_SUBSTRING_H
#include <string>
#include <vector>

// Given two strings text1 and text2, return the length of their longest common substring. If there is no common
// substring, return 0.
// A substring of a string is a new string generated from the original string with some characters (can be none)
// deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

int longest_common_substring(std::string word1, std::string word2) {

	auto help = std::vector<std::vector<int>>(word1.size() + 1 , std::vector<int>(word2.size() +1, 0));
	int length{};
	for(int i1 = 0; i1 <= word1.size(); ++i1 )
	{
		for(int i2 =0; i2 <= word2.size(); ++i2)
		{
			if(i1 ==0 || i2 ==0)
				continue;
			else if(word1[i1-1] == word2[i2-1])
			{
				help[i1][i2] = help[i1-1][i2-1] + 1;
				length = std::max(help[i1][i2],length);
			}
			else
				help[i1][i2] = 0;
		}
	}

	return length;
}

#endif //LONGEST_COMMON_SUBSTRING_H
