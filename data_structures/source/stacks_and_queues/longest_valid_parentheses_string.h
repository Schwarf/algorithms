//
// Created by andreas on 03.07.23.
//

#ifndef LONGEST_VALID_PARENTHESES_STRING_H
#define LONGEST_VALID_PARENTHESES_STRING_H

#include <string>
#include <stack>
// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed)
//	parentheses substring

// O(n) in time and space
int longest_valid_parentheses_string(const std::string &input) {
    std::stack<int> s{{-1}};
    int max{};
    for (int i{}; i < input.size(); ++i) {
        // We push the indices to the stack
        if (input[i] == '(')
            s.push(i);
        else {
            s.pop();
            // if stack is empty a ')' will not help so we just push its index
            if (s.empty())
                s.push(i);
            else
                max = std::max(max, i - s.top());
        }
    }
    return max;
}

// O(n) in time and O(1) in space
int longest_valid_parentheses_string_optimized(const std::string &input) {
    int left{};
    int right{};
    int max{};
    for (int i{}; i < input.size(); ++i) {
        input[i] == '(' ? left++ : right++;
        left == right ? max = std::max(max, 2 * right) : (int) 0;
        if (right > left)
            right = left = 0;
    }
    right = left = 0;
    for (int i = input.size() - 1; i > -1; --i) {
        input[i] == '(' ? left++ : right++;
        left == right ? max = std::max(max, 2 * right) : (int) 0;
        if (left > right)
            right = left = 0;
    }
    return max;
}


#endif //LONGEST_VALID_PARENTHESES_STRING_H
