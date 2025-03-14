//
// Created by andreas on 14.03.25.
//

#ifndef MINIMAL_COST_DATA_H
#define MINIMAL_COST_DATA_H
// Enthusiasts are working on a data interpolation model to increase the size of the data set for better learning.
// In one such model, there are 26 different classifications possible and the ith data point is annotated to belong to the data[i] class where data is a string of lowercase English letters. However, for some data points, data[i] is equal to '?' representing that the corresponding data point classification is missing and needs to be replaced with some lowercase English letter.
// The cost of any index i of the string data is defined as the number of indices before it that also have the same classification result. For example,
// For the string "hello" the costs are [0, 0, 0, 1, 0] corresponding to each index.
// For the string "abc" the costs are [0, 0, 0] corresponding to each index.
// For the string "aaccbbc" the costs are [0, 1, 0, 1, 0, 1, 2] corresponding to each index because before the last c character, there are 2 more c characters.
// The task is to replace all the characters '?' so that the sum of the indices' cost is minimum.
// Given the string data , interpolate the data such that the total cost of all the indices is minimized. If there are multiple ways to get minimum cost, print the lexicographically smallest possible string that satisfies the goal.
// Function Description
// Complete the function getMinCostData in the editor below.
// getMinCostData has the following parameter:
//   data : a string
#include <string>
#include <vector>
#include <algorithm>
std::string minimal_data_costs(std::string & data)
{
    std::vector<int> chars(26, 0);
    for(const char c : data)
    {
         if(c != '?')
        {
           chars[c-'a']++;
         }
    }

    for(char & c : data)
    {
        if(c == '?')
        {
          auto it = std::min_element(std::begin(chars), std::end(chars));
          c = std::distance(chars.begin(), it) + 'a';
          (*it)++;
        }
    }
    return data;

}

#endif //MINIMAL_COST_DATA_H
