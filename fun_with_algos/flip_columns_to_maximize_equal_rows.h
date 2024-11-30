//
// Created by andreas on 25.11.24.
//

#ifndef FLIP_COLUMNS_TO_MAXIMIZE_EQUAL_ROWS_H
#define FLIP_COLUMNS_TO_MAXIMIZE_EQUAL_ROWS_H
// You are given an m x n binary matrix matrix.
// You can choose any number of columns in the matrix and flip every cell in that column
// (i.e., Change the value of the cell from 0 to 1 or vice versa).
// Return the maximum number of rows that have all values equal after some number of flips.
#include <vector>
int maximize_equal_rows(std::vector<std::vector<int>>& matrix)
{
    int max_identical_rows{};
    for(auto & row : matrix)
    {
        auto flipped_row = row;
        for(auto & column : flipped_row)
        {
            column = 1 - column;
        }
        int identical_rows{};
        for(auto & other_row: matrix)
        {
            if(flipped_row == other_row || row==other_row)
                identical_rows++;
        }
        max_identical_rows = std::max(max_identical_rows, identical_rows);
    }
    return max_identical_rows;
}


#endif //FLIP_COLUMNS_TO_MAXIMIZE_EQUAL_ROWS_H
