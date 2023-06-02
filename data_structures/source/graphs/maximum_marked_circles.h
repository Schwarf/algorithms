//
// Created by andreas on 02.06.23.
//

#ifndef MAXIMUM_MARKED_CIRCLES_H
#define MAXIMUM_MARKED_CIRCLES_H
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <stack>
// You are given a list of circles. The range of a circle is defined as the area defined by its radius.
// The circle are represented by a 0-indexed 2D integer array circles where circle[i] = [xi, yi, ri]. xi and yi
// denote the X-coordinate and Y-coordinate of the location of the ith circle, whereas ri denotes the radius.
// Choose one single circle I and mark it. All circles O within the range of I get marked too. These marked circles O
// will mark all circles in their range and so on.
// Return the maximum number of circles that can be marked if you are allowed to mark only one circle initially.

int dfs(std::unordered_map<int, std::vector<int>> &graph, int index)
{
	std::stack<int> s{{index}};
	std::unordered_set<int> visited{index};
	while (!s.empty()) {
		int current = s.top();
		s.pop();
		for (const auto &neighbor: graph[current]) {
			if (visited.find(neighbor) == visited.end()) {
				visited.insert(neighbor);
				s.push(neighbor);
			}
		}
	}
	return visited.size();
}

int bfs(std::unordered_map<int, std::vector<int>> &graph, int index)
{
	std::queue<int> q{{index}};
	std::unordered_set<int> visited{index};
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (const auto &neighbor: graph[current]) {
			if (visited.find(neighbor) == visited.end()) {
				visited.insert(neighbor);
				q.push(neighbor);
			}
		}
	}
	return visited.size();
}

template<typename T, bool choose_bfs>
int maximum_marked_circles(const std::vector<std::vector<T>> &circles)
{
	std::unordered_map<int, std::vector<int>> graph;
	int n = circles.size();
	for (int i{}; i < n; ++i) {
		for (int j{}; j < n; ++j) {
			if (i == j)
				continue;
			double distance_squared =
				static_cast<double>(circles[i][0] - circles[j][0]) * static_cast<double>(circles[i][0] - circles[j][0])
					+ static_cast<double>(circles[i][1] - circles[j][1])
						* static_cast<double>(circles[i][1] - circles[j][1]);
			double radius_squared = static_cast<double>(circles[i][0]) * static_cast<double>(circles[i][0]);
			if (distance_squared <= radius_squared)
				graph[i].push_back(j);
		}
	}
	auto function = choose_bfs ? &bfs : &dfs;
	int maximum{};
	for (int i{}; i < graph.size(); ++i) {
		maximum = std::max(maximum, function(graph, i));
	}
	return maximum;
}

#endif //MAXIMUM_MARKED_CIRCLES_H
