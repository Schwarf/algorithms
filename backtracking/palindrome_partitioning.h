//
// Created by andreas on 03.11.26.
//

#ifndef ALGORITHMS_PALINDROME_PARTITIONING_H
#define ALGORITHMS_PALINDROME_PARTITIONING_H
// Given a string s, partition it into substrings such that every substring is a palindrome.
// Return all possible valid partitions in any order.
// A palindrome reads the same forward and backward.

#include <vector>
#include <string>

bool is_palindrome(std::string s)
{
    int size = s.length();
    if (size ==1)
        return true;
    int left = 0;
    int right = size-1;
    while (left <= right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

void backtrack(std::vector<std::vector<std::string>> & result, std::vector<std::string> &current, int start, const std::string & s)
{
    if (start == s.size())
    {
        result.push_back(current);
        return;
    }
    for (int end{start}; end < s.size(); ++end) {
        if (is_palindrome(s.substr(start, end-start+1))) {
            current.push_back(s.substr(start, end-start+1));
            backtrack(result, current, end+1, s);
            current.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> palindrome_partitioning(std::string s)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current;
    backtrack(result, current, 0, s);
    return result;
}
#endif // ALGORITHMS_PALINDROME_PARTITIONING_H
