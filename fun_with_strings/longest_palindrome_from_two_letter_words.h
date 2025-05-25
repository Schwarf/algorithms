//
// Created by andreas on 25.05.25.
//

#ifndef LONGEST_PALINDROME_FROM_TWO_LETTER_WORDS_H
#define LONGEST_PALINDROME_FROM_TWO_LETTER_WORDS_H
// You are given an array of strings words. Each element of words consists of two lowercase English letters.
// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
// A palindrome is a string that reads the same forward and backward.
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int longestPalindrome(std::vector<std::string>& words)
{
    std::unordered_map<std::string, int> map;
    int count{};
    for (const auto& word : words)
    {
        map[word]++;
    }
    bool found{};
    for (const auto& [key, f] : map)
    {
        std::string rev{key[1], key[0]};
        auto rev_iterator = map.find(rev);
        auto key_iterator = map.find(key);
        if (key[0] != key[1])
        {
            // non-palindromic pair
            if (rev_iterator != map.end())
            {
                const int pairs = std::min(key_iterator->second, rev_iterator->second);
                count += pairs * 4;
                key_iterator->second -= pairs;
                rev_iterator->second -= pairs;
            }
        }
        else
        {
            // palindromic word “aa” case
            const int pairs = key_iterator->second / 2;
            count += pairs * 4;
            key_iterator->second -= pairs * 2;
            // leftover 1 can be center—handle after the loop
        }
    }
    for (auto& [k, freq] : map)
    {
        if (k[0] == k[1] && freq > 0)
        {
            count += 2;
            break; // only one center allowed
        }
    }

    return count;
}
#endif //LONGEST_PALINDROME_FROM_TWO_LETTER_WORDS_H
