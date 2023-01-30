//
// Created by andreas on 30.01.23.
//

#ifndef QUICK_UNION_WITH_UNION_BY_RANK_H
#define QUICK_UNION_WITH_UNION_BY_RANK_H
#include <vector>

class QuickUnionByRank
{
public:
	explicit QuickUnionByRank(size_t size)
		:
		roots(size),
		ranks(size, 1)
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
		if (ranks[root_x] > ranks[root_y])
			roots[root_y] = root_x;
		else if (ranks[root_x] < ranks[root_y])
			roots[root_x] = root_y;
		else {
			roots[root_y] = root_x;
			ranks[root_x]++;
		}
	}

	bool are_connected(size_t x, size_t y)
	{
		return find(x) == find(y);
	}

private:
	std::vector<size_t> roots;
	std::vector<size_t> ranks;
};

#endif //QUICK_UNION_WITH_UNION_BY_RANK_H
