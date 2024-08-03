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

int shortest_path_binray_matrix_bfs(std::vector<std::vector<int>> &matrix) {
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
    while (!q.empty()) {
        int q_size = q.size();
        length++;
        while (q_size--) {
            auto [row, column] = q.front();
            q.pop();
            if (row == n - 1 && column == n - 1)
                return length;
            if (row + 1 < n && column + 1 < n && matrix[row + 1][column + 1] == 0) {
                matrix[row + 1][column + 1] = 1;
                q.emplace(row + 1, column + 1);
            }
            if (row + 1 < n && column - 1 > -1 && matrix[row + 1][column - 1] == 0) {
                matrix[row + 1][column - 1] = 1;
                q.emplace(row + 1, column - 1);
            }
            if (row - 1 > -1 && column - 1 > -1 && matrix[row - 1][column - 1] == 0) {
                matrix[row - 1][column - 1] = 1;
                q.emplace(row - 1, column - 1);
            }
            if (row - 1 > -1 && column + 1 < n && matrix[row - 1][column + 1] == 0) {
                matrix[row - 1][column + 1] = 1;
                q.emplace(row - 1, column + 1);
            }
            if (row + 1 < n && matrix[row + 1][column] == 0) {
                matrix[row + 1][column] = 1;
                q.emplace(row + 1, column);
            }
            if (row - 1 > -1 && matrix[row - 1][column] == 0) {
                matrix[row - 1][column] = 1;
                q.emplace(row - 1, column);
            }
            if (column + 1 < n && matrix[row][column + 1] == 0) {
                matrix[row][column + 1] = 1;
                q.emplace(row, column + 1);
            }
            if (column - 1 > -1 && matrix[row][column - 1] == 0) {
                matrix[row][column - 1] = 1;
                q.emplace(row, column - 1);
            }

        }
    }
    return -1;
}


#endif //DATA_STRUCTURES_SHORTEST_PATH_IN_BINARY_MATRIX_H
