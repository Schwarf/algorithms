//
// Created by andreas on 12.05.23.
//

#ifndef MAXIMUM_POINTS_SOLVED_WITH_BRAIN_POWER_H
#define MAXIMUM_POINTS_SOLVED_WITH_BRAIN_POWER_H

#include <vector>
#include <concepts>
//You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
//The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.
//For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
//If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
//If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
//Return the maximum points you can earn for the exam.

template<typename T>
requires std::is_integral_v<T>
long long maximum_points_solved_with_brain_power(std::vector<std::vector<T>> &questions) {
    int n = questions.size();
    std::vector<long long> dp(n);
    dp[n - 1] = questions[n - 1][0];

    for (int i = n - 2; i > -1; --i) {
        dp[i] = questions[i][0];
        T skip = questions[i][1];
        if (i + skip + 1 < n) {
            dp[i] += dp[i + skip + 1];
        }

        // dp[i] = max(solve it, skip it)
        dp[i] = std::max(dp[i], dp[i + 1]);
    }

    return dp[0];
}

#endif //MAXIMUM_POINTS_SOLVED_WITH_BRAIN_POWER_H
