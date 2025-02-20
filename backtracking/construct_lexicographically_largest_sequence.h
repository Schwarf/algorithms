//
// Created by andreas on 15.02.25.
//

#ifndef CONSTRUCT_LEXICOGRAPHICALLY_LARGEST_SEQUENCE_H
#define CONSTRUCT_LEXICOGRAPHICALLY_LARGEST_SEQUENCE_H

// Given an integer n, find a sequence with elements in the range [1, n] that satisfies all of the following:
//
//    The integer 1 occurs once in the sequence.
//    Each integer between 2 and n occurs twice in the sequence.
//    For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
//
// The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
//
// Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
//
// A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.
// LC: 1718
#include <vector>

bool find_lexicographically_largest_sequence(int current_index,
                                             std::vector<int>& result_sequence,
                                             std::vector<char>& is_number_used,
                                             int target_number)
{
    // If we have filled all positions, return true indicating success
    if (current_index == result_sequence.size())
    {
        return true;
    }

    // If the current position is already filled, move to the next index
    if (result_sequence[current_index] != 0)
    {
        return find_lexicographically_largest_sequence(
            current_index + 1, result_sequence, is_number_used, target_number);
    }

    // Attempt to place numbers from targetNumber to 1 for a lexicographically largest result
    for (int number_to_place = target_number; number_to_place >= 1; number_to_place--)
    {
        if (is_number_used[number_to_place] == 1)
            continue;

        is_number_used[number_to_place] = 1;
        result_sequence[current_index] = number_to_place;

        // If placing number 1, move to the next index directly
        if (number_to_place == 1)
        {
            if (find_lexicographically_largest_sequence(current_index + 1, result_sequence, is_number_used,
                                                        target_number))
                return true;
        }
        // Place larger numbers at two positions if valid
        else if (current_index + number_to_place < result_sequence.size() &&
            result_sequence[current_index + number_to_place] == 0)
        {
            result_sequence[current_index + number_to_place] = number_to_place;

            if (find_lexicographically_largest_sequence(
                current_index + 1, result_sequence, is_number_used,
                target_number))
            {
                return true;
            }

            // Undo the placement for backtracking
            result_sequence[current_index + number_to_place] = 0;
        }

        // Undo current placement and mark the number as unused
        result_sequence[current_index] = 0;
        is_number_used[number_to_place] = 0;
    }

    return false;
}

std::vector<int> construct_distanced_sequence(int target_number)
{
    // Initialize the result sequence with size 2*n - 1 filled with 0s
    std::vector<int> result_sequence(target_number * 2 - 1, 0);

    // Keep track of which numbers are already placed in the sequence
    std::vector<char> is_number_used(target_number + 1, 0);

    // Start recursive backtracking to construct the sequence
    find_lexicographically_largest_sequence(0, result_sequence, is_number_used, target_number);

    return result_sequence;
}


#endif //CONSTRUCT_LEXICOGRAPHICALLY_LARGEST_SEQUENCE_H
