//
// Created by andreas on 13.08.24.
//

#ifndef BACKTRACKING_FIND_ALL_COMBINATIONS_TO_SUM_UP_TO_TARGET_H
#define BACKTRACKING_FIND_ALL_COMBINATIONS_TO_SUM_UP_TO_TARGET_H
// You are given an integer array and a target number. Find all combinations of array-elements that sum up to the target
// number. Each element can only be used once.
#include <vector>
#include <set>

template <typename T>
requires std::is_integral_v<T>
std::vector<std::vector<T>> find_all_combinations_brute_force(std::vector<T> & input, T target)
{
    std::sort(input.begin(), input.end());
    std::set<std::vector<int>> results;
    int n = input.size();
    int total_sub_sets = 1 << n; // 2^n subsets

    for (int i = 0; i < total_sub_sets; i++) {
        std::vector<int> current_sub_set;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {  // Check if the j-th element is included in the subset
                current_sub_set.push_back(input[j]);
                sum += input[j];
            }
        }
        if (sum == target) {
            // Sort current subset to normalize its order for set insertion
            std::sort(current_sub_set.begin(), current_sub_set.end());
            results.insert(current_sub_set);
        }
    }

    return std::vector<std::vector<int>>(results.begin(), results.end());
}


template <typename T>
void get_combinations(std::vector<std::vector<T>> & results, std::vector<T>& current_combination, std::vector<T> & input, T target, int index)
{
    if(target ==0) {
        results.push_back(current_combination);
        return;
    }
    for (int i = index; i < input.size() && target >= input[i];
         ++i) {
        if (i == index || input[i] != input[i - 1]) {
            current_combination.push_back(input[i]);
            get_combinations(results, current_combination, input, target - input[i], i + 1);
            current_combination.pop_back();
        }
    }


}

template <typename T>
requires std::is_integral_v<T>
std::vector<std::vector<T>> find_all_combinations_backtracking(std::vector<T> & input, T target)
{
    std::sort(input.begin(), input.end());
    std::vector<std::vector<T>> results;
    std::vector<T> current_combination;
    get_combinations(results, current_combination, input, target, 0);
    return results;
}


#endif //BACKTRACKING_FIND_ALL_COMBINATIONS_TO_SUM_UP_TO_TARGET_H
