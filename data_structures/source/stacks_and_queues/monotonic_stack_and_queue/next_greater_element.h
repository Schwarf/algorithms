//
// Created by andreas on 23.08.26.
//

#ifndef ALGORITHMS_NEXT_GREATER_ELEMENT_H
#define ALGORITHMS_NEXT_GREATER_ELEMENT_H
// You are given a circular array of integers.
// For each element in the array, find the next greater element when moving to the right.
// The next greater element for a value is the first element encountered that is strictly greater than it.
// If no greater element exists, return -1 for that position.
// Return an array containing the next greater element for every index.
#include <vector>
#include <stack>

std::vector<int> next_greater_element_brute_force(const std::vector<int>& input)
{
    int n = input.size();
    std::vector<int> result(n, -1);
    for (int i = 0; i < n; ++i)
    {
        for (int step = 1; step < n; ++step)
        {
            if (input[(i + step) % n] > input[i])
            {
                result[i] = input[(i + step) % n];
                break;
            }
        }
    }
    return result;
}

std::vector<int> next_greater_element(const std::vector<int>& input)
{
    int n = input.size();
    std::vector<int> result(n, -1);
    std::stack<int> stack;
    for (int i = 0; i < 2*n; ++i)
    {
        const int index = i % n;
        while (!stack.empty() && input[stack.top()] < input[index])
        {
            result[stack.top()] = input[index];
            stack.pop();
        }
        if (i < n)
            stack.push(i);
    }
    return result;
}

#endif // ALGORITHMS_NEXT_GREATER_ELEMENT_H
