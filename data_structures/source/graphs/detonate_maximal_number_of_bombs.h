//
// Created by andreas on 04.06.24.
//

#ifndef DATA_STRUCTURES_DETONATE_MAXIMAL_NUMBER_OF_BOMBS_H
#define DATA_STRUCTURES_DETONATE_MAXIMAL_NUMBER_OF_BOMBS_H
// You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt.
// This area is in the shape of a circle with the center as the location of the bomb.
// The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote
// the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.
// You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range.
// These bombs will further detonate the bombs that lie in their ranges.
// Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to
// detonate only one bomb.
#include <vector>
#include <queue>
#include <stack>

int maximum_number_bfs(std::vector<std::vector<int>> &bombs) {

    const int n = bombs.size();
    std::vector<std::vector<int>> graph(n);

    auto square_distance = [](const std::vector<int> &bomb1, const std::vector<int> &bomb2) {
        return static_cast<long long>(bomb1[0] - bomb2[0]) * (bomb1[0] - bomb2[0])
               + static_cast<long long>(bomb1[1] - bomb2[1]) * (bomb1[1] - bomb2[1]);
    };
    // compute connections aka build graph
    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j) {
            if (i == j)
                continue;

            const long long radius = bombs[i][2];
            if (radius * radius >= square_distance(bombs[i], bombs[j]))
                graph[i].push_back(j);
        }
    }

    int max_count{};

    for (int i{}; i < n; ++i) {
        std::queue<int> q;
        std::vector<bool> visited(n);
        q.push(i);
        int count{};
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            if (visited[current])
                continue;
            visited[current] = true;
            // we only add just visited bombs
            count++;
            for (const auto neighbor: graph[current]) {
                if (visited[neighbor])
                    continue;
                q.push(neighbor);
            }
        }
        max_count = std::max(count, max_count);
    }
    return max_count;
}

int maximum_number_dfs(std::vector<std::vector<int>> &bombs) {

    const int n = bombs.size();
    std::vector<std::vector<int>> graph(n);

    auto square_distance = [](const std::vector<int> &bomb1, const std::vector<int> &bomb2) {
        return static_cast<long long>(bomb1[0] - bomb2[0]) * (bomb1[0] - bomb2[0])
               + static_cast<long long>(bomb1[1] - bomb2[1]) * (bomb1[1] - bomb2[1]);
    };
    // compute connections aka build graph
    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j) {
            if (i == j)
                continue;

            const long long radius = bombs[i][2];
            if (radius * radius >= square_distance(bombs[i], bombs[j]))
                graph[i].push_back(j);
        }
    }

    int max_count{};

    for (int i{}; i < n; ++i) {
        std::stack<int> s;
        std::vector<bool> visited(n);
        s.push(i);
        int count{};
        while (!s.empty()) {
            auto current = s.top();
            s.pop();
            if (visited[current])
                continue;
            visited[current] = true;
            // we only add just visited bombs
            count++;
            for (const auto neighbor: graph[current]) {
                if (visited[neighbor])
                    continue;
                s.push(neighbor);
            }
        }
        max_count = std::max(count, max_count);
    }
    return max_count;
}


#endif //DATA_STRUCTURES_DETONATE_MAXIMAL_NUMBER_OF_BOMBS_H
