//
// Created by andreas on 15.09.24.
//

#ifndef BIT_MANIPULATION_FIND_LONGEST_SUBSTRING_WITH_EVEN_VOWL_COUNT_H
#define BIT_MANIPULATION_FIND_LONGEST_SUBSTRING_WITH_EVEN_VOWL_COUNT_H
// Given the string s, return the size of the longest substring containing each vowel an even number of times.
// That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
#include <vector>
#include <string>
int find_longest_valid_substring(std::string & s)
{
    int prefix_XOR{};
    std::vector<int> character_map(26);
    character_map['a'-'a'] = 1; // 0th-bit
    character_map['e'-'a'] = 2;
    character_map['i'-'a'] = 4;
    character_map['o'-'a'] = 8;
    character_map['u'-'a'] = 16; // 4th-bit
    // Its essential to initialize to -1 so the length computation for consonants is correct
    std::vector<int> bitmask_first_seen(32, -1);
    int longest_substring{};

    for (int i = 0; i < s.length(); i++) {
        // for a consonant the following assignment does not change prefix_XOR
        // if a vowel is found the corresponding bit in prefix_XOR is toggled
        prefix_XOR ^= character_map[s[i] - 'a'];
        // Check if this is the first occurrence of the current prefix_XOR state (excluding the initial state).
        if (bitmask_first_seen[prefix_XOR] == -1 and prefix_XOR != 0)
            bitmask_first_seen[prefix_XOR] = i;
        // Update longest_substring by calculating the length from the first occurrence of the current prefix_XOR state.
        longest_substring = std::max(longest_substring, i - bitmask_first_seen[prefix_XOR]);
    }

    return longest_substring;
}

#endif //BIT_MANIPULATION_FIND_LONGEST_SUBSTRING_WITH_EVEN_VOWL_COUNT_H
