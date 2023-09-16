//
// Created by andreas on 16.09.23.
//

#ifndef PATH_WITH_MINIMUM_EFFORT_H
#define PATH_WITH_MINIMUM_EFFORT_H
#include <vector>
#include <queue>
#include <concepts>
#include <stack>
#include <limits>
template<typename T>
requires std::is_signed_v<T>
bool bfs_algo_reaches_right_lower_end(const std::vector<std::vector<T>> &heights, T threshold)
{
	int rows = heights.size();
	int columns = heights[0].size();
	std::vector<int> dirX = {-1, 1, 0, 0};
	std::vector<int> dirY = {0, 0, -1, 1};
	std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
	std::queue<std::pair<int, int>> q;
	q.emplace(0, 0);
	visited[0][0] = true;
	while (!q.empty()) {
		std::pair<int, int> current_position = q.front();
		q.pop();
		int x = current_position.first;
		int y = current_position.second;

		for (int i = 0; i < 4; ++i) {
			int newX = x + dirX[i];
			int newY = y + dirY[i];

			if (newX >= 0 && newX < rows && newY >= 0 && newY < columns && !visited[newX][newY]) {
				T effort = abs(heights[newX][newY] - heights[x][y]);
				if (effort <= threshold) {
					q.emplace(newX, newY);
					visited[newX][newY] = true;
				}
			}
		}
	}
	return visited[rows - 1][columns - 1];
}

template<typename T>
requires std::is_signed_v<T>
bool dfs_algo_reaches_right_lower_end(const std::vector<std::vector<T>> &heights, T threshold)
{
	int rows = heights.size();
	int columns = heights[0].size();
	std::vector<int> dirX = {-1, 1, 0, 0};
	std::vector<int> dirY = {0, 0, -1, 1};
	std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
	std::stack<std::pair<int, int>> q;
	q.emplace(0, 0);
	visited[0][0] = true;
	while (!q.empty()) {
		std::pair<int, int> current_position = q.top();
		q.pop();
		int x = current_position.first;
		int y = current_position.second;

		for (int i = 0; i < 4; ++i) {
			int newX = x + dirX[i];
			int newY = y + dirY[i];

			if (newX >= 0 && newX < rows && newY >= 0 && newY < columns && !visited[newX][newY]) {
				T effort = abs(heights[newX][newY] - heights[x][y]);
				if (effort <= threshold) {
					q.emplace(newX, newY);
					visited[newX][newY] = true;
				}
			}
		}
	}
	return visited[rows - 1][columns - 1];
}

template<typename T, typename GraphFunction>
requires std::is_signed_v<T>
T path_with_minimum_effort(const std::vector<std::vector<T>> &heights, GraphFunction graph_function)
{
	T left{};
	T right = 1e6; // Binary search bounds

	// Define 4 possible directions: up, down, left, right
	// We do a binary search for all possible height between 0...1e6
	while (left < right) {
		T mid = left + (right - left) / 2;
		// For each mid-value we search for a path (here bfs) that has a maximum effort below equal mid

		// If we can reach the bottom-right cell, we update mid-value fo binary search
		if (graph_function(heights, mid)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

// Using Djikstra algorithm
template<typename T>
requires std::is_signed_v<T>
T path_with_minimum_effort2(std::vector<std::vector<T>> &heights)
{
	int rows = heights.size();
	int cols = heights[0].size();

	// Initialize a 2D vector to store the minimum effort required to reach each cell
	std::vector<std::vector<T>> minimum_effort(rows, std::vector<T>(cols, std::numeric_limits<T>::max()));

	// Priority queue for Dijkstra's algorithm
	std::priority_queue<std::tuple<T, int, int>,
						std::vector<std::tuple<T, int, int>>,
						std::greater<std::tuple<T, int, int>>> pq;

	// Start from the top-left cell
	pq.push(std::make_tuple(0, 0, 0));
	minimum_effort[0][0] = 0;

	// Define possible directions to move (up, down, left, right)
	std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	while (!pq.empty()) {
		auto [currentEffort, currentRow, currentCol] = pq.top();
		pq.pop();

		// If we have reached the bottom-right cell, return the minimum effort
		if (currentRow == rows - 1 && currentCol == cols - 1) {
			return currentEffort;
		}

		for (const auto &dir: directions) {
			int newRow = currentRow + dir.first;
			int newCol = currentCol + dir.second;

			// Check if the new cell is within bounds
			if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
				// Calculate the effort to move to the new cell
				int newEffort = std::max(currentEffort, abs(heights[newRow][newCol] - heights[currentRow][currentCol]));

				// If the new effort is less than the minimum effort to reach the new cell,
				// update the minimum effort and add the new cell to the priority queue
				if (newEffort < minimum_effort[newRow][newCol]) {
					minimum_effort[newRow][newCol] = newEffort;
					pq.push(std::make_tuple(newEffort, newRow, newCol));
				}
			}
		}
	}

	// If we reach this point, it means we couldn't reach the bottom-right cell (should not happen in this context)
	return {};
}


#endif //PATH_WITH_MINIMUM_EFFORT_H
