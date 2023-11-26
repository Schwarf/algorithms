//
// Created by andreas on 26.11.23.
//

#ifndef LARGEST_SUBMATRIX_BY_MOVING_COLUMNS_H
#define LARGEST_SUBMATRIX_BY_MOVING_COLUMNS_H
// You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the
// columns of the matrix in any order. The matrix only contains 1's and 0's.
// Return the area of the largest submatrix within matrix where every element of the
// submatrix is 1 after reordering the columns optimally.
#include <vector>
#include <concepts>
#include <functional>

template <typename T>
requires std::is_integral_v<T>
int largest_submatrix(std::vector<std::vector<T>>& matrix) {
	int rows = matrix.size();
	int columns = matrix[0].size();
	auto previous_row = std::vector(columns, 0);
	int result = 0;

	for (int row = 0; row < rows; row++) {
		auto current_row = matrix[row];
		for (int col = 0; col < columns; col++) {
			if (current_row[col] != 0) {
				current_row[col] += previous_row[col];
			}
		}

		std::vector<T> current_sorted_row = current_row;
		std::sort(current_sorted_row.begin(), current_sorted_row.end(), std::greater<T>());
		for (int i = 0; i < columns; i++) {
			result = std::max(result, static_cast<int>(current_sorted_row[i] * (i + 1)));
		}
		previous_row = current_row;
	}

	return result;
}

#endif //LARGEST_SUBMATRIX_BY_MOVING_COLUMNS_H
