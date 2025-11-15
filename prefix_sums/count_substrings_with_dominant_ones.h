//
// Created by andreas on 15.11.25.
//

#ifndef ALGORITHMS_COUNT_SUBSTRINGS_WITH_DOMINANT_ONES_H
#define ALGORITHMS_COUNT_SUBSTRINGS_WITH_DOMINANT_ONES_H

// You are given a binary string s.
// Return the number of
// with dominant ones.
// A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.
#include <string>
#include <vector>
int number_of_substrings(const std::string & s)
{
    int n = s.size();
    std::vector<int> prefix(n+1);
    prefix[0] = -1;
    for (int j= 1; j <= n; ++j)
    {
        
        if (i == 0 || i > 0 && s[i-1] == '0')
            prefix[i+1] = i;
        else
            prefix[i+1] = prefix[i];
    }
}

#endif //ALGORITHMS_COUNT_SUBSTRINGS_WITH_DOMINANT_ONES_H