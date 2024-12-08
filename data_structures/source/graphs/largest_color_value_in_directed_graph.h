//
// Created by andreas on 04.12.24.
//

#ifndef LARGEST_COLOR_VALUE_IN_DIRECTED_GRAPH_H
#define LARGEST_COLOR_VALUE_IN_DIRECTED_GRAPH_H
#include <queue>

#include "graph.h"
// There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
// You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node
// in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there
// is a directed edge from node aj to node bj.
// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge
// from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
// Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

// TAG: Topological sort
int largest_color_value_in_directed_graph(std::string & colors, std::vector<std::vector<int>> & edges)
{
    int n = colors.size();
    std::vector<std::vector<int>> graph(n);
    std::vector<int> indegree(n);
    for(const auto & edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    std::vector<std::vector<int>> count(n, std::vector<int>(26) );
    std::queue<int> q;
    for(int i{}; i < n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    int result{};
    int node_visited{};
    while(!q.empty())
    {
        auto current = q.front();
        q.pop();
        result = std::max(result, ++count[current][colors[current] - 'a']);
        node_visited++;
        for(const auto neighbor : graph[current])
        {
            for(int i{}; i < 26; i++){
                // Try to update the frequency of colors for neighbor to include paths
                    // that use node->neighbor edge.
                        count[neighbor][i] = std::max(count[neighbor][i], count[current][i]);
            }
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return node_visited < n ? -1 : result;
}

#endif //LARGEST_COLOR_VALUE_IN_DIRECTED_GRAPH_H
