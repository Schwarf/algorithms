//
// Created by andreas on 17.07.26.
//

#ifndef ALGORITHMS_COUNT_SUBSTRINGS_REARRANGED_H
#define ALGORITHMS_COUNT_SUBSTRINGS_REARRANGED_H
// Given two strings word1 and word2, count the number of contiguous substrings of word1 whose characters can be
// rearranged so that word2 appears as a prefix.
// Return the total number of valid substrings.
#include <string>
#include <unordered_map>
long long count_substrings_rearranged(const std::string& word1, const std::string& word2)
{
    if (word2.length() > word1.length())
        return 0;

    std::unordered_map<char, int> prefix;
    for (const auto c : word2)
    {
        ++prefix[c];
    }
    int missing = word2.length();
    int left = 0;
    long long count = 0;
    for (int right = 0; right < word1.length(); ++right)
    {
        if (prefix.contains(word1[right]))
        {
            const char current = word1[right];
            if (prefix[current] > 0)
                --missing;
            --prefix[current];
        }

        while (missing == 0)
        {
            count += word1.length() - right;
            const char c = word1[left];
            if (prefix.contains(c))
            {
                ++prefix[c];
                if (prefix[c] > 0)
                    ++missing;
            }
            ++left;
        }
    }
    return count;
}

#endif // ALGORITHMS_COUNT_SUBSTRINGS_REARRANGED_H
