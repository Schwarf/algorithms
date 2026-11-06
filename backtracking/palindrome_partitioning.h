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
    }
    return true;
}

void backtrack(std::vector<std::vector<std::string>> & result, std::vector<std::string> &current, int start, const std::string & s)
{
    if (start == s.size())
    {
        result.push_back(current);
    }

}

std::vector<std::vector<std::string>> palindrome_partitioning(std::string s)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current;

}
#endif // ALGORITHMS_PALINDROME_PARTITIONING_H
