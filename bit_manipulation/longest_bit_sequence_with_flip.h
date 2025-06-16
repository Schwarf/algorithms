//
// Created by andreas on 16.06.25.
//

#ifndef LONGEST_BIT_SEQUENCE_WITH_FLIP_H
#define LONGEST_BIT_SEQUENCE_WITH_FLIP_H
#include <cmath>
// You have an integer and you can flip exactly one bit from a 0 to a 1, Write code to
// find the length of the longest sequence of Is you could create.
int longest_bit_sequence_with_flip(int number)
{
    bool flip = true;
    int exponent = std::log2(number) + 1;
    int max_length{};
    int length{};
    for (int i{}; i < exponent; ++i) {
        if ((1 << i) & number)
            length++;
        else if (flip) {
            length++;
            flip = false;
        }
        else {
            max_length = std::max(max_length, length);
            length = 0;
        }
    }
    return std::max(max_length, length);
}
#endif //LONGEST_BIT_SEQUENCE_WITH_FLIP_H
