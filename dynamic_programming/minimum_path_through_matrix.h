//
// Created by andreas on 13.12.22.
//

#ifndef MINIMUM_PATH_THROUGH_MATRIX_H
#define MINIMUM_PATH_THROUGH_MATRIX_H
#include <vector>
#include <algorithm>
#include <climits>
//Given an n x n integer matrix, return the minimum sum of any downward path through the matrix.
//A downward path starts at any element in the first row and chooses the element in the next row that is either
// directly below or diagonally left/right.
//Specifically, the next element from position [row, col] will be [row + 1, col - 1], [row + 1, col]
// or [row + 1, col + 1].

int minimal_downward_path_through_matrix(std::vector<std::vector<int>> &matrix)
{
	int N = matrix.size();
	int total_minimum{INT_MAX};
	int minimum_last_row{};
	for (int row{1}; row < N; ++row) {
		for (int col{}; col < N; ++col) {
			minimum_last_row = matrix[row - 1][col];
			if (col > 0)
				minimum_last_row = std::min(minimum_last_row, matrix[row - 1][col - 1]);
			if (col < N - 1)
				minimum_last_row = std::min(minimum_last_row, matrix[row - 1][col + 1]);
			matrix[row][col] += minimum_last_row;
		}
	}
	for (int col{}; col < N; ++col)
		total_minimum = std::min(total_minimum, matrix[N - 1][col]);
	return total_minimum;
}
#endif //MINIMUM_PATH_THROUGH_MATRIX_H
