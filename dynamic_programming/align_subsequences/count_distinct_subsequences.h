//
// Created by andreas on 12.07.26.
//

#ifndef ALGORITHMS_COUNT_DISTINCT_SUBSEQUENCES_H
#define ALGORITHMS_COUNT_DISTINCT_SUBSEQUENCES_H

#include <string>
#include <vector>

int count_distinct_subsequences(const std::string& source, const std::string& target)
{
    int n_s = source.size();
    int n_t = target.size();

    std::vector<std::vector<int>> dp(n_t + 1, std::vector<int>(n_s + 1));
    // to form an empty target from any source prefix, there is exactly one way ... choose no character from source
    for (int j{}; j < n_s + 1; ++j)
        dp[0][j] = 1;
    // to form a non-empty target from an empty source, there is now way
    for (int i{1}; i < n_t + 1; ++i)
        dp[i][0] = 0;

    for (int i{1}; i <= n_t; ++i)
    {
        for (int j{1}; j <= n_s; ++j)
        {
            if (source[j - 1] == target[i - 1])
                // Since s[j - 1] matches t[i - 1], count both possibilities:
                // 1. Use s[j - 1] to match t[i - 1]:
                //    dp[i - 1][j - 1]
                // 2. Skip s[j - 1] and form the same target prefix from the earlier source prefix:
                //    dp[i][j - 1]
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[n_t][n_s];
}

#endif // ALGORITHMS_COUNT_DISTINCT_SUBSEQUENCES_H
