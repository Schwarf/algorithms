//
// Created by andreas on 30.01.23.
//

#ifndef QUICK_FIND_H
#define QUICK_FIND_H
#include <vector>

class QuickFind
{
public:
    explicit QuickFind(size_t size)
        :
        roots(size)
    {
        for (size_t i{}; i < size; ++i)
        {
            roots[i] = i;
        }
    }

    size_t find_root(size_t element)
    {
        return roots[element];
    }

    void union_set(size_t element1, size_t element2)
    {
        auto root_element1 = find_root(element1);
        auto root_element2 = find_root(element2);
        if (root_element1 == root_element2)
            return;
        for (size_t i{}; i < roots.size(); ++i)
        {
            if (roots[i] == root_element2)
                roots[i] = root_element1;
        }
    }

    bool are_connected(size_t element1, size_t element2)
    {
        return find_root(element1) == find_root(element2);
    }

private:
    std::vector<size_t> roots;
};


#endif //QUICK_FIND_H
