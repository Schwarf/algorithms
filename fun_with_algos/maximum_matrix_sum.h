//
// Created by andreas on 24.11.24.
//

#ifndef MAXIMUM_MATRIX_SUM_H
#define MAXIMUM_MATRIX_SUM_H
// You are given an n x n integer matrix. You can do the following operation any number of times:
// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.
// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements
// using the operation mentioned above.
#include <limits>
#include <vector>
#include <cmath>

long long maximum_matrix_sum(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    long long sum{};
    int min = std::numeric_limits<int>::max();
    int negative_count{};
    for(int r{}; r < n; ++r)
    {
        for(int c{}; c < n; ++c)
        {
            if(matrix[r][c] <= 0)
                negative_count++;
            min = std::min(min, std::abs(matrix[r][c]));
            sum += std::abs(matrix[r][c]);
        }
    }
    if(negative_count & 1)
        return sum-2*min;
    return sum;
}

#endif //MAXIMUM_MATRIX_SUM_H
