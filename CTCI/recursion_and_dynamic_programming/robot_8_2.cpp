//
// Created by andreas on 28.05.22.
//

#include <vector>
#include <iostream>
#include <unordered_set>

struct pair_hash
{
	template<class T1, class T2>
	std::size_t operator()(std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};

bool getPath(std::vector<std::vector<bool>> &maze, int row, int col, std::vector<std::pair<int, int>> &points)
{
	if (row < 0 || col < 0 || !maze[row][col])
		return false;

	bool origin_reached = (row == 0) && (col == 0);
	if (origin_reached || getPath(maze, row - 1, col, points) || getPath(maze, row, col - 1, points)) {
		points.push_back(std::make_pair(row, col));
		return true;
	}

	return false;
}

std::vector<std::pair<int, int>> getPath(std::vector<std::vector<bool>> &maze)
{
	std::vector<std::pair<int, int>> points;
	if (getPath(maze, maze.size() - 1, maze[0].size() - 1, points))
		return points;
	return {};
}

bool getPath_memo(std::vector<std::vector<bool>> &maze,
				  int row,
				  int col,
				  std::vector<std::pair<int, int>> &points,
				  std::unordered_set<std::pair<int, int>, pair_hash> &memo)
{
	if (row < 0 || col < 0 || !maze[row][col])
		return false;

	if (memo.find(std::make_pair(row, col)) != memo.end())
		return false;

	bool origin_reached = (row == 0) && (col == 0);
	if (origin_reached || getPath_memo(maze, row - 1, col, points, memo)
		|| getPath_memo(maze, row, col - 1, points, memo)) {
		points.push_back(std::make_pair(row, col));
		return true;
	}
	memo.insert(std::make_pair(row, col));
	return false;
}

std::vector<std::pair<int, int>> getPath_memo(std::vector<std::vector<bool>> &maze)
{
	std::vector<std::pair<int, int>> points;
	std::unordered_set<std::pair<int, int>, pair_hash> memo;
	if (getPath_memo(maze, maze.size() - 1, maze[0].size() - 1, points, memo))
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
	for (const auto &pair: path) {
		std::cout << pair.first << "  " << pair.second << std::endl;
	}

	std::cout << "***************" << std::endl;
	auto path2 = getPath(maze);
	for (const auto &pair: path2) {
		std::cout << pair.first << "  " << pair.second << std::endl;
	}
	return 0;
}