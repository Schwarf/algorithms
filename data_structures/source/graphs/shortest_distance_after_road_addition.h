//
// Created by andreas on 01.12.24.
//

#ifndef SHORTEST_DISTANCE_AFTER_ROAD_ADDITION_H
#define SHORTEST_DISTANCE_AFTER_ROAD_ADDITION_H

// You are given an integer n and a 2D integer array queries.
// There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to
// city i + 1 for all 0 <= i < n - 1.
// queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi.
// After each query, you need to find the length of the shortest path from city 0 to city n - 1.
// Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is
// the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.
#include <queue>
#include <vector>


int road_bfs(const int n, const std::vector<std::vector<int>>& graph)
{
    std::queue<int> q{{0}};
    int distance{};
    std::vector<bool> visited(n);

    while(!q.empty())
    {
        auto size = q.size();
        while(size)
        {
            auto current = q.front();
            visited[current] = true;
            q.pop();
            if(current == n-1)
                return distance;
            for(auto neighbor : graph[current] )
            {
                if(!visited[neighbor])
                    q.push(neighbor);
            }
            size--;
        }
        distance++;

    }
    return -1;
}



std::vector<int> shortest_distance_after_road_additions(int n, std::vector<std::vector<int>>& additional_roads)
{
    std::vector<std::vector<int>> graph(n, std::vector<int>());
    for(int i{}; i < n-1; ++i)
    {
        graph[i].push_back(i+1);
    }
    std::vector<int> results(additional_roads.size(), 0);
    for(int i{}; i < additional_roads.size(); ++i)
    {
        graph[additional_roads[i][0]].push_back(additional_roads[i][1]);
        auto distance = road_bfs(n, graph);
        if(distance == 1)
        {
            std::fill(results.begin()+i, results.end(), 1);
            break;
        }
        results[i] = distance;
    }
    return results;

}



#endif //SHORTEST_DISTANCE_AFTER_ROAD_ADDITION_H
