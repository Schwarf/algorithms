//
// Created by andreas on 13.04.24.
//

#ifndef DATA_STRUCTURES_FIND_MAX_RECTANGLE_H
#define DATA_STRUCTURES_FIND_MAX_RECTANGLE_H
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing
// only 1's and return its area.
#include <vector>
#include <stack>

int largest_rectangle_area_in_histogram(const std::vector<int> &histogram) {
    int result{};
    std::stack<int> s;

    for (int i{}; i <= histogram.size(); ++i) {
        while (!s.empty() &&
               (i == histogram.size() || histogram[s.top()] > histogram[i])) {
            const int height = histogram[s.top()];
            s.pop();
            const int width = s.empty() ? i : i - s.top() - 1;
            result = std::max(result, height * width);
        }
        s.push(i);
    }

    return result;
}

int maximal_rectangle(std::vector<std::vector<char>> &grid) {
    if (grid.empty())
        return 0;

    int result{};
    std::vector<int> current_histogram(grid[0].size());

    for (const auto &row: grid) {
        // Computing current_histogram for each row
        for (int i{}; i < row.size(); ++i) {
            current_histogram[i] = row[i] == '0' ? 0 : current_histogram[i] + 1;
        }
        result = std::max(result, largest_rectangle_area_in_histogram(current_histogram));
    }

    return result;
}

#endif //DATA_STRUCTURES_FIND_MAX_RECTANGLE_H
