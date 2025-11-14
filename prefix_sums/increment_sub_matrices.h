//
// Created by andreas on 14.11.25.
//

// You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.
// You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:
// Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.
// Return the matrix mat after performing every query.

#ifndef ALGORITHMS_INCREMENT_SUB_MATRICES_H
#define ALGORITHMS_INCREMENT_SUB_MATRICES_H
#include <vector>

template <typename T>
std::vector<std::vector<T>> add_queries(int n, std::vector<std::vector<int>> & queries)
{
    std::vector difference(n + 1, std::vector<int>(n + 1));
    // For each query [row1, col1, row2, col2], which means
    // “add 1 to all cells in the submatrix from (row1, col1) to (row2, col2)”,
    // we update diff like this:
    for (const auto& query : queries) {
        int row1 = query[0];
        int col1 = query[1];
        int row2 = query[2];
        int col2 = query[3];
        difference[row1][col1] += 1;
        difference[row2 + 1][col1] -= 1;
        difference[row1][col2 + 1] -= 1;
        difference[row2 + 1][col2 + 1] += 1;
    }
    std::vector result(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int all_above_i = (i == 0) ? 0 : result[i - 1][j];
            int all_left_j = (j == 0) ? 0 : result[i][j - 1];
            int remove_double_count = (i == 0 || j == 0) ? 0 : result[i - 1][j - 1];
            result[i][j] = difference[i][j] + all_above_i + all_left_j - remove_double_count;
        }
    }
    return result;
}
#endif //ALGORITHMS_INCREMENT_SUB_MATRICES_H