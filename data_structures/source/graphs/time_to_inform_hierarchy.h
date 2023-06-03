//
// Created by andreas on 03.06.23.
//

#ifndef TIME_TO_INFORM_HIERARCHY_H
#define TIME_TO_INFORM_HIERARCHY_H
// A group of n people is organize in a hierarchy and each person has a unique ID between 0 and n-1;
// The group leader has the provided headID. Each group member has a sub-group leader which is given in
// the array leaders and leaders[i] represents the subgroup leader of member i. The group-leader with headID
// has no leader leaders[headID] = -1. In addition a array time of size n where each entry i represents
// the time needed of member i to inform all the members of his/hers subgroup.
// Return the total time needed to inform all group members.

#include <vector>
#include <queue>
int time_to_inform_group(int n, int headID, const std::vector<int> &leaders, const std::vector<int> &times)
{
	std::vector<std::vector<int>> graph(n);
	for (int i{}; i < n; ++i) {
		if (leaders[i] == -1)
			continue;
		graph[leaders[i]].push_back(i);
	}
	std::queue<std::pair<int, int>> q;
	q.emplace(headID, 0);
	int max_time{};
	while (!q.empty()) {
		auto [member, time] = q.front();
		q.pop();
		max_time = std::max(max_time, time);
		for (const auto &comrade: graph[member])
			q.emplace(comrade, time + times[member]);
	}
	return max_time;
}

void dfs(std::vector<std::vector<int>> graph, const std::vector<int> &times, int member, int time, int &max_time)
{
	max_time = std::max(max_time, time);
	for (const auto &comrade: graph[member]) {
		dfs(graph, times, comrade, time + times[comrade], max_time);
	}
}

int time_to_inform_group_dfs(int n, int headID, const std::vector<int> &leaders, const std::vector<int> &times)
{
	std::vector<std::vector<int>> graph(n);
	for (int i{}; i < n; ++i) {
		if (leaders[i] == -1)
			continue;
		graph[leaders[i]].push_back(i);
	}
	int max_time{};
	dfs(graph, times, headID, 0, max_time);
	return max_time;
}

#endif //TIME_TO_INFORM_HIERARCHY_H
