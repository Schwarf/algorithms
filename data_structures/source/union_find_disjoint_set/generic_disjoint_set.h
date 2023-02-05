//
// Created by andreas on 05.02.23.
//

#ifndef GENERIC_DISJOINT_SET_H
#define GENERIC_DISJOINT_SET_H
#include <unordered_map>

template<typename id_T>
class DisjointSet
{

private:
	std::unordered_map<id_T, id_T> parent_mapping_;
	std::unordered_map<id_T, size_t> rank_;
	
};

#endif //GENERIC_DISJOINT_SET_H
