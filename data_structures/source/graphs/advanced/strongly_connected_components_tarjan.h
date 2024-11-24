//
// Created by andreas on 05.11.24.
//

#ifndef TARJAN_ALGORITHM_DIRECTED_GRAPH_H
#define TARJAN_ALGORITHM_DIRECTED_GRAPH_H

#include <stack>
#include "./../graph.h"


template <typename NodeType>
    requires std::is_signed_v<NodeType>
void dfs_ssc_trajan(NodeType current_node, const DirectedGraph<NodeType>& graph,
                    std::unordered_map<NodeType, int>& discovery_order,
                    std::unordered_map<NodeType, int>& ancestor_reachability_value,
                    std::stack<NodeType>& scc_candidates,
                    std::unordered_set<NodeType>& in_active_path, std::set<std::set<NodeType>>& SCCs,
                    int& discovery_index)
{
    // Discovery order keeps track of the order in which each node was first visited during DFS.
    discovery_order[current_node] = discovery_index++;
    // Ancestor reachability value tracks the smallest discovery index reachable from current_node,
    // including back edges within the current DFS path. Initially, it is set to the node's own discovery order.
    ancestor_reachability_value[current_node] = discovery_order[current_node];
    // This adds current_node to the stack of nodes that are potential candidates for the current SCC.
    // Nodes remain in scc_candidates until we identify the root of the SCC they belong to.
    scc_candidates.push(current_node);
    // This marks current_node as being in the active DFS path, meaning it is part of the current exploration.
    // Nodes in in_active_path are still being considered for SCC formation.
    in_active_path.insert(current_node);

    for (auto neighbor : graph.get_neighbors(current_node))
    {
        // This branch handles the first encounter of the neighbor-node
        if (!discovery_order.contains(neighbor))
        {
            dfs_ssc_trajan(neighbor, graph, discovery_order, ancestor_reachability_value, scc_candidates,
                           in_active_path, SCCs, discovery_index);
            // update the reachability
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node],
                                                                 ancestor_reachability_value[neighbor]);
        }
        // This branch handles the second (or higher) encounters of the neighbor-nodes
        else if (in_active_path.contains(neighbor))
        {
            // Neighbor node is in the current active path. That means we saw it before, and we found a back-edge.
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node],
                                                                 discovery_order[neighbor]);
        }
    }

    // Check if current node is a ROOT node of a strongly connected component
    // The ROOT node has the same ancestor_reachability_value as the discovery_order
    if (ancestor_reachability_value[current_node] == discovery_order[current_node])
    {
        std::set<NodeType> scc{};
        NodeType node{};
        do
        {
            node = scc_candidates.top();
            scc_candidates.pop();
            in_active_path.erase(node);
            scc.insert(node);
        }
        while (node != current_node);
        SCCs.insert(scc);
    }
}


template <typename NodeType>
    requires std::is_signed_v<NodeType>
std::set<std::set<NodeType>> strongly_connected_components_tarjan(const DirectedGraph<NodeType>& graph)
{
    std::unordered_map<NodeType, int> discovery_order;
    std::set<std::set<NodeType>> strongly_connected_components;
    // We push all potential candidates here. Starting form the first node visited.
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
