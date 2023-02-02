//
// Created by andreas on 30.01.23.
//

#ifndef QUICK_UNION_H
#define QUICK_UNION_H
#include <vector>

class QuickUnion
{
public:
	explicit QuickUnion(size_t size)
		:
		roots(size)
	{
		for (size_t i{}; i < size; ++i) {
			roots[i] = i;
		}
	}

	size_t find(size_t element)
	{
		while (element != roots[element])
			element = roots[element];
		return element;
	}

	void union_set(size_t element1, size_t element2)
	{
		auto root_element1 = find(element1);
		auto root_element2 = find(element2);
		if (root_element1 == root_element2)
			return;
		roots[root_element2] = root_element1;
	}

	bool are_connected(size_t element1, size_t element2)
	{
		return find(element1) == find(element2);
	}


private:
	std::vector<size_t> roots;
};


#endif //QUICK_UNION_H
