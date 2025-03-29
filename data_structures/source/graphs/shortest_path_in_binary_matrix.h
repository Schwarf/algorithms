//
// Created by andreas on 03.08.24.
//

#ifndef DATA_STRUCTURES_SHORTEST_PATH_IN_BINARY_MATRIX_H
#define DATA_STRUCTURES_SHORTEST_PATH_IN_BINARY_MATRIX_H
// Given an n x n binary matrix determine the shortest path from [0, 0] to [n-1, n-1]. All 8 directions from a cell are allowed.
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell
// (i.e., (n - 1, n - 1)) such that all the visited cells of the path are 0.

#include <vector>
#include <queue>

// For debugging purpose we track the path
inline std::vector<std::pair<int, int>>
reconstruct_path(std::vector<std::vector<std::pair<int, int>>> &parent, int n) {
    std::vector<std::pair<int, int>> path;
    for (int x = n - 1, y = n - 1; parent[x][y] != std::make_pair(x, y);) {
        path.emplace_back(x, y);
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    path.emplace_back(0, 0); // add the start node
    std::reverse(path.begin(), path.end());
    return path;
}

inline int shortest_path_binary_matrix_bfs(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    if (matrix[0][0] == 1 || matrix[n - 1][n - 1])
        return -1;
    if (n == 1)
        return 1;

    int length{};
    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);
    // We use the 1 value as block for already visited nodes.
    matrix[0][0] = 1;
    std::vector<std::pair<int, int>> directions = {{1,  1},
                                                   {1,  -1},
                                                   {-1, -1},
                                                   {-1, 1},
                                                   {1,  0},
                                                   {-1, 0},
                                                   {0,  1},
                                                   {0,  -1}};


    while (!q.empty()) {
        int q_size = q.size();
        length++;
        while (q_size--) {
            auto [row, column] = q.front();
            q.pop();

            if (row == n - 1 && column == n - 1) {
                return length;
            }

            for (const auto &[dx, dy]: directions) {

                int nx = row + dx, ny = column + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && matrix[nx][ny] == 0) {
                    matrix[nx][ny] = 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    return -1;
}


inline int astar_algorithm(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.emplace(n - 1, 0); // Chebyshev Distance: h=max( abs(n−1−0),abs(n−1−0)) = n−1
    std::vector<int> distances(n * n, std::numeric_limits<int>::max());
    // Each node costs one
    distances[0] = 1;
    std::vector<std::pair<int, int>> directions = {{1,  1},
                                                   {1,  -1},
                                                   {-1, -1},
                                                   {-1, 1},
                                                   {1,  0},
                                                   {-1, 0},
                                                   {0,  1},
                                                   {0,  -1}};
    while (!q.empty()) {
        auto current = q.top();
        q.pop();
        int current_idx = current.second;
        int x = current_idx / n;
        int y = current_idx % n;

        // If we reach the goal
        if (x == n - 1 && y == n - 1) {
            return distances[current_idx];
        }

        // Skip processing if already visited

        // Explore all possible directions
        for (const auto &dir: directions) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && matrix[new_x][new_y] == 0) {
                int new_idx = new_x * n + new_y;
                int new_distance = distances[current_idx] + 1;
                if (new_distance < distances[new_idx]) {
                    distances[new_idx] = new_distance;
                    int heuristic = std::max(std::abs(n - 1 - new_x) , std::abs(n - 1 - new_y)); // Chebyshev distance to goal
                    q.emplace(new_distance + heuristic, new_idx);
                }

            }
        }
    }
    return -1;
}

inline int shortest_path_binary_matrix_astar(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    if (matrix[0][0] || matrix[n - 1][n - 1])
        return -1;
    return astar_algorithm(matrix);
}


#endif //DATA_STRUCTURES_SHORTEST_PATH_IN_BINARY_MATRIX_H

