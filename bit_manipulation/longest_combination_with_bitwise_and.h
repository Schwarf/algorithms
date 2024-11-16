//
// Created by andreas on 16.11.24.
//

#ifndef LONGEST_COMBINATION_WITH_BITWISE_AND_H
#define LONGEST_COMBINATION_WITH_BITWISE_AND_H
// The bitwise AND of an array input is the bitwise AND of all integers in input.
// For example, for input = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
// Also, for input = [7], the bitwise AND is 7.
// You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.
// Return the size of the largest combination of candidates with a bitwise AND greater than 0.

#include <algorithm>
#include <vector>
int longest_combination_bitwise_and(std::vector<int>& input)
{

    // We count for each number ion input the bits in this array
    std::vector<int> bit_count(31, 0);
    for(int bit_position{}; bit_position< 31; ++bit_position)
    {
        for(const auto number: input)
        {
            if(number & (1 << bit_position))
                bit_count[bit_position]++;
        }
    }

    return *std::max_element(bit_count.begin(), bit_count.end());
}


#endif //LONGEST_COMBINATION_WITH_BITWISE_AND_H
