//
// Created by andreas on 09.09.24.
//

#ifndef DATA_STRUCTURES_SPIRAL_MATRIX_H
#define DATA_STRUCTURES_SPIRAL_MATRIX_H
// You are given two integers rows and columns, which represent the dimensions of a matrix.
// You are also given the head of a linked list of integers.
// Generate an rows x columns matrix that contains the integers in the linked list presented in spiral order (clockwise),
// starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
// Return the generated matrix.
#include <vector>
#include "node.h"

template <typename T>
std::vector<std::vector<T>> spiral_matrix(int rows, int columns, Node<T>* head)
{
    std::vector<std::vector<int>> result(rows, std::vector<int>(columns, -1));
    std::vector<std::pair<int, int>> directions{
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    if (!head)
        return result;
    int direction_index{};
    int row{};
    int col{};
    while (head)
    {
        result[row][col] = head->value;
        head = head->next;
        auto direction = directions[direction_index];
        auto new_row = direction.first + row;
        auto new_col = direction.second + col;
        if (std::min(new_col, new_row) < 0 || new_row >= rows || new_col >= columns || result[new_row][new_col] != -1)
        {
            direction_index = (direction_index + 1) % 4;
        }
        row += directions[direction_index].first;
        col += directions[direction_index].second;
    }
    return result;
}

#endif //DATA_STRUCTURES_SPIRAL_MATRIX_H
