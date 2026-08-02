//
// Created by andreas on 02.08.26.
//

#ifndef ALGORITHMS_KRUSKAL_ALGORITHM_H
#define ALGORITHMS_KRUSKAL_ALGORITHM_H

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

struct Edge
{
    int from;
    int to;
    int weight;
};

std::vector<std::vector<std::vector<int>>> kruskal_algorithm(std::vector<std::vector<std::vector<int>>> & edges)
{
    const int n = edges.size();
    std::vector<Edge> sorted_edges;

    for(int from = 0; from < n; ++from)
    {
        for(const auto & edge : edges[from])
        {
            sorted_edges.push_back({from, edge[0], edge[1]});
        }
    }
    std::ranges::sort(sorted_edges.begin(), sorted_edges.end(), [](const Edge & lhs, const Edge & rhs){return lhs.weight < rhs.weight;});
    std::vector<int> parents(n, -1);
    std::vector<int> rank(n);
    std::iota(parents.begin(), parents.end(), 0);

    auto find = [&](auto && self, int node) -> int
    {
        if (node != parents[node])
            parents[node] = self(self, parents[node]);
        return parents[node];
    };

    auto unite = [&](int first, int second)
    {
        int root_first = find(find, first);
        int root_second = find(find, second);
        if (root_first == root_second)
            return;

        if (rank[root_first] < rank[root_second])
            parents[root_first] = root_second;
        else if (rank[root_first] > rank[root_second])
            parents[root_second] = root_first;
        else
        {
            parents[root_second] = root_first;
            ++rank[root_first];
        }
    };

    std::vector<std::vector<std::vector<int>>> mst;
    for(const auto & edge : sorted_edges)
    {
        if (find(find, edge.from) != find(find, edge.to))
        {
            unite(edge.from, edge.to);
            mst[edge.from].push_back({edge.to, edge.weight});
            mst[edge.to].push_back({edge.from, edge.weight});
        }
    }

    return mst;
}


#endif // ALGORITHMS_KRUSKAL_ALGORITHM_H
