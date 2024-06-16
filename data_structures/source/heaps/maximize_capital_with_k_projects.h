//
// Created by andreas on 16.06.24.
//

#ifndef DATA_STRUCTURES_MAXIMIZE_CAPITAL_WITH_K_PROJECTS_H
#define DATA_STRUCTURES_MAXIMIZE_CAPITAL_WITH_K_PROJECTS_H
// Suppose you want to start a IPO soon. In order to sell a good price of its shares to Venture Capital, you
// would like to work on some projects to increase its capital before the IPO. Since it has limited resources,
// it can only finish at most k distinct projects before the IPO. Help design the best way to maximize its total
// capital after finishing at most k distinct projects.
// You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i]
// is needed to start it. Initially, you have w capital. When you finish a project, you will obtain its pure profit
// and the profit will be added to your total capital. Pick a list of at most k distinct projects from given
// projects to maximize your final capital, and return the final maximized capital.
// The answer is guaranteed to fit in a 32-bit signed integer.
#include <vector>
#include <queue>

int maximize_capital(int k, int start_capital, std::vector<int> &profits, std::vector<int> &capital) {
    int number_of_projects = profits.size();
    std::vector<std::pair<int, int>> projects;
    for (int i{}; i < number_of_projects; ++i) {
        projects.emplace_back(capital[i], profits[i]);
    }
    std::sort(projects.begin(), projects.end());
    std::priority_queue<int> q;
    int index{};
    for (int i{}; i < k; ++i) {
        while (index < number_of_projects && projects[index].first <= start_capital) {
            q.push(projects[index].second);
            index++;
        }
        if (q.empty())
            break;
        start_capital += q.top();
        q.pop();
    }
    return start_capital;
}

#endif //DATA_STRUCTURES_MAXIMIZE_CAPITAL_WITH_K_PROJECTS_H
