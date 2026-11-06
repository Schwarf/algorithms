//
// Created by andreas on 03.11.26.
//

#ifndef ALGORITHMS_BINARY_STRING_WITHOUT_CONSECUTIVE_ONES_H
#define ALGORITHMS_BINARY_STRING_WITHOUT_CONSECUTIVE_ONES_H
// Given a positive integer n, generate all binary strings of length n that do not contain two consecutive 1s.
// A binary string consists only of the characters '0' and '1'.
// Return all valid strings in any order.
#include <vector>
#include <string>


void backtrack(std::vector<std::string> & result, std::string & current, int n)
{
    if (current.size() == n)
    {
        result.push_back(current);
        return;
    }

    if (!current.empty() && current.back() == '1')
    {
        current.push_back('0');
        backtrack(result, current, n);
        current.pop_back();
    }
    else
    {
        for (const auto c : {'1', '0'})
        {
            current.push_back(c);
            backtrack(result, current, n);
            current.pop_back();
        }
    }

}

std::vector<std::string> binary_strings(int n)
{
    std::vector<std::string> result;
    std::string current;
    backtrack(result, current, n);
    return result;
}

#endif // ALGORITHMS_BINARY_STRING_WITHOUT_CONSECUTIVE_ONES_H
