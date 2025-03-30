//
// Created by andreas on 30.09.23.
//

#ifndef INC_132_PATTERN_H
#define INC_132_PATTERN_H
#include <concepts>
#include <vector>
#include <stack>
// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k]
// such that i < j < k and nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.
template <typename T>
    requires std::is_signed_v<T>
bool find_132_pattern(const std::vector<T>& nums)
{
    std::stack<T> s;
    int third = std::numeric_limits<T>::min();

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] < third) return true;
        while (!s.empty() && s.top() < nums[i])
        {
            third = s.top();
            s.pop();
        }
        s.push(nums[i]);
    }
    return false;
}

#endif //INC_132_PATTERN_H
