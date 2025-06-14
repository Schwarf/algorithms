//
// Created by andreas on 14.06.25.
//

#ifndef ZERO_MATRIX_H
#define ZERO_MATRIX_H
// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to 0.
#include <vector>
#include <unordered_set>
void zero_matrix(std::vector<std::vector<int>>& matrix)
{
      int rows = matrix.size();
      int columns = matrix[0].size();
      std::unordered_set<int> zero_cols;
      std::unordered_set<int> zero_rows;
      for(int row = 0; row < rows; ++row){
            for(int col = 0; col < columns; ++col)
            {
                if(matrix[row][col] == 0)
                {
                    zero_cols.insert(col);
                    zero_rows.insert(row);
                }
            }
      }

    for(int row = 0; row < rows; ++row){
        for(int col = 0; col < columns; ++col)
        {
            if(zero_cols.contains(col) || zero_rows.contains(row))
            {
              matrix[row][col] = 0;
            }
        }
    }

}
#endif //ZERO_MATRIX_H
