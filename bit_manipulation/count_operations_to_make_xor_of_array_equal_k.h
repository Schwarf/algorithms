//
// Created by andreas on 29.04.24.
//

#ifndef BIT_MANIPULATION_COUNT_OPERATIONS_TO_MAKE_XOR_OF_ARRAY_EQUAL_K_H
#define BIT_MANIPULATION_COUNT_OPERATIONS_TO_MAKE_XOR_OF_ARRAY_EQUAL_K_H
#include <vector>
// You are given a 0-indexed integer array nums and a positive integer k.
// You can apply the following operation on the array any number of times:
// Choose any element of the array and flip a bit in its binary representation.
// Return the minimum number of operations required to make the bitwise XOR of all elements of
// the final array equal to k.
// Note that you can flip leading zero bits in the binary representation of elements.
// For example, for the number (101)2 you can flip the fourth bit and obtain (1101)2.
bool is_bit_set(int index, int number)
{
    return ((number >> index) & 1);
}

int count_operations(const std::vector<int>& input, int k) {
    int x_or{};
    for(const auto & element: input)
        x_or ^= element;
    int count{};
    for(int i{}; i< 32; ++i)
    {
        if(is_bit_set(i, x_or) == is_bit_set(i, k))
            continue;
        count++;
    }
    return count;

}

#endif //BIT_MANIPULATION_COUNT_OPERATIONS_TO_MAKE_XOR_OF_ARRAY_EQUAL_K_H
