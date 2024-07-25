//
// Created by andreas on 25.04.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_LONGEST_IDEAL_STRING_SUBSEQUENCE_H
#define DYNAMIC_PROGRAMMING_SAMPLES_LONGEST_IDEAL_STRING_SUBSEQUENCE_H

#include <string>
#include <vector>

// You are given a string s consisting of lowercase letters and an integer k.
// We call a string t ideal if the following conditions are satisfied:
//  - t is a subsequence of the string s.
//  - The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
// Return the length of the longest ideal string.
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing
// the order of the remaining characters.
// Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a'
// and 'z' is 25, not 1.

int dfs(int index, int character, std::vector<std::vector<int>> &dp, std::string &input, int k) {
    if (dp[index][character] != -1)
        return dp[index][character];

    dp[index][character] = 0;
    auto does_match = (character == (input[index] - 'a'));
    if (does_match)
        dp[index][character] = 1;

    if (index > 0) {
        dp[index][character] = dfs(index - 1, character, dp, input, k);
        if (does_match) {
            for (int char_index{}; char_index < 26; ++char_index) {
                if (std::abs(character - char_index) <= k) {
                    dp[index][character] = std::max(dp[index][character], 1 + dfs(index - 1, char_index, dp, input, k));
                }
            }
        }
    }
    return dp[index][character];
}

//int longest_ideal_string_top_down(std::string &input, int k) {
//    int n = input.size();
//    std::vector<std::vector<int>> dp(n, std::vector<int>(26, -1));
//
//    int result{};
//    for (int character{}; character < 26; ++character) {
//        result = std::max(result, dfs(n - 1, character, dp, input, k));
//    }
//
//}


int longest_ideal_string_bottom_up(std::string s, int k) {
    int n = s.size();
    std::vector<int> dp(26, 0);

    int result{};
    // Updating dp with the i-th character
    for (int i{}; i < n; i++) {
        int current = s[i] - 'a';
        int best{};
        for (int prev{}; prev < 26; prev++) {
            if (abs(prev - current) <= k) {
                best = std::max(best, dp[prev]);
            }
        }

        // Appending s[i] to the previous longest ideal subsequence allowed
        dp[current] = std::max(dp[current], best + 1);
        result = std::max(result, dp[current]);
    }
    return result;
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_LONGEST_IDEAL_STRING_SUBSEQUENCE_H
