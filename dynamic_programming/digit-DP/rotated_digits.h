//
// Created by andreas on 28.09.26.
//

#ifndef BEHAVIORAL_PATTERNS_ROTATED_DIGITS_H
#define BEHAVIORAL_PATTERNS_ROTATED_DIGITS_H
// An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.
//
// A number is valid if each digit remains a digit after rotation. For example:
//
//     0, 1, and 8 rotate to themselves,
//     2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
//     6 and 9 rotate to each other, and
//     the rest of the numbers do not rotate to any other number and become invalid.
//
// Given an integer n, return the number of good integers in the range [1, n].
#include <vector>
#include <string>

int dfs(const std::string& digits,
        int pos,
        bool tight,
        bool changed,
        std::vector<std::vector<int>>& dp)
{
    if (pos == digits.size())
        return changed ? 1 : 0;

    if (!tight && dp[pos][changed] != -1)
        return dp[pos][changed];

    int limit = tight ? digits[pos] - '0' : 9;
    int result = 0;

    for (int digit = 0; digit <= limit; ++digit) {

        if (digit == 3 || digit == 4 || digit == 7)
            continue;

        bool newChanged =
            changed ||
            digit == 2 ||
            digit == 5 ||
            digit == 6 ||
            digit == 9;

        bool newTight =
            tight && (digit == limit);

        result += dfs(
            digits,
            pos + 1,
            newTight,
            newChanged,
            dp
        );
    }

    if (!tight)
        dp[pos][changed] = result;

    return result;
}

int rotated_digits(int n)
{
    std::string digits = std::to_string(n);

    std::vector<std::vector<int>> dp(
        digits.size(),
        std::vector<int>(2, -1)
    );

    return dfs(digits, 0, true, false, dp);
}
#endif // BEHAVIORAL_PATTERNS_ROTATED_DIGITS_H
