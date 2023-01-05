//
// Created by andreas on 05.01.23.
//

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H
#include "graph.h"

template<typename id_T, typename data_T, typename weight_T, bool directed_ = false>
class WeightedGraph
{
public:
	void set_has_cycle()
	{
		has_cycle_ = true;
	}

	bool has_cycle()
	{
		return has_cycle_;
	}
private:
	// Here we store the relations between nodes/vertices if they exist including the weights.
	std::unordered_map<id_T, std::set<std::pair<weight_T, id_T>>> edges_;
	// Here we store all graph-nodes (id, data) pairs, that can be retrieved using the id. A node might be isolated.
	// not participating in any relations with other nodes
	std::unordered_map<id_T, GraphNodePtr<id_T, data_T>> vertices_;
	bool has_cycle_{};

};


#endif //WEIGHTED_GRAPH_H
