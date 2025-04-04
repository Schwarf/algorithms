//
// Created by andreas on 07.11.24.
//

#ifndef STRONGLY_CONNECTED_COMPONENTS_GABOW_H
#define STRONGLY_CONNECTED_COMPONENTS_GABOW_H
#include <stack>
#include "graphs/graph.h"

template <typename NodeType>
void gabow_dfs(NodeType current_node, const DirectedGraph<NodeType>& graph,
               std::unordered_map<NodeType, int>& discover_order,
               std::stack<NodeType>& path_stack, std::stack<int>& boundary_stack,
               std::unordered_set<NodeType>& identified_scc_nodes,
               std::set<std::set<NodeType>>& SCCs, int& current_index)
{
    discover_order[current_node] = current_index++;
    path_stack.push(current_node);
    boundary_stack.push(discover_order[current_node]);

    for (auto& neighbor : graph.get_neighbors(current_node))
    {
        if (!discover_order.contains(neighbor))
        {
            gabow_dfs(neighbor, graph, discover_order, path_stack, boundary_stack, identified_scc_nodes, SCCs,
                      current_index);
        }
        if (!identified_scc_nodes.contains(neighbor))
        {
            while (boundary_stack.top() > discover_order[neighbor])
            {
                boundary_stack.pop();
            }
        }
    }

    if (boundary_stack.top() == discover_order[current_node])
    {
        boundary_stack.pop();
        std::set<NodeType> scc;
        NodeType node;
        do
        {
            node = path_stack.top();
            path_stack.pop();
            identified_scc_nodes.insert(node);
            scc.insert(node);
        }
        while (node != current_node);
        SCCs.insert(scc);
    }
}


template <typename NodeType>
std::set<std::set<NodeType>> strongly_connected_components_gabow(const DirectedGraph<NodeType>& graph)
{
    std::unordered_map<NodeType, int> discover_index;
    std::stack<NodeType> path_stack;
    std::stack<int> boundary_stack;
    std::unordered_set<NodeType> identified_scc_nodes;
    std::set<std::set<NodeType>> strongly_connected_components;
    int current_index{};

    for (auto& node : graph.get_all_nodes())
    {
        if (!discover_index.contains(node))
        {
            gabow_dfs(node, graph, discover_index, path_stack, boundary_stack, identified_scc_nodes,
                      strongly_connected_components, current_index);
        }
    }
    return strongly_connected_components;
}


#endif //STRONGLY_CONNECTED_COMPONENTS_GABOW_H
