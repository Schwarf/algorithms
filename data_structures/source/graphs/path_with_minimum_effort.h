//
// Created by andreas on 16.09.23.
//

#ifndef PATH_WITH_MINIMUM_EFFORT_H
#define PATH_WITH_MINIMUM_EFFORT_H
#include <vector>
#include <queue>
int path_with_minimum_effort_bfs(const std::vector<std::vector<int>> &heights)
{
	int rows = heights.size();
	int columns = heights[0].size();
	int left{};
	int right = 1e6; // Binary search bounds

	// Define 4 possible directions: up, down, left, right
	std::vector<int> dirX = {-1, 1, 0, 0};
	std::vector<int> dirY = {0, 0, -1, 1};
	// We do a binary search for all possible height between 0...1e6
	while (left < right) {
		int mid = left + (right - left) / 2;
		// For each mid value we search for a path (here bfs) that has a maximum effort below equal mid
		std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
		std::queue<std::pair<int, int>> q;
		q.emplace(0, 0);
		visited[0][0] = true;
		while (!q.empty()) {
			std::pair<int, int> curr = q.front();
			q.pop();
			int x = curr.first;
			int y = curr.second;

			for (int i = 0; i < 4; ++i) {
				int newX = x + dirX[i];
				int newY = y + dirY[i];

				if (newX >= 0 && newX < rows && newY >= 0 && newY < columns && !visited[newX][newY]) {
					int effort = abs(heights[newX][newY] - heights[x][y]);
					if (effort <= mid) {
						q.emplace(newX, newY);
						visited[newX][newY] = true;
					}
				}
			}
		}

		// If we can reach the bottom-right cell, reduce the search space
		if (visited[rows - 1][columns - 1]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

#endif //PATH_WITH_MINIMUM_EFFORT_H
