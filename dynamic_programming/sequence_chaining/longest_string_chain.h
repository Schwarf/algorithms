//
// Created by andreas on 23.09.23.
//

#ifndef LONGEST_STRING_CHAIN_H
#define LONGEST_STRING_CHAIN_H
// You are given an array of words where each word consists of lowercase English letters.
// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere
// in wordA without changing the order of the other characters to make it equal to wordB.
// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a
// predecessor of word2, word2 is a predecessor of word3, and so on.
// A single word is trivially a word chain with k == 1.
// Return the length of the longest possible word chain with words chosen from the given list of words.
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

int longest_string_chain(std::vector<std::string> &words) {
    std::unordered_map<std::string, int> counter;
    std::sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
        return word1.length() < word2.length();
    });
    // The minimum size is one, since at least one word forms a chain.
    int max_chain_length{0};
    for (const auto &current_word: words) {
        counter[current_word] = 1;
        for (int i{}; i < current_word.size(); ++i) {
            const std::string
                    possible_predecessor = current_word.substr(0, i) + current_word.substr(i + 1);
            if (counter.find(possible_predecessor) != counter.end()) {
                counter[current_word] = std::max(counter[current_word], counter[possible_predecessor] + 1);
            }
        }
        max_chain_length = std::max(max_chain_length, counter[current_word]);
    }
    return max_chain_length;
}

#endif //LONGEST_STRING_CHAIN_H
