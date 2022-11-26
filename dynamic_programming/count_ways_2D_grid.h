//
// Created by andreas on 18.07.22.
//

#ifndef COUNT_WAYS_2D_GRID_H
#define COUNT_WAYS_2D_GRID_H
#include <unordered_map>

// 2D grid. You start from upper left corner and have to reach lower right corner. How many ways are there to reach
// the lower right corner.

struct pair_hash
{
	template<class T1, class T2>
	std::size_t operator()(const std::pair<T1, T2> &pair) const
	{
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

int count_ways_down_and_right_in_2D_grid(int number_of_rows,
										 int number_of_columns,
										 std::unordered_map<std::pair<int, int>, int, pair_hash> &help)
{
	if (number_of_columns == 0 || number_of_rows == 0)
		return 0;
	auto pair = std::make_pair(number_of_rows, number_of_columns);

	if (help.find(pair) != help.end())
		return help[pair];
	help[pair] = count_ways_down_and_right_in_2D_grid(number_of_rows - 1, number_of_columns, help)
		+ count_ways_down_and_right_in_2D_grid(number_of_rows, number_of_columns - 1, help);

	return help[pair];
}

int count_ways_down_and_right_in_2D_grid(int number_of_rows, int number_of_columns)
{
	std::unordered_map<std::pair<int, int>, int, pair_hash> row_column_number_of_ways;
	// The termination condition for the recursive call is stored in the unordered_map
	row_column_number_of_ways[std::make_pair(1, 1)] = 1;
	return count_ways_down_and_right_in_2D_grid(number_of_rows, number_of_columns, row_column_number_of_ways);
}

#endif //COUNT_WAYS_2D_GRID_H
