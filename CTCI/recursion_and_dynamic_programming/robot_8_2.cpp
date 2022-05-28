//
// Created by andreas on 28.05.22.
//

#include <vector>
#include <iostream>

bool getPath(std::vector<std::vector<bool>> & maze, int row, int col, std::vector<std::pair<int, int>> & points)
{
	if(row < 0 || col < 0 || !maze[row][col])
		return false;

	bool origin_reached = (row == 0) && (col == 0);
	if(origin_reached || getPath(maze, row-1, col, points) || getPath(maze, row, col-1, points))
	{
		points.push_back(std::make_pair(row, col));
		return true;
	}

	return false;
}

std::vector<std::pair<int, int>> getPath(std::vector<std::vector<bool>> & maze)
{
	std::vector<std::pair<int, int>> points;
	if(getPath(maze, maze.size() - 1, maze[0].size() - 1, points))
		return points;
	return {};
}



int main()
{
	auto maze = std::vector<std::vector<bool>>(3, std::vector<bool>(5, true));
	maze[0][1] = false;

	maze[1][1] = false;
	maze[1][2] = false;
	maze[1][3] = false;

	auto path = getPath(maze);
	for(const auto & pair: path)
	{
		std::cout << pair.first << "  " << pair.second << std::endl;
	}
	return 0;
}