//
// Created by andreas on 22.06.25.
//

#ifndef MINIMUM_WINDOW_SUBSTRING_H
#define MINIMUM_WINDOW_SUBSTRING_H
// Given two strings s and t of lengths m and n respectively, return the minimum window
// of s such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string "".
// Expect an input that generates unique answers
#include <string>
#include <unordered_map>
std::string minWindow(std::string s, std::string t) {
    if(s.length() == 0 || t.length() == 0)
        return {};
    std::unordered_map<char, int> map;
    for(const auto c: t)
        map[c]++;
    int required_unique_chars = map.size();
    int frequency_matches_count = 0;
    std::unordered_map <char, int> window_counts;
    int result_data[3] = {-1, 0, 0};
    int left{};
    int right{};
    while(right < s.length())
    {
        auto c = s[right];
        window_counts[c]++;
        if(map.find(c) != map.end() && window_counts[c] == map[c])
            frequency_matches_count++;

        while(left <= right && frequency_matches_count == required_unique_chars)
        {
            c = s[left];
            if(result_data[0] == -1 || right-left + 1 < result_data[0])
            {
                result_data[0] = right -left +1;
                result_data[1] = left;
                result_data[2] = right;
            }
            window_counts[c]--;
            if(map.find(c) != map.end() && window_counts[c] < map[c])
                frequency_matches_count--;
            left++;
        }
        right++;
    }
    return result_data[0] == -1 ? "" : s.substr(result_data[1], result_data[2] - result_data[1] + 1);
}

#endif //MINIMUM_WINDOW_SUBSTRING_H
