//
// Created by andreas on 05.11.24.
//

#ifndef TARJAN_ALGORITHM_DIRECTED_GRAPH_H
#define TARJAN_ALGORITHM_DIRECTED_GRAPH_H

#include <stack>
#include "graph.h"


template <typename NodeType>
    requires std::is_signed_v<NodeType>
void dfs_ssc_trajan(NodeType current_node, const DirectedGraph<NodeType>& graph, std::unordered_map<NodeType, int>& discovery_order,
         std::unordered_map<NodeType, int>& ancestor_reachability_value, std::stack<NodeType>& stack,
         std::unordered_set<NodeType>& on_stack, std::set<std::set<NodeType>>& SCCs, int& discovery_index) {

    discovery_order[current_node] = ancestor_reachability_value[current_node] = discovery_index++;
    stack.push(current_node);
    on_stack.insert(current_node);

    for (auto neighbor : graph.get_neighbors(current_node)) {
        if (!discovery_order.contains(neighbor)) {  // Neighbor node has not been visited
            dfs_ssc_trajan(neighbor, graph, discovery_order, ancestor_reachability_value, stack, on_stack, SCCs, discovery_index);
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node], ancestor_reachability_value[neighbor]);
        } else if (on_stack.contains(neighbor)) {  // Neighbor node is in the current SCC
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node], discovery_order[neighbor]);
        }
    }

    // Check if current node is a root node of a strongly connected component
    if (ancestor_reachability_value[current_node] == discovery_order[current_node]) {
        std::set<NodeType> scc;
        NodeType node;
        do {
            node = stack.top();
            stack.pop();
            on_stack.erase(node);
            scc.insert(node);
        } while (node != current_node);
        SCCs.insert(scc);
    }
}


template <typename NodeType>
    requires std::is_signed_v<NodeType>
std::set<std::set<NodeType>> strongly_connected_components_tarjan(const DirectedGraph<NodeType>& graph)
{
    std::unordered_map<NodeType, int> discovery_order;
    std::set<std::set<NodeType>> strongly_connected_components;
    std::stack<NodeType> stack{};
    std::unordered_set<NodeType> on_stack{};
    std::unordered_map<NodeType, int> ancestor_reachability_value;
    int discovery_index{};

    // Run DFS for each unvisited node
    for (auto node : graph.get_all_nodes())
    {
        if (!discovery_order.contains(node))
        {

            // Node v has not been visited
            dfs_ssc_trajan(node, graph, discovery_order, ancestor_reachability_value, stack, on_stack,
                strongly_connected_components, discovery_index);
        }
    }

    return strongly_connected_components;
}

#endif //TARJAN_ALGORITHM_DIRECTED_GRAPH_H
