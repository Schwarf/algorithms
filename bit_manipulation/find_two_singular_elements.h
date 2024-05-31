//
// Created by andreas on 31.05.24.
//

#ifndef BIT_MANIPULATION_FIND_TWO_SINGULAR_ELEMENTS_H
#define BIT_MANIPULATION_FIND_TWO_SINGULAR_ELEMENTS_H
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly
// twice. Find the two elements that appear only once. You can return the answer in any order.
// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
#include <vector>

std::vector<int> find_singular_elements(std::vector<int> &input) {
    int x_or{};
    for (const auto element: input) {
        x_or ^= element;
    }
    int right_most_bit = x_or & ~(x_or - 1);
    int number1{};
    int number2{};
    for (const auto element: input) {
        if (element & right_most_bit)
            number1 ^= element;
        else
            number2 ^= element;
    }
    return {number1, number2};
}

#endif //BIT_MANIPULATION_FIND_TWO_SINGULAR_ELEMENTS_H
