//
// Created by andreas on 01.03.25.
//

#ifndef NO_SAME_ADJACENT_CHARS_H
#define NO_SAME_ADJACENT_CHARS_H
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
#include <string>
#include <vector>
#include <queue>

std::string no_equal_adjacent_chars(const std::string & s) {
    std::vector<int> char_count(26, 0);
    for(const auto c: s)
    {
        char_count[c-'a']++;
    }
    std::priority_queue<std::pair<int, char>> queue;
    for(int i{}; i < 26; ++i)
    {
        if(char_count[i])
        {
            queue.emplace(char_count[i], i+'a');
        }
    }
    std::string result{};
    while(!queue.empty())
    {
        auto freq_char1 = queue.top();
        queue.pop();
        if(result.empty() || freq_char1.second != result.back())
        {
            result += freq_char1.second;
            if((freq_char1.first - 1) > 0)
                queue.emplace(freq_char1.first-1, freq_char1.second);
        }
        else
        {
            // We choose the next character because the first one (above) is at the end of the result-string.
            if(queue.empty())
                return "";
            auto freq_char2 = queue.top();
            queue.pop();
            result += freq_char2.second;
            if((freq_char2.first - 1) > 0)
                queue.emplace(freq_char2.first-1, freq_char2.second);
            // We did not use freq_char1, so we put it back again
            queue.push(freq_char1);

        }
    }
    return result;

}

#endif //NO_SAME_ADJACENT_CHARS_H
