//
// Created by andreas on 04.06.22.
//

#ifndef QUEENS_PROBLEM_H
#define QUEENS_PROBLEM_H

#include <vector>
#include <string>

void depth_first_search(std::vector<std::vector<std::vector<int>>> &solutions,
                        std::vector<int> &queens,
                        int current_row,
                        int board_size,
                        std::vector<bool> &invalid_columns,
                        std::vector<bool> &invalid_forward_diagonals,
                        std::vector<bool> &invalid_backward_diagonals) {
    if (current_row == board_size) {
        std::vector<std::vector<int>> board(board_size, std::vector<int>(board_size, 0));
        for (int i = 0; i < board_size; ++i) {
            board[i][queens[i]] = 1;
        }
        solutions.push_back(board);
        return;
    }
    for (int col{}; col < board_size; ++col) {
        if (invalid_columns[col] || invalid_backward_diagonals[col + current_row]
            || invalid_forward_diagonals[col - current_row + board_size - 1])
            continue;
        queens[current_row] = col;
        invalid_columns[col] = true;
        invalid_backward_diagonals[col + current_row] = true;
        invalid_forward_diagonals[col - current_row + board_size - 1] = true;
        depth_first_search(solutions,
                           queens,
                           current_row + 1,
                           board_size,
                           invalid_columns,
                           invalid_forward_diagonals,
                           invalid_backward_diagonals);
        queens[current_row] = -1;
        invalid_columns[col] = false;
        invalid_backward_diagonals[col + current_row] = false;
        invalid_forward_diagonals[col - current_row + board_size - 1] = false;
    }
}

std::vector<std::vector<std::vector<int>>> solve_queen_problem(int board_size) {
    auto solutions = std::vector<std::vector<std::vector<int>>>();
    auto queens = std::vector<int>(board_size, -1);
    auto invalid_columns = std::vector<bool>(board_size);
    auto invalid_forward_diagonals = std::vector<bool>(2 * board_size - 1);
    auto invalid_backward_diagonals = std::vector<bool>(2 * board_size - 1);
    depth_first_search(solutions,
                       queens,
                       0,
                       board_size,
                       invalid_columns,
                       invalid_forward_diagonals,
                       invalid_backward_diagonals
    );
    return solutions;

}


#endif //QUEENS_PROBLEM_H
