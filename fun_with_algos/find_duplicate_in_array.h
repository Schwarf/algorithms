//
// Created by andreas on 24.03.24.
//

#ifndef FIND_DUPLICATE_IN_ARRAY_H
#define FIND_DUPLICATE_IN_ARRAY_H

// Given an array of integers input containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in input, return this repeated number.
// You must solve the problem without modifying the array input and uses only constant extra space.
#include <vector>
#include <algorithm>
// Easy-peasy: Sort and find the duplicate. Here we concentrate on O(N) solutions.

int find_duplicate(std::vector<int> &input) {
    for (int i{}; i < input.size(); ++i) {
        // We compute the index and negate the value at the index.
        int index = std::abs(input[i]);
        // If the value at the index is already negative, we return the index because it has been visited once before/
        if (input[index] < 0)
            return index;
        // HERE we negate
        input[index] = -input[index];
    }
    return -1;
}

// Due to the given problem structure (n+1) numbers in [1, n] with a duplicate, we can approach this problem like
// a linked list. We use slow and fast runner in linked list and use them to find the begining of a cycle in
// linked list.

int find_duplicate_linked_list(const std::vector<int> &input) {
    int slow = input[0];
    int fast = input[0];
    // Find the intersection point of the two pointers
    do {
        slow = input[slow];
        fast = input[input[fast]];
    } while (slow != fast);


    // Find the entrance of the cycle
    slow = input[0];
    while (slow != fast) {
        slow = input[slow];
        fast = input[fast];
    }
    return slow;
}


#endif //FIND_DUPLICATE_IN_ARRAY_H
