//
// Created by andreas on 06.10.24.
//

#ifndef FUN_WITH_STRINGS_PERMUTATION_INCLUDED_IN_STRING_H
#define FUN_WITH_STRINGS_PERMUTATION_INCLUDED_IN_STRING_H
// Given two strings s1 and s2, return true if s2 contains a permutation
// of s1, or false otherwise. In other words, return true if one of s1's permutations is the substring of s2.
#include <string>
#include <vector>

bool check_if_permutation_included(std::string &s1, std::string &s2) {
    if (s1.size() > s2.size())
        return false;
    std::vector<int> frequency1(26, 0);
    for (const char c: s1)
        frequency1[c - 'a']++;
    // We need to check each substring of length s2-s1 in s2
    for (int i{}; i <= s2.size() - s1.size(); ++i) {
        std::vector<int> frequency2(26, 0);
        // Count the chars in each substring
        for (int j = 0; j < s1.size(); ++j)
            frequency2[s2[i + j] - 'a']++;
        if (frequency1 == frequency2)
            return true;
    }
    return false;
}


#endif //FUN_WITH_STRINGS_PERMUTATION_INCLUDED_IN_STRING_H
