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
         std::unordered_map<NodeType, int>& ancestor_reachability_value, std::stack<NodeType>& scc_candidates,
         std::unordered_set<NodeType>& in_active_path, std::set<std::set<NodeType>>& SCCs, int& discovery_index) {

    discovery_order[current_node] = ancestor_reachability_value[current_node] = discovery_index++;
    scc_candidates.push(current_node);
    in_active_path.insert(current_node);

    for (auto neighbor : graph.get_neighbors(current_node)) {
        if (!discovery_order.contains(neighbor)) {
            dfs_ssc_trajan(neighbor, graph, discovery_order, ancestor_reachability_value, scc_candidates, in_active_path, SCCs, discovery_index);
            // update the reachability
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node], ancestor_reachability_value[neighbor]);
        } else if (in_active_path.contains(neighbor)) {
            // Neighbor node is in the current SCC
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node], discovery_order[neighbor]);
        }
    }

    // Check if current node is a root node of a strongly connected component
    if (ancestor_reachability_value[current_node] == discovery_order[current_node]) {
        std::set<NodeType> scc;
        NodeType node;
        do {
            node = scc_candidates.top();
            scc_candidates.pop();
            in_active_path.erase(node);
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
    std::stack<NodeType> scc_candidates{};
    std::unordered_set<NodeType> in_active_path{};
    std::unordered_map<NodeType, int> ancestor_reachability_value;
    int discovery_index{};

    // Run DFS for each unvisited node
    for (auto node : graph.get_all_nodes())
    {
        if (!discovery_order.contains(node))
        {

            // Node v has not been visited
            dfs_ssc_trajan(node, graph, discovery_order, ancestor_reachability_value, scc_candidates, in_active_path,
                strongly_connected_components, discovery_index);
        }
    }

    return strongly_connected_components;
}

#endif //TARJAN_ALGORITHM_DIRECTED_GRAPH_H
