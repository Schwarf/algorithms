//
// Created by andreas on 19.08.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_MINIMUM_COPY_PASTE_OPERATIONS_H
#define DYNAMIC_PROGRAMMING_SAMPLES_MINIMUM_COPY_PASTE_OPERATIONS_H
// You are given two operations 'copy' and 'paste' to create n copies of the single fixed character 'A'.
// Initially the character 'A' appears exactly once on your screen. It is your task to get the minimal number
// of operations to create it n times. You can copy as many characters as you want and paste them then,

#include <algorithm>

int count_operations(int n, int current_length, int paste_length) {
    if (current_length == n)
        return 0;

    if (current_length > n)
        return 1000;
    // copy and paste current length
    int two_operations = 2 + count_operations(n, 2 * current_length, current_length);
    // paste paste_length
    int one_operation = 1 + count_operations(n, current_length + paste_length, paste_length);
    return std::min(one_operation, two_operations);
}

// O(2^N)
// Copy + Paste operation adds 2 operations
// Paste operation add 1 operation
// n <= 1000
int minimum_copy_paste_operations_recursive(int n) {
    if (n == 1)
        return 0;
    return 1 + count_operations(n, 1, 1);
}

int count_operations(int n, int current_length, int paste_length, std::vector<std::vector<int>> &memo) {
    if (current_length == n)
        return 0;
    if (current_length > n)
        return 1000;
    if (memo[current_length][paste_length] != 0)
        return memo[current_length][paste_length];
    // copy and paste current length
    int two_operations = 2 + count_operations(n, 2 * current_length, current_length, memo);
    // paste paste_length
    int one_operation = 1 + count_operations(n, current_length + paste_length, paste_length, memo);

    memo[current_length][paste_length] = std::min(one_operation, two_operations);
    return memo[current_length][paste_length];
}

int minimum_copy_paste_operations_top_down(int n) {
    if (n == 1)
        return 0;
    // We can only copy (and paste) maximal n/2 +1 elements in the last step
    std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n / 2 + 1, 0));
    return 1 + count_operations(n, 1, 1, memo);
}


#endif //DYNAMIC_PROGRAMMING_SAMPLES_MINIMUM_COPY_PASTE_OPERATIONS_H
