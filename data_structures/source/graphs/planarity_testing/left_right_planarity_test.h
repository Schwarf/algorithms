//
// Created by andreas on 14.12.24.
//

#ifndef LEFT_RIGHT_PLANARITY_TEST_H
#define LEFT_RIGHT_PLANARITY_TEST_H
#include "graphs/graph.h"


template<typename NodeType>
bool is_planar(UndirectedGraph<NodeType> & graph)
{
    // Check Euler's formula
    if(graph.get_edge_count() > 2 && graph.get_edge_count() > 3 * graph.get_node_count() -6)
        return false;
    std::vector<NodeType> roots;
    std::unordered_map<NodeType, int> heights;
    

}


#endif //LEFT_RIGHT_PLANARITY_TEST_H
