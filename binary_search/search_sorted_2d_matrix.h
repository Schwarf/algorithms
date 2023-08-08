//
// Created by andreas on 08.08.23.
//

#ifndef SEARCH_SORTED_2D_MATRIX_H
#define SEARCH_SORTED_2D_MATRIX_H

#include <concepts>
#include <vector>

template<typename T>
requires std::is_arithmetic_v<T>
bool search_matrix(const std::vector<std::vector<T>> &matrix, T target)
{
	int max_col = matrix[0].size();
	int max_row = matrix.size();
	int max_index = max_col * max_row - 1;
	auto row_col = [&](int index) -> std::pair<int, int>
	{
		int row = index / max_col;
		int col = index - row * max_col;
		return std::make_pair(row, col);
	};
	int left = 0;
	int right = max_index;
	while (left <= right) {
		int mid = (left + right) / 2;
		auto [row, col] = row_col(mid);
		if (matrix[row][col] == target)
			return true;
		if (matrix[row][col] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return false;

}

#endif //SEARCH_SORTED_2D_MATRIX_H
