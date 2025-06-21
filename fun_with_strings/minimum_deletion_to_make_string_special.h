//
// Created by andreas on 21.06.25.
//

#ifndef MINIMUM_DELETION_TO_MAKE_STRING_SPECIAL_H
#define MINIMUM_DELETION_TO_MAKE_STRING_SPECIAL_H
// You are given a string word and an integer k.
// We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
// Here, freq(x) denotes the
// of the character x in word, and |y| denotes the absolute value of y.
// Return the minimum number of characters you need to delete to make word k-special.
#include <string>
#include <unordered_map>
int minimumDeletions(std::string word, int k) {
    std::unordered_map<char, int> frequencies;
    for(const auto c: word)
    {
        frequencies[c]++;
    }
    int result = word.size();
    for(auto &[_, count]: frequencies)
    {
        int deleted = 0;
        for(auto & [_, count2]: frequencies)
        {
            if(count > count2)
                deleted += count2;
            else if(count2 > count+k)
                deleted += count2 - (count+k);
        }
        result = std::min(result, deleted);
    }
    return result;
}


#endif //MINIMUM_DELETION_TO_MAKE_STRING_SPECIAL_H
