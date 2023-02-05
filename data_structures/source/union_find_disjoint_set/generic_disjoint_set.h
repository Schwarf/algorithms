//
// Created by andreas on 05.02.23.
//

#ifndef GENERIC_DISJOINT_SET_H
#define GENERIC_DISJOINT_SET_H
#include <unordered_map>

template<typename id_T>
class DisjointSet
{

public:
	bool add_set(const id_T &element)
	{
		if (parent_mapping_.find(element) != parent_mapping_.end())
			return false;
		parent_mapping_[element] = element;
		rank_[element] = 1;
	}

	id_T get_root(const id_T &element)
	{
		if (element == parent_mapping_[element])
			return element;
		return parent_mapping_[element] = get_root(parent_mapping_[element]);
	}

	void union_set(const id_T &element1, const id_T &element2)
	{
		id_T root1 = get_root(element1);
		id_T root2 = get_root(element2);
		if (root1 == root2)
			return;
		if (rank_[root1] > rank_[root2])
			parent_mapping_[root2] = root1;
		else if (rank_[root1] < rank_[root2])
			parent_mapping_[root1] = root2;
		else {
			parent_mapping_[root2] = root1;
			rank_[root1]++;
		}
	}

	bool are_connected(const id_T &element1, const id_T &element2)
	{
		return get_root(element1) == get_root(element2);
	}
private:
	std::unordered_map<id_T, id_T> parent_mapping_;
	std::unordered_map<id_T, size_t> rank_;

};

#endif //GENERIC_DISJOINT_SET_H
