//
// Created by andreas on 17.09.23.
//

#ifndef SHORTEST_PATH_LENGTH_H
#define SHORTEST_PATH_LENGTH_H
#include <queue>
#include <vector>
template<typename T>
requires std::is_unsigned_v<T>
T shortest_path_length(std::vector<std::vector<T>> &graph)
{
	const int n = graph.size();
	const int goal = (1 << n) - 1;

	T ans{};
	std::queue<std::pair<T, int>> q;  // (u, state)
	std::vector<std::vector<bool>> seen(n, std::vector<bool>(1 << n));

	for (int i = 0; i < n; ++i)
		q.emplace(i, 1 << i);

	while (!q.empty()) {
		for (int sz = q.size(); sz > 0; --sz) {
			const auto [u, state] = q.front();
			q.pop();
			if (state == goal)
				return ans;
			if (seen[u][state])
				continue;
			seen[u][state] = true;
			for (const int v: graph[u])
				q.emplace(v, state | (1 << v));
		}
		++ans;
	}

	return -1;
}
#endif //SHORTEST_PATH_LENGTH_H
