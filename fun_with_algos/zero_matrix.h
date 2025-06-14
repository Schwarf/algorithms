//
// Created by andreas on 14.06.25.
//

#ifndef ZERO_MATRIX_H
#define ZERO_MATRIX_H
// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to 0.
#include <vector>
#include <unordered_set>

void zero_matrix(std::vector<std::vector<int>>& matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();
    std::unordered_set<int> zero_cols;
    std::unordered_set<int> zero_rows;
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            if (matrix[row][col] == 0)
            {
                zero_cols.insert(col);
                zero_rows.insert(row);
            }
        }
    }

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            if (zero_cols.contains(col) || zero_rows.contains(row))
            {
                matrix[row][col] = 0;
            }
        }
    }
}

void zero_matrix_optimized(std::vector<std::vector<int>>& matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();
    bool first_column_contains_zero{};
    bool first_row_contains_zero{};
    for (int row = 0; row < rows; ++row)
    {
        if (matrix[row][0] == 0)
        {
            first_column_contains_zero = true;
            break;
        }
    }

    for (int col = 0; col < rows; ++col)
    {
        if (matrix[0][col] == 0)
        {
            first_row_contains_zero = true;
            break;
        }
    }

    for (int row = 1; row < rows; ++row)
    {
        for (int col = 1; col < columns; ++col)
        {
            if (matrix[row][col] == 0)
            {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    for (int row = 1; row < rows; ++row)
    {
        for (int col = 1; col < columns; ++col)
        {
            if (matrix[row][0] == 0 || matrix[0][col] == 0)
            {
                matrix[row][col] = 0;
            }
        }
    }
    if (first_column_contains_zero)
    {
        for (int row = 0; row < rows; ++row)
        {
            matrix[row][0] = 0;
        }
    }

    if (first_row_contains_zero)
    {
        for (int col = 0; col < rows; ++col)
        {
            matrix[0][col] = 0;
        }
    }
}

#endif //ZERO_MATRIX_H
