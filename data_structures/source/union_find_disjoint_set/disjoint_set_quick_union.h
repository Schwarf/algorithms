//
// Created by andreas on 30.01.23.
//

#ifndef DISJOINT_SET_QUICK_UNION_H
#define DISJOINT_SET_QUICK_UNION_H
//
// Created by andreas on 30.01.23.
//

#ifndef DISJOINT_SET_QUICK_FIND_H
#define DISJOINT_SET_QUICK_FIND_H
#include <vector>

class DisjointSetQuickUnion
{
public:
	explicit DisjointSetQuickUnion(size_t size)
		:
		roots(size)
	{
		for (size_t i{}; i < size; ++i) {
			roots[i] = i;
		}
	}

	size_t find(size_t x)
	{
		while (x != roots[x])
			x = roots[x];
		return x;
	}

	void union_set(size_t x, size_t y)
	{
		auto root_x = find(x);
		auto root_y = find(y);
		if (root_x == root_y)
			return;
		roots[root_y] = root_x;
	}

	bool are_connected(size_t x, size_t y)
	{
		return find(x) == find(y);
	}

private:
	std::vector<size_t> roots;
};


#endif //DISJOINT_SET_QUICK_FIND_H

#endif //DISJOINT_SET_QUICK_UNION_H
