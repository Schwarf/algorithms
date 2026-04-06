//
// Created by andreas on 22.06.25.
//

#ifndef MINIMUM_WINDOW_SUBSTRING_H
#define MINIMUM_WINDOW_SUBSTRING_H
// Given two strings s and t of lengths m and n respectively, return the minimum window
// of s such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string "".
// Expect an input that generates unique answers
#include <limits>
#include <string>
#include <unordered_map>

std::string minimum_window_substring(std::string s, std::string t)
{
    if (s.length() == 0 || t.length() == 0)
        return {};
    std::unordered_map<char, int> count_t;
    for (const auto c : t)
        count_t[c]++;
    int required_unique_chars = count_t.size();
    int need = 0;
    std::unordered_map<char, int> window;
    std::pair<int, int> result{-1, -1};
    int result_size = std::numeric_limits<int>::max();
    int left{};
    int right{};
    while (right < s.length())
    {
        auto c = s[right];
        window[c]++;
        if (count_t.find(c) != count_t.end() && window[c] == count_t[c])
            need++;

        while (left <= right && need == required_unique_chars)
        {
            c = s[left];
            if (right - left + 1 < result_size)
            {
                result_size = right - left + 1;
                result = {left, right};
            }
            window[c]--;
            if (count_t.find(c) != count_t.end() && window[c] < count_t[c])
                need--;
            left++;
        }
        right++;
    }
    return result_size == std::numeric_limits<int>::max() ? "" : s.substr(result.first, result_size);
}

#endif //MINIMUM_WINDOW_SUBSTRING_H
