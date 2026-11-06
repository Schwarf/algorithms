//
// Created by andreas on 03.11.26.
//

#ifndef ALGORITHMS_PALINDROME_GENERATION_H
#define ALGORITHMS_PALINDROME_GENERATION_H
// Generate Palindromes Up to Length K
// You are given a string s containing distinct characters and an integer k.
//
// Return all non-empty palindromic strings of length at most k that can be formed using characters from s.
//
// Each character in s may be used any number of times.
//
// A palindrome is a string that reads the same from left to right and right to left.
//
// The order of the returned palindromes does not matter.
// Example 1
// Input:
// s = "ab"
// k = 2
//
// Output:
// ["a", "b", "aa", "bb"]

#include <vector>
#include <string>

void backtrack(std::vector<std::string> & result, const std::string & s, std::string & current, int k, int index)
{
    if (current.size() == k)
    {
        result.push_back(current);
        return;
    }

    if (2*current.size() < k)
    {
        for (int i{}; i < s.size(); ++i)
        {
            current.push_back(s[i]);
            backtrack(result,s, current, k, index+1);
            current.pop_back();
        }
    }
    else
    {
        current.push_back(current[k-index-1]);
        backtrack(result,s, current, k, index+1);
        current.pop_back();
    }
}


std::vector<std::string> palindromes(const std::string& s, int k)
{
    std::vector<std::string> result;
    for (int i{1}; i <=k; ++i)
    {
        std::string current{};
        backtrack(result, s, current, i, 0);
    }
    return result;
}


#endif // ALGORITHMS_PALINDROME_GENERATION_H
