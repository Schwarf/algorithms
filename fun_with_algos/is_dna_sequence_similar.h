//
// Created by andreas on 12.03.25.
//

#ifndef IS_DNA_SEQUENCE_SIMILAR_H
#define IS_DNA_SEQUENCE_SIMILAR_H
// A DNA sequence is represented by a string of lowercase letters. Given a pair of DNA sequences,
// if the scientist is able to remove any number of a letter in sequence1 and any number of a letter in
// sequence2 to make the strings anagrams, then the sequences are similar.
// Given n pairs of DNA sequences, for each pair, attempt to find if they are similar.
// Return a list of boolean values where boolean[i] indicates for the i'th pair.
#include <vector>
#include <string>
#include <unordered_map>

int comparsison(const std::string & s1, const std::string & s2)
{
    std::vector<int> count1(26);
    std::vector<int> count2(26);
    for(const auto c: s1)
    {
      count1[c-'a']++;
    }
    for(const auto c: s2)
    {
        count2[c-'a']++;
    }
    int count{};
    for(int i{}; i< 26; i++)
    {
      if(count1[i] != count2[i])
        count++;
    }
    return count;

}


std::vector<bool> are_sequences_similar(std::vector<std::vector<std::string>> & input)
{
  std::vector<bool> result;
    for(const auto & pair: input)
    {
        if(comparsison(pair[0], pair[1]) < 3)
             result.push_back(true);
        else
            result.push_back(false);
    }
    return result;
}
#endif //IS_DNA_SEQUENCE_SIMILAR_H

