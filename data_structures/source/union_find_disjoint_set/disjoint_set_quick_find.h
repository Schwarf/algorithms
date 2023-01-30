//
// Created by andreas on 30.01.23.
//

#ifndef DISJOINT_SET_QUICK_FIND_H
#define DISJOINT_SET_QUICK_FIND_H
#include <vector>

class DisjointSetQuickFind
{
public:
	explicit DisjointSetQuickFind(size_t size)
		:
		roots(size)
	{
		for (size_t i{}; i < size; ++i) {
			roots[i] = i;
		}
	}

	size_t find(size_t x)
	{
		return roots[x];
	}

	void union_set(size_t x, size_t y)
	{
		auto root_x = find(x);
		auto root_y = find(y);
		if (root_x == root_y)
			return;
		for (size_t i{}; i < roots.size(); ++i) {
			if (roots[i] == root_y)
				roots[i] = root_x;
		}
	}

	bool are_connected(size_t x, size_t y)
	{
		return find(x) == find(y);
	}

private:
	std::vector<size_t> roots;
};


#endif //DISJOINT_SET_QUICK_FIND_H
