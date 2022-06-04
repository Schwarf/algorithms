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
	for(int col =0; col < board_size; ++col)
	{
		if(invalid_columns[col] || invalid_backward_diagonals[col + row ] || invalid_forward_diagonals[col - row + board_size -1])
			continue;
		
	}
}

std::vector<std::vector<std::string>> solve_queen_problem(int board_size)
{
	auto result = std::vector<std::vector<std::string>>();
	auto board = std::vector<std::string>(board_size, std::string(board_size, '.'));
	depth_first_search(result,
					   std::move(board),
					   0,
					   board_size,
					   std::vector<bool>(board_size),
					   std::vector<bool>(2 * board_size - 1),
					   std::vector<bool>(2 * board_size - 1));

}


#endif //QUEENS_PROBLEM_H
