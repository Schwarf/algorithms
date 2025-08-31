//
// Created by andreas on 31.08.25.
//

#ifndef ALGORITHMS_SUDOKO_SOLVER_H
#define ALGORITHMS_SUDOKO_SOLVER_H
#include <array>
#include <functional>
#include <vector>


// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
//     Each of the digits 1-9 must occur exactly once in each row.
//     Each of the digits 1-9 must occur exactly once in each column.
//     Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//
// The '.' character indicates empty cells.


void solve_sudoku(std::vector<std::vector<char>>& board)
{
    constexpr int N = 9;
    constexpr int n = 3;

    std::array<std::array<int, N + 1>, N> rows{};
    std::array<std::array<int, N + 1>, N> columns{};
    std::array<std::array<int, N + 1>, N> boxes{};
    bool sudoku_solved = false;
    auto box_index = [&](int r, int c) { return (r / n) * n + c / n; };

    auto place_number = [&](int digit, int row, int col)
    {
        int index = box_index(row, col);
        rows[row][digit] = 1;
        columns[col][digit] = 1;
        boxes[index][digit] = 1;
        board[row][col] = (char)(digit + '0');
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char num = board[i][j];
            if (num != '.')
            {
                int digit = num - '0';
                place_number(digit, i, j);
            }
        }
    }
    auto can_place = [&](int digit, int row, int col) -> bool
    {
        int index = box_index(row, col);
        return rows[row][digit] + columns[col][digit] + boxes[index][digit] == 0;
    };

    std::function<void(int,int)> backtrack; // declare first

    auto place_next_number = [&](int row, int col)
    {
        if (row == N - 1 && col == N - 1) { sudoku_solved = true; return; }


        int next_row = (col == N - 1) ? row + 1 : row;
        int next_col = (col == N - 1) ? 0  : col + 1;
        backtrack(next_row, next_col);
    };

    auto remove_number = [&](int digit, int row, int col)
    {
        int index = box_index(row, col);
        rows[row][digit] = 0;
        columns[col][digit] = 0;
        boxes[index][digit] = 0;
        board[row][col] = '.';
    };


    backtrack = [&](int row, int col)
    {
        if (board[row][col] != '.')
        {
            place_next_number(row, col);
            return;
        }

        for (int digit =1 ; digit< 10; ++digit)
        {
            if(can_place(digit, row, col))
            {
                place_number(digit, row, col);
                place_next_number(row, col);
                if (!sudoku_solved)
                    remove_number(digit, row, col);
            }
        }
    };

    backtrack(0, 0);
}

#endif //ALGORITHMS_SUDOKO_SOLVER_H