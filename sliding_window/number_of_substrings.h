//
// Created by andreas on 12.01.24.
//

#ifndef NUMBER_OF_SUBSTRINGS_H
#define NUMBER_OF_SUBSTRINGS_H
// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
#include <string>
#include <unordered_map>

int number_of_substrings(const std::string &s) {
    int n = s.size();
    std::unordered_map<char, int> frequency;
    int counter{};
    int left{};
    int right{};

    while (right < n) {
        frequency[s[right]]++;
        while (frequency['a'] > 0 && frequency['b'] > 0 && frequency['c'] > 0) {
            counter += (n - right);
            frequency[s[left]]--;
            left++;

        }
        right++;
    }
    return counter;
}

#endif //NUMBER_OF_SUBSTRINGS_H
