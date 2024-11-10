//
// Created by andreas on 10.11.24.
//

#ifndef ROTATE_STRING_H
#define ROTATE_STRING_H
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on input1.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
#include <algorithm>
#include <string>

inline bool are_strings_equal_brute_force(std::string & input1, const std::string & input2)
{
    if (input1.length() != input2.length()) return false;
    int length = input1.length();

    // Try all possible rotations of the string
    for (int rotationCount = 0; rotationCount < length; ++rotationCount) {
        // Perform one rotation
        std::rotate(input1.begin(), input1.begin() + 1, input1.end());
        if (input1 == input2)
            return true;
    }
    return false;
}



#endif //ROTATE_STRING_H
