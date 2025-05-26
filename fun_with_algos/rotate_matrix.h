//
// Created by andreas on 26.05.25.
//

#ifndef ROTATE_MATRIX_H
#define ROTATE_MATRIX_H
// Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90/180/270 degrees. Can you do this in place?
#include <vector>
#include <algorithm>

void rotate_matrix_90(std::vector<std::vector<int>> &matrix){
    int n = matrix.size();
	// 1) Transpose (swap only when j < i)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    // 2) Horizontal flip
    for(auto & row : matrix)
    {
        std::reverse(row.begin(), row.end());
    }
}

void rotate_matrix_180(std::vector<std::vector<int>> &matrix){
 	// 1) horizontal flip
  	for (auto & row : matrix) {
        std::reverse(row.begin(), row.end());
    }
    // 2) vertical flip
    std::reverse(matrix.begin(), matrix.end());
}

void rotate_matrix_270(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    // 1) Horizontal flip
    for (auto & row : matrix) {
        std::reverse(row.begin(), row.end());
    }
    // 2) Transpose (swap only when j < i)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}
#endif //ROTATE_MATRIX_H
