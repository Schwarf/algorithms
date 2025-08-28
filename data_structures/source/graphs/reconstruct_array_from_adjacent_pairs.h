//
// Created by andreas on 10.11.23.
//

#ifndef RECONSTRUCT_ARRAY_FROM_ADJACENT_PAIRS_H
#define RECONSTRUCT_ARRAY_FROM_ADJACENT_PAIRS_H
#include <vector>
#include <unordered_map>
#include <stack>

template <typename T>
std::vector<T> reconstruct_array_from_adjacent_pairs(std::vector<std::vector<T>>& pairs)
{
    std::unordered_map<T, std::vector<T>> graph;
    for (auto& pair : pairs)
    {
        graph[pair[0]].push_back(pair[1]);
        graph[pair[1]].push_back(pair[0]);
    }
    T start{};
    for (auto node : graph)
    {
        if (node.second.size() == 1)
        {
            start = node.first;
            break;
        }
    }
    std::stack<T> s;
    s.push(start);
    T last{};
    std::vector<T> result;
    while (!s.empty())
    {
        auto current = s.top();
        result.push_back(current);
        s.pop();
        for (auto node : graph[current])
        {
            if (node != last)
            {
                s.push(node);
            }
        }
        last = current;
    }
    return result;
}

#endif //RECONSTRUCT_ARRAY_FROM_ADJACENT_PAIRS_H
