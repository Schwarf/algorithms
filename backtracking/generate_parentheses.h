//
// Created by andreas on 02.10.26.
//

#ifndef BEHAVIORAL_PATTERNS_GENERATE_PARENTHESES_H
#define BEHAVIORAL_PATTERNS_GENERATE_PARENTHESES_H
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#include <vector>
#include <string>

void backtrack(std::string & current, int open, int close, int n, std::vector<std::string> & result)
{
    if (current.size() == 2*n)
        result.push_back(current);

    if (open < n)
    {
        current.push_back('(');
        backtrack(current, open+1, close, n, result);;
        current.pop_back();
    }
    if (close < open)
    {
        current.push_back(')');
        backtrack(current, open, close+1, n, result);
        current.pop_back();
    }
}

std::vector<std::string> generate_parentheses(int n)
{
    std::vector<std::string> result;
    std::string current;
    backtrack(current, 0, 0, n, result);
    return result;
}

#endif // BEHAVIORAL_PATTERNS_GENERATE_PARENTHESES_H
