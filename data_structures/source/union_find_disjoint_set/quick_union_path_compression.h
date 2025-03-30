//
// Created by andreas on 31.01.23.
//

#ifndef QUICK_UNION_PATH_COMPRESSION_H
#define QUICK_UNION_PATH_COMPRESSION_H
#include <vector>

class QuickUnionPathCompression
{
public:
    explicit QuickUnionPathCompression(size_t size)
        :
        roots(size)
    {
        for (size_t i{}; i < size; ++i)
        {
            roots[i] = i;
        }
    }

    size_t find(size_t element)
    {
        if (element == roots[element])
            return element;
        return roots[element] = find(roots[element]);
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


#endif //QUICK_UNION_PATH_COMPRESSION_H
