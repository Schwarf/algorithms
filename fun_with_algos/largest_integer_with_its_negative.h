//
// Created by andreas on 04.05.24.
//

#ifndef FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H
#define FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H

#include <vector>
#include <unordered_set>

int largest_integer_with_its_negative(std::vector<int> & input)
{
    std::sort(input.begin(), input.end());
    int left{};
    int right = input.size()-1;
    while(left !=right)
    {
        if(input[left]/input[right] > 0)
            return -1;
        if(std::abs(input[left]) == input[right])
            return input[right];
        else if(std::abs(input[left]) > input[right])
            left++;
        else
            right--;
    }
    return -1;
}

int largest_integer_with_its_negative_hashset(std::vector<int> & input)
{
    int result{-1};
    std::unordered_set<int> seen;
    for(const auto element: input)
    {
        auto abs = std::abs(element);
        if(abs > result && seen.contains(-element))
            result = abs;
        seen.insert(element);
    }
    return result;
}


#endif //FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H

