//
// Created by andreas on 28.01.24.
//

#ifndef NUMBER_OF_SUB_MATRICES_THAT_SUM_TO_TARGET_H
#define NUMBER_OF_SUB_MATRICES_THAT_SUM_TO_TARGET_H
// Given a matrix and a target, return the number of non-empty submatrices that sum to target.
// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
#include <vector>
int number_of_submatrixes_with_target_sum(const std::vector<std::vector<int>> &matrix, int target)
{
	int rows = matrix.size();
	int columns = matrix[0].size();
	int count = 0;
	// Compute the prefix sum in each column across all rows
	std::vector<std::vector<int>> prefix_columns(rows + 1, std::vector<int>(columns));
	for (int row{}; row < rows; ++row) {
		for (int col{}; col < columns; ++col) {
			prefix_columns[row + 1][col] = prefix_columns[row][col] + matrix[row][col];
		}
	}

	for (int upper_row = 0; upper_row < rows; upper_row++) {
		for (int lower_row = upper_row + 1; lower_row <= rows; lower_row++) {
			for (int left_col = 0; left_col < columns; left_col++) {
				int sum = 0;
				for (int right_col = left_col; right_col < columns; right_col++) {
					sum += prefix_columns[lower_row][right_col] - prefix_columns[upper_row][right_col];
					if (sum == target) {
						count++;
					}
				}
			}
		}
	}
	return count;
}
#endif //NUMBER_OF_SUB_MATRICES_THAT_SUM_TO_TARGET_H
