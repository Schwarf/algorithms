//
// Created by andreas on 21.06.24.
//

#ifndef BINARY_SEARCH_MINIMUM_NUMBER_OF_DAYS_H
#define BINARY_SEARCH_MINIMUM_NUMBER_OF_DAYS_H
// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be
// used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden.
// If it is impossible to make m bouquets return -1.
#include <vector>

int get_number_of_bouquets(std::vector<int> &bloom_days, int mid, int flowers_per_bouquet) {
    int number_of_bouquets{};
    int count{};
    for (int i{}; i < bloom_days.size(); ++i) {
        if (bloom_days[i] <= mid)
            count++;
        else
            count = 0;

        if (count == flowers_per_bouquet) {
            number_of_bouquets++;
            count = 0;
        }
    }
    return number_of_bouquets;
}


int minimal_days(std::vector<int> &bloom_days, int required_bouquets, int flowers_per_bouquet) {
    // First we determine the search space by extracting the earliest and the latest day a flower blooms.
    int left{std::numeric_limits<int>::max()};
    int right{std::numeric_limits<int>::min()};
    for (const auto day: bloom_days) {
        left = std::min(left, day);
        right = std::max(right, day);
    }

    // Now we start the binary search in the before determined search space.
    int minimal_days{-1};
    while (left <= right) {
        int mid = (right + left) / 2;
        // For each mid_value we compute how many bouquets we can generate. If
        // we exceed the number of required bouquets we store the current value and
        //
        if (get_number_of_bouquets(bloom_days, mid, flowers_per_bouquet) >= required_bouquets) {
            minimal_days = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }
    return minimal_days;

}

#endif //BINARY_SEARCH_MINIMUM_NUMBER_OF_DAYS_H
