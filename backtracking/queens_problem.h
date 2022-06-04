//
// Created by andreas on 04.06.22.
//

#ifndef QUEENS_PROBLEM_H
#define QUEENS_PROBLEM_H
#include <vector>
#include <string>

void depth_first_search(std::vector<std::vector<std::string>> &result,
						std::vector<std::string> &&board,
						int row,
						int board_size,
						std::vector<bool> &&invalid_columns,
						std::vector<bool> &&invalid_forward_diagonals,
						std::vector<bool> &&invalid_backward_diagonals)
{
	if (row == board_size) {
		result.push_back(board);
		return;
	}
	for (int col = 0; col < board_size; ++col) {
		if (invalid_columns[col] || invalid_backward_diagonals[col + row]
			|| invalid_forward_diagonals[col - row + board_size - 1])
			continue;
		board[row][col] = 'Q';
		invalid_columns[col] = true;
		invalid_backward_diagonals[col + row] = true;
		invalid_forward_diagonals[col - row + board_size - 1] = true;
		depth_first_search(result,
						   std::move(board),
						   row + 1,
						   board_size,
						   std::move(invalid_columns),
						   std::move(invalid_forward_diagonals),
						   std::move(invalid_backward_diagonals));
		invalid_columns[col] = false;
		invalid_backward_diagonals[col + row] = false;
		invalid_forward_diagonals[col - row + board_size - 1] = false;
		board[row][col] = '-';

	}
}

std::vector<std::vector<std::string>> solve_queen_problem(int board_size)
{
	auto result = std::vector<std::vector<std::string>>();
	auto board = std::vector<std::string>(board_size, std::string(board_size, '-'));
	depth_first_search(result,
					   std::move(board),
					   0,
					   board_size,
					   std::vector<bool>(board_size),
					   std::vector<bool>(2 * board_size - 1),
					   std::vector<bool>(2 * board_size - 1));
	return result;

}


#endif //QUEENS_PROBLEM_H
