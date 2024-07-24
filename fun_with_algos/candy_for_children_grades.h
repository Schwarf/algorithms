//
// Created by andreas on 13.09.23.
//

#ifndef CANDY_FOR_CHILDREN_GRADES_H
#define CANDY_FOR_CHILDREN_GRADES_H
// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

// #GREEDY
#include <vector>
#include <concepts>

template<typename T>
requires std::is_signed_v<T>
T total_candy(const std::vector<T> &grades) {
    int n = grades.size();
    // each child gets at least one candy
    int candy = n;
    int i{1};
    while (i < n) {
        if (grades[i] == grades[i - 1]) {
            i++;
            continue;
        }
        int peak{};
        while ((i < n) && grades[i] > grades[i - 1]) {
            peak++;
            candy += peak;
            i++;
        }
        int valley{};
        while ((i < n) && grades[i] < grades[i - 1]) {
            valley++;
            candy += valley;
            i++;
        }
        candy -= std::min(peak, valley);
    }
    return candy;

}

#endif //CANDY_FOR_CHILDREN_GRADES_H
