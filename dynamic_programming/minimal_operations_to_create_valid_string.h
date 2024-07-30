//
// Created by andreas on 30.07.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_OPERATIONS_TO_CREATE_VALID_STRING_H
#define DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_OPERATIONS_TO_CREATE_VALID_STRING_H
// Given a string consisting only of ‘a’ and ‘b’ find the minimum number of deletions to make it a ‘valid’ string
// where no ‘b’ is left of an ‘a’ and no ‘a’ is right of an ‘b’.
// Valid string: aaabb.
// Invalid string: abab.
// String size up to 10^5 characters.
#include <string>
#include <vector>
#include <stack>

// O(N) time complexity, O(N) space complexity
int operations_to_create_valid_string_dp(const std::string &input) {
    int n = input.size();
    std::vector<int> leftB(n);
    std::vector<int> rightA(n);
    leftB[0] = input[0] == 'b' ? 1 : 0;
    rightA[n - 1] = input[n - 1] == 'a' ? 1 : 0;
    for (int i{1}; i < n; ++i)
        leftB[i] = leftB[i - 1] + (input[i] == 'b');
    for (int i{n - 2}; i > -1; --i)
        rightA[i] = rightA[i + 1] + (input[i] == 'a');

    int min{1000000};
    for (int i{}; i < n; ++i) {
        min = std::min(min, leftB[i] + rightA[i] - 1);
    }
    return min;
}

// O(N) time complexity, O(N) space complexity
int operations_to_create_valid_string_stack(const std::string &input) {
    std::stack<char> s;
    int delete_count{};
    for (const auto &c: input) {
        // whenever we have a 'b' on top of the stack and an 'a' we have to delete one of them
        if (!s.empty() && s.top() == 'b' && c == 'a') {
            delete_count++;
            s.pop();
        } else
            s.push(c);
    }
    return delete_count;
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_OPERATIONS_TO_CREATE_VALID_STRING_H
