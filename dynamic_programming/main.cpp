//
// Created by andreas on 18.07.22.
//
#include "pascal_triangle.h"
#include <iostream>
#include <vector>
class Solution
{
public:
	std::vector<std::vector<int>> generate(int numRows)
	{

		std::vector<std::vector<int>> result;
		for (int i{}; i < numRows; ++i) {
			std::vector<int> row(i + 1, 1);
			result.push_back(row);
		}
		for (int row{1}; row < numRows; ++row) {
			for (int col{1}; col <= row; ++col) {
				result[row][col] = result[row - 1][col - 1] + result[row - 1][col];
			}
		}
		return result;
	}
};

int main()
{
	auto s = Solution();
	auto t = s.generate(5);
	int x = 1;
}