//
// Created by andreas on 14.08.24.
//

#ifndef BINARY_SEARCH_FIND_KTH_SMALLEST_DISTANCE_H
#define BINARY_SEARCH_FIND_KTH_SMALLEST_DISTANCE_H
#include <vector>
#include <map>
int smallest_distance_pair_brute_force1(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    std::map<int, int> distances;
    for(int i{}; i < n-1; ++i)
    {
        for(int j{i+1}; j < n; ++j)
        {
            distances[std::abs(nums[i] - nums[j])]++;
        }
    }
    int count{};
    for(const auto & [distance, frequency]: distances)
    {
        for(int i{}; i < frequency; ++i)
        {
            count++;
            if(count == k)
                return distance;
        }
    }
    return {};

}


int smallest_distance_pair_brute_force2(std::vector<int>& nums, int k) {
    int arraySize = nums.size();

    int maxElement = *max_element(nums.begin(), nums.end());

    std::vector<int> distance_bucket(maxElement + 1, 0);

    for (int i = 0; i < arraySize; ++i) {
        for (int j = i + 1; j < arraySize; ++j) {
            // Compute the distance between nums[i] and nums[j]
            int distance = abs(nums[i] - nums[j]);

            ++distance_bucket[distance];
        }
    }

    for (int dist = 0; dist <= maxElement; ++dist) {
        k -= distance_bucket[dist];

        if (k <= 0) {
            return dist;
        }
    }
    return -1;
}
#endif //BINARY_SEARCH_FIND_KTH_SMALLEST_DISTANCE_H
