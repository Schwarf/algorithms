//
// Created by andreas on 14.09.23.
//

#ifndef RECONSTRUCT_FLIGHT_ITINERARY_H
#define RECONSTRUCT_FLIGHT_ITINERARY_H
#include <string>
#include <vector>
#include <unordered_map>
// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival
// airports of one flight. Reconstruct the itinerary in order and return it.
// All the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK".
// If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical
// order when read as a single string.
// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

void dfs(std::unordered_map<std::string, std::vector<std::string>> &graph,
		 std::string &current,
		 std::vector<std::string> &result)
{
	while (!graph[current].empty()) {
		auto next = graph[current].back();
		graph[current].pop_back();
		dfs(graph, next, result);
	}
	result.push_back(current);
}

std::vector<std::string> reconstruct_itinerary(const std::vector<std::vector<std::string>> &tickets)
{
	std::unordered_map<std::string, std::vector<std::string>> graph;

	// Create a graph from the given tickets
	for (const std::vector<std::string> &ticket: tickets) {
		graph[ticket[0]].push_back(ticket[1]);
	}

	// Sort the destinations in lexical order to satisfy the requirement
	for (auto &pair: graph) {
		sort(pair.second.begin(), pair.second.end(), std::greater<std::string>());
	}

	std::vector<std::string> result;
	std::string start = "JFK";
	dfs(graph, start, result);

	// Reverse the result to get the correct order
	reverse(result.begin(), result.end());

	return result;
}

#endif //RECONSTRUCT_FLIGHT_ITINERARY_H
