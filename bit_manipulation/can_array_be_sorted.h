//
// Created by andreas on 16.11.24.
//

#ifndef CAN_ARRY_BE_SORTED_H
#define CAN_ARRY_BE_SORTED_H

// You are given a 0-indexed array of positive integers input.
//
// In one operation, you can swap any two adjacent elements if they have the same number of
// set bits. You are allowed to do this operation any number of times (including zero).
//
// Return true if you can sort the array in ascending order, else return false.
#include <limits>
#include <vector>

bool can_array_be_sorted_bubble_sort(std::vector<int> & input)
{
    int n = input.size();
    if(n == 1)
        return true;
    for (int i{}; i < n; i++) {
        for (int j{}; j < n - i - 1; j++) {
            if (input[j] >= input[j + 1]) {
                if (__builtin_popcount(input[j]) == __builtin_popcount(input[j + 1])) {
                    // Swap the elements
                    std::swap(input[j], input[j + 1]);
                    } else {
                        return false;
                    }
            }
        }
    }
    return true;
}


bool can_array_be_sorted(std::vector<int>& input) {
    // Number of set bits of the elements in the current segment
    int number_of_set_bits = __builtin_popcount(input[0]);
    int maximum_of_segment = input[0];
    int minimum_of_segment = input[0];

    // Initialize max of the previous segment to the smallest possible
    // integer
    int maximum_of_previous_segment = std::numeric_limits<int>::min();

    for (int i{1}; i < input.size(); i++) {
        if (__builtin_popcount(input[i]) == number_of_set_bits) {
            // Element belongs to the same segment
            // Update min and max values of the segment
            maximum_of_segment = std::max(maximum_of_segment, input[i]);
            minimum_of_segment = std::min(minimum_of_segment, input[i]);
        } else {  // Element belongs to a new segment
            // Check if the segments are arranged properly
            // If not we can not swap to a valid sorted order
            if (minimum_of_segment < maximum_of_previous_segment) {
                return false;
            }

            // Update the previous segment's max
            maximum_of_previous_segment = maximum_of_segment;

            // Start a new segment with the current element
            maximum_of_segment = input[i];
            minimum_of_segment = input[i];
            number_of_set_bits = __builtin_popcount(input[i]);
        }
    }
    // Final check for proper segment arrangement
    if (minimum_of_segment < maximum_of_previous_segment) {
        return false;
    }
    return true;
}
#endif //CAN_ARRY_BE_SORTED_H
