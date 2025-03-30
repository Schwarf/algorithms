//
// Created by andreas on 31.01.23.
//

#ifndef OPTIMIZED_DISJOINT_SET_H
#define OPTIMIZED_DISJOINT_SET_H
#include <vector>

class OptimizedDisjointSet
{
public:
    explicit OptimizedDisjointSet(size_t size)
        :
        roots(size),
        ranks(size)
    {
        for (size_t i{}; i < size; ++i)
        {
            roots[i] = i;
            ranks[i] = 1;
        }
    }

    size_t find_root(size_t element)
    {
        if (element == roots[element])
            return element;
        return roots[element] = find_root(roots[element]);
    }

    void union_set(size_t element1, size_t element2)
    {
        auto root_element1 = find_root(element1);
        auto root_element2 = find_root(element2);
        if (root_element1 == root_element2)
            return;
        if (ranks[root_element1] > ranks[root_element2])
            roots[root_element2] = root_element1;
        else if (ranks[root_element1] < ranks[root_element2])
            roots[root_element1] = root_element2;
        else
        {
            roots[root_element2] = root_element1;
            ranks[root_element1]++;
        }
    }

    bool are_connected(size_t element1, size_t element2)
    {
        return find_root(element1) == find_root(element2);
    }

private:
    std::vector<size_t> roots;
    std::vector<size_t> ranks;
};

#endif //OPTIMIZED_DISJOINT_SET_H
