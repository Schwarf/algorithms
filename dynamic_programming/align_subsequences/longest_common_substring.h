//
// Created by andreas on 14.06.22.
//

#ifndef LONGEST_COMMON_SUBSTRING_H
#define LONGEST_COMMON_SUBSTRING_H
#include <algorithm>
#include <string>
#include <vector>

// Given two strings text1 and text2, return the length of their longest common
// substring. If there is no common substring, return 0. A substring of a string
// is a new string generated from the original string with some characters (can
// be none) deleted without changing the relative order of the remaining
// characters. For example, "ace" is a subsequence of "abcde". A common
// subsequence of two strings is a subsequence that is common to both strings.

int longest_common_substring(const std::string& word1, const std::string& word2)
{
    if (word1.empty() || word2.empty())
        return 0;

    int n1 = word1.size();
    int n2 = word2.size();

    std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1));

    int longest{};
    for (int i1{1}; i1 <= n1; ++i1)
    {
        for (int i2{1}; i2 <= n2; ++i2)
        {
            if (word1[i1 - 1] == word2[i2 - 1])
            {
                dp[i1][i2] = dp[i1 - 1][i2 - 1] + 1;
                longest = std::max(longest, dp[i1][i2]);
            }
        }
    }
    return longest;
}

#endif // LONGEST_COMMON_SUBSTRING_H
