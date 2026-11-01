//
// Created by andreas on 01.11.26.
//

#ifndef ALGORITHMS_MINIMUM_MOVE_TO_EQUAL_ARRAY_ELEMENTS_H
#define ALGORITHMS_MINIMUM_MOVE_TO_EQUAL_ARRAY_ELEMENTS_H
// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
// In one move, you can increment n - 1 elements of the array by 1.
#include <vector>
#include <limits>

// This is a trick question. Instead of incrementing n-1 elements one can decrement just one element. That
// is an equivalent move. With this we can simply compute to the distance to the minimum element of the array, which
// is the equivalent to the task
int minimum_moves(const std::vector<int> & input)
{
    int min = std::numeric_limits<int>::max();
    for (const auto element: input)
    {
        min  = std::min(min, element);
    }
    int moves{};
    for (auto element: input)
    {
        moves += element - min;
    }
    return moves;
}


#endif // ALGORITHMS_MINIMUM_MOVE_TO_EQUAL_ARRAY_ELEMENTS_H
