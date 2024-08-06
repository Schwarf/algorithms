//
// Created by andreas on 06.08.24.
//

#ifndef SORT_MINIMUM_NUMBER_OF_DIAL_PUSHES_FOR_WORD_H
#define SORT_MINIMUM_NUMBER_OF_DIAL_PUSHES_FOR_WORD_H
// Given a phone dial where digits 2-9 also provide to input letters by one or more pushes consider the following problem.
// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters.
// The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key.
// You need to find the minimum number of times the keys will be pushed to type the string word.
// Return the minimum number of pushes needed to type word after remapping the keys.
#include <vector>
#include <string>

int minimum_dial_pushes(std::string word) {
    std::vector<int> letters(26);
    for (const auto c: word) {
        letters[c - 'a']++;
    }
    std::sort(letters.begin(), letters.end(), std::greater<>());
    int pushes{};
    for (int i{}; i < 26; ++i) {
        if (i < 8)
            pushes += letters[i];
        else if (i < 16)
            pushes += 2 * letters[i];
        else if (i < 24)
            pushes += 3 * letters[i];
        else
            pushes += 4 * letters[i];
    }
    return pushes;

}


#endif //SORT_MINIMUM_NUMBER_OF_DIAL_PUSHES_FOR_WORD_H
